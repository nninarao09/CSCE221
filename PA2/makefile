all : output1 output2

output1: q1.o
	g++ q1.o -o output1

output2: q2.o
	g++ q2.o -o output2

q1.o: q1.cpp
	g++ -c q1.cpp
	
q2.o: q2.cpp BinarySearchTree.h queueheader.h
	g++ -c q2.cpp

clean:
	rm *.o output1 output2 