#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
};

class BST
{
    private:
       struct node *first;
       int iCount = 0; 

    public:
        BST();
        void Insert(int);
        void Inorder(struct node *); 
        void DisplayInorder();  
        void Preorder(struct node *); 
        void DisplayPreorder();    
        void Postorder(struct node *);   
        void DisplayPostorder();  
        bool Search(int);
        int Count(struct node *);
        int CountLeafNodes(struct node *);
        int CountParentNodes(struct node *);
        void CountAll();
};

BST :: BST()
{
    this->first = NULL;
    this->iCount = 0;
}

void BST :: Insert(int no)
{
    struct node * temp = NULL;
    struct node * newn = NULL;

    newn = new node;
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

void BST :: Inorder(struct node * first)
{
    struct node *temp = first;

    if(temp != NULL)
    {
        Inorder(temp->lchild);
        cout<<temp->data<<"\t";
        Inorder(temp->rchild);
       
    }
}

void BST :: DisplayInorder()
{
    cout<<"Inorder Traversal : \n";
    Inorder(first);
    cout<<"\n";
}

void BST :: Preorder(struct node * first)
{
    struct node *temp = first;

    if(temp != NULL)
    {
        cout<<temp->data<<"\t";
        Preorder(temp->lchild);
        Preorder(temp->rchild);
       
    }
}

void BST :: DisplayPreorder()
{
    cout<<"Preorder Traversal : \n";
    Preorder(first);
    cout<<"\n";
}

void BST :: Postorder(struct node * first)
{
    struct node *temp = first;

    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout<<temp->data<<"\t";
       
    }
}
void BST :: DisplayPostorder()
{
    cout<<"Postorder Traversal : \n";
    Postorder(first);
    cout<<"\n";
}

bool BST :: Search(int no)
{
    bool bFlag = false;
    int TimeComplexity = 0;
    struct node *temp = first;

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

int BST :: Count(struct node *first)
{
    int static iCount = 0;
    struct node *temp = first;

    if(temp != NULL)
    {
        iCount++;

        Count(first->rchild);
        Count(first->lchild);
    }

    return iCount;
}

int BST :: CountLeafNodes(struct node *first)
{
    struct node *temp = first;
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

int BST :: CountParentNodes(struct node *first)
{
    struct node * temp = first;
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

void BST :: CountAll()
{
    cout<<"Number of Nodes are : "<<Count(first)<<"\n";
    cout<<"Number of Leaf Nodes are : "<<CountLeafNodes(first)<<"\n";
    cout<<"Number of Parent Nodes are : "<<CountParentNodes(first)<<"\n";
}

int main()
{
    BST *bobj = new BST();

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