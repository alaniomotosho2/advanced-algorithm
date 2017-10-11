#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;
void boyerAlgo();
int check(string ,string ,int, int[]);
int main(){
	cout<<setw(60)<<"String Mathcing Using Boyer Moore Algorithms\n";
	boyerAlgo();
}
void boyerAlgo(){
	string text;string pattern;
	cout<<setw(30)<<"Enter Text ?";
	//cin>>text;
	getline(cin,text);
	cin.ignore (numeric_limits<streamsize>::max(), '\n');
	cout<<setw(30)<<"Enter Pattern ?";
	cin>>pattern;
	int l = 0;
	int table[pattern.length()-1];
	int j =0;
	int tmp;
	while(j < pattern.length()-1){
		table[j] = pattern.length() - j-1;
		if(j > 0){
			for(int k=0; k < j;k++){
				if(pattern[j] == pattern[k]){
					table[k] = table[j];
				}
			}
		}
		j++;
	}

	int left =0;
    int rigth = left + pattern.length()-1;
	bool found = false;
	int tmpp = rigth;
	while(rigth < text.length() ){
		for(int i = pattern.length()-1; i >=0;i--){

			if(pattern[pattern.length()-1] != text[text.length()-1] && tmpp >= text.length()-1 ){
				rigth = text.length();
				break;
			}

			if(pattern[i] != text[rigth]){
				int skipBy = check(pattern,text,rigth,table);
				left = left + skipBy;
				rigth = left + pattern.length()-1;
				tmpp = rigth;
				break;
			}
			if(pattern[i] == text[rigth]){
				rigth -=1;
			}
			if(i == 0){
				found = true;
					cout<<"Match Found at : "<<left<<endl;
					left++;
					rigth = left + pattern.length()-1;
					break;
			}

			}
		}
}

int check(string pattern,string text,int rigth, int table[]){
	for(int i =0; i < pattern.length()-1;i++){
		if(text[rigth] == pattern[i]){
			return table[i];
		}
	}
	return pattern.length();
}



