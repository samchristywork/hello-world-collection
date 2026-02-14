## Overview

This is the actix-web version of "Hello, World!". It starts an HTTP server on
port 8080 with several example endpoints:

- `GET /hello/{name}` - responds with a greeting
- `GET /double/{n}` - returns the number doubled
- `GET /json/{name}` - returns a JSON object
- `GET /session` - tracks visit count using a cookie session

Static files are served from `static/root/` and the root page is `index.html`.

It can be built and run with `cargo`.

## Running

```
cargo run
```

## Testing

```
cargo test
```

## Dependencies

```
cargo
rust
```
