#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
};

class Tree
{
    node *root;
    public:
        Tree();
        void add(int);
        void del(int);
        void lookup(int);
        void preorder(node*);
        void show();
};

Tree::Tree()
{
    root = NULL;
}

void Tree::add(int e)
{
    node *ptr = new node;
    if(root==NULL)
    {
        ptr->val = e;
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
    }
    else
    {
        node *temp = new node;
        temp->val = e;
        temp->left = NULL;
        temp->right = NULL;
        ptr = root;
        while(true)
        {
            if(e <= ptr->val)
            {
                if(ptr->left != NULL)
                    ptr = ptr->left;
                else
                    break;
            }
            else
            {
                if(ptr->right != NULL)
                    ptr = ptr->right;
                else
                    break;
            }
        }
        if(e <= ptr->val)
            ptr->left = temp;
        else
            ptr->right = temp;
        cout<<"Value "<<e<<" successfully inserted as a child of "<<ptr->val<<endl;
    }
}

void Tree::del(int e)
{
    node *ptr = root;

}

void Tree::preorder(node *n)
{
    if(n==NULL)
        return;
    cout<<n->val<<"\t";
    preorder(n->left);
    preorder(n->right);
}

void Tree::show()
{
    preorder(root);
}

int main()
{
    Tree t;
    int ch, e;
    while(true)
    {
        cout<<"----------Menu----------\n";
        cout<<"1. Insert an element\n";
        cout<<"2. Delete an element\n";
        cout<<"3. Search an element\n";
        cout<<"4. Show preorder\n";
        cout<<"5. Exit program\n";
        cout<<"Enter choice here: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter the element to be inserted here: ";
                cin>>e;
                t.add(e);
                break;
            case 2:
                cin>>e;
                t.del(e);
                break;
//            case 3:
//                cin>>e;
//                t.lookup(e);
//                break;
            case 4:
                t.show();
                cout<<endl;
                break;
            case 5:
                exit(false);
                break;
            default:
                cout<<"Make a valid choice!\n";
        }
        cout<<endl;
    }

    return 0;
}
