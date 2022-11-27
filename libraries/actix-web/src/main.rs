use actix_files::Files;
use actix_session::{storage::CookieSessionStore, SessionMiddleware};
use actix_web::middleware::Logger;
use actix_web::{App, HttpServer};
use env_logger::Env;

mod get_double;
mod get_hello;
mod get_json;
mod get_session;

static SESSION_SIGNING_KEY: &[u8] = &[0; 64]; // Just an example

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    env_logger::init_from_env(Env::default().default_filter_or("info"));

    let key = actix_web::cookie::Key::from(SESSION_SIGNING_KEY);

    let host = "0.0.0.0";
    let port = 8080;
    log::info!("Serving on {} port {}", host, port);
    HttpServer::new(move || {
        App::new()
            .wrap(
                SessionMiddleware::builder(CookieSessionStore::default(), key.clone())
                    .cookie_secure(false)
                    .build(),
            )
            .wrap(Logger::default())
            .wrap(Logger::new("%a %{User-Agent}i"))
            .service(get_hello::hello)
            .service(get_double::double)
            .service(get_session::session)
            .service(get_json::json)
            .service(Files::new("/images", "static/images/").show_files_listing())
            .service(Files::new("/", "./static/root/").index_file("index.html"))
    })
    .bind((host, port))?
    .run()
    .await
}

#[cfg(test)]
mod tests {
    use super::*;
    use actix_web::{test, App};

    #[actix_web::test]
    async fn test_get_double() {
        let mut app = test::init_service(App::new().service(get_double::double)).await;

        let req = test::TestRequest::get().uri("/double/10").to_request();
        let resp = test::call_service(&mut app, req).await;
        assert!(resp.status().is_success());

        let req = test::TestRequest::get().uri("/double/10").to_request();
        let resp = test::call_and_read_body(&app, req).await;
        assert_eq!(resp, "Success: Your doubled number is 20!");

        let req = test::TestRequest::get().uri("/double/a").to_request();
        let resp = test::call_service(&mut app, req).await;
        assert!(resp.status().is_success());

        let req = test::TestRequest::get().uri("/double/a").to_request();
        let resp = test::call_and_read_body(&app, req).await;
        assert_eq!(
            resp,
            "Error: Please make sure your request includes a number."
        );
    }

    #[actix_web::test]
    async fn test_get_hello() {
        let mut app = test::init_service(App::new().service(get_hello::hello)).await;

        let req = test::TestRequest::get().uri("/hello/test").to_request();
        let resp = test::call_service(&mut app, req).await;
        assert!(resp.status().is_success());

        let req = test::TestRequest::get().uri("/hello/foo").to_request();
        let resp = test::call_and_read_body(&app, req).await;
        assert_eq!(resp, "Hello foo!");

        let req = test::TestRequest::get().uri("/hello/bar").to_request();
        let resp = test::call_and_read_body(&app, req).await;
        assert_eq!(resp, "Hello bar!");
    }

    #[actix_web::test]
    async fn test_get_json() {
        let mut app = test::init_service(App::new().service(get_json::json)).await;

        let req = test::TestRequest::get().uri("/json/foo").to_request();
        let resp = test::call_service(&mut app, req).await;
        assert!(resp.status().is_success());

        let req = test::TestRequest::get().uri("/json/foo").to_request();
        let resp = test::call_and_read_body(&app, req).await;
        assert_eq!(resp, "{\"name\":\"foo\",\"name_double\":\"foofoo\"}");
    }
}
