//this program finds the array element that has occured odd no of times. the input is ensured with only one value with odd repetition
//brute force takes O(n*n)
//hashing takes O(n) but with extra space ie. we have keep track the count of the variables with entries as keys and their count as values
//XORing provides the result in O(n) and requires no extra space
//hint A^A=0 and A^0=A

int getOddoccurance(int arr[],int n){
	int result=0;//since a^0=a
	for(int i=0;i<n;i++){
		result^=arr[i];
	}
	return (result);
}

#include<iostream>
using namespace std;
main(){
	int arr[]={2,1,2,3,3,2,2,3,3,4,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	int res=getOddoccurance(arr,n);
	cout<<res<<endl;
}
