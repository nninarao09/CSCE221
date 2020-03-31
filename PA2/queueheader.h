
#ifndef QUEUEHEADER_H
#define QUEUEHEADER_H
#define MAX_SIZE 100
#include<iostream>
using namespace std;

class queue{
	
	private:
		int array[MAX_SIZE];
		int front;
		int back;
		
	public:
		queue(){
			front = 0;
			back = -1;
		}
		bool isEmpty(){
			if(front>back){
				return true;
			}
			else{
				return false;
			}
		}
		void enqueue(int);
		int dequeue();
		int size();
		void display();
		int top();
		
};


void queue::enqueue(int data){
	array[++back] = data;
}

int queue::dequeue(){
	return array[front++];
}

int queue::size(){
	return back - front + 1;
}

void queue::display(){
	
	for(int i=front; i<=back; i++){
		cout << array[i]<<endl;
	}
}

int queue::top(){

	return array[front];
}

#endif

