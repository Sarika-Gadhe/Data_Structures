#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void Enqueue(struct node ** first,int no)
{
    struct node *newn = NULL;
    struct node *temp = NULL;


    newn = (struct node *)malloc(sizeof(struct node));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

}

int Dequeue(struct node ** first)
{
    struct node *temp = NULL;

    int value = 0;

    if(first == NULL)
    {
        printf("Unable to remove as queue is empty\n");
        return -1;
    }
    else
    {
        temp = *first;

        value = temp->data;

        *first = (*first)->next;
        free (temp);

        return value;
        
    }
}


void Display(struct node *first)
{
    while(first != NULL)
    {
        printf("| %d | -> ",first->data);
        first = first->next;
    }
    printf("\n");
}

int Count(struct node *first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    printf("\n");
    
    return iCount;

}


int main()
{
    struct node *head = NULL;
    int iRet = 0;
    
    Enqueue(&head,50);
    Enqueue(&head,20);
    Enqueue(&head,10);

    Display(head);
    iRet = Count(head);
    printf("Number of elements are : %d\n",iRet);

    iRet = Dequeue(&head);
    printf("removed elements is  : %d\n",iRet);

    iRet = Dequeue(&head);
    printf("removed elements is  : %d\n",iRet);

    Display(head);
    iRet = Count(head);
    printf("Number of elements are : %d\n",iRet);


    return 0;
}