//this program finds the leader elements ( >1) in the given unsorted array ie. in an descending array all the elements are leaders
//an element is termed leader if all the elements to its right are lesser than the element chosen andso the last element will always be a leader. Bruteforce takes O(n*n) and the trick of scanning the array from right to left takes O(n)

#include<iostream>
using namespace std;
void displeader(int a[],int n){
	int max_from_right=a[n-1];
	cout<<max_from_right<<" ";
	for(int i=n-2;i>=0;i--){
		if(a[i] > max_from_right){
			max_from_right=a[i];
			cout<<max_from_right<<" ";
		}
	}
	cout<<endl;
}
main(){
	int arr[]={5,10,11,22,100};
	int n=sizeof(arr)/sizeof(arr[0]);
	displeader(arr,n);
}
