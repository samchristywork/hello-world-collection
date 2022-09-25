GHDL := ghdl-gcc

all: hello_world

run: hello_world
	${GHDL} -r $^

hello_world: hello.o
	${GHDL} -e $@

hello.o: hello.vhdl
	${GHDL} -a $^

gtkwave: hello_world.ghw
	gtkwave $^

hello_world.ghw: hello_world
	ghdl -r $^ --wave=$@ --stop-time=50ns

clean:
	ghdl --clean
	rm -f work-obj93.cf
	rm -f hello_world.ghw

.PHONY: clean run gtkwave
