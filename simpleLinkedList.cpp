#include <iostream>
// DATA STRUCTURE LINKED-LIST

using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

// Prototypes
void describe_node(Node *node);
void add(Node *node, int value);
bool have(Node *node, int n);
void remove_val(Node *&node, int n);

// main
int main()
{
    //primeiro valor
    Node *firts = new Node;
    firts->value = 10;
    firts->next = NULL;

    // adiciona os valores
    add(firts, 20);
    add(firts, 30);
    add(firts, 40);

    describe_node(firts);

    remove_val(firts, 40);

    describe_node(firts);

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
    Node *aux = node;

    int contador = 1;

    cout <<contador;
    cout << " Adress: " << aux << endl;
    cout << "value: " << aux->value << endl;
    cout << "Next: " << aux->next << "\n\n";

    while (aux->next != NULL )
    {
        aux = aux->next;
        contador ++;

        cout << contador;
        cout << " Adress: " << aux << endl;
        cout << "value: " << aux->value << endl;
        cout << "Next: " << aux->next << "\n\n";
    }

}

// adiciona um valor ao final da linked-list
void add(Node *node, int value)
{
    //crio o novo list
    Node *tmp = new Node;
    tmp->value = value;
    tmp->next = NULL;

    //node auxiliar
    Node *aux = new Node;
    aux = node;

    //link
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = tmp;
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
        node = aux->next;
        return;
    }

    // dai pra baixo preciso implementar


    while (aux->next != NULL)
    {
        aux = aux->next;

        if (aux->value == n)
        {
            cout << "\t Encontrado mudando " << previus->next << " para " << aux->next << endl;
            previus->next = aux->next;
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
