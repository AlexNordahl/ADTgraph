# Makefile

make:
	g++ -std=c++20 main.cpp graph.cpp -o main

clean:
	rm -f main