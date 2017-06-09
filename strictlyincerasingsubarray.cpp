//this program will find the no of strictly increasing subarrays from a given unsorted subarray
//brute force takes O(n*n*n) and better way takes O(m) where m is the no of subarrays
/*
better way
for(i=0;i<n;i++){
	for(j=i+1;j<n;j++){
		if(arr[j+1] > arr[j]){
			count++;
		}
		else{
			break;
		}
	}
}
*/
//Efficient way is to do in O(n) time by exploiting the fact that a sorted array of len has len*(len-1)/2 subarrays which are strictly increasing

#include<iostream>
using namespace std;
int findcount(int arr[],int n){
//initial values
	int len=1;
	int cnt=0;
	for(int i=0;i<n-1;i++){
		if(arr[i+1] > arr[i]){
			len++;
		}
		else{
			cnt+=(len*(len-1))/2;
			len=1;//important point
		}
	}
	if(len > 1){
		cnt+=(len*(len-1))/2;
	}
	return cnt;
}
	
main(){
	int arr[]={3,-1,0,-10};
	int n=sizeof(arr)/sizeof(arr[0]);
	int len=findcount(arr,n);
	cout<<len<<endl;
}

