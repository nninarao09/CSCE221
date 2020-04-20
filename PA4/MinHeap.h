#ifndef MIN_HEAP_H
#define MIN_HEAP_H

using namespace std;       

class MinHeap
{
  private:

    int *arr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap
	

  public:

    // Constructor for the MinHeap
    MinHeap(int cap) {
        heap_size = 0; 
        capacity = cap; 
        arr = new int[cap]; 
    }
	
	MinHeap(int *new_arr, int size) {
        heap_size = size; 
        capacity = size; 
        arr = new int[size];
		for(int i=0; i<size; ++i){
			arr[i] = new_arr[i];
		}
		BuildHeap();
    }

    // to ge the index of parent of node at index i
    inline int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    inline int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    inline int right(int i) { return (2*i + 2); } 

    // Returns the minimum key (key at root) from min heap 
    inline int getMin() {  return arr[0]; } 

    // Inserts a new key 'k' 
    void insertKey(int k) {
	    heap_size++; 
		int i = heap_size - 1; 
		arr[i] = k; 
		int x;
		int y;
	
		
		while (arr[parent(i)] > arr[i] && i!=0) 
		{ 
			int x = arr[i];
			int y = arr[parent(i)];
			arr[i] = y;
			arr[parent(i)] = x;
		   
		    i = parent(i); 
		} 
		
    }

    // Extract the root which is the minimum element 
    int extractMin() {
		
		int x,y;
		int root = arr[0];
		arr[0] = arr[heap_size-1];
		heap_size--;
		
		for(int i=0; i<heap_size; ++i){
			
			if(arr[parent(i)] > arr[i]){
				int x = arr[i];
				int y = arr[parent(i)];
				arr[i] = y;
				arr[parent(i)] = x;
			
			}
			
		}
		
		return root;
    }
  
    // Decreases key value of key at index i to newVal 
    void decreaseKey(int i, int newVal) {
        int x,y;
		
		int remove = arr[i];
		arr[i] = newVal;
		
		for(int i=0; i<heap_size; ++i){
			
			if(arr[parent(i)] > arr[i]){
				int x = arr[i];
				int y = arr[parent(i)];
				arr[i] = y;
				arr[parent(i)] = x;
			
			}
			
		}
    }
  
    // Deletes a key stored at index i 
    void deleteKey(int i) {
        int x,y;
		
		int deleted = arr[i];
		arr[i] = arr[heap_size-1];
		heap_size--;
		
		for(int i=0; i<heap_size; ++i){
			
			if(arr[parent(i)] > arr[i]){
				int x = arr[i];
				int y = arr[parent(i)];
				arr[i] = y;
				arr[parent(i)] = x;
			
			}
			
		}

    }
	 
	void percDown(int i){


		int child;
		int tmp = arr[i];
		
		
		for( tmp = move( arr[i] ); left(i) < heap_size; i = child )
		{
			child = left( i );
			if( child != heap_size - 1 && arr[ child ] > arr[ child + 1 ] )
				++child;

			if( tmp > arr[child])
				arr[ i ] = move(arr[ child ]);
			else
				break;
		}
		arr[i] = move(tmp);
		
	}
	
	void BuildHeap(){
		for(int i = heap_size/2; i>=0; --i){
			percDown(i);
		}
	}

	
	
	//I made this to test my code
	void printHeap(){
		for(int i =0; i<heap_size; ++i){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

#endif
