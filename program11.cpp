#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;
int inf = numeric_limits<int>::max();
int adjMatric[3][3] = {
	{0,4,11},
	{6,0,2},
	{3,inf,0}
};
int main(){
	cout<<setw(70)<<"All Pair Shortest Path using Flyod Algorithms (Dynamic Programming)\n";
	cout<<"\n Algorithm : A(k)(i,j) = min{A(k-1)(i,k)+A(k-1)(k,j),c(i,j)}\n";
	cout<<"Infinity is taken from c++ limits Library : "<<inf<<endl;
	int k =-1;
	cout<<endl;
	cout<<setw(30)<<"A(0)\n";
	for(int i =0; i < 3; i++){
		for(int j =0; j <3; j++){
			cout<<setw(20)<<adjMatric[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n";
	for(int a =0; a <3;a++){
		k +=1;
		cout<<setw(30)<<"A("<<a+1<<")\n";
		for(int i =0; i < 3; i++){
			for(int j =0; j <3; j++){
				adjMatric[i][j] = min(adjMatric[i][k]+adjMatric[k][j],adjMatric[i][j]);
				cout<<setw(20)<<adjMatric[i][j]<<"  ";
			}
			cout<<endl;
		}
		cout<<endl;

	}
}