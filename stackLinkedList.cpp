#include <iostream>
using namespace std;

typedef char ItemType;

struct Node{
    ItemType v;
    Node* next = NULL;
};

struct Stack{
    Node* node = NULL;
};

bool isEmpty(Stack *p)
{
    return (p->node == NULL);
}

bool isFull(Stack *p)
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

void push(Stack* &p, ItemType n)
{
    if(!isFull(p))
    {
        Node *newnode = new Node;

        newnode->v = n;
        newnode->next = p->node;

        p->node = newnode;
    }
    else
    {
        cout << "Stack cheia! " << endl;
    }


}

ItemType pop(Stack* &p)
{
    if(!isEmpty(p))
    {

        Node *tmpnode  = p->node;
        ItemType tmp = tmpnode->v;
        p->node = p->node->next;
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

/**
 * Função que exibe na tela uma representação da pilha.
 */
void describe(Stack *p)
{
    Node* aux = p->node;

    if (aux == NULL)
    {
        cout << "Stack: Vazia" << endl;
    }
    else
    {
        cout << "Stack: " ;

        for(; aux != NULL; aux = aux->next)
        {
            cout << aux->v << " ";
        }
        
        cout << endl;
    }
}

/* Retorna a quantidade de itens na stack */
int stackLenght(Stack* p)
{
    int tam = 0;

    for(Node *aux = p->node; aux != NULL; aux = aux->next)
        tam++;

    return tam;
}

int main()
{
    
    //criação da pilha com o nome stack
    Stack *stack = new Stack;
    
    /* O processo abaixo lê caracteres até que seja diferente de '\n' ou Enter */
    ItemType c;
    cin.get(c);

    while(c != '\n')
    {
        push(stack,c);
        cin.get(c);
    }
    
    /* O processo abaixo desempilha os valores empilhados acima, e caso o número
    de caracteres empilhados seja maior que o tamanho da pilha será exibida uma mensagem
    informando que a pilha está cheia. */
   
    describe(stack);
    while(!isEmpty(stack))
    {
        cout << pop(stack);
    }
    
    delete stack;
    return 0;
}