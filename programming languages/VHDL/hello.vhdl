library ieee;
use ieee.std_logic_1164.all;

entity hello_world is
  port (clk: inout std_logic; comp: out std_logic);
end hello_world;

architecture behavior of hello_world
is
  constant period : time := 10 ns;
begin
  clk_process: process
  begin
    clk <= '0';
    wait for period/4;

    comp <= NOT clk;
    wait for period/4;

    clk <= '1';
    wait for period/4;

    comp <= NOT clk;
    wait for period/4;
  end process;
end behavior;
