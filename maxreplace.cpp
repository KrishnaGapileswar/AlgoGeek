//this program replaces every element with its next greatest element andso the last element that no values to its right is made -1
//brute force takes O(n*n)
//trick that traversing the array from right takes O(n)

#include<iostream>
using namespace std;
void replace(int arr[],int n){
	int max_from_right=arr[n-1];
	arr[n-1]=-1;//corner case
	for(int i=n-2;i>=0;i--){
		int temp=arr[i];
		arr[i]=max_from_right;
		if(temp > max_from_right){
			max_from_right=temp;
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
main(){
	int arr[]={16,17,4,3,5,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	replace(arr,n);
}
