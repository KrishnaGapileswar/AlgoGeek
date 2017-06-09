//this program implements the basic singly linked list and its basic operations
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;//self-referential structure
};
typedef struct node node;
node *start=NULL;
int count=0;
node* getNode(){
	node *newnode;
	newnode=(node*)malloc(sizeof(node));//memory allocation
	printf("\nEnter value...");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	count++;
	return (newnode);
}
void insert_end(){
	node *newnode=getNode();
	if(start==NULL){
		start=newnode;
	}
	else{
		node *temp=start;
		while(temp->link!=NULL){
			temp=temp->link;//traversing the list
		}
		temp->link=newnode;
	}
}
void insert_beg(){
	node *newnode=getNode();
	if(start==NULL){
		start=newnode;
	}
	else{
		newnode->link=start;
		start=newnode;
	}
}
void insert_mid(){
	int pos=0;
	int ctr=1;
	node *newnode=getNode();
	node *temp=start;
	node *prev=start;
	printf("\nInsert position to insert ");
	scanf("%d",&pos);
	if(pos==1){
		insert_beg();
	}
	else if(pos == count){
		insert_end();
	}
	else if(pos >1 && pos < count){
		while(ctr < pos){
			prev=temp;
			temp=temp->link;
			ctr++;
		}
		prev->link=newnode;
		newnode->link=temp;
	}
}
		

      
void del_end(){
	if(start==NULL){
		printf("\nNo nodes in the list\n");
	}
	else{
		node *prev,*temp;
		prev=start;
		temp=start;
		while(temp->link!=NULL){
			prev=temp;
			temp=temp->link;
		}
		prev->link=NULL;
		count--;
		free(temp);//deallocating the memory
	}
}
void del_beg(){
	if(start==NULL){
		printf("\nNo nodes in the list\n");
	}
	else{
		node *temp=start;
		start=start->link;
		count--;
		free(temp);
	}
}
void del_mid(){
        int pos=0;
        int ctr=1;
        node *temp=start;
        node *prev=start;
        printf("\nInsert position to delete ");
        scanf("%d",&pos);
        if(pos==1){
                del_beg();
        }
        else if(pos == count){
                del_end();
        }
        else if(pos >1 && pos < count){
                while(ctr < pos){
                        prev=temp;
                        temp=temp->link;
                        ctr++;
                }
                prev->link=temp->link;
                free(temp);
                count--;
        }

}

void forward_disp(){
	node *temp=start;
	if(start==NULL){
		printf("\nList empty\n");
	}
	else{
		while(temp->link!=NULL){
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("%d\n",temp->data);
	}
}
void reverse_disp(node *temp){
	if(temp==NULL){
		return;
	}
	else{
		reverse_disp(temp->link);
		printf("%d ",temp->data);
	}
}

int count_of_nodes(){
	return (count);
}
		
main(){
	int flag=1;
	int c;
	while(flag){
		printf("\nEnter 1 for creation or appending\n2 for inserting at the beginning\n3 for inserting at middle\n4 for deleting at the end\n5 for deleting at the front\n6 for deleting at the middle\n7 for displaying left to right\n8 for reversed display\n9 for count of nodes\n");
		int ch;
		scanf("%d",&ch);
		switch(ch){
			case 1:insert_end();break;
			case 2:insert_beg();break;
			case 3:insert_mid();break;
			case 4:del_end();break;
			case 5:del_beg();break;
			case 6:del_mid();break;
			case 7:forward_disp();break;
			case 8:reverse_disp(start);break;
			case 9:c=count_of_nodes();
			printf("\nNo of nodes %d\n",c);break;
		}
		printf("\nDo you want to continue(1/0)...");
		scanf("%d",&flag);
	}
}
