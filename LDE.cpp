#include <iostream>
using namespace std;

/* 
    Lista duplamente encadeada inspirada nos operações em Js.
    Pop, Push, Shift and Unshift Array Methods in JavaScript
    push(): Add items to the end of an array.
    pop(): Remove an item from the end of an array.
    unshift(): Add items to the beginning of an array.
    shift(): Remove an item from the beginning of an array.

    Autor: Kevin R.
*/

typedef char ItemType;

//Node duplamente encadeado
struct NodeD{
    ItemType v;
    NodeD* prev = NULL;
    NodeD* next = NULL;
};

//Lista duplamente encadeada
struct ListaDE{
    //ponteiro para o inicio, default NULL
    NodeD* front = NULL;

    //ponteiro para o final, default NULL
    NodeD* back = NULL;
};

/* Anda mostrando os valores do front pro back */
void describeFtoB(ListaDE* l){
    cout << "Lista FtoB: ";
    for (NodeD* aux = l->front; aux != NULL; aux = aux->next)
        cout << aux->v << " ";
    cout << endl;
}

/* Anda mostrando os valores do back pro front */
void describeBtoF(ListaDE* l){
    cout << "Lista BtoF: ";
    for (NodeD* aux = l->back; aux != NULL; aux = aux->prev)
        cout << aux->v << " ";
    cout << endl;
}

/* Retorna se a lista está vazia */
bool isEmpty(ListaDE* l)
{
    return (l->back == NULL && l->front == NULL);
}

/* Retorna se a lista está cheia */
bool isFull(ListaDE* l)
{
    //Cria um novo node;
    try{
        NodeD* newnode = new NodeD;
        delete newnode;
        return false;
    }catch(std::bad_alloc e)
    {
        cout << "Memoria cheia" << endl;
        return true;
    }
}

/* Add items to the end of an list */
void push(ListaDE*& l, ItemType v)
{
    //Cria um novo node;
    if (isFull(l))
    {
        cout << "Memoria cheia" << endl;
        return;
    }

    NodeD* newnode = new NodeD;
    newnode->v = v;

    //caso nao seja null o back,
    //ajudas o next pra apontar para esse novo noded
    if (l->back != NULL)
        l->back->next = newnode;

    //ajusta os ponteiros, o novo aponta pro que ja estava,
    // e back agora é o ultimo
    newnode->prev = l->back;
    l->back = newnode;

    if (l->front == NULL)
        l->front = newnode;
    
}

/* Add items to the beginning of an array */
void unshift(ListaDE*& l, ItemType v)
{
    if (isFull(l))
    {
        cout << "Memoria cheia" << endl;
        return;
    }

    NodeD* newnode = new NodeD;
    newnode->v = v;

    //ajusta os ponteiros
    newnode->next = l->front;

    if (l->front != NULL)
        l->front->prev = newnode;
    else
        l->back = newnode;

    l->front = newnode;
}

/* Remove an item from the beginning of an array.*/
ItemType shift(ListaDE*& l)
{

    if (!isEmpty(l))
    {
        ItemType r = l->front->v;
        
        if (l->front->next != NULL)
        {
            l->front = l->front->next;
            delete l->front->prev;
            l->front->prev = NULL;

        }
        else
        {
            delete l->front;
            l->front = NULL;
            l->back = NULL;
        }

        return r;
    }

    cout << "Lista vazia\n";
    return false;
    

}

/* Remove an item from the end of an list */
ItemType pop(ListaDE*& l)
{
    if (!isEmpty(l))
    {
        if (l->back->prev != NULL)
        {
            l->back = l->back->prev;
            ItemType r = l->back->next->v;
            delete l->back->next;

            //ajusta o ponteiro
            l->back->next = NULL;

            return r;
        }

        //else implicito
        ItemType r = l->back->v;
        delete l->back;
        l->back = NULL;
        l->front = NULL;

        return r;
    }
    else
    { 
        cout << "Lista vazia\n";
        return false;
    }
}

