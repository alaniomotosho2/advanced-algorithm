#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int rBinarySearch(int [],int,int,int);
int linearSearch(int [],int,int);
int main(){
	cout<<setw(100)<<"Analysis of Recursive Binary Search and Linear Search\n";
	int sta;
	int inputSize;
	int element;
	int ch;
	int v;
	while(true){
		cout<<setw(40)<<"\n1 for Recursive Binary Search\n";
		cout<<setw(40)<<"2 for Linear Search\n";
		cout<<setw(40)<<"3 to exit\n";
		cout<<setw(50)<<"Enter choice ?";
		cin>>ch;
		if(ch == 3)exit(0);
		cout<<setw(100)<<"Enter input size ?";
		cin>>inputSize;
		int array[inputSize];
		for(int i =0; i < inputSize; i++){
			cout<<setw(40)<<"Enter element ? ";
			cin>>element;
			array[i] = element;
		}
		cout<<"done!\n\n";
		cout<<setw(100)<<"Enter element to search Search ?";
		cin>>element;
		switch (ch){
			case 1:
				v = rBinarySearch(array,0,inputSize-1,element);
				if(v < 0){
					cout<<"element not Found return for recursive Binary Search : "<<v;
				}else{
					cout<<"element Found at index : "<<v+1<<"for recursive binary search\n";
				}
				break;

			case 2:
				v = linearSearch(array,element,inputSize);
				if(v < 0){
					cout<<"element not Found return for linear search : "<<v;
				}else{
					cout<<"element Found at index : "<<v+1<<" for linear search\n\n";
				}
				break;
		}
	}
	
}
int rBinarySearch(int array[],int low,int high,int element){
	if(high >= low){
		int mid = (low + high)/2;
		if(array[mid] == element){
			return mid;
		}
		if(element > array[mid]){
			low = mid+1;
			mid = (low + high)/2;
			//rBinarySearch(array,mid+1,high,element);
		}
		if(element < array[mid]){
			high = mid-1;
			mid = (low + high)/2;
			//rBinarySearch(array,low,mid-1,element);
		}
		return rBinarySearch(array,low,high,element);
	}
	return -1;
}
int linearSearch(int array[],int value, int inputSize){
	for(int i=0; i < inputSize; i++){
		if(array[i] == value){
			return i;
		}
	}
	return -1;
}