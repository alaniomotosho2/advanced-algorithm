#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;
//set = {11,13,24,7}
int inf = numeric_limits<int>::max();
int main(){
	cout<<setw(50)<<"Subset Sum Program using Dnamic Programming\n";
	cout<<"Enter number of element to Enter into a set ?";
	int num;cin>>num;
	int set[num];int element;
	for(int i =0; i < num; i++){
		cout<<"Enter element ?";
		cin>>element;
		set[i] = element;
	}
	cout<<" Enter a Number to find its from from the set ? ";
	int sum;
	cin>>sum;
	cout<<setw(50)<<"\nSet : { ";
	for(int i =0; i <num; i++){
		cout<<set[i]<<" , ";
	}
	cout<<" } ";
	cout<<endl;
	cout<<"Positive Number : "<<sum<<endl;
	int tmp[num][num];
	string total = "";
	int t;
	for(int i =0; i < num; i++){
		for(int j =0; j< num; j++){

			if(set[i] == set[j] || set[i] + set[j] > sum){
				tmp[i][j] = inf;
				continue;
			}
			tmp[i][j] = set[i] + set[j];
		}
	}
	cout<<setw(50)<<"The Set that form sum of subset are :\n";
	bool found = false;
	for(int i =0; i < num; i++){
		for(int j =0; j < num; j++){
			if( tmp[i][j] == sum){
				cout<<"{ "<<set[i]<<" , "<<set[j]<<" }\n";
				found = true;
				continue;
			}else if(tmp[i][j] < sum){
				total = "{ "+ to_string(set[i]) + " , "+to_string(set[j])+ " , ";
				for(int k = j; k < num; k++){
					t = tmp[i][j]+ set[k];
					if(t == sum){
						total = total + to_string(set[k])+ " }";
						found = true;
						cout<<total<<endl;
					}
				}
			}
		}
	}
	if(found == false){
		cout<<setw(50)<<" No sum of subset found!\n";
	}
}