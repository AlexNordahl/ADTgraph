# Makefile

make:
	g++ -std=c++20 main.cpp graph.cpp -o main

clean:
	rm -f main; \
	rm -f graph.dot; \
	rm -f mygraph.png

test:
	cd tests; \
	g++ -std=c++20 test_constructors_and_assignment.cpp ../graph.cpp -lgtest -lgtest_main -pthread -o test; \
	./test; \
	rm -f test

plot:
	make; \
	./main; \
	dot -Tpng graph.dot -o mygraph.png; \
	feh mygraph.png