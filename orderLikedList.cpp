#include <iostream>
using namespace std;

typedef float ItemType;

struct Node {
    ItemType data;
    Node *next = NULL;
};

struct OrdList
{
    Node *head = NULL;
};

/* Prototypes */
void insert(OrdList &list, ItemType n);
void show(OrdList list);
void remove(OrdList &list, ItemType n);
bool have(OrdList list, ItemType n);
bool isEmpty(OrdList list);

int main()
{

    OrdList lo;

    /* int x;
    cin >> x;

    while (x != -1)
    {
        insert(lo,x);
        cin >> x;
    } */

    insert(lo,3);
    insert(lo,5);
    insert(lo,7);
    insert(lo,2);
    insert(lo,6);
    insert(lo,6);


    /* for (int i = 7; i < 100; i++)
    {
        insert(lo,i);
    } */
    
    show(lo);

    remove(lo,2);
    remove(lo,6);
    //remove(lo,10);
    show(lo);

    return 0;
}

void insert(OrdList &list, ItemType n)
{
    if (list.head == NULL)
    {
        Node *newnode = new Node;
        newnode->data = n;
        list.head = newnode;

        return;
    }

    if (n <= list.head->data)
    {
        Node *newnode = new Node;
        newnode->data  = n;
        newnode->next = list.head;

        list.head = newnode;

        return;
    }

    Node *aux, *prev;

    prev = list.head;
    aux = list.head;


    while (aux->data < n)
    {
        aux = aux->next;

        if (aux == NULL)
        {
            Node *newnode = new Node;
            newnode->data = n;
            prev->next = newnode;

            return;
        }

        if ( n > aux->data )
        {
            prev = prev->next;
        }
        else
        {
            Node *newnode = new Node;
            newnode->data = n;
            newnode->next = aux;
            prev->next = newnode;

            return;
        }
    }
}

void remove(OrdList  &list, ItemType n)
{
    if (list.head == NULL)
    {
        return ;
    }

    Node *aux = list.head;

    if (aux->data == n)
    {
        list.head = list.head->next;
        delete aux;
        return;
    }

    Node *prev = aux;

    while(aux != NULL )
    {
        if (n > aux->data)
            aux = aux->next;
        
        if ( aux->data == n)
        {
            Node *tmp = prev->next;
            prev->next = aux->next;
            delete tmp;
            return;
        }
        else if(n < aux->data)
        {
            return;
        }

        prev = prev->next;
    }
}

bool isEmpty(OrdList list)
{
    return (list.head == NULL);

}

bool have(OrdList list, ItemType n)
{
    if (isEmpty(list))
        return false;

    Node *aux = list.head;

    while(aux != NULL)
    {
        if (aux->data == n)
            return true;
        else if ( n < aux->data)
        {
            return false;
        }

        aux = aux->next;
    }

    return false;

}

void show(OrdList list){
    
    Node *aux = list.head;
    while(aux != NULL)
    {
        cout << aux->data <<" ";
        aux = aux->next;
    }

    cout << endl;
}