//this program will return the fixed point in an array ie. the index of an element is equal to the value of the element eg. arr[4]=4
//simple brute force takes O(n)
//the input is sorted andso we can go for binary search with complexity O(log n)

#include<iostream>
using namespace std;
int binarysearch(int arr[],int low, int high){
	if(high >= low){
		int mid=(high+low)/2;
		if(arr[mid]==mid){
			return mid;
		}
		else if(mid > arr[mid]){
			return (binarysearch(arr,mid+1,high)); //right half
		}
		else{
			return (binarysearch(arr,0,mid-1)); //left half
		}
	}
	else{
		return -1;
	}
}
main(){
	int arr[]={-10,-6,0,8,10,27};
	int n=sizeof(arr)/sizeof(arr[0]);
	int fixed=binarysearch(arr,0,n-1);
	cout<<fixed<<endl;
}
