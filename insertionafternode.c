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
    printf("\n");
}
struct node * insertafternode(struct node * head ,struct node *prevnode, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevnode->next;
    prevnode->next = ptr;
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
    head->data = 7;
    head->next = second;

    //link second and third node
    second->data = 19;
    second->next = third;

    //link third and fourth node
    third->data = 41;
    third->next = fourth;

    //teminate the list at the fourth node
    fourth->data = 66;
    fourth->next = NULL;

    linkedlisttraversal(head);
    head = insertafternode(head,second,56);
    linkedlisttraversal(head);

return 0;
}    