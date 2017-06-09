//this program finds the ceiling and floor of an element from the given sorted array
/* note that 
ceiling of x is the smallest element that is greater than or equal to x
floor of x is the greatest element that  is smaller than or equal to x
*/
//linear search takes O(n). Binary search takes O(logn) complexity

#include<iostream>
using namespace std;
int ceilSearch(int arr[],int low,int high,int x){
	if(arr[low] >= x){
		return low;
	}
	if(x > arr[high]){
		//it is not in the array's range
		return -1;
	}
	int mid=(low+high)/2;
	if(arr[mid] == x){
		return mid;
	}
	else if(arr[mid] > x){
		if(arr[mid-1] == x && mid-1 >=low){
			return (mid-1);
		}
		else{
			return (ceilSearch(arr,0,mid-1,x));
		}
	}
	else{
		if(arr[mid+1]==x && mid+1 <=high){
			return (mid+1);
		}
		else{
			return (ceilSearch(arr,mid+1,high,x));
		}
	}
}
//flaw in floor search
/*
int floorSearch(int arr[],int low,int high,int x){
	if(arr[high] <= x){
                return high;
        }
	if(x < arr[low]){
		//it is not in the array's range
		return -1;
	}
	int mid=(low+high)/2;
	cout<<"mid="<<mid<<endl;
	if(arr[mid] == x){
		return mid;
	}
	else if(arr[mid] > x){
		if(arr[mid+1] == x && mid+1 <=high){
                      return (mid+1);
        	}
	        else{
        	        return (floorSearch(arr,mid+1,high,x));
	        }
        }
        else{
                if(arr[mid-1]==x && mid-1 >=low){
                        return (mid-1);
                }
                else{
                        return (floorSearch(arr,0,mid-1,x));
		}
	}
}*/
int floorSearch(int arr[],int n, int x){
	int i;
	if(arr[n-1] <= x){
		return (n-1);
	}
	if(x < arr[0]){
		return -1;
	}
	for(i=0;i<n-1;i++){
		if(arr[i]==x){
			return i;
		}
		else{
			if(arr[i-1]<=x && arr[i] > x){
				return (i-1);
			}
		}
	}
}
main(){
	int arr[]={0,1,2,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=3;
	int index=ceilSearch(arr,0,n-1,x);
	if(index >= 0){
		cout<<"Ceil is "<<arr[index]<<endl;
	}
	else{
		cout<<"Ceil not found"<<endl;
	}
	index=floorSearch(arr,n,x);
        if(index >= 0){
                cout<<"Floor is "<<arr[index]<<endl;
        }
        else{
                cout<<"Floor not found"<<endl;
        }
}
