#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;
int adjMatrix[4][4] = {{0,1,0,0},{0,0,0,1},{0,0,0,0},{1,0,1,0}};
int inf = numeric_limits<int>::max();
int main(){
	cout<<setw(70)<<"Topological Ordering and Transistive closure of Directed Graph using Wrashall Algorithm\n";
	cout<<setw(40)<<"Toplooogical Ordering (Dynamic Programming): \n";
	cout<<setw(40)<<"Algorithms : R(k)(i,j) = R(k-1)(i,j) OR R(k-1)(i,k) && R(k-1)(k,j): \n";
	for(int k =-1; k<4; k++){
		cout<<setw(10)<<"R("<<k+1<<")\n";
		cout<<setw(20)<<"------------------------------------\n";
		for(int i =0; i < 4; i++){
		for(int j =0; j <4; j++){
			if(k == -1){
				cout<<setw(5)<<adjMatrix[i][j]<<"\t";
				continue;
			}
			if(adjMatrix[i][j] == 1){
				cout<<setw(5)<<adjMatrix[i][j]<<"\t";
				continue;
			}
			if(adjMatrix[i][j] == 0){
				if(adjMatrix[i][k] == 1 && adjMatrix[k][j] == 1){
					adjMatrix[i][j] = 1;
					cout<<setw(5)<<adjMatrix[i][j]<<"\t";
				}else{
					cout<<setw(5)<<adjMatrix[i][j]<<"\t";
				}
			}
		}
		cout<<endl;
	}
	cout<<"\n\n";
	}
}
