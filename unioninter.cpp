//this program will compute the union and intersection of two sets.
//the input needs to be sorted first
//the complexity is O(m+n)


#include<iostream>
using namespace std;

void findunion(int arr[],int brr[], int m, int n){
	int i=0,j=0,k=0;
	int unionarr[m+n];
	while(i<m && j<n){
		if(arr[i] < brr[j]){
			unionarr[k++]=arr[i++];	
		}
		else if(arr[i] > brr[j]){
			unionarr[k++]=brr[j++];
		}
		else/*when they are equal*/{
			unionarr[k++]=arr[i++];
			j++;
		}
	}


	//when either of the sets is exhausted and the two sets need not be equal length
	while(i < m){
		unionarr[k++]=arr[i++];
	}
	while(j < n){
		unionarr[k++]=brr[j++];
	}

	cout<<"\nThe union is\n";
	for(i=0;i<k;i++){
		cout<<unionarr[i]<<" ";
	}
	cout<<endl;
}

void findinter(int arr[], int brr[], int m,int n){
	int i=0,j=0,k=0;
        int interarr[m+n];
        while(i<m && j<n){
                if(arr[i] < brr[j]){
        		i++;        
	         }
                else if(arr[i] > brr[j]){
                        j++;
                }
                else/*when they are equal*/{
                        interarr[k++]=arr[i++];
                        j++;
                }
        }
	cout<<"\nThe intersection is\n";
	for(i=0;i<k;i++){
		cout<<interarr[i]<<" ";
	}
	cout<<endl;
}


main(){
	int a[10],b[10];
	int m,n;
	
//to note that length of an array can be found by the formula len=sizeof(arr)/sizeof(arr[0]);

	cout<<"\nlength of a ";
	cin>>m;
	cout<<"\nlength of b ";
	cin>>n;
	cout<<"Enter values for a\n";
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	cout<<"Enter values for b\n";
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	findunion(a,b,m,n);
	findinter(a,b,m,n);
}
