#include <fstream>
#include <cctype>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string line, filename, word;
    int pos;

    ifstream in;
    set<string> idents;
    set<string> reserved;
    string reserveArray[]= {"for", "if","else", "fstream", "set","string",
        "include", "main", "using", "namespace","std", "iostream", "string", 
        "ifstream","char","auto","size","open","while","return","int","endl"};
    
    for (int i = 0; i <22; i++){
        reserved.insert(reserved.end(),reserveArray[i]);
	}
	
	set<string> words;
	string wordArray[]= {};

    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
 

    while (in)
    {
        
		getline(in,line);
		

		set<string>::iterator SetIt = reserved.begin();
		for(SetIt = reserved.begin(); SetIt != reserved.end(); ++SetIt){
			
			if(line.find(*SetIt)!=-1){
				word = "";
				for(auto x : line){
					if(x==' '||x==')'||x==':'||x=='#'||x=='<'||x=='>'||x=='('||x==';'||x=='0'||x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7'||x=='8'||x=='9'||x==','){
				
						words.insert(word);
	
						word = "";						
					}
					else{
						word = word + x;
					}
				}
				words.insert(word);
 			}
		}

	
		set<string>::iterator BetIt = words.begin();
		for(BetIt = words.begin(); BetIt != words.end(); ++BetIt){
			string TEST = "\"";
			string Test2 = *BetIt;
			std::size_t found = Test2.find(TEST);
			if (found!=string::npos)
			{
					//cout << "Quotedd Betit " << *BetIt << endl;
				//break;
			}
			else{
				if(reserved.find(Test2) == reserved.end()){
					idents.insert(*BetIt);
				}
				
		
			}
		}
		
		

		
    }
	in.close();
	

    for (auto x:idents)
        cout<<x<<endl;
    return 0;
}
