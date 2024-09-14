# type "mingw32-make -f make1.mk" to run this makefile

main: make1.cpp
	g++ make1.cpp -o make1

clean:
	rm -f make1