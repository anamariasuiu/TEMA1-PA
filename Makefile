all: build

build: walsh.cpp statistics.cpp prinel.cpp crypto.cpp 
	g++ -Wall walsh.cpp -o walsh -lm
	g++ -Wall statistics.cpp -o statistics -lm
	g++ -Wall prinel.cpp -o prinel -lm
	g++ -Wall crypto.cpp -o crypto -lm

run-p1:
	./walsh

run-p2:
	./statistics

run-p3:
	./prinel

run-p4:
	./crypto


.PHONY: clean

clean:
	rm -f run-p1 run-p2 run-p3 run-p4 run-p5
	rm -f *.out