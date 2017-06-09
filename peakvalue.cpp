//this program returns one of the peak values in an array
//a peak value is that the element should not be less than its neighbours
//for the first and last element we compare only the right and left neighbour respectively
//brute force is O(n) time complexity
//we go for binary search strategy whose time complexity is O(log n)
//ascending order input has the last value as peak always
//descending order input has the first value as peak always
#include<iostream>
using namespace std;
int findpeak(int arr[],int low, int high,int n){
	if(high >= low){
		int mid=(high+low)/2;
		if(mid==0){
			if(arr[mid] >= arr[mid+1]){
				return (arr[mid]);
			}	
		}
		else if(mid == n-1){
			if(arr[mid] >= arr[mid-1]){
				return (arr[mid]);
			}
		}
		else if(mid >0){
			if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1]){
				return (arr[mid]);
			}
			else if(arr[mid] < arr[mid-1]){//mid value is less than its left neighbour
				return (findpeak(arr,0,mid-1,n)); //left half
			}
			else if(arr[mid] < arr[mid+1]){//mid value is less than its right neighbour
				return (findpeak(arr,mid+1,high,n)); //right half
			}
		}
	}
	else{
		return -1;
	}
}
			
main(){
	int arr[]={10,40,29,34,67,9};
	int n=sizeof(arr)/sizeof(arr[0]);
	int peak= findpeak(arr,0,n-1,n);
	cout<<peak<<endl;
}
	
