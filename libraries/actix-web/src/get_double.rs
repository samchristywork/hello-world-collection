use actix_web::{get, web, Responder};

#[get("/double/{number}")]
async fn double(number: web::Path<String>) -> impl Responder {
    match number.parse::<i32>() {
        Ok(x) => format!("Success: Your doubled number is {}!", x * 2),
        Err(_) => format!("Error: Please make sure your request includes a number."),
    }
}
