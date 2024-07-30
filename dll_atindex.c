#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};
void linkedlisttraversal (struct node *ptr)
{
    while (ptr != 0)
    {
        printf("Elements : %d\n",ptr->data);
        ptr = ptr->next;
    }
}
struct node *insertatindex(struct node *n1, int data, int index){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = n1;
    ptr->data = data;
    int i = 0;

    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
    return n1;
    
}
int main (){
    struct node *n1;
    struct node *n2;
    struct node *n3;
    struct node *n4;
    
    //Allocate memory for nodes in the linked list
    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    n3 = (struct node *)malloc(sizeof(struct node));
    n4 = (struct node *)malloc(sizeof(struct node));

    //link first and second node
    n1->data = 7;
    n1->next = n2;
    n1->prev = NULL;

    //link second and third node
    n2->data = 11;
    n2->next = n3;
    n2->prev = n1;

    //link third and fourth node
    n3->data = 41;
    n3->next = n4;
    n3->prev = n2;

    //teminate the list at the fourth node
    n4->data = 66;
    n4->next = NULL;
    n4->prev = n3;

    printf("Before adding node:\n");
    linkedlisttraversal(n1);

    printf("\nAfter adding node:\n");
    n1 = insertatindex(n1,18,2);
    linkedlisttraversal(n1);
    return 0;
}