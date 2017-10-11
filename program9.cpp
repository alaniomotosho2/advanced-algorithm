#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;
void naiveMatch();
void kmp();
int main(){
	cout<<setw(80)<<"String Matching using Naive and Knuth Morris Pratt Approach \n\n ";
	naiveMatch();
	kmp();
}

void naiveMatch(){
	string text;string pattern;
	cout<<setw(60)<<" Naive String Mathcing Method \n";
	cout<<"Enter Text to search ? ";
	cin>>text;
	cout<<"Enter Pattern ? ";
	cin>>pattern;
	int index;
	bool found = false;
	for(int i =0; i < text.length(); i++){
		index = i;
		for(int j =0; j < pattern.length(); j++){
			if( pattern[j] != text[++index]){
				break;
			}
			if(j == pattern.length()-1){
				found = true;
				cout<<"Match Found At Position : "<<(index - pattern.length())+1<<endl;
				//i = index;
			}
		}
	}
	if(found == false){
		cout<<"No Match Found!!!\n";
	}
}


void kmp(){
	cout<<setw(60)<<" Knuth Morris Pratt Mathcing Method \n";
	string text;string pattern;
	cout<<"Enter Text to search ? ";
	cin.ignore();
	getline(cin,text);
	cin.ignore (numeric_limits<streamsize>::max(), '\n'); 
	cout<<"Enter Pattern ? "; 
	cin>>pattern;
	int table[pattern.length()];
	int j =  0;
	int tmp = j;
	for(int i =0; i < pattern.length(); i++){
		if(pattern[i] != pattern[j] && j !=0){

			while( j > 0){
				tmp  = j-1;
				int value = table[tmp];
				if(pattern[value] == pattern[i]){
					table[i] = value+1;
					j = value;
					break;
				}else{
					//tmp = value;
					j = value;
				}
				if(j == 0 && pattern[0] != pattern[i]){
					table[i] =0;
				}
			}
		}

		if(i == j){
			table[i] = 0;continue;
		}
		if(pattern[i]  != pattern[j] && j == 0){
			table[i] = 0;continue;
		}
		if(pattern[i] == pattern[j] && j== 0){
			//j +=1;
			table[i] = ++j;continue;
		}

		if(pattern[i] == pattern[j] && j !=0){
			table[i] = ++j;continue;
		}
	}
	j =0;
	int counter =0;
	while( j < text.length()){
		if(counter == pattern.length()-1){
			cout<<"Match Found at : "<<(j-counter)<<endl;
			j -=1;
			counter = 0;
		}
		if( pattern[counter] == text[j]){
			j +=1;
			counter +=1;continue;
		}
		
		if(pattern[counter] != text[j] && counter > 0){
			counter -=1;
			int val = table[counter];
			counter = val;continue;
		}
		if(pattern[counter] != text[j] && counter == 0){
			j +=1;
			counter =0;
		}
	}


}