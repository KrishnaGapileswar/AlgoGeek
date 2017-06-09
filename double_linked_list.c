//this program implements a double linked list and its operations
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};
typedef struct node node;
node *start=NULL;
int count=0;
node* getNode(){
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("\nEnter data...");
	scanf("%d",&newnode->data);
	newnode->left=newnode->right=NULL;
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
		while(temp->right!=NULL){
			temp=temp->right;
		}
		temp->right=newnode;
		newnode->left=temp;
	}
}
void insert_beg(){
	node *newnode=getNode();
	if(start==NULL){
		start=newnode;
	}
	else{
		newnode->right=start;
		start->left=newnode;
		start=newnode;
	}
}
void insert_mid(){
	int pos;
	int ctr=1;
	node *prev,*temp;
	printf("\nEnter position...");
	scanf("%d",&pos);
	if(pos <= 0 || pos >count){
		printf("\nPosition not valid\n");
	}
	else{
		if(pos==1){
			insert_beg();
		}
		else if(pos==count){
			insert_end();
		}
		else{
			node *newnode=getNode();
			temp=prev=start;
			while(ctr < pos){
				prev=temp;
				temp=temp->right;
				ctr++;
			}
			prev->right=newnode;
			newnode->right=temp;
			temp->left=newnode;
			newnode->left=prev;
		}
	}
}
void del_beg(){
	if(start==NULL){
		printf("\nlist empty\n");
	}
	else{
		node *temp=start;
		start=start->right;
		start->left=NULL;
		free(temp);
		count--;
	}
}
void del_end(){
	if(start==NULL){
		printf("\nlist empty\n");
	}
	else{
		node *prev,*temp;
		temp=prev=start;
		while(temp->right!=NULL){
			prev=temp;
			temp=temp->right;
		}
		prev->right=NULL;
		free(temp);
		count--;
	}
}
void del_mid(){
	int pos;
        int ctr=1;
        node *prev,*temp;
        printf("\nEnter position...");
        scanf("%d",&pos);
        if(pos <= 0 || pos >count){
                printf("\nPosition not valid\n");
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
                                temp=temp->right;
                                ctr++;
                        }
                        prev->right=temp->right;
			temp->right->left=prev;
			free(temp);
			count--;
                }
        }
}
void for_disp(){
	if(start==NULL){
		printf("\nlist empty\n");
	}
	else{
		node *temp=start;
		while(temp->right!=NULL){
			printf("%d ",temp->data);
			temp=temp->right;
		}
		printf("%d\n",temp->data);
	}
}
void rev_disp(){
	if(start==NULL){
		printf("\nlist empty\n");
	}
	else{
		node *temp=start;
		while(temp->right!=NULL){
			temp=temp->right;
		}
		while(temp->left!=NULL){
			printf("%d ",temp->data);
			temp=temp->left;
		}
		printf("%d\n",temp->data);
	}
}
int noofnodes(){
	return (count);
}
main(){
	int flag=1;
	int ch,c=0;
	while(flag){
		printf("\nenter 1 for creation or appending\n2 for inserting at front\n3 for inserting at middle\n4 for deletion at end\n5 for deletion at front\n6 for deletion at middle\n7 for display left to  right\n8 for display right to left\n9 for no of nodes\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:insert_end();break;
			case 2:insert_beg();break;
			case 3:insert_mid();break;
			case 4:del_end();break;
			case 5:del_beg();break;
			case 6:del_mid();break;
			case 7:for_disp();break;
			case 8:rev_disp();break;
			case 9:c=noofnodes();printf("\nno of nodes = %d",c);
			break;
		}
		printf("\ndo you want to continue...(1/0):");
		scanf("%d",&flag);
	}
}
