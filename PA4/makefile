all : output1 output2_1 output2_3 

output1: q1.o 
	g++ q1.o -o output1

output2_1: q2_1.o
	g++ q2_1.o -o output2_1
	
output2_3: q2_3.o 
	g++ q2_3.o -o output2_3

q1.o: q1.cpp Sort.h
	g++ -c q1.cpp
	
q2_1.o: q2_1.cpp MinHeap.h
	g++ -c q2_1.cpp

q2_3.o: q2_3.cpp MinHeap.h
	g++ -c q2_3.cpp
	
clean:
	rm *.o output1 output2_1 output2_3
