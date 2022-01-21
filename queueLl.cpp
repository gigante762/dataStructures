#include <iostream>
using namespace std;


/*  Fila com lista encadeada
    Autor: Kevin R.
*/

typedef char ItemType;

struct Node
{
    ItemType v;
    struct Node *next;
};

/* Fila */
struct Queue{
    Node* ini = NULL;
    Node* fim = NULL;
};

bool isFull(Queue* f)
{ 
    try{
        Node *newnode = new Node;
        
        delete newnode;
        return false;
    }
    catch(std::bad_alloc e)
    {
        cout << "Memoria cheia!" << endl;
        return true;
    }

}

bool isEmpty(Queue* f)
{ 
    return (f->ini == f->fim) && (f->fim == NULL);
}

void push(Queue* f, ItemType v)
{
    if(!isFull(f))
    {
        Node* newnode = new Node;
        newnode->v = v;
        newnode->next = NULL;

        if (f->fim == NULL)
        {
            f->fim = newnode;
            f->ini = newnode;
        }
        else
        {
            f->fim->next = newnode;
            f->fim = newnode;
        }
    }
}

void describe(Queue* f)
{

    cout << "Fila: ";
    for (Node* aux = f->ini; aux != NULL; aux = aux->next)
    {
        cout << aux->v << " ";
    }
    cout << endl;
    
}

ItemType pop(Queue* f)
{
    if (!isEmpty(f))
    {
        Node* aux = f->ini;
        f->ini = f->ini->next;
        ItemType c = aux->v;

        delete aux;

        if (f->ini == NULL)
            f->fim = NULL;

        return c;
    }
    else {
        cout << "fila vazia!" << endl;
        return false;
    }
    
}

int main()
{
    Queue* fila  = new Queue;

    ItemType c;
    cin.get(c);

    while(c != '\n')
    {
        push(fila,c);
        cin.get(c);
    }
    
    
    while(!isEmpty(fila))
    {
        cout << pop(fila);
    }

    delete fila;
    return 0;
}