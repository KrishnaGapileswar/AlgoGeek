//this program finds the missing nos in the range from 0 to 99 and we ignore nos outside the range [0,99]
//key idea is to use a boolean array of size 100 

#include<iostream>
using namespace std;
void findmiss(int arr[],int n){
	bool miss[100];
	int i;
	for(i=0;i<100;i++){
		miss[i]=false;
	}
	for(i=0;i<n;i++){
		if(arr[i] >= 0 && arr[i] <=99){
			miss[arr[i]]=true;
		}
	}
	for(i=0;i<100;i++){
		if(miss[i] == false){
			cout<<i<<",";
		}
	}
	cout<<endl;
}
main(){
	int arr[]={-10,4,10,100,234};
	int n=sizeof(arr)/sizeof(arr[0]);
	findmiss(arr,n);
}
