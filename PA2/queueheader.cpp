
#ifndef QUEUEHEADER_H
#define QUEUEHEADER_H

#define MAX_SIZE 100
#include<iostream>
using namespace std;


struct BinaryNode(){
	int data;
	Node* left;
	Node* right;
};

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
		void enqueue(BinaryNode);
		int dequeue();
		int size();
		void display();
		int top();
		
};


void queue::enqueue(BinaryNode* node){
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


int main(){
	
	queue myq;
	int data;
	
	myq.enqueue(10);
	myq.enqueue(20);
	myq.enqueue(30);
	myq.enqueue(40);
	myq.enqueue(50);
	cout << endl;
	cout << myq.top()<<endl;
	cout << endl;
	myq.dequeue();
	myq.display();
	
	cout << endl;
	cout << myq.top()<<endl;


	return 0;
}

