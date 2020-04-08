all : output1 output2 output3 output4

output1: q1.o 
	g++ q1.o -o output1

output2: q2.o
	g++ q2.o -o output2
	
output3: q3.o 
	g++ q3.o -o output3

output4: q4.o
	g++ q4.o -o output4

q1.o: q1.cpp
	g++ -c q1.cpp
	
q2.o: q2.cpp
	g++ -c q2.cpp

q3.o: q3.cpp
	g++ -c q3.cpp
	
q4.o: q4.cpp OrderedMap.h
	g++ -c q4.cpp
	
clean:
	rm *.o output1 output2 output3 output4