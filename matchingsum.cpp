//this program finds a pair from an array such that sum of the elements of the pair is equal to a no say x
//naive O(n*n)

#include<iostream>
#include<limits.h>
using namespace std;
/*naive method
bool isSum(int arr[],int n,int x){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]+arr[j] == x){
				return true;
			}
		}
	}
	return false;
}
*/
//We can do in O(n) time complexity using hash map but we need a priori about the range of nos in the array
bool isSum(int arr[],int n,int x){
	int temp;
	bool binmap[100]={0};//all indices to zero
	for(int i=0;i<n;i++){
		temp=x-arr[i];
		if(temp >=0 && binmap[temp]==1)/*checking if binmap is set*/{
			cout<<"the pair found "<<arr[i]<<" "<<temp<<endl;
			return true;
		}
		binmap[arr[i]]=1;
	}
	return false;
}
	
main(){
	int arr[]={1,2,10,8,6,-9};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=16;
	bool res=isSum(arr,n,x);
	if(res){
		cout<<"there exists pair"<<endl;
	}
	else{
		cout<<"there is no pair"<<endl;
	}
}

