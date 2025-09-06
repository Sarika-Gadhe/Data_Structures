#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node <T> * next;
    struct node <T> *prev;

};


template <class T>
class DoublyCircularLL
{
    private:

        struct node<T> *first;
        struct node<T> *last;
        int iCount;

    public:

        DoublyCircularLL();
        int Count();
        void Display();
        void DeleteLast();
        void DeleteFirst();
        void InsertLast(T);
        void InsertFirst(T);
        void DeleteAtPos(int);
        void InsertAtPos(T,int);

};

template <class T>
DoublyCircularLL <T>:: DoublyCircularLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}


template <class T>
void DoublyCircularLL <T>:: InsertFirst(T no)
{
    struct node <T>*newn = NULL;

    newn = new struct node<T>;
    
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


template <class T>
void DoublyCircularLL <T>:: InsertLast(T no)
{
    struct node <T>*newn = NULL;

    newn = new struct node<T>;
    
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


template <class T>
void DoublyCircularLL <T>:: DeleteFirst()
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


template <class T>
void DoublyCircularLL <T>:: DeleteLast()
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


template <class T>
void DoublyCircularLL <T>:: InsertAtPos(T no,int pos)
{
    struct node <T>*newn =  NULL;
    struct node <T>*temp = NULL;

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
        newn = new struct node<T>;

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


template <class T>
void DoublyCircularLL <T>:: DeleteAtPos(int pos)
{
    struct node <T>*temp = NULL;

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


template <class T>
void DoublyCircularLL <T>:: Display()
{
    struct node <T>*temp = NULL;

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


template <class T>
int DoublyCircularLL <T>:: Count()
{
    return iCount;
}

int main()
{
     int datatype = 0;

    cout<<"Select Data Type : "<<endl;
    cout<<"1. int : "<<endl;
    cout<<"2. char : "<<endl;
    cout<<"3. double : "<<endl;
    cout<<"Enter choice "<<endl;
    cin>>datatype;

    if(datatype == 1)
    {
        DoublyCircularLL <int> sobj;
        int iValue = 0, ichoice = 1, ipos = 0,iRet = 0;
    

        while(ichoice != 0)
        {
            
            cout<<"-------------------------------------------------------------------------------"<<"\n";
            cout<<"----------------------------- Doubly Circular Linked List In Generic -----------------------"<<"\n";
            cout<<"-------------------------------------------------------------------------------"<<"\n";

            cout<< "1 : Insert First"<<"\n";
            cout<< "2 : Insert Last"<<"\n";
            cout<< "3 : Insert At Position"<<"\n";
            cout<< "4 : Delete First"<<"\n";
            cout<< "5 : Delete Last"<<"\n";
            cout<< "6 : Delete At Position"<<"\n";
            cout<< "7 : Display List"<<"\n";
            cout<< "8 : Count Total Number of Nodes"<<"\n";
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

                case 0: 
                    cout<<"Thank you for using the Doubly Circular Linked List application...!"<<"\n";
                    exit(0);

                default :
                    cout<<"Invalid Choice."<<"\n";    
            }
        }
    }
    else if(datatype == 2)
    {
        DoublyCircularLL <char> sobj;
        int ichoice = 1, ipos = 0,iRet = 0;
        char iValue;

        while(ichoice != 0)
        {
            
            cout<<"-------------------------------------------------------------------------------"<<"\n";
            cout<<"----------------------------- Doubly Circular Linked List In Generic -----------------------"<<"\n";
            cout<<"-------------------------------------------------------------------------------"<<"\n";

            cout<< "1 : Insert First"<<"\n";
            cout<< "2 : Insert Last"<<"\n";
            cout<< "3 : Insert At Position"<<"\n";
            cout<< "4 : Delete First"<<"\n";
            cout<< "5 : Delete Last"<<"\n";
            cout<< "6 : Delete At Position"<<"\n";
            cout<< "7 : Display List"<<"\n";
            cout<< "8 : Count Total Number of Nodes"<<"\n";
            cout<< "0 : Exit"<<"\n";
            cout<< "-------------------------------------------------------------------------------"<<"\n";
            
            cout<< "Please Enter your Choice : ";
            cin>>ichoice;

            switch(ichoice)
            {
                case 1: 
                    cout<<"Enter the character that you want to insert at first : "<<"\n";
                    cin>>iValue;
                    sobj.InsertFirst(iValue);
                    break;
                    
                case 2: 
                    cout<<"Enter the character that you want to insert at last :"<<"\n";
                    cin>>iValue;
                    sobj.InsertLast(iValue);
                    break;

                case 3: 
                    cout<<"Enter the character that you want to insert at a specific position :"<<"\n";
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

                case 0: 
                    cout<<"Thank you for using the Doubly Circular Linked List In Generic application...!"<<"\n";
                    exit(0);

                default :
                    cout<<"Invalid Choice."<<"\n";    
            }
        }
    }
    else if(datatype == 3)
    {
        DoublyCircularLL <double> sobj;
        int ichoice = 1, ipos = 0,iRet = 0;
        double iValue;

        while(ichoice != 0)
        {
            
            cout<<"-------------------------------------------------------------------------------"<<"\n";
            cout<<"----------------------------- Doubly Circular Linked List In Generic -----------------------"<<"\n";
            cout<<"-------------------------------------------------------------------------------"<<"\n";

            cout<< "1 : Insert First"<<"\n";
            cout<< "2 : Insert Last"<<"\n";
            cout<< "3 : Insert At Position"<<"\n";
            cout<< "4 : Delete First"<<"\n";
            cout<< "5 : Delete Last"<<"\n";
            cout<< "6 : Delete At Position"<<"\n";
            cout<< "7 : Display List"<<"\n";
            cout<< "8 : Count Total Number of Nodes"<<"\n";
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

                case 0: 
                    cout<<"Thank you for using the Doubly Circular Linked List In Generic application...!"<<"\n";
                    exit(0);

                default :
                    cout<<"Invalid Choice."<<"\n";    
            }
        }
    }
    else
    {
        cout<<"Invalid choice .....!"<<"\n";
    }

    

    return 0;
}