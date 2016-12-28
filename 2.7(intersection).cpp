#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

/* Link list node */
struct node
{
int data;
struct node* next;
};

/* Function to get the counts of node in a linked list */
/* Takes head pointer of the linked list and
returns the count of nodes in the list */


/* function to get the intersection point of two linked
lists head1 and head2 where head1 has d more nodes than
head2 */

/* function to get the intersection point of two linked
lists head1 and head2 */

/* function to get the intersection point of two linked
lists head1 and head2 where head1 has d more nodes than
head2 */
void makeSameSize(struct node* &list, struct node* &list1){
	struct node* temp;
	temp = list;
	int count = 0;
	while(temp->next!=NULL){
		count++;
		temp=temp->next;
	}

	struct node* temp1;
	temp1 = list1;
	int cnt = 0;
	while(temp1->next!=NULL){
		cnt++;
		temp1=temp1->next;
	}
	
	if(temp1!=temp){
		throw invalid_argument( "The lists are not in intersection" );
	}
	int dif =0;
	struct node* t;
	if(count>cnt){
		dif=count-cnt;
		t=list;
		for(int i=0; i<dif; i++){
			list=list->next;
		}

	}
	if(cnt>count){
		dif = cnt-count;
		for(int i=0; i<dif; i++){
			list1=list1->next;
		}
	}
 
}

void display(struct node* list){
	struct node* temp = list; 
	while(temp!=NULL){
	    cout<<temp->data<<" ";
	    temp= temp->next;
	}
}
int getIntesectionNode(struct node* head1, struct node* head2)
{
	makeSameSize(head1,head2);
	struct node* h1= head1;
	struct node* h2= head2;
	struct node* intersection = new node();
	while(h1!= NULL & h2!=NULL){
		if(h1==h2){
			intersection = h1;
			return intersection->data;
		}
		h1=h1->next;
		h2=h2->next;
	}
throw invalid_argument( "The lists are not in intersection" );
return -1;
}



/* IGNORE THE BELOW LINES OF CODE. THESE LINES
ARE JUST TO QUICKLY TEST THE ABOVE FUNCTION */
int main()
{
/*
	Create two linked lists

	1st 3->6->9->15->30
	2nd 10->15->30

	15 is the intersection point
*/

	struct node* newNode;
	struct node* head1 =
				(struct node*) malloc(sizeof(struct node));
	head1->data = 10;

	struct node* head2 =
				(struct node*) malloc(sizeof(struct node));
	head2->data = 3;

	newNode = (struct node*) malloc (sizeof(struct node));
	newNode->data = 6;
	head2->next = newNode;

	newNode = (struct node*) malloc (sizeof(struct node));
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = (struct node*) malloc (sizeof(struct node));
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = (struct node*) malloc (sizeof(struct node));
	newNode->data = 30;
	head1->next->next= newNode;

	head1->next->next->next = NULL;
	printf("\n The node of intersection is %d \n",
			getIntesectionNode(head1, head2));



	return 0;

}
