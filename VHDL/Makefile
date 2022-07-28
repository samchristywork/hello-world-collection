GHDL := ghdl-gcc

all: hello_world

run: hello_world
	${GHDL} -r hello_world

hello_world: hello.o
	${GHDL} -e hello_world

hello.o: hello.vhdl
	${GHDL} -a hello.vhdl

gtkwave: hello_world.ghw
	gtkwave hello_world.ghw

hello_world.ghw: hello_world
	ghdl -r hello_world --wave=hello_world.ghw --stop-time=50ns

clean:
	ghdl --clean
	rm -f work-obj93.cf
	rm -f hello_world.ghw

.PHONY: clean run gtkwave
