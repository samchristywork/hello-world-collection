(module
  (import "wasi_snapshot_preview1" "fd_write"
    (func $fd_write (param i32 i32 i32 i32) (result i32)))
  (memory 1)
  (export "memory" (memory 0))
  (data (i32.const 8) "Hello, World!\n")
  (func $main (export "_start")
    ;; iovec: ptr=8, len=14
    (i32.store (i32.const 0) (i32.const 8))
    (i32.store (i32.const 4) (i32.const 14))
    (drop
      (call $fd_write
        (i32.const 1)  ;; stdout
        (i32.const 0)  ;; iovec array
        (i32.const 1)  ;; one iovec
        (i32.const 20) ;; nwritten (unused)
      )
    )
  )
)
