#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int main(){
	cout<<setw(60)<<"0/1 Knapsack Problem using Dynamic Programming\n\n";
	cout<<setw(60)<<"n = 3 (w1,w2,w3) = (2,3,4) (p1,p2,p3) = (1,2,5) M = 6 \n";
	cout<<setw(60)<<"n = Number of the Item\n";
	cout<<setw(60)<<"w = weigth of each Item\n";
	cout<<setw(60)<<"P = Profit of the Item\n";
	cout<<setw(60)<<"M = Total Capacity or wigth of the Knapsack\n";
	cout<<endl;
	cout<<setw(80)<<"Formular : Fn(m) = max{ fn-1(m),fn-1(m-wn)+ pn} => wn is the weigth and pn is the profit\n";
	int wt[3] = {2,3,4};
	int prt[3] = {1,2,5};
	int fneg = -77777;
	int f0_1 =0;int f0_2 =0;int f0_3 =0;int f0_4 =0;int f0_5 =0;int f0_6 = 0;
	int f0_0 =0;
	int f1_6 = max(f0_6,(f0_4+1));
	int f1_3 = max(f0_3,(f0_1+1));
	int f2_6 = max(f1_6,(f1_3+prt[1]));//zero based
	int f1_2 = max(f0_2,(f0_0+prt[0]));
	int f2_2 = max(f1_2,(fneg+prt[1]));
	//int f2_6 = max(f1_6,(f1_3+prt[1]));
	int f3_6 = max(f2_6,(f2_2+prt[2]));
	cout<<setw(70)<<"The maximization Problem for the 0/1 knapscak Problem is : "<<f3_6<<endl;
}