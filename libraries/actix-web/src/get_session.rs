use actix_session::Session;
use actix_web::{get, Responder};

#[get("/session")]
async fn session(session: Session) -> impl Responder {
    let counter = match session.get::<i32>("counter") {
        Ok(counter) => match counter {
            Some(counter) => counter + 1,
            _ => 1,
        },
        _ => 1,
    };

    match session.insert("counter", counter) {
        _ => format!("You have visited {} times", counter),
    }
}
