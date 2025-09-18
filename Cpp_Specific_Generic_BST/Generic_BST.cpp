#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node <T> * lchild;
    struct node <T>* rchild;
};

template <class T>
class BST
{
    private:
       struct node <T>*first;
       int iCount = 0; 

    public:
        BST();
        void Insert(T);
        void Inorder(struct node <T> *); 
        void DisplayInorder();  
        void Preorder(struct node <T>*); 
        void DisplayPreorder();    
        void Postorder(struct node <T>*);   
        void DisplayPostorder();  
        bool Search(T);
        int Count(struct node <T>*);
        int CountLeafNodes(struct node <T>*);
        int CountParentNodes(struct node <T>*);
        void CountAll();
};

template <class T>
BST <T> :: BST()
{
    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void BST <T>:: Insert(T no)
{
    struct node <T>* temp = NULL;
    struct node <T>* newn = NULL;

    newn = new struct node <T>;
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(1)
        {
            if(no == temp->data)
            {
                cout<<"Duplicate Element : Unable to insert node"<<"\n";
                delete newn;
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp  = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }

}

template <class T>
void BST <T> :: Inorder(struct node <T>* first)
{
    struct node <T> * temp = first;

    if(temp != NULL)
    {
        Inorder(temp->lchild);
        cout<<temp->data<<"\t";
        Inorder(temp->rchild);
       
    }
}

template <class T>
void BST <T>:: DisplayInorder()
{
    cout<<"Inorder Traversal : \n";
    Inorder(first);
    cout<<"\n";
}

template <class T>
void BST <T> :: Preorder(struct node <T>* first)
{
    struct node <T> *temp = first;

    if(temp != NULL)
    {
        cout<<temp->data<<"\t";
        Preorder(temp->lchild);
        Preorder(temp->rchild);
       
    }
}

template <class T>
void BST <T> :: DisplayPreorder()
{
    cout<<"Preorder Traversal : \n";
    Preorder(first);
    cout<<"\n";
}

template <class T>
void BST <T> :: Postorder(struct node <T>* first)
{
    struct node <T> *temp = first;

    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout<<temp->data<<"\t";
       
    }
}

template <class T>
void BST <T> :: DisplayPostorder()
{
    cout<<"Postorder Traversal : \n";
    Postorder(first);
    cout<<"\n";
}

template <class T>
bool BST <T> :: Search(T no)
{
    bool bFlag = false;
    int TimeComplexity = 0;
    struct node <T> *temp = first;

    while(temp != NULL)
    {
        if(no == temp->data)
        {
            bFlag = true;
            break;
        }
        else if(no > temp->data)
        {
            temp = temp->rchild;
        }
        else if(no < temp->data)
        {
            temp = temp->lchild;
        }

        TimeComplexity++;
    }

    cout<<"Time Complexity of Search is : "<<TimeComplexity<<"\n";
    return bFlag;
}

template <class T>
int BST <T> :: Count(struct node <T>*first)
{
    int static iCount = 0;
    struct node <T> *temp = first;

    if(temp != NULL)
    {
        iCount++;

        Count(first->rchild);
        Count(first->lchild);
    }

    return iCount;
}

template <class T>
int BST <T> :: CountLeafNodes(struct node <T> *first)
{
    struct node <T> *temp = first;
    int static iCount = 0;

    if(first != NULL)
    {
        if(first->lchild == NULL && first->rchild == NULL)
        {
            iCount++;
        }

        CountLeafNodes(temp->rchild);
        CountLeafNodes(temp->lchild);
    }
    return iCount;
}

template <class T>
int BST <T> :: CountParentNodes(struct node <T>*first)
{
    struct node <T> * temp = first;
    int static iCount = 0;

    if(temp != NULL)
    {
        if(temp->lchild != NULL || temp->rchild != NULL)
        {
            iCount++;
        }

        CountParentNodes(temp->rchild);
        CountParentNodes(temp->lchild);
    }

    return iCount;
}

template <class T>
void BST <T> :: CountAll()
{
    cout<<"Number of Nodes are : "<<Count(first)<<"\n";
    cout<<"Number of Leaf Nodes are : "<<CountLeafNodes(first)<<"\n";
    cout<<"Number of Parent Nodes are : "<<CountParentNodes(first)<<"\n";
}

int main()
{
    BST <int>*bobj = new BST<int>();

    int iRet = 0;
    bool bRet = false;

    bobj->Insert(11);
    bobj->Insert(9);
    bobj->Insert(17);
    bobj->Insert(25);
    bobj->Insert(7);
    bobj->Insert(35);
    bobj->Insert(10);
    bobj->Insert(15);
    bobj->Insert(21);
    bobj->Insert(26);
    bobj->Insert(37);
    bobj->Insert(89);
    bobj->Insert(91);
    bobj->Insert(65);
    bobj->Insert(12);
    bobj->Insert(20);
    bobj->Insert(45);
    bobj->Insert(66);
    bobj->Insert(90);
    bobj->Insert(88);

    bobj->DisplayInorder();
    bobj->DisplayPreorder();
    bobj->DisplayPostorder();

    bRet = bobj->Search(66);
    if(bRet)
    {
        cout<<"Element is Present\n";
    }
    else
    {
        cout<<"There is no such Element\n";
    }

    bobj->CountAll();

    return 0;
}