#include <iostream>
using namespace std;


typedef char ItemType;

struct Node{
    ItemType v;
    Node* next = NULL;
};


bool isEmpty(Node *p)
{
    return (p == NULL);
}

bool isFull(Node *p)
{
    try
    {
        Node *newnode = new Node;
        delete newnode;
        return false;
    }
    catch(std::bad_alloc e)
    {
        return true;
    }
    
}

void push(Node* &p, ItemType n)
{
    if(!isFull(p))
    {
        Node *newnode = new Node;

        newnode->v = n;
        newnode->next = p;

        p = newnode;
    }
    else
    {
        cout << "Stack cheia! " << endl;
    }


}

ItemType pop(Node* &p)
{
    if(!isEmpty(p))
    {

        Node *tmpnode  = p;
        ItemType tmp = tmpnode->v;
        p = p->next;
        delete tmpnode;

        return tmp;
    }
    else
    {
        cout << "Stack vazia!" << endl;
        ItemType n;
        return n;
    }

}

void describe(Node *p)
{
    if (p == NULL)
    {
        cout << "Stack Vazia" << endl;
        return;
    }

    cout << "Stack: " ;
    while(p != NULL)
    {
        cout << p->v;

        p = p->next;
    }
   cout << endl;
}

int main()
{

    Node *stack = NULL;

    ItemType c;

    cin.get(c);

    while(c != '\n')
    {
        push(stack,c);
        cin.get(c);
    }
    
    
    while(!isEmpty(stack))
    {
        cout << pop(stack);
    }

    

    return 0;
}