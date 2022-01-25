#include <iostream>
using namespace std;

#define OS 'windows' // windows , linux

/* 
    Lista duplamente encadeada circular inspirada nos operações em Js.
    Pop, Push, Shift and Unshift Array Methods in JavaScript
    push(): Add items to the end of an array.
    pop(): Remove an item from the end of an array.
    unshift(): Add items to the beginning of an array.
    shift(): Remove an item from the beginning of an array.

    Autor: Kevin R.
*/

/* 

    Check list de desenvolvimento. Em ordem de prioridade.
 
    ---- Operações da lista ----
    Inserir valores na lista ok
    Inserir mais de uma valor na lista, 1 2 3 ... ok
    
    Buscar um valor na list -> encontrar; ok
    Buscar um valor na list -> retornar; ok
        Atualizar um valor da lista ok
        
    Remover um valor da lista
    Remover todos os valores da lista
    --------

    ----- Projeto ----- 
    
    ---------

*/

typedef char ItemType;

//Node duplamente encadeado
struct NodeD{
    ItemType v;
    NodeD* prev = NULL;
    NodeD* next = NULL;
};

//Lista duplamente circular
struct ListaDEC{
    //ponteiro para o inicio, default NULL
    NodeD* first = NULL;
};


/* Anda mostrando os valores do front pro back */
/*
void describeFtoB(ListaDE* l){
    cout << "Lista FtoB: ";
    for (NodeD* aux = l->front; aux != NULL; aux = aux->next)
        cout << aux->v << " ";
    cout << endl;
}/*

/* Anda mostrando os valores do back pro front */
/* 
void describeBtoF(ListaDE* l){
    cout << "Lista BtoF: ";
    for (NodeD* aux = l->back; aux != NULL; aux = aux->prev)
        cout << aux->v << " ";
    cout << endl;
}
*/


/*Mostra todos os valores partindo de l->first*/
void describeAll(ListaDEC* l)
{
    
    if(l->first == NULL)
    {
        cout << "Lista vazia\n";
        return;
    }
    
    NodeD* aux = l->first;
    
    do{
         cout << aux->v << " ";
         aux = aux->next;
    }while(aux != l->first);
    
    
    cout << endl;
}

/* Retorna se a lista está vazia */
bool isEmpty(ListaDEC* l)
{
    return (l->first == NULL);
}

/* Retorna se a lista está cheia */
bool isFull(ListaDEC* l)
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
/*
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
*/

/* Add items to the beginning of an array */
/*
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
*/

/* Remove an item from the beginning of an array.*/
/*
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
*/

/* Remove an item from the end of an list */
/*
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
*/

/* Procura o valor v na lista e caso encontre retorna o noded
caso contrario retorna o noded com null; */
/*
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
*/

/* Insere um noded após outro noded */
/*
void insertAfter(ListaDEC*& l, NodeD* n, ItemType v)
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
*/

/* Insere um noded antes outro noded */
/*
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
*/





/*Funçõe para a Lista Duplamente Encadeada Circular*/

/*insert, insere um valor na lista após o node first da lista*/
void insert(ListaDEC*& l,  ItemType v)
{
    
    if (isFull(l))
    {
        cout << "Memoria cheia" << endl;
        return;
    }
    
    // checar o primeiro elemento
    if (l->first == NULL)
    {
        NodeD* newnode = new NodeD;
        newnode->v = v;
        
        // ajusta os ponteiros
        newnode->next = newnode;
        newnode->prev = newnode;
        
        l->first = newnode;
    }
    else
    {
        NodeD* newnode = new NodeD;
        newnode->v = v;
        
        newnode->next = l->first->next;
        l->first->next = newnode;
        
        newnode->next->prev = newnode;
        
        newnode->prev = l->first;
        
        
    }
    
    
}


/*Buscar um valor na lista e retorna uma NodeD*/
NodeD* buscarValor(ListaDEC* l, ItemType v)
{
    NodeD* result = NULL;
    
    NodeD* aux = l->first;
    
    do{
        if(aux->v == v)
        {
            result = aux;
        }
         aux = aux->next;
    }while(aux != l->first);
    
    
    return result;
}

/*Atualizar um valor da lista*/
NodeD* atualizarValor(ListaDEC*& l, ItemType v, ItemType a)
{
    NodeD* result = buscarValor(l, v);
    
    if(result)
    {
        result->v = a;
    }
    return result;
}

bool removeValor(ListaDEC*& l, ItemType v)
{
    
    NodeD* result = buscarValor(l, v);
    
    if (!result)
    {
        return false;
    }
    
    
    
    // remoção do elemento da ponta direita...    
    if (result->next == l->first)
    {
        l->first->prev = result->prev;
        result->prev->next = l->first;
        return true;
    }
    
    // remoção do elemento da ponta direita...
    
    
    // caso de remoção de elemento ao meio
    result->next->prev = result->prev;
    result->prev->next = result->next;
    
    
    delete result;
    
    return true;
}



int main()
{
    ListaDEC* listaDEC = new ListaDEC;
    
    insert(listaDEC, 'A');
    insert(listaDEC, 'B');
    insert(listaDEC, 'C');
    
    cout << removeValor(listaDEC, 'B') << endl;
    
    describeAll(listaDEC);
    
    
    

    delete listaDEC;
    return 0;
}
