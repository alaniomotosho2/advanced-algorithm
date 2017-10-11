#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
void merge(int,int,int);
void mergesort(int, int);
int a[10] = {7,2,1,10,6,45,5,9,3,8};
int b[10];
int main(){
	cout<<setw(50)<<"Merge Sort\n";
	mergesort(0,9);
	for(int i =0; i < 10; i++){
		cout<<a[i]<<endl;
	}
}

void mergesort(int low,int high){
	int mid;
	if(low < high){
		mid = floor((low+high)/2);
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
}

void merge(int low, int mid, int high){
	int left = low;
	int index = left;
	int rigth = mid+1;
	while( left <= mid && rigth <= high){
		if(a[left] < a[rigth]){
			b[index] = a[left];
			left++;
		}else{
			b[index] = a[rigth];
			rigth++;
		}
		index++;
	}
	if( left <= mid){
		for(int k = left; k <= mid; k++){
			b[index] = a[k];
			index++;
		}
	}
	if(rigth <= high ){
		for(int k = rigth; k <= high; k++){
			b[index] = a[k];
			index++;
		}
	}
	for(int i = low; i <= high; i++)
      a[i] = b[i];
}