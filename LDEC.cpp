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
        
    Remover um valor da lista ok
    Remover todos os valores da lista ok
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
    // ponteiro para o inicio, default NULL
    NodeD* first = NULL;
};

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

    if (l->first == NULL)
    {
        return result;
    }
    
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
        cout << "Valor '" << v << "' nao localizado para remocao\n";
        return false;
    }
    
    // remoção do elemento da ponta direita...
    if (result->next == l->first && result != l->first)
    {
        l->first->prev = result->prev;
        result->prev->next = l->first;
        return true;
    }
    
    // remoção do elemento first...
    // verificar se há outro ou só um elemento na lista
    if (result == l->first)
    {
        //verifica se há outro além dele, nesse caso remove se só há um;
        if (result->next == l->first && result->prev == l->first)
        {
            
            delete l->first;
            l->first = NULL;
            return true;
        }
        else
        {
            //faz o first ser o proximo da lista;
            l->first = l->first->next;

            // como agora ele não é o first pode chamar o método novamente para cuidar
            // dessa remoção, ou será meio ou direita;
            return removeValor(l, v);
        }
    }

    
    // caso de remoção de elemento ao meio
    result->next->prev = result->prev;
    result->prev->next = result->next;
    
    delete result;
    
    return true;
}



int main()
{
    ListaDEC* listaDEC = new ListaDEC;
    
    describeAll(listaDEC);
    insert(listaDEC, 'A');
    insert(listaDEC, 'B');
    insert(listaDEC, 'C');

    
    describeAll(listaDEC);
    cout << removeValor(listaDEC, 'A') << endl;
    describeAll(listaDEC);
    cout << removeValor(listaDEC, 'B') << endl;
    describeAll(listaDEC);
    cout << removeValor(listaDEC, 'C') << endl;
    describeAll(listaDEC);

    cout << removeValor(listaDEC, 'C') << endl;
    describeAll(listaDEC);
    
   
    //fim do programa, vai liberar toda a memória
    delete listaDEC;
    return 0;
}
