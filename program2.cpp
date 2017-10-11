#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int SIZE = 10;
int a[] = {4,1,790,2,7,88,9,66,5,10};
int low = 0;int high = 9;
int partition(int,int);
void quicksort(int,int);
void changePos(int , int);
int main()
{
	cout<<setw(50)<<"Quicksort Algorithms\n";
	quicksort(0,9);
	for(int i =0; i < 10; i++){
		cout<<a[i]<<endl;
	}
	//pri();
}

void quicksort(int low,int high){
	if(low < high){
		int pivot = partition(low,high);
	    //cout<<pivot<<endl;
	    quicksort(low,pivot-1);
	    quicksort(pivot+1,high);
	}
}


int partition(int low,int high){
	int pivot = a[low];
	int i = low+1;
	int j = high;

	while( true){
		while( i <= j && a[i] <=  pivot){
			i++;
		}
		while(j >= i && a[j] >= pivot){
			j--;
		}
		if (j < i){
			break;
		}else{
			changePos(i,j);
		}
	}
	int temp = a[low];
	a[low] = a[j];
	a[j] = temp;
	return j;
}

void changePos(int i , int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}