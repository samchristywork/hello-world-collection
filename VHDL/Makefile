GHDL := ghdl-gcc

all: hello_world

hello_world: hello.o
	${GHDL} -e hello_world

hello.o: hello.vhdl
	${GHDL} -a hello.vhdl

clean:
	ghdl --clean
	rm -f work-obj93.cf

.PHONY: clean run
