#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
void linkedlisttraversal (struct node *ptr)
{
    while (ptr != 0)
    {
        printf("Elements : %d\n",ptr->data);
        ptr = ptr->next;
    }
}
struct node *deletionatend(struct node *head){
    struct node *p = head;
    struct node *q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    return head;
}
int main (){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    
    //Allocate memory for nodes in the linked list
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    //link first and second node
    head->data = 4;
    head->next = second;

    //link second and third node
    second->data = 3;
    second->next = third;

    //link third and fourth node
    third->data = 8;
    third->next = fourth;

    //teminate the list at the fourth node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Lnked list before deletion:\n");
    linkedlisttraversal(head);

    printf("Lnked list after deletion:\n");
    head = deletionatend(head);
    linkedlisttraversal(head);
    return 0;
}