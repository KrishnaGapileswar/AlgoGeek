//this program finds the minimum distance between two given elements. 


#include<iostream>
using namespace std;
#include<limits.h>
int getMindist(int arr[],int n, int x,int y){
	int i=0;
	int prev;
	int mindist=INT_MAX;
	for(;i<n;i++){
		if(arr[i]==x || arr[i]==y){
			prev=i;
			break;
		}
	}
	for(;i<n;i++){
		if(arr[i]==x || arr[i]==y){
			if((arr[i] != arr[prev]) && (i-prev) < mindist){
				mindist=i-prev;
				prev=i;
			}
			else{
				prev=i;
			}
		}
	}
	return mindist;
}
main(){
	int arr[]={3,5,4,2,6,3,0,0,5,4,8,3};
	int x=3,y=6;
	int n=sizeof(arr)/sizeof(arr[0]);
	int dist=getMindist(arr,n,x,y);
	cout<<"\nthe minimum distance is "<<dist<<endl;
}
