//this program implements circular singly linked list

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
int count=0;
typedef struct node node;
node *start=NULL;
node* getNode(){
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("\nEnter data...");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	count++;
	return (newnode);
}
void ins_end(){
	node *newnode=getNode();
	if(start==NULL){
		start=newnode;
		newnode->link=start;//circular fashion
	}
	else{
		node *last;
		last=start;
		while(last->link!=start){
			last=last->link;
		}
		last->link=newnode;
		newnode->link=start;
	}
}
void ins_beg(){
	node *newnode=getNode();
	if(start==NULL){
		start=newnode;
		newnode->link=start;
	}
	else{
		node *last=start;
		while(last->link!=start){
			last=last->link;
		}
		newnode->link=start;
		start=newnode;
		last->link=start;
	}
}
void ins_mid(){
	int pos;
	int ctr=1;
	node *prev,*temp;
	printf("\nenter position...");
	scanf("%d",&pos);
	if(pos <=0 || pos > count+1){
		printf("\ninvalid position\n");
	}
	else{
		if(pos==1){
			ins_beg();
		}
		else if(pos==count+1){
			ins_end();
		}
		else{
			node *newnode=getNode();
			temp=prev=start;
			while(ctr < pos){
				prev=temp;
				temp=temp->link;
				ctr++;
			}
			prev->link=newnode;
			newnode->link=temp;
		
		}
	}
}

void del_beg(){
	if(start==NULL){
		printf("\nlist empty\n");
	}
	else{
		node *last=start;
		while(last->link!=start){
			last=last->link;
		}
		node *temp=start;
		start=start->link;
		last->link=start;
		free(temp);
		count--;
		if(count==0){
			start=NULL;
		}
	}
}

void del_end(){
		if(start==NULL){
			printf("\nlist empty\n");
		}
		else{
			node *prev,*last;
			last=prev=start;
			while(last->link!=start){
				prev=last;
				last=last->link;
			}
			prev->link=start;
			free(last);
			count--;
			if(count==0){
				start=NULL;
			}
		}
}

void del_mid(){
	int pos;
        int ctr=1;
        node *prev,*temp;
        printf("\nenter position...");
        scanf("%d",&pos);
        if(pos <=0 || pos > count){
                printf("\ninvalid position\n");
        }
        else{
                if(pos==1){
                        del_beg();
                }
                else if(pos==count){
                        del_end();
                }
                else{
                        temp=prev=start;
                        while(ctr < pos){
                                prev=temp;
                                temp=temp->link;
				ctr++;
                        }
                        prev->link=temp->link;
			free(temp);
			count--;
			if(count==0){
				start=NULL;
			}

                }
        }
}

int noofnodes(){
	return (count);
}
void for_disp(){
	node *temp=start;
	while(temp->link!=start){
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("%d\n",temp->data);
}

void rev_disp(){
	int arr[count];
	int top=-1;
	node *temp=start;
	while(temp->link!=start){
		arr[++top]=temp->data;
		temp=temp->link;
	}
	arr[++top]=temp->data;
	int i;
	for(i=top;i>=0;i--){
		printf("%d ",arr[i]);	
	}
	printf("\n");

}

main(){
	int flag=1;
	int ch,c=0;
	while(flag){
		printf("\nEnter 1 for creation and appending\n2 for inserting at front\n3 for inserting at mid\n4 for deletion at front\n5 for deletionat end\n6 for deletion at mid\n7 for forward display\n8 for backward display\n9 for no of nodes\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:ins_end();break;
			case 2:ins_beg();break;
			case 3:ins_mid();break;
			case 4:del_beg();break;
			case 5:del_end();break;
			case 6:del_mid();break;
			case 7:for_disp();break;
			case 8:rev_disp();break;
			case 9:c=noofnodes();
			printf("\nNo of nodes = %d",c);break;
		}
		printf("\nDo you want to continue...(1/0)");
		scanf("%d",&flag);
	}
}
