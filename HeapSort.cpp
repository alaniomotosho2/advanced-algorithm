#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
void heapSort(int [],int);
void buildHeap(int [],int);
void adjust(int [],int);
int size;
int main(){
	int choice;
	int element;
	while(true){
		cout<<" 1  for heap sort\n2 to exit \nEnter choice ?";
		cin>>choice;
		if(choice == 2)exit(0);
		cout<<"Enter Array Size ?";
		cin>>size;
		int array[size];
		for(int i =1; i < size+1; i++){
			cout<<" Enter element ?";
			cin>>element;
			array[i] = element;
		}
		switch (choice){
			case 1:
				buildHeap(array,size);
				heapSort(array,size);
				break;
			case 2:
				break;
		}
	}
}
void buildHeap(int array[],int size){
	int temp;
	for(int i =size; i >1; i--){
		if(array[i] > array[1]){
			temp = array[i];
			array[i] = array[1];
			array[1] = temp;
			adjust(array,size);
		}
	}
	for(int  i =1; i <= size; i++){
		cout<<array[i]<<endl;
	}
}

void adjust(int array[],int size){
	int l = floor((size)/2);
	int temp;
	while(l > 0){
		int a = l*2;
		int b = a+1;
		int chs;
		if( a > size  && b > size) break;
		if( b > size){
			chs = a;
		}else{
			if( array[a] > array[b])chs = a;
			if(array[b] >= array[a])chs = b;
		}

		if( array[chs] > array[l]){
			temp = array[l];
			array[l] = array[chs];
			array[chs] = temp;
		}
		l -=1;
	}
} 

void heapSort(int array[],int size){
	cout<<setw(20)<<"sorted Array \n";
	int result[size];
	int s = size;
	int s3 = size;
	int ss = size;
	for(int i =1; i < s+1; i++){
		//cout<<array[1]<<endl;
		result[s3] = array[1];
		s3 -=1;
		array[1] = array[size];
		//ss -=1;
		size -=1;
		adjust(array,size);

	}
	for(int i =1; i < s+1; i++){
		cout<<result[i]<<endl;
	}
}