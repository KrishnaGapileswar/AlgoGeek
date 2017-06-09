//this program finds the missing no in an array where array has numbers from 1 to n of length n-1
//two ways of O(n) but XOR method avoids the trap of integer overflow
/*

int getMissingno(int arr[],int n){
	int sum=(n+1)*(n+2)/2;
	for(i=0;i<n;i++){
		sum-=arr[i];
	}
	return sum;
}
but this method may lead to integer overflow
}
*/
int getMissingno(int arr[],int n){
	int x1=arr[0];
	int x2=1;
	for(int i=0;i<n;i++){
		x1=x1^arr[i];
	}
	for(int i=1;i<=n+1;i++){
		x2=x2^i;
	}
	return(x1^x2);
}


#include<iostream>
using namespace std;
main(){
	int arr[]={1,2,3,4,5,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<n<<endl;
	int miss=getMissingno(arr,n);
	cout<<"\nThe missing no is "<<miss<<endl;
}
