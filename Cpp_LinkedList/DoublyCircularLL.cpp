// Doubly Circular LINKED LIST

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
    struct node *prev;

};

class DoublyCircularLL
{
    private:

        struct node *first;
        struct node *last;
        int iCount;

    public:

        DoublyCircularLL();
        int Count();
        int Maximum();
        int Minimum();
        void Display();
        int CountOdd();
        int CountEven();
        int Summation();
        bool Search(int);
        void DeleteLast();
        void DeleteFirst();
        int Frequency(int);
        void InsertLast(int);
        void DeleteAtPos(int);
        void InsertFirst(int);
        void InsertAtPos(int ,int);

};

DoublyCircularLL :: DoublyCircularLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

void DoublyCircularLL :: InsertFirst(int no)
{
    struct node *newn = NULL;

    newn = new struct node;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
        newn->next->prev = newn;
    }
        last->next = first;
        first->prev = last;
    
        iCount++;

}


void DoublyCircularLL :: InsertLast(int no)
{
    struct node *newn = NULL;

    newn = new struct node;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
       last->next = newn;
       newn->prev = last;
       last = newn;

    }
        last->next = first;
        first->prev = last;
        iCount++;
        
}

void DoublyCircularLL :: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    iCount--;
}

void DoublyCircularLL :: DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        
        last = last->prev;
        delete first->prev;
        first->prev = last;
        last->next = first;
    }
    iCount--;
}

void DoublyCircularLL :: InsertAtPos(int no,int pos)
{
    struct node *newn =  NULL;
    struct node *temp = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(i = 1; i < pos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }

}


void DoublyCircularLL :: DeleteAtPos(int pos)
{
    struct node *temp = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1;i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }

}


void DoublyCircularLL :: Display()
{
    struct node *temp = NULL;

    if(first == NULL && last == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }

    temp = first;

    cout<<"<=> ";
    do
    {
        cout<<"| "<<temp->data<<" | <=>";
        temp = temp->next;
    }while(temp != last->next);

    cout<<"\n";
    
}


int DoublyCircularLL :: Count()
{
    return iCount;
}


int DoublyCircularLL :: CountEven()
{
    int iCountEven = 0;

    struct node *temp = NULL;

    temp = first;

    do
    {
        if(temp->data % 2 == 0)
        {
            iCountEven++;
        }
        temp = temp->next;
    }while(temp != last->next);
    
    return iCountEven;
}

int DoublyCircularLL :: CountOdd()
{
    int iCountOdd = 0;

    struct node *temp = NULL;

    temp = first;

    do
    {
        if(temp->data % 2 != 0)
        {
            iCountOdd++;
        }
        temp = temp->next;
    }while(temp != last->next);

    return iCountOdd;
}

int DoublyCircularLL :: Summation()
{
    int iSum = 0;

    struct node *temp = NULL;
    temp = first;
    do
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }while(temp != last->next);

    return iSum;

}

int DoublyCircularLL :: Maximum()
{
    int iMax = first->data;
    struct node *temp = NULL; 

    if(first == NULL && last == NULL)
    {
        cout<<"Linked List is Empty"<<"\n";
        return -1;
    }

    temp = first;

    do 
    {
        if(temp->data > iMax)
        {
            iMax = temp->data;
        }

        temp = temp->next;
    }while(temp != last->next);

    return iMax;

}

int DoublyCircularLL :: Minimum()
{
    int iMin = first->data;
    struct node *temp = NULL; 

    if(first == NULL && last == NULL)
    {
        cout<<"Linked List is Empty"<<"\n";
        return -1;
    }

    temp = first;

   do 
    {
        if(temp->data < iMin)
        {
            iMin = temp->data;
        }

        temp = temp->next;
    }while(temp != last->next);

    return iMin;
}


int DoublyCircularLL ::  Frequency(int iNo)
{
    int iFrequency = 0;

    struct node *temp = NULL;

    temp = first;

    do
    {
        if(temp->data == iNo)
        {
            iFrequency++;
        }
        temp = temp->next;
    }while(temp != last->next);

    return iFrequency;
}

bool DoublyCircularLL ::  Search(int iNo)
{
    struct node *temp = first;

    do
    {
        if(temp->data == iNo)
        {
            return true;
        }
        temp = temp->next;
    }while(temp != last->next);

    return false;

}

