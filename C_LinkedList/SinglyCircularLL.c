// SINGLY CIRCULAR LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first,PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;  
    }
    (*last)->next = *first;
    
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;
    }
    (*last)->next = *first;
}

void DeleteFirst(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first == NULL;
        *last == NULL; 
    }
    else
    {
        *first = (*first)->next;
        free((*last)->next);
        (*last)->next = *first;
    }
}

void DeleteLast(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first == NULL;
        *last == NULL; 
    }
    else
    {
        temp = *first;

        while(temp->next != *last )
        {
            temp = temp->next;
        }
        free(temp->next);
        *last = temp;
        (*last)->next = *first; 
    }
}

void Display(PNODE first,PNODE last)
{
   
    do
    {
        printf("| %d | -> ",first->data);
        first = first->next;
    }while(first != last->next);
    
    printf("NULL\n");
}

int Count (PNODE first,PNODE last)
{
     int iCount = 0;
    do
    {
        iCount++;
        first = first->next;
    }while(first != last->next);

    return iCount;
}

void InsertAtPos(PPNODE first, PPNODE last,int no,int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCount = 0;
    int i = 0;

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount+1)
    {
        printf("Invalid Postion\n");
        return ;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(i = 1;i< pos -1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE first, PPNODE last,int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    int iCount = 0;
    int i = 0;

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount)
    {
        printf("Invalid Postion\n");
        return ;
    }

    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iCount+1)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;

        for(i = 1;i< pos -1;i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
    }

}

int CountEven(PNODE first, PNODE last)
{
    int iCountEven = 0;

    if(first == NULL && last == NULL)
    {
        return -1;
    }

    do
    {
        if(first->data % 2 == 0)
        {
            iCountEven++;
        }
        first = first->next;
    }while(first != last->next);

    return iCountEven;
}

int CountOdd(PNODE first, PNODE last)
{
    int iCountOdd = 0;

    if(first == NULL && last == NULL)
    {
        return -1;
    }

    do
    {
        if(first->data % 2 != 0)
        {
            iCountOdd++;
        }
        first = first->next;
    }while(first != last->next);

    return iCountOdd;
}

int Summation(PNODE first, PNODE last)
{
    int iSum = 0;
    
    if(first == NULL && last == NULL)
    {
        return -1;
    }

    do
    {
        iSum = iSum + first->data;
        first = first->next;
    }while(first != last->next);

    return iSum;
}

int Maximum(PNODE first, PNODE last)
{
    PNODE temp = NULL;

    if(first == NULL && last == NULL)
    {
        return -1;
    }

    int iMax = first->data;
    temp = first->next;


    while(temp != last->next)
    {
        if(temp->data > iMax)
        {
            iMax = temp->data;

        }
        temp = temp->next;
    }

    return iMax;
}

int Minimum(PNODE first, PNODE last)
{
    PNODE temp = NULL;

    if(first == NULL && last == NULL)
    {
        return -1;
    }

    int iMin = first->data;
    temp = first->next;

    while(temp != last->next)
    {
        if(temp->data < iMin)
        {
            iMin = temp->data;

        }
        temp = temp->next;
    }

    return iMin;
}

bool Search(PNODE first, PNODE last, int iNo)
{
    if(first == NULL && last == NULL)
    {
        return -1;

    }

    do
    {
        if(first->data == iNo)
        {
            return true;
        }

        first = first->next;
    }while(first != last->next);

    return false;

}

int Frequency(PNODE first, PNODE last, int iNo)
{
    int iFrequency = 0;
    
    if(first == NULL && last == NULL)
    {
        return -1;

    }

    do
    {
        if(first->data == iNo)
        {
            iFrequency++;
        }
        first = first->next;
    }while(first != last->next);

    return iFrequency;

}


int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iValue = 0, ichoice = 0, ipos = 0,iRet = 0;
    bool bRet = false;
    

    while(1)
    {
        
        printf("-------------------------------------------------------------------------------\n");
        printf("----------------------------- Singly Circular Linked List -----------------------\n");
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
                InsertFirst(&head,&tail,iValue);
                break;
                
            case 2: 
                printf("Enter the value that you want to insert at last :\n");
                scanf("%d", &iValue);
                InsertLast(&head,&tail,iValue);
                break;

            case 3: 
                printf("Enter the value that you want to insert at a specific position :\n");
                scanf("%d", &iValue);
                printf("Enter the position where you want to insert the value:\n");
                scanf("%d",&ipos);
                InsertAtPos(&head,&tail,iValue,ipos);
                break;

            case 4: 
                printf("Delete the first node from the linked list.\n:");
                DeleteFirst(&head,&tail);
                break;

            case 5: 
                printf("Delete the last node from the linked list.\n:");
                DeleteLast(&head,&tail);
                break;

            case 6: 
                printf("Enter the position of the node that you want to delete:\n");
                scanf("%d",&ipos);
                DeleteAtPos(&head,&tail,ipos);
                break;

            case 7: 
                printf("Displaying the linked list:\n");
                Display(head,tail);
                break;

            case 8:
                iRet = Count(head,tail); 
                printf("Total number of nodes are : %d\n",iRet);
                break;

            case 9: 
                iRet = CountEven(head,tail);
                printf("Total number of Even nodes are : %d\n",iRet);
                break;

            case 10: 
                iRet = CountOdd(head,tail);
                printf("Total number of Odd nodes are : %d\n",iRet);
                break;

            case 11: 
                iRet = Summation(head,tail);
                printf("Summation of total nodes are : %d\n",iRet);
                break;

            case 12: 
                iRet = Maximum(head,tail);
                printf("Maximum Elements is : %d\n",iRet);
                break;

            case 13: 
                iRet = Minimum(head,tail);
                printf("Minimum Element is : %d\n",iRet);
                break;

            case 14: 
                printf("Enter node that you want to search : \n");
                scanf("%d",&iValue);
                bRet = Search(head,tail,iValue);

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
                iRet = Frequency(head,tail,iValue);
                printf("Frequency of %d is : %d\n",iValue,iRet);
                break;

            case 0: 
                printf("Thank you for using the Singly Circular Linked List application...!\n");
                exit(0);

            default :
                printf("Invalid Choice.\n");    
        }


    }
  


    return 0;
}