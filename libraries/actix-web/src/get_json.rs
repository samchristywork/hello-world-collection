use actix_web::{get, web, Responder};
use serde::Serialize;

#[derive(Serialize)]
struct MyObj {
    name: String,
    name_double: String,
}

#[get("/json/{name}")]
async fn json(name: web::Path<String>) -> impl Responder {
    let obj = MyObj {
        name: name.to_string(),
        name_double: name.to_string() + name.as_str(),
    };
    web::Json(obj)
}
