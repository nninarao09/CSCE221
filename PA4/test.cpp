#include<iostream>
#include<cmath>
#include<chrono>
#include<vector>
#include"Sort.h"

using namespace std;

bool isSorted( vector<int> & a )
{
    for(int i=1; i<a.size(); ++i){	
		if(a[i-1] > a[i]){
			return false;
		}
		
	}
    return true;
}

void selectionSort( vector<int> &a )
{
	
	int min=1000000;
	int index=0;
	int x=0;
	int y=0;
	
    for(int i=0; i<a.size(); ++i){
		for(int j=i; j<a.size(); ++j){
			if(a[j]<min){
				min = a[j];
				index = j;
				
			}
			//locout << min << endl;
		}
		min = 1000000;
		x = a[i];
		y = a[index];
		a[i] = y;
		a[index] = x;
		//cout << "a[i] " << a[i] << " and " << a[index] << endl;
	}
	
}

void bubbleSort( vector<int> &a )
{
	int x=0;
	int y=0;
	
	for(int j=0; j<a.size(); ++j){
		for(int i=1; i<a.size(); ++i){
		
			if(a[i-1] > a[i]){
				x = a[i-1];
				y = a[i];
				//cout << "x " << x << " and y " << y << endl;

				a[i] = x;
				a[i-1] = y;
				//cout << "a[i-1] " << a[i-1] << " and a[i] " << a[i] << endl;

			}
			
		}
	}
}

void hybridSort( vector<int> & a )
{
	vector<int> temp(10e11);
	

	if(a.size()<16){
		bubbleSort(a);
	}
	else{
		
		quicksort(a, 0, (a.size( )/4)-1);
		quicksort(a, (a.size( )/4), (a.size( )/2)-1);
		quicksort(a, (a.size( )/2), (3*a.size( )/4)-1);
		quicksort(a, (3*a.size( )/4), (a.size( )-1));
		
		merge(a, temp, 0, a.size()/4, (a.size()/2)-1);
		merge(a, temp, a.size()/2, (3*a.size())/4, (a.size()-1));
		merge(a, temp, 0, a.size()/2, (a.size()-1));
	
	}
	

}

int main() 
{ 
    vector<int> g1; 
	g1.push_back(10); 
	g1.push_back(5); 
	g1.push_back(8); 
	g1.push_back(12); 
	g1.push_back(15); 
	g1.push_back(6); 
	g1.push_back(3); 
	g1.push_back(9); 
	g1.push_back(16); 
	g1.push_back(11); 
	g1.push_back(7); 
	g1.push_back(17); 
	g1.push_back(22); 
	g1.push_back(0); 
	g1.push_back(2); 
	g1.push_back(4); 
	g1.push_back(19); 
	g1.push_back(21); 
	g1.push_back(1); 
	g1.push_back(26);

	
	
	for(int i=0; i<g1.size(); ++i){
		cout << g1[i] << " ";
	}
	cout << endl << endl;

	
	//bubbleSort(g1);
	//selectionSort(g1);
	hybridSort(g1);
	
	/*
	for(int i=0; i<g1.size(); ++i){
		cout << g1[i] << " ";
	}
	cout << endl;
*/
    return 0; 
} 