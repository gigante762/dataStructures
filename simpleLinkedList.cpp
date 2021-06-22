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

    // mostra a estrutura de dados
    describe_node(firts);

    add(firts, 40);
    add(firts, 50);

    describe_node(firts);

    cout << "======\n";

    // vejo se ha um numero na linked-list
    int numeroProcurado = 20;

    if ( have(firts, numeroProcurado) )
    {
        cout << "Tem o numero '" << numeroProcurado <<"'\n";
    }
    else
    {
        cout << "não tem o numero '" << numeroProcurado <<"'\n";
    }

    return 0;

}

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



