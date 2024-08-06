#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void linkedlisttraversal(struct node *ptr)
{
    while (ptr != 0)
    {
        printf("Elements : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    int n, data;

    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *last = NULL;

    // accept the number of nodes from user
    printf("Enter the number of nodes :");
    scanf("%d", &n);

    // accept the data of nodes from user
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);

        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp; //first node
            last = head;
        }
        else
        {
            last->next = temp; //linked part
            last = temp;
        }
    }
    printf("Linked List :\n");
    linkedlisttraversal(head);

    return 0;
}