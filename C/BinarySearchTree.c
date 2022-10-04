#include <stdio.h>
#include <stdlib.h>

// The individual node
struct node 
{
   int data; // The data of the node
   struct node *leftPointer; // The next node left
   struct node *rightPointer; // The next node right
}*startingNode;

// All of the functions
int numOfBST(int key);          // calculate the total number of possible BST by calculating Catalan Number for given key    
int factorial(int num);         // calculate the factorial of given number

// The stuff that runs in main
int main()
{
    printf("Total number of possible Binary Search Trees with given key: %d", numOfBST(5));    // Shows the possible binary search trees
    return 0;
}

int factorial(int num)
{
    int fact = 1;
    if (num == 0)
    {
        return 1;
    }
    else
    {
        while (num>1)
        {
            fact = fact * num;
            num--;
        }
        return fact;
    }
}

int numOfBST(int key)
{
    int calcNumber = factorial(2*key)/(factorial(key+1) * factorial(key));
    return calcNumber;
}