int main()
{
    DoublyCircularLL sobj;
   int iValue = 0, ichoice = 0, ipos = 0,iRet = 0;
    bool bRet = false;
    

    while(1)
    {
        
        cout<<"-------------------------------------------------------------------------------"<<"\n";
        cout<<"----------------------------- Doubly Circular Linked List -----------------------"<<"\n";
        cout<<"-------------------------------------------------------------------------------"<<"\n";

        cout<< "1 : Insert First"<<"\n";
        cout<< "2 : Insert Last"<<"\n";
        cout<< "3 : Insert At Position"<<"\n";
        cout<< "4 : Delete First"<<"\n";
        cout<< "5 : Delete Last"<<"\n";
        cout<< "6 : Delete At Position"<<"\n";
        cout<< "7 : Display List"<<"\n";
        cout<< "8 : Count Total Number of Nodes"<<"\n";
        cout<< "9 : Count Even Nodes"<<"\n";
        cout<< "10 : Count Odd Nodes"<<"\n";
        cout<< "11 : Summation of All Elements"<<"\n";
        cout<< "12 : Find Maximum Element"<<"\n";
        cout<< "13 : Find Minimum Elements"<<"\n";
        cout<< "14 : Search an Element"<<"\n";
        cout<< "15 : Frequency of a number"<<"\n";
        cout<< "0 : Exit"<<"\n";
        cout<< "-------------------------------------------------------------------------------"<<"\n";
        
        cout<< "Please Enter your Choice : ";
        cin>>ichoice;

        switch(ichoice)
        {
            case 1: 
                cout<<"Enter the value that you want to insert at first : "<<"\n";
                cin>>iValue;
                sobj.InsertFirst(iValue);
                break;
                
            case 2: 
                cout<<"Enter the value that you want to insert at last :"<<"\n";
                cin>>iValue;
                sobj.InsertLast(iValue);
                break;

            case 3: 
                cout<<"Enter the value that you want to insert at a specific position :"<<"\n";
                cin>>iValue;
                cout<<"Enter the position where you want to insert the value: "<<"\n";
                cin>>ipos;
                sobj.InsertAtPos(iValue,ipos);
                break;

            case 4: 
                cout<<"Delete the first node from the linked list."<<"\n";
                sobj.DeleteFirst();
                break;

            case 5: 
                cout<<"Delete the last node from the linked list."<<"\n";
                sobj.DeleteLast();
                break;

            case 6: 
                cout<<"Enter the position of the node that you want to delete:"<<"\n";
                cin>>ipos;
                sobj.DeleteAtPos(ipos);
                break;

            case 7: 
                cout<<"Displaying the linked list:"<<"\n";
                sobj.Display();
                break;

            case 8:
                iRet = sobj.Count(); 
                cout<<"Total number of nodes are : "<<iRet<<"\n";
                break;

            case 9: 
                iRet = sobj.CountEven();
                cout<<"Total number of Even nodes are : "<<iRet<<"\n";
                break;

            case 10: 
                iRet = sobj.CountOdd();
                cout<<"Total number of Odd nodes are : "<<iRet<<"\n";
                break;

            case 11: 
                iRet = sobj.Summation();
                cout<<"Summation of total nodes are : "<<iRet<<"\n";
                break;

            case 12: 
                iRet = sobj.Maximum();
                cout<<"Maximum Elements is : "<<iRet<<"\n";
                break;

            case 13: 
                iRet = sobj.Minimum();
                cout<<"Minimum Element is : "<<iRet<<"\n";
                break;

            case 14: 
                cout<<"Enter node that you want to search : "<<"\n";
                cin>>iValue;
                bRet = sobj.Search(iValue);

                if(bRet)
                {
                    cout<<"Element is present."<<"\n";
                }
                else
                {
                    cout<<"Element is not present."<<"\n";
                }

                break;

            case 15: 
                cout<<"Enter number to check frequency : "<<"\n";
                cin>>iValue;
                iRet = sobj.Frequency(iValue);
                cout<<"Frequency : "<<iRet<<endl;
                break;

            case 0: 
                cout<<"Thank you for using the Doubly Circular Linked List application...!"<<"\n";
                exit(0);

            default :
                cout<<"Invalid Choice."<<"\n";    
        }


    }

    return 0;
}