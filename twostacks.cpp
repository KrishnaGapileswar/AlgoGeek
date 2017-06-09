//this program tries to implement two stacks in a single array
//naive way of dividing the array into equla halves will lead to inefficient usage of space 
//we follow a different strategy that we start two stacks from  the two extremes of the array
#include<iostream>
#include<stdlib.h>
using namespace std;
class twostacks{
	int *arr;
	int size;
	int top1,top2;
	public:
	twostacks(int n){
		size=n;
		arr=new int[n];
		top1=-1;
		top2=size;
	}
	void push1(int x){
		if(top2-top1 > 1){
			arr[++top1]=x;
		}
		else{
			cout<<"stack overflow"<<endl;
		}
	}
	void push2(int x){
		if(top2-top1 > 1){
			arr[--top2]=x;
		}
		else{
			cout<<"stack overflow"<<endl;
		}
	}
	int pop1(){
		if(top1 >=0){
			int x=arr[top1--];
			return x;
		}
		else{
			cout<<"stack underflow"<<endl;
			exit(1);
		}	
	}
	int pop2(){
		if(top2 < size){
			int x=arr[top2++];
			return x;
		}
		else{
			cout<<"stack underflow"<<endl;
			exit(1);
		}
	}
};

main(){
	twostacks ts(10);
	ts.push1(23);
	ts.push1(29);
	ts.push2(100);
	ts.push2(120);
	ts.push1(56);
	cout<<"value by pop1() is "<<ts.pop1()<<endl;
	ts.push2(89);
	cout<<"value by pop2() is "<<ts.pop2()<<endl;
}
