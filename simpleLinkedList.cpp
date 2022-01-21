#include <iostream>
// DATA STRUCTURE LINKED-LIST

using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

struct LinkedList{
    Node *root = NULL;
};

// Prototypes
void describe_node(Node *node);
void add_tail(Node *node, int value);
void add_head(Node *&node, int value);
bool have(Node *node, int n);
void remove_val(Node *&node, int n);

// main
int main()
{
    //primeiro valor
    Node *first = new Node;
    first->value = 10;
    first->next = NULL;

    // adiciona os valores
    add_head(first, 20);
    add_head(first, 30);
    add_head(first, 40);

    describe_node(first);

    remove_val(first, 30);

    describe_node(first);

    cout << "======\n";

    // vejo se ha um numero na linked-list
    /*
    int numeroProcurado = 20;
    if ( have(firts, numeroProcurado) )
    {
        cout << "Tem o numero '" << numeroProcurado <<"'\n";
    }
    else
    {
        cout << "não tem o numero '" << numeroProcurado <<"'\n";
    }
    */
    return 0;
}

// mostra como está a estrutura de dados
void describe_node(Node *node)
{
    int contador = 1;

    for(Node *aux = node; aux != NULL ; aux = aux->next, contador++)
    {
        cout << contador;
        cout << " Adress: " << aux << endl;
        cout << "value: " << aux->value << endl;
        cout << "Next: " << aux->next << "\n\n";
    }

}

// adiciona um valor ao final da linked-list
void add_tail(Node *node, int value)
{
    //crio o novo list
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = NULL;

    //node auxiliar
    Node *aux = node;

    //link
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = newNode;
}
// adiciona um valor ao inicio da linked-list
void add_head(Node *&node, int value)
{
    //crio o novo list
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = node;

    //node auxiliar
    node = newNode;
}
// remove um valor da linked list se esse existir
void remove_val(Node *&node, int n)
{
    cout << "Pedido de remoção do valor: " << n <<endl;

    Node *aux = node;
    Node *previus = node;

    //se for o primeiro, o head da list vira o next do primeiro.
    if (node->value == n)
    {
        cout << "\t Encontrado mudando " << node << " para " << aux->next << endl;

        node = node->next;
        delete(aux); // o adress onde estava o node
        return;
    }
    // remove um node que possui o valor n
    while (aux->next != NULL)
    {
        aux = aux->next;

        if (aux->value == n)
        {
            cout << "\t Encontrado mudando " << previus->next << " para " << aux->next << endl;
            previus->next = aux->next;
            delete(aux); // o adress onde estava o node 'aux'
            return;
        }

        previus = aux;
    }
}
// verifica se existe o valor n na linked-list
bool have(Node *node, int n)
{
    Node *aux = node;

    if (aux->value == n)
    {
        return true;
    }

    while (aux->next != NULL)
    {
        aux = aux->next;

        if (aux->value == n)
        {
            return true;
        }
    }
    return false;
}
