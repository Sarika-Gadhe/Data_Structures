// DOUBLY LINEAR LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
        newn->prev = NULL;
        newn->next = NULL;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }
    
}

void InsertLast(PPNODE first,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
        newn->prev = NULL;
        newn->next = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;

    }
}

void DeleteFirst(PPNODE first)
{
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);
        (*first)->prev = NULL;
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void Display(PNODE first)
{
    printf("NULL <=> ");
    while(first != NULL)
    {
        printf("| %d | <=> ",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    
    return iCount;
}

void InsertAtPos(PPNODE first,int no,int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int i = 0;
    int iCount = 0;

    iCount = Count(*first);

    if(pos < 1 || pos > iCount+1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(first,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for(i = 1; i < pos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}


void DeleteAtPos(PPNODE first,int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    int i = 0;
    int iCount = 0;

    iCount = Count(*first);

    if(pos < 1 || pos > iCount)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(i = 1; i < pos-1;i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        free(target);
        
    } 
}


int CountEven(PNODE first)
{
    int iCountEven = 0;

    while(first != NULL)
    {
        if((first->data) % 2 == 0)
        {
            iCountEven++;
        }
        first = first->next;
    }

    return iCountEven;
}

int CountOdd(PNODE first)
{
    int iCountOdd = 0;

    while(first != NULL)
    {
        if((first->data) % 2 != 0)
        {
            iCountOdd++;
        }
        first = first->next;
    }

    return iCountOdd;
}

int Summation(PNODE first)
{
    int iSum = 0;

    while(first != NULL)
    {
        iSum = iSum + first->data;

        first = first->next;
    }

    return iSum;
}

int Maximum(PNODE first)
{
    
    int iMax = first->data;

    if(first == NULL)
    {
        printf("Linked List is Empty\n");
        return -1;
    }


    while(first != NULL)
    {
        if( first->data > iMax)
        {
            iMax = first->data;

        }
        first = first->next;
    }

    return iMax;
}

int Minimum(PNODE first)
{
    int iMin = first->data;

    if(first == NULL)
    {
        printf("Linked List is Empty\n");
        return -1;
    }
    

    while(first != NULL)
    {
        if( first->data < iMin)
        {
            iMin = first->data;

        }
        first = first->next;
    }

    return iMin;
}

bool Search(PNODE first, int no)
{
    while(first != NULL)
    {
        if(first->data == no)
        {
            return true;
        }

        first = first->next;
    }

    return false;
}

int Frequency(PNODE first, int no)
{
    int iFrequency = 0;

    while(first != NULL)
    {
        if(first ->data == no)
        {
            iFrequency++;
        }

        first = first->next;
    }

    return iFrequency;
}

int main()
{
    PNODE head = NULL;
    int iValue = 0, ichoice = 0, ipos = 0,iRet = 0;
    bool bRet = false;
    

    while(1)
    {
        
        printf("-------------------------------------------------------------------------------\n");
        printf("----------------------------- Doubly Linear Linked List -----------------------\n");
        printf("-------------------------------------------------------------------------------\n");

        printf("1 : Insert First\n");
        printf("2 : Insert Last\n");
        printf("3 : Insert At Position\n");
        printf("4 : Delete First\n");
        printf("5 : Delete Last\n");
        printf("6 : Delete At Position\n");
        printf("7 : Display List\n");
        printf("8 : Count Total Number of Nodes\n");
        printf("9 : Count Even Nodes\n");
        printf("10 : Count Odd Nodes\n");
        printf("11 : Summation of All Elements\n");
        printf("12 : Find Maximum Element\n");
        printf("13 : Find Minimum Elements\n");
        printf("14 : Search an Element\n");
        printf("15 : Frequency of a number\n");
        printf("0 : Exit\n");
        printf("-------------------------------------------------------------------------------\n");

        printf("Please Enter your Choice : ");
        scanf("%d",&ichoice);

        switch(ichoice)
        {
            case 1: 
                printf("Enter the value that you want to insert at first : \n");
                scanf("%d", &iValue);
                InsertFirst(&head,iValue);
                break;
                
            case 2: 
                printf("Enter the value that you want to insert at last :\n");
                scanf("%d", &iValue);
                InsertLast(&head,iValue);
                break;

            case 3: 
                printf("Enter the value that you want to insert at a specific position :\n");
                scanf("%d", &iValue);
                printf("Enter the position where you want to insert the value:\n");
                scanf("%d",&ipos);
                InsertAtPos(&head,iValue,ipos);
                break;

            case 4: 
                printf("Delete the first node from the linked list.\n:");
                DeleteFirst(&head);
                break;

            case 5: 
                printf("Delete the last node from the linked list.\n:");
                DeleteLast(&head);
                break;

            case 6: 
                printf("Enter the position of the node that you want to delete:\n");
                scanf("%d",&ipos);
                DeleteAtPos(&head,ipos);
                break;

            case 7: 
                printf("Displaying the linked list:\n");
                Display(head);
                break;

            case 8:
                iRet = Count(head); 
                printf("Total number of nodes are : %d\n",iRet);
                break;

            case 9: 
                iRet = CountEven(head);
                printf("Total number of Even nodes are : %d\n",iRet);
                break;

            case 10: 
                iRet = CountOdd(head);
                printf("Total number of Odd nodes are : %d\n",iRet);
                break;

            case 11: 
                iRet = Summation(head);
                printf("Summation of total nodes are : %d\n",iRet);
                break;

            case 12: 
                iRet = Maximum(head);
                printf("Maximum Elements is : %d\n",iRet);
                break;

            case 13: 
                iRet = Minimum(head);
                printf("Minimum Element is : %d\n",iRet);
                break;

            case 14: 
                printf("Enter node that you want to search : \n");
                scanf("%d",&iValue);
                bRet = Search(head,iValue);

                if(bRet)
                {
                    printf("Element is present.\n");
                }
                else
                {
                    printf("Element is not present.\n");
                }

                break;

            case 15: 
                printf("Enter number to check frequency : \n");
                scanf("%d",&iValue);
                iRet = Frequency(head,iValue);
                printf("Frequency of %d is : %d\n",iValue,iRet);
                break;

            case 0: 
                printf("Thank you for using the Doubly Linear Linked List application...!\n");
                exit(0);

            default :
                printf("Invalid Choice.\n");    
        }


    }
  

  
    return 0;
}