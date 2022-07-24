module print_on_state_change(input in);

  always @ (posedge in) begin
    $display("\"in\" changed from 0 to 1");
  end

  always @ (negedge in) begin
    $display("\"in\" changed from 1 to 0");
  end
endmodule

module test_bench();

  reg in;
  print_on_state_change instance_name(in);

  initial begin
    $display("Hello, World!");

    repeat(5) begin
      in=0; #1;
      in=1; #1;
    end
    $finish;
  end
endmodule
