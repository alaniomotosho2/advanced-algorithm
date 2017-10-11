#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;
int infinity = numeric_limits<int>::max();
int adjMatrix[7][7] = {
						{0,3,6,infinity,infinity,infinity,infinity},
						{3,0,2,4,infinity,infinity,infinity},
						{6,2,0,1,4,2,infinity},
						{infinity,4,1,0,2,infinity,4},
						{infinity,infinity,4,2,0,2,1},
						{infinity,infinity,2,infinity,2,0,1},
						{infinity,infinity,infinity,4,1,1,0}
};

char edge[] = {'A','B','C','D','E','F','G'};
//bool visited[7] = {false,false,false,false,false,false,false};
int shtPath[7];
int main(){
	cout<<setw(40)<<"Dijkstra Shortest Path\n";
	int mn = infinity;
	bool setBegin = true;
	int visited = 0;
	int total = 0;
	for(int i =0; i < 7; i++){
		for(int j =0; j < 7; j++){
			cout<<setw(8)<<""<<adjMatrix[i][j]<<setw(10);
		}
		cout<<endl;
	}
	shtPath[0] = 0;
	for(int i =0; i < 7; i++){
		visited++;
		//cout<<visited<<endl;
		for(int j =visited; j < 7; j++){
			if(adjMatrix[i][j] < mn && adjMatrix[i][j] !=0){
				mn = adjMatrix[i][j];
			}
		}
		shtPath[i+1] = mn;
		mn = infinity;
		cout<<endl;
	}
	for(int i =0; i < 7; i++){
		cout<<shtPath[i]<<" ";
	}
	for(int i =0; i < 7; i++){
		total+=shtPath[i];
	}
	cout<<endl;
	cout<<"Total Cost as shortest Path : "<<total<<endl;

}