//this program finds the pythogorean triplet in an array if it exists
//brute force takes O(n*n*n) complexity
/*
for(i=0;i<n;i++){
	for(j=i+1;j<n;j++){
		for(k=j+1;k<n;k++){
			a=arr[i]*arr[i];
			b=arr[j]*arr[j];
			c=arr[k]*arr[k];
			if(a==b+c || b==a+c || c==a+b){
				return true;
			}
		}
	}
}
return false;
}
*/

//method 2 takes time O(n*n). First we square the entries in the array and then we sort it.
//We fix the last element as (arr[n-1]=) a and we find a pair (b,c) such that b+c=a from the subarray 0 to arr[n-2]. If not found we make necessary altertions

#include<iostream>
using namespace std;
void sort(int arr[],int n){
//insertion sort O(n*n)
	for(int i=0;i<n;i++){
		int pos=i;
		while(pos >0 && arr[pos] < arr[pos-1]){
			int temp=arr[pos];
			arr[pos]=arr[pos-1];
			arr[pos-1]=temp;
			pos--;
		}
	}
}
bool findTriplet(int arr[],int n){
	//we fix arr[n-1] as a
	for(int i=n-2;i>=2;i--){
		int left=0;
		int right=i-1;
		while(left < right){
			if(arr[left]+arr[right] == arr[i]){
				return true;
			}
			(arr[left]+arr[right] < arr[i])?left++:right--;
		}
	}
	return false;
}
main(){
	int arr[]={5,20,4,3,1,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	//Squaring the array
	for(int i=0;i<n;i++){
		arr[i]=arr[i]*arr[i];
	}
	sort(arr,n);
	cout<<endl;
	bool res=findTriplet(arr,n);
	if(res){
		cout<<"there exists a triplet"<<endl;
	}
	else{
		cout<<"there exists not a triplet"<<endl;
	}
}

