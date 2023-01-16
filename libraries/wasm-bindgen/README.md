## WASM Bindgen Example

This sample program shows how to call a rust library from JavaScript with Web
Assembly.

## Requirements

Make sure your Rust install has the WASM architecture installed:

```
rustup target add wasm32-unknown-unknown
```

Make sure you have the `wasm-pack` program:

```
cargo install wasm-pack
```

Use `wasm-pack` to compile the Rust library:

```
wasm-pack build --target web
```

This will create a `pkg` directory with your compiled program. The contents of
this directory should be something like this:

```
package.json
README.md
wasm_bindgen_example_bg.wasm
wasm_bindgen_example_bg.wasm.d.ts
wasm_bindgen_example.d.ts
wasm_bindgen_example.js
```
