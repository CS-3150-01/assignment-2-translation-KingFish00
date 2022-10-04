#include <stdio.h>
#include <stdlib.h>

// The individual node
struct node 
{
   int data; // The data of the node
   struct node *nextPointer; // The next node
}*startingNode;

void createNode(int dataIn); // Create node and add to end of list
void displayList();         // function to display the list

int main()
{
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
 
    displayList();
    return 0;
}

// Function to create a list from user input
void createNodeList(int n)
{
    struct node *fnNode, *temp;
    int userData;
    startingNode = (struct node *)malloc(sizeof(struct node));

    if(startingNode == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        // reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &userData);
        startingNode->data = userData;      
        startingNode->nextPointer = NULL; // links the address field to NULL
        temp = startingNode;
        // Creating n nodes and adding to linked list
        for(int i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &userData);

                fnNode->data = userData;      // links the num field of fnNode with num
                fnNode->nextPointer = NULL; // links the address field of fnNode with NULL

                temp->nextPointer = fnNode; // links previous node i.e. tmp to the fnNode
                temp = temp->nextPointer;
            }
        }  
    }
}

// Create node and add to end of list
void createNode(int dataIn)
{
    int doLoop = 1;
    struct node *fnNode, *temp;
    if(startingNode == NULL) // Has a list been started
    {
        startingNode = (struct node *)malloc(sizeof(struct node)); // Create the head of the node
        startingNode->data = dataIn;      // Set starting node data
        startingNode->nextPointer = NULL; // links the address field to NULL
    }
    else
    {
        temp = startingNode; // Convert the head into the temp node

        while (doLoop == 1) // Continue to loop until they find the end of the list
        {
            if (temp->nextPointer == NULL) // Check if the current node is the end of the list
            {
                fnNode = (struct node *)malloc(sizeof(struct node)); // Create a new node
                fnNode->data = dataIn;      // links the num field of fnNode with num
                fnNode->nextPointer = NULL; // links the address field of fnNode with N
                temp->nextPointer=fnNode;
                break;
            }
            else
            {
                temp=temp->nextPointer; // Move to the next node
            }
        }
    }
}

// function to display the list
void displayList()
{
    struct node *temp;
    if(startingNode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        printf("Nodes of singly linked list:\n");
        temp = startingNode;
        while(temp != NULL)
        {
            printf("%d ", temp->data); // Print current node data
            temp = temp->nextPointer; // Move to next node
        }
    }
}