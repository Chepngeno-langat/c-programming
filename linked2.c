// A simple C program for traversal of a linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* link;
};

void printList(struct Node* n)
{
  if (n == NULL)
    printf("list is empty.\n");
  while (n != NULL) {
		printf(" %d ", n->data);
		n = n->link;
	}
}

/*insert new node at the beginning of list*/
void beginning(struct Node** head, int new_data)
{
  struct Node * new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->link = *head;
  *head = new_node;
}

/*insert new node at the end of the list*/
void insertAtEnd(struct Node** head, int new_data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  struct Node *p = *head;
  
  new_node->data = new_data;

  if (*head == NULL)
    {
      *head = new_node;
      return;
    }

  while(p->link != NULL)
    p = p->link;

  p->link = new_node;
  new_node->link = NULL;
  
}

/*insert new node between nodes*/
void insertBetween(struct Node* prev_node, int new_data)
{
  struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
 
  new_node->data = new_data;
  new_node->link = prev_node->link;
  prev_node->link = new_node;
}

/*delete node*/
struct Node *deleteNode(struct Node *head, int x)
{
  struct Node *temp, *p;
  /*deletion of first node*/
  if (head->data == x)
    {
      temp = head;
      head = head->link;
      free(temp);
      return head;
    }
  /* deletion in between or at the end*/
  p = start;
  while (p->link != NULL)
    {
      if(p->link->info == x)
	break;
      p = p->link;
    }
  if (p->link == NULL)
    printf("Element %d not in list.\n", x);
  else
    {
      temp = p->link;
      p->link = temp->link;
      free(temp);
    }
  return head;
}

/*reversing list*/
struct Node *reverseList(struct node *head)
{
  struct Node *prev, *ptr, *next;
  prev=NULL;
  ptr=head;
  while (ptr != NULL)
    {
      next = ptr->link;
      ptr->link = prev;
      prev = ptr;
      ptr = next;
    }
  head = prev;
  return head;
}

int main(int x)
{
  	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth = NULL;
	struct Node* new_data = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	new_data = (struct Node*)malloc(sizeof(struct Node));

	head->data = 10;
	head->link = second;

	second->data = 15;
	second->link = third;

	third->data = 20;
	third->link = fourth;

	fourth->data = 25;
	fourth->link = NULL;

	beginning(&head, 5);
	insertBetween(second, 18);
	insertAtEnd(&head, 30);

	/*deleteNode(head, 10);*/
	
	printList(head);
}
