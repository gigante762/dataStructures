#include <iostream>
using namespace std;

/* 
    Aplicação de lista encadeada em uma lista ordenada de valores;
    Autor: Kevin R.
 */

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

    insert(lo,3);
    insert(lo,1);
    insert(lo,7);
    insert(lo,2);
    insert(lo,6);    
    show(lo);

    remove(lo,6);
    show(lo);

    remove(lo,2);
    show(lo);

    return 0;
}

void insert(OrdList &list, ItemType n)
{
    if (list.head == NULL || n <= list.head->data)
    {
        Node *newnode = new Node;
        newnode->data = n;
        newnode->next = list.head;
        list.head = newnode;
    }
    else
    {
        Node *aux;
        aux = list.head;

        while (aux->next != NULL &&  n > aux->next->data)
        {
            aux = aux->next;
        }

        Node *newnode = new Node;
        newnode->data = n;
        newnode->next = aux->next;
        aux->next = newnode;

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


    while (aux->next != NULL && aux->next->data != n && aux->next->data < n)
    {
        aux = aux->next;
    }

    if (aux->next == NULL)
        return ;

    if(aux->next->data == n)
    {
        Node *tmp = aux->next;
        aux->next = aux->next->next;

        delete tmp;
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