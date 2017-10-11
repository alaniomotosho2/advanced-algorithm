#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <experimental/random>
using namespace std;
int main(){
	//i seed it to generate psudo random number
	//srand(time(NULL));
	cout<<setw(70)<<"Monte Carlos Randomized Algorithm to Test for primality \n\n";
	cout<<"Monte Carlos Algorithms is an Efficient Algorithms with impressive\n";
	cout<<"time complexity BUT being a Randomized Algorithms it does not usually \n";
	cout<<"Return a ccorrect answer unlike Las Vegas Algorithms as it will be shown now\n";
	cout<<"The Reason Being That it Randomly select a number to work with....\n\n";
	cout<<"Enter any Number to Test its Primality using Randomized Algorithms ?";
	//a^n-1 mod n if it is 1 then its is prime else not prime
	int number;
	cin>>number;
	//cout<<pow(2,4);
	//long  randNumber = rand() % number;
	long randNumber = std::experimental::randint(1, number);
	cout<<"Number "<<randNumber<<endl;
	int n = number-1;
	//int result = (randNumber **(number-1)) % number;
	long result = pow(randNumber,n);
	result = (result % number);
	if(result == 1){
		cout<<setw(50)<<"The Number you Enter is A Prime Number\n";
	}else{
		cout<<setw(50)<<"The Number you Enter is NOT a Prime Number\n";
	}
}