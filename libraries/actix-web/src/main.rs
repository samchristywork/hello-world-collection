use actix_web::middleware::Logger;
use actix_web::{App, HttpServer};
use env_logger::Env;

mod get_double;
mod get_hello;

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    env_logger::init_from_env(Env::default().default_filter_or("info"));

    let host = "0.0.0.0";
    let port = 8080;
    println!("Serving on {} port {}.", host, port);
    HttpServer::new(|| {
        App::new()
            .wrap(Logger::default())
            .wrap(Logger::new("%a %{User-Agent}i"))
            .service(get_hello::hello)
            .service(get_double::double)
    })
    .bind((host, port))?
    .run()
    .await
}
