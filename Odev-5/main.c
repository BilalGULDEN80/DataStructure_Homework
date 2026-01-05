#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void traverse();
void double_linked_remove(int key);
void insertAtEnd(int veri);
struct node *Arabul(int veri);
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = NULL;
int main(int argc, char *argv[]) {
	insertAtEnd(40);
    insertAtEnd(30);
    insertAtEnd(20);
    insertAtEnd(10);
    insertAtEnd(11);
    insertAtEnd(12);
    insertAtEnd(13);
    
    printf("Olusturulan liste:\n");
    traverse();
    
    
    printf("\n20 degeri araniyor: ");
    struct node* bulunan = Arabul(20);
    if (bulunan != NULL) {
        printf("Adres: %p, Deger: %d\n", 
		(void*)bulunan, bulunan->data);
    } else {
        printf("Bulunamadi.\n");
    }
    
    printf("\n degeri siliniyor\n");
    double_linked_remove(30);
    printf("\nSilme sonrasi liste:\n");
    traverse();
}
void insertAtEnd(int key) 
{
	if(head == NULL) 
	{
		head = (struct node *)malloc(sizeof(struct node));
		head -> data = key;
		head -> next = NULL;
		head -> prev = NULL;
	}
	else 
	{
		struct node *temp = head;
		struct node *temp2 = (struct node *)malloc(sizeof(struct node));
		while(temp -> next != NULL)
			temp = temp -> next;
		temp2 -> data = key;
		temp2 -> next = NULL;
		temp2 -> prev = temp;
		temp -> next = temp2;
		head=temp;
	}
}
void traverse() {
    struct node* temp = head;
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    
    printf("Bastan sona: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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
		free(temp);
	}
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
