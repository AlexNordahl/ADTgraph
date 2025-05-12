# Makefile

make:
	g++ -std=c++20 main.cpp graph.cpp -o main

clean:
	rm -f main; \
	cd tests;

test:
	cd tests; \
	g++ tests.cpp ../graph.cpp -lgtest -lgtest_main -pthread -o test; \
	./test; \
	rm -f test