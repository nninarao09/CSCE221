#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;

int insertLinear(int x, vector<int> & linear);
int insertQuad(int x, vector<int> & quad);
int insertDuble(int x, int dubHash, vector<int> & duble);

int main()
{
  int linCollides=0;
  int quadCollides= 0;
  int dubCollides = 0;
  int quadInc;
  int tableSize;
  bool fail = false;
  int x, count=0;
  int doubleHash;

  srand(time(NULL));
  cout<<"enter the size of the table ";
  cin>>tableSize;
  vector<int> linear(tableSize,-1);//initalize each table to -1 for empty
  vector<int> quad(tableSize,-1);  //initalize each table to -1 for empty
  vector<int> duble(tableSize,-1);  //initalize each table to -1 for empty
  do{
   doubleHash = rand()%tableSize;
  }while (doubleHash < tableSize/10 && doubleHash%tableSize==0);

  while(count < tableSize && !fail)
  {
    x= rand()%tableSize;// value to insert
	
	quadInc=insertQuad(x,quad);
	if (quadInc < 0)
		fail = true; 
	else
	{
	 quadCollides += quadInc;
	 linCollides+=insertLinear(x,linear);
	 //dubCollides+=insertDuble(x,doubleHash, duble);
	 dubCollides+=insertDuble(x,rand()%tableSize, duble);
	}
	count++;
  }
  cout<<"Num linear collides "<<linCollides<<endl;
  /*
  for(int i=0; i<linear.size(); ++i){
	  cout << linear[i] << " ";
  }
  cout << endl;
  
  */
  cout<<"Num quadratic collides "<<quadCollides<<endl;
  /*
  for(int i=0; i<quad.size(); ++i){
	  cout << quad[i] << " ";
  }
  cout << endl;
  */
  cout<<"Num double hash collides "<<dubCollides<<endl;
  /*
  for(int i=0; i<duble.size(); ++i){
	  cout << duble[i] << " ";
  }
  cout << endl; 
  */
  return 0;
}

int insertLinear(int x, vector<int> & linear)
{
	
	int key = x%linear.size();
	int collide = 0;
	if(linear[key] == -1){
		linear[key] = x;	
	}
	else{
		for(int i=key; i<linear.size(); ++i){
			if(linear[i] == -1){
				linear[i] = x;
				return collide;

			
			}
			else{
				collide++;
			}
		}	
		for(int i=0; i<key; ++i){
			if(linear[i] == -1){
				linear[i] = x;
				return collide;
			}
			else{
				collide++;
			}
		}

		
		
	}
	return collide;

}

int insertQuad(int x, vector<int> & quad)
{
	int key = x%quad.size();
	int collide = 0;
	int i = 1;
	
	if(quad[key] == -1){
		quad[key] = x;	
		return collide; 
	}
	else{
		for(int i=1; i<quad.size(); ++i){
			key = (x+i*i)%quad.size();
			if(quad[key]== -1){
				quad[key]=x;
				return collide;
			}
			else{
				collide++;
			}
		}	

		
	}
	return collide;
	


}

int insertDuble(int x, int dubHash, vector<int> & duble)
{
	
	
	int key = x%duble.size();
	int collide = 0;
	
	if(duble[key] == -1){
		duble[key] = x;	
		return collide; 
	}
	else{
		for(int i=1; i<duble.size(); ++i){
			key = (x+dubHash*i)%duble.size();
			
			if(duble[key]== -1){
				duble[key]=x;
				return collide;
			}
			else{

				collide++;
			}
		}	

		
	}
	return collide;
	
}