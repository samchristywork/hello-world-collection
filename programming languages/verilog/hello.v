/*
 * This is a module. Modules are similar to functions in procedural languages,
 * but instead of being "called" they are "instantiated". This is a subtle,
 * but important difference.
 *
 * It is worth thinking about modules not in terms of "actions", but more in
 * terms of "behaviors". Modules don't "do" things when they are instantiated.
 * Instead, they "act" in certain ways as a consequence of other modules in
 * the program.
 */
module print_on_state_change(input in);

  /*
   * This block of code "listens" for a positive edge on a signal, and
   * executes the block of statements whenever that edge is detected.
   */
  always @ (posedge in) begin
    $display("\"in\" changed from 0 to 1");
  end

  /*
   * This block of code "listens" for a negative edge on a signal, and
   * executes the block of statements whenever that edge is detected.
   */
  always @ (negedge in) begin
    $display("\"in\" changed from 1 to 0");
  end
endmodule

/*
 * This is the de-facto "main" or "entry point" for this program. Because
 * Verilog is inherently concurrent, there can be multiple entry points, or
 * none at all. The thing that differentiates this module from a module that
 * doesn't serve as an entry point is the "initial" block, described below.
 */
module test_bench();

  /*
   * This is where the module that was defined earlier is instantiated. This
   * instantiation brings the module into being. Each instance needs a unique
   * name.
   *
   * The argument that is passed to this instance is a register. We can think
   * of this register as being "connected" to the instance, so that the state
   * of the register is visible to the internals of the module that it is
   * being passed to.
   */
  reg in;
  print_on_state_change instance_name(in);

  /*
   * The initial block contains a list of statements that are executed when
   * the simulation begins. This can be useful for setting initial state, and
   * for writing test benches.
   */
  initial begin
    $display("Hello, World!");

    /*
     * This block of code toggles the state of the "in" variable between "on"
     * and "off" five times. The "#1" is a delay that waits for the simulation
     * to advance by one tick before continuing.
     */
    repeat(5) begin
      in=0; #1;
      in=1; #1;
    end
    $finish;
  end
endmodule
