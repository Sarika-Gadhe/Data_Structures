#include<iostream>
using namespace std;

template <class T>  
struct node
{
    T data;
    struct node *next;
};

template <class T>  
class QueueX
{
    private:
        struct node <T>*first;
        int iCount;

    public:
        QueueX();
        void Enqueue(T);
        int Dequeue();
        void Display();
        int Count();    
};

template <class T>  
QueueX <T> :: QueueX()
{
    this->first = NULL;
    this->iCount = 0;
}

template <class T>  
void QueueX <T>:: Enqueue(T no)
{
    struct node <T> *newn = NULL;
    struct node <T> *temp = NULL;

    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

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

        temp->next = newn;
    }


    iCount++;
}

template <class T>  
int QueueX <T>:: Dequeue()
{
    struct node <T>*temp = NULL;

    int value = 0;

    if(first == NULL)
    {
        cout<<"Unable to remove as queue is empty"<<"\n";
        return -1;
    }
    else
    {
        temp = first;

        value = temp->data;

        first = first->next;
        delete temp;

        iCount--;

        return value;
        
    }
}

template <class T>  
void QueueX <T>:: Display()
{
    struct node <T>*temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";

}

template <class T>  
int QueueX <T> :: Count()
{
    return iCount;
}


int main()
{
    QueueX <int>*sobj = new QueueX<int>();
    int iRet = 0;

    sobj->Enqueue(51);
    sobj->Enqueue(21);
    sobj->Enqueue(11);
    
    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    iRet = sobj->Dequeue();
    cout<<"removed elements is :"<<iRet<<"\n";


    iRet = sobj->Dequeue();
    cout<<"removed elements is :"<<iRet<<"\n";    
    
    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    delete sobj;
    return 0;

}