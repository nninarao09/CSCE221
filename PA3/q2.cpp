#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string line, filename;
    map <string,int> coronamap;

    ifstream in;
    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    getline(in,line);

    string partOf;
	
	int max = 0;
	string maxcountry;
	
	
    while (in){
		
		string country; int cases;
		in>>country>>cases;
		if(cases>max){
			max = cases;
			maxcountry = country;
		}
    }
	in.close();
    
	cout << "Most confirmed cases are in " << maxcountry << endl;
   

    return 0;
}
