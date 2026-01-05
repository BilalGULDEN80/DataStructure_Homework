#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = NULL;
struct node *Arabul(int veri);
void double_linked_remove(int key);
void traverse();
void addhead(int key) ;
void addhead(int key) 
	{
		if(head == NULL) 
		{
			head = (struct node *)malloc(sizeof(struct node));
			head -> data = key;
			head -> next = head;
			head -> prev = head;
		}
		else
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp -> data = key;
			struct node *last = head;			
			head->prev->next=temp;
			temp->next=head;
			temp->prev=head->prev;
			head->prev=temp;
			head = temp;
	}
}
void double_linked_remove(int key) 
{
	struct node *temp = head;
	if(head -> data == key) 
	{ 
		head = head -> next;
		head -> prev = NULL;
		free(temp);
	}
	else 
	{
		while(temp -> data != key)
		temp = temp -> next;
		temp -> prev -> next = temp -> next;
		if(temp -> next != NULL)
		temp -> next -> prev = temp -> prev;
		head=temp;
		free(temp);
	}
}
void traverse() {
    struct node* temp = head;
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    
    printf("Bastan sona: ");
    while (temp != NULL && temp->next!=head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
struct node* Arabul(int veri)
{
	struct node* locate = NULL;
	while(head != NULL) 
	{
		if(head -> data != veri) 
		{
			head = head -> next; 
		}
		else 
		{
			locate = head;
			break; 
		}
	}
	return locate;
}

int main(int argc, char *argv[]) {
	addhead(25);
	addhead(5);
	addhead(15);	
	double_linked_remove(15);
	addhead(16);
	traverse();
	return 0;
}
