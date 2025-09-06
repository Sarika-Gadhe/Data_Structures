// DOUBLY LINEAR LINKED LIST

#include<iostream>
using namespace std;


struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyLinearLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLinearLL()
        {
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            
            newn = new NODE;

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

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

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
            PNODE temp = NULL;

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
            PNODE temp;

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

        void InsertAtPos(int no, int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;

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
                newn = new NODE;

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
            PNODE temp = NULL;
            PNODE target = NULL;

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
        
        int CountEven()
        {
            int iCountEven = 0;

            struct node *temp = NULL;

            temp = first;

            while(temp != NULL)
            {
                if(temp->data % 2 == 0)
                {
                    iCountEven++;
                }
                temp = temp->next;
            }

            return iCountEven;
        }

        int CountOdd()
        {
            int iCountOdd = 0;

            struct node *temp = NULL;

            temp = first;

            while(temp != NULL)
            {
                if(temp->data % 2 != 0)
                {
                    iCountOdd++;
                }
                temp = temp->next;
            }

            return iCountOdd;
        }

        int Summation()
        {
            int iSum = 0;

            struct node *temp = NULL;
            temp = first;
            while(temp != NULL)
            {
            iSum = iSum + temp->data;

            temp = temp->next;
            }

            return iSum;

        }

        int Maximum()
        {
            int iMax = first->data;
            struct node *temp = NULL; 

            if(first == NULL)
            {
                cout<<"Linked List is Empty"<<"\n";
                return -1;
            }

            temp = first;

            while(temp != NULL)
            {
                if(temp->data > iMax)
                {
                    iMax = temp->data;
                }

                temp = temp->next;
            }

            return iMax;

        }

                
        int Minimum()
        {
            int iMin = first->data;
            struct node *temp = NULL; 

            if(first == NULL)
            {
                cout<<"Linked List is Empty"<<"\n";
                return -1;
            }

            temp = first;

            while(temp != NULL)
            {
                if(temp->data < iMin)
                {
                    iMin = temp->data;
                }

                temp = temp->next;
            }

            return iMin;
        }


        int Frequency(int iNo)
        {
            int iFrequency = 0;

            struct node *temp = NULL;

            temp = first;

            while(temp != NULL)
            {
                if(temp->data == iNo)
                {
                    iFrequency++;
                }
                temp = temp->next;
            }

            return iFrequency;
        }

        bool Search(int iNo)
        {
            struct node *temp = first;

            while(temp != NULL)
            {
                if(temp->data == iNo)
                {
                    return true;
                }
                temp = temp->next;
            }

            return false;

        }
};


int main()
{
    DoublyLinearLL sobj;
     
   int iValue = 0, ichoice = 0, ipos = 0,iRet = 0;
    bool bRet = false;
    

    while(1)
    {
        
        cout<<"-------------------------------------------------------------------------------"<<"\n";
        cout<<"----------------------------- Doubly Linear Linked List -----------------------"<<"\n";
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
                cout<<"Total number of Even nodes are : "<<iRet<<endl;
                break;

            case 10: 
                iRet = sobj.CountOdd();
                cout<<"Total number of Odd nodes are : "<<iRet<<endl;
                break;

            case 11: 
                iRet = sobj.Summation();
                cout<<"Summation of total nodes are : "<<iRet<<endl;
                break;

            case 12: 
                iRet = sobj.Maximum();
                cout<<"Maximum Elements is : "<<iRet<<endl;
                break;

            case 13: 
                iRet = sobj.Minimum();
                cout<<"Minimum Element is : "<<iRet<<endl;
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
                cout<<"Thank you for using the Doubly Linear Linked List application...!"<<"\n";
                exit(0);

            default :
                cout<<"Invalid Choice."<<"\n";    
        }


    }
   

   return 0;
}