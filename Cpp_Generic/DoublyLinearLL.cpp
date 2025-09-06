// DOUBLY LINEAR LINKED LIST

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node <T> *next;
    struct node <T> *prev;
};

template <class T>
class DoublyLinearLL
{
    private:
        struct node <T>* first;
        int iCount;

    public:
        DoublyLinearLL()
        {
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(T no)
        {
            struct node <T>* newn = NULL;
            
            newn = new struct node<T>;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                newn->next = first;
                first->prev = newn;

                first = newn;
            }
            iCount++;
        }

        void InsertLast(T no)
        {
            struct node <T>* newn = NULL;
            struct node <T>* temp = NULL;

            newn = new struct node<T>;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                temp = first;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                
                newn->prev = temp;
                temp->next = newn;
            }
            iCount++;
        }

        void DeleteFirst()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first;

                first = NULL;
            }
            else
            {
                first = first->next;
                delete first->prev;
                first->prev = NULL;  
            }
            iCount--;
        }

        void DeleteLast()
        {
            struct node <T> * temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first;

                first = NULL;
            }
            else
            {
                temp = first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }

                delete temp->next;
                temp->next = NULL;
            }
            iCount--;
        }

        void Display()
        {
            struct node <T>* temp;

            temp = first;

            cout<<"NULL <=> ";
            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" | <=> ";
                temp = temp->next;
            }

            cout<<"NULL"<<"\n";
            
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(T no, int pos)
        {
            struct node <T>* temp = NULL;
            struct node <T>* newn = NULL;

            int i = 0;

            if(pos < 1 || pos > iCount +1)
            {
                cout<<"Position is invalid"<<"\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
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

                for(i = 1; i < pos-1; i++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next->prev = newn;
                newn->prev = temp;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            struct node <T>* temp = NULL;
            struct node <T>* target = NULL;

            int i = 0;

            if(pos < 1 || pos > iCount)
            {
                cout<<"Position is invalid"<<"\n";
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

                for(i = 1; i < pos-1; i++)
                {
                    temp = temp->next;
                }
               target = temp->next;

               temp->next = target->next;
               target->next->prev = temp;

               delete target;

                iCount--;
            }

        }
};


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
        DoublyLinearLL <int> sobj;
        int iValue = 0, ichoice = 1, ipos = 0,iRet = 0;
    

        while(ichoice != 0)
        {
            
            cout<<"-------------------------------------------------------------------------------"<<"\n";
            cout<<"----------------------------- Doubly Linear Linked List In Generic -----------------------"<<"\n";
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
                    cout<<"Thank you for using the Doubly Linear Linked List application...!"<<"\n";
                    exit(0);

                default :
                    cout<<"Invalid Choice."<<"\n";    
            }
        }
    }
    else if(datatype == 2)
    {
        DoublyLinearLL <char> sobj;
        int ichoice = 1, ipos = 0,iRet = 0;
        char iValue;

        while(ichoice != 0)
        {
            
            cout<<"-------------------------------------------------------------------------------"<<"\n";
            cout<<"----------------------------- Doubly Linear Linked List In Generic -----------------------"<<"\n";
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
                    cout<<"Thank you for using the Doubly Linear Linked List In Generic application...!"<<"\n";
                    exit(0);

                default :
                    cout<<"Invalid Choice."<<"\n";    
            }
        }
    }
    else if(datatype == 3)
    {
        DoublyLinearLL <double> sobj;
        int ichoice = 1, ipos = 0,iRet = 0;
        double iValue;

        while(ichoice != 0)
        {
            
            cout<<"-------------------------------------------------------------------------------"<<"\n";
            cout<<"----------------------------- Doubly Linear Linked List In Generic -----------------------"<<"\n";
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
                    cout<<"Thank you for using the Doubly Linear Linked List In Generic application...!"<<"\n";
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