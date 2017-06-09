//this program finds the majority element in an array ie. the element should have occured more than n/2 times andso there can be atmost one majority element
//here we exploit Moore's voting algorithm to find the candidate element and we check this candidate is the majority 
//time complexity is O(n)

#include<iostream>
using namespace std;

int getCandidate(int arr[],int n){
	int count=1;
	int maj_index=0;
	//since assuming the first element to be the candidate and it will have occured atleast once
	for(int i=1;i<n;i++){
		if(arr[i] == arr[maj_index]){
			count++;
		}
		else{
			count--;
		}
		//important point to be noted
		if(count==0){
			maj_index=i;
			count=1;
		}
	}
	return (arr[maj_index]);
}

bool checkMajority(int arr[],int n,int m){
	int count=0;
	for(int i=0;i<n;i++){
		if(arr[i]==m){
			count++;
		}
	}
	cout<<"count:"<<count<<endl;
	if(count > (n/2)){
		return 1;
	}
	else{
		return 0;
	}
}

main(){
	int arr[]={1,3,1,1,1,4,1,3,3,};
	int n=sizeof(arr)/sizeof(arr[0]);
	int majority=getCandidate(arr,n);
	bool test=checkMajority(arr,n,majority);
	if(test){
		cout<<majority<<endl;
	}
	else{
		cout<<"No majority element\n";
	}
}
