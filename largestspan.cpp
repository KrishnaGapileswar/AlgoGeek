//the program is to find the length of largest subarray such that the sum of elements in two given binary arrays with the found subarray length must be maximum


#include<iostream>
#include<string.h>
using namespace std;
#define n 10
main()
{



	int arr1[n];
	int arr2[n];
	cout<<"\nEnter arr 1 entries\n";
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	cout<<"\nEnter arr 2 entries\n";
        for(int i=0;i<n;i++){
                cin>>arr2[i];
        }
	//Since we deal with bool arrays the max sum for an array will be n and their differences will be from -n to +n ie.2n+1 values
	int diff[2*n+1];
	memset(diff,-1,sizeof(diff));
	
	//Making use of the fact that if the prefix sum is equal ie. if the difference is zero length of subarray is i+1
	
	int pre1=0,pre2=0,maxlen=0;
	for(int i=0;i<n;i++){
		pre1+=arr1[i];
		pre2+=arr2[i];
		
		int curr_diff=pre1-pre2;

		//here we add n to the curr_diff because the index of an array cannot be negative and if diff is -n the -n+n leads to 0
		int diff_index=n+curr_diff;
		
		if(curr_diff == 0){
			maxlen=i+1;
		}
		//Checking whether we visit the position for the first time
		else if(diff[diff_index] == -1){
			diff[diff_index]=i;
		}
		else/*Calculate length */{
			int len= i-diff[diff_index];
			if(len > maxlen){
				maxlen=len;
			}
		}
	}
	cout<<maxlen<<endl;
}
			
//The complexity is O(n)
	
	

