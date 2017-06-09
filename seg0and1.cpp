//this program segregates the 0s and 1s in an array
//method 1: count no of zeros and 1s and print zeros to left of the array and 1s to the right. But this method traverses the array twice
//method 2: does the job in one traversal

#include<iostream>
using namespace std;
void seg0and1(int arr[],int n){
	//we have two indices for zero and one. if they are out of order we swap them
	int left=0;
	int right=n-1;
	while(left < right){
		while(arr[left]==0 && left < right){
			left++;
		}
		while(arr[right]==1 && left < right){
			right--;
		}
		if(left < right){
			int temp=arr[left];
			arr[left]=arr[right];
			arr[right]=temp;
			left++;
			right--;
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
main(){
	int arr[]={0,1,1,0,1,0,1,1,0,0};
	int n=sizeof(arr)/sizeof(arr[0]);
	seg0and1(arr,n);
}
