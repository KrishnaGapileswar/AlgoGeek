//this program implements quick sort
//time complexity is O(n*n) in worst case because the pivot need not to be the median always 
//by default we choose the first element as pivot
//a divide and conquer strategy without merging
#include<iostream>
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void quicksort(int arr[],int l,int r){
	if(l < r){
	int yellow=l+1,green;
	for(green=l+1;green<r;green++)/*implicit increment of green pointer*/{
		if(arr[green] <= arr[l]){
			swap(arr[green],arr[yellow]);
			yellow++;
		}
	}
	//swapping pivot and yellow pointer
	swap(arr[yellow-1],arr[l]);
	quicksort(arr,l,yellow-1);
	quicksort(arr,yellow,r);
	}
}
main(){
	int arr[]={10,1,78,-19,0};
	int n=sizeof(arr)/sizeof(arr[0]);
	quicksort(arr,0,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