/* Procura o valor v na lista e caso encontre retorna o noded
caso contrario retorna o noded com null; */
NodeD* findValue(ListaDE* l, ItemType v)
{
    for (NodeD* aux = l->front; aux != NULL; aux = aux->next)
    {
        if(aux->v == v)
            return aux;
    }

    NodeD* r = NULL;
    return r;
}

/* Insere um noded após outro noded */
void insertAfter(ListaDE*& l, NodeD* n, ItemType v)
{
    if (isFull(l))
    {
        cout << "Memoria cheia" << endl;
        return;
    }

    NodeD* newnode = new NodeD;
    newnode->v = v;

    //ajusta o ponteiro do newnode;
    newnode->prev = n;
    newnode->next = newnode->prev->next;

    // verifico se é o noded é o back da lista
    if (l->back == n)
        l->back = newnode;

    //ajusta o found
    n->next = newnode;

    //ajusta o 'da frente'
    if (newnode->next)
        newnode->next->prev = newnode;
}

/* Insere um noded antes outro noded */
void insertBefore(ListaDE*& l, NodeD* n, ItemType v)
{
    if (isFull(l))
    {
        cout << "Memoria cheia" << endl;
        return;
    }

    NodeD* newnode = new NodeD;
    newnode->v = v;

    newnode->next = n;
    newnode->prev = n->prev;

    if (newnode->prev != NULL)
    {
        newnode->prev->next = newnode;

    }

    n->prev = newnode;

    if (l->front == n)
        l->front = newnode;
    
}

int main()
{
    ListaDE* listaDE = new ListaDE;

    //preenche de A - Z
    for (short int i = 'A'; i <= 'Z'; i++)
        push(listaDE, (char) i);

    describeFtoB(listaDE); cout << endl;

    /* procurar o G e inseri o 7 depois do G */
    if (NodeD* found = findValue(listaDE, 'G'))
        insertAfter(listaDE, found, '7');

    /* procurar o Z e inserir o 9 depois do Z, realizando o ajuste nos ponteiros */
    if (NodeD* found = findValue(listaDE, 'Z'))
        insertAfter(listaDE, found, '9');

    // insere o 5 no final
    push(listaDE, '5');
    describeFtoB(listaDE);cout << endl;

    /* Remove os elementos da lista */
    cout << "Pops: ";
    while (!isEmpty(listaDE))
        cout << pop(listaDE) << " ";
    cout << endl;

    describeFtoB(listaDE);
    //verifica o ajuste dos ponteiros internos
    cout << listaDE->back << endl;
    cout << listaDE->front << endl << endl;

    /* ------------------------------------------ */

    /* Inserir no começo */
    unshift(listaDE, '1');
    unshift(listaDE, '3');
    unshift(listaDE, '5');
    unshift(listaDE, '6');
    unshift(listaDE, '2');
    describeFtoB(listaDE); cout << endl;

    /* Remover no começo */
    cout << "Pops: ";
    while (!isEmpty(listaDE))
        cout << shift(listaDE) << " ";
    cout << endl;

    describeFtoB(listaDE); cout << endl;

    /* Inserir antes */

    // preenche com unshift de Z - A;
    for (short int i = 'Z'; i >= 'A' ; i--)
        unshift(listaDE, (char) i);

    describeFtoB(listaDE); cout << endl;

    /* procurar o G e inserir o 7 antes do G */
    if (NodeD* found = findValue(listaDE, 'G'))
        insertBefore(listaDE, found, '7');

    /* procurar o A e inserir o 3 antes do A */
    if (NodeD* found = findValue(listaDE, 'A'))
        insertBefore(listaDE, found, '3');

    // insere o 5 no inicio
    unshift(listaDE, '5');
    describeFtoB(listaDE); cout << endl;

    /* Remover no começo  */
    cout << "Pops: ";
    while (!isEmpty(listaDE))
        cout << shift(listaDE) << " ";
    cout << endl;
    describeFtoB(listaDE);

    //verifica o ajuste dos ponteiros internos
    cout << listaDE->back << endl;
    cout << listaDE->front << endl << endl;

    
    delete listaDE;
    return 0;
}
