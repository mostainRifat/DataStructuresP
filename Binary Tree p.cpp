#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int id;
    int value;
    node *Left;
    node *Right;
    node *parent;
};

class BinaryTree
{
public:
    node *root;

    BinaryTree()
    {
        root = NULL;
    }

    node *CreateNewNode(int id, int value)
    {
        node *newnode = new node;
        newnode->id = id;
        newnode->value = value;
        newnode->Left = NULL;
        newnode->Right = NULL;
        newnode->parent = NULL;
        return newnode;
    }

    void Insertion(int id, int value)
    {
        node *newnode = CreateNewNode(id, value);
        if (root == NULL)
        {
            root = newnode;
            return;
        }
        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *a = q.front();
            q.pop();

            if (a->Left != NULL)
            {
                q.push(a->Left);
            }
            else
            {
                // insert in the left child
                a->Left = newnode;
                newnode->parent = a;
                return;
            }

            if (a->Right != NULL)
            {
                q.push(a->Right);
            }
            else
            {
                // intsert in the right child
                a->Right = newnode;
                newnode->parent = a;
                return;
            }
        }
    }

    void BFS()
    {
        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *a = q.front();
            q.pop();

            int p = -1, l = -1, r = -1;
            if (a->Left != NULL)
            {
                l = a->Left->id;
                q.push(a->Left);
            }

            if (a->Right != NULL)
            {
                r = a->Right->id;
                q.push(a->Right);
            }

            if (a->parent != NULL)
                p = a->parent->id;

            cout << "Node id = " << a->id << " Left Child = " << l;
            cout << " Right Child = " << r << " Parent id = " << p << "\n";
        
        }
    }
    void DFS(node *a)
    {
        if (a == NULL)
            return;

        cout << a->id << " ";
        DFS(a->Left);
        DFS(a->Right);
    }

    void Search(node*a ,int value)
    {
        if(a==NULL)
            return ;
        
        if(a->value == value)
            cout<<a->id<<" ";

        Search(a->Left , value);
        Search(a->Right , value);
    }
};

int main()
{
    BinaryTree bt;
    bt.Insertion(0, 5);
    bt.Insertion(1, 10);
    bt.Insertion(2, 10);
    bt.Insertion(3, 9);
    bt.Insertion(4, 8);
    bt.Insertion(5, 5);
    bt.Insertion(6, 7);

    bt.BFS();
    cout<<"\n";
    bt.Search(bt.root,5);
    return 0;
}