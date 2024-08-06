#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

int main()
{
    int n, data;
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *last = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Check if the number of nodes is positive
    if (n <= 0)
    {
        printf("Number of nodes must be greater than 0.\n");
        return 1;
    }

    // Create the linked list based on user input
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        temp->data = data;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp; // First node
            last = head;
        }
        else
        {
            last->next = temp; // Link new node
            last = temp;       // Update last
        }
    }

    // Print the linked list
    printf("Original linked list:\n");
    linkedlisttraversal(head);

    // Insert a new node at the beginning
    printf("Enter data for the new first node: ");
    scanf("%d", &data);
    head = insertatfirst(head, data);

    // Print the updated linked list
    printf("Linked list after insertion at the beginning:\n");
    linkedlisttraversal(head);

    return 0;
}
