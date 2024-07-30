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
struct node *deletefirst(struct node *head){
    struct node *ptr = head;
    head = head->next;
    free(ptr);
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
    head = deletefirst(head);
    linkedlisttraversal(head);
    return 0;
}