#include <iostream>
using namespace std;

#define TAM 5
typedef char ItemType;

struct Queue
{
    ItemType data[TAM];
    int ini = -1 , fim = -1;
    int length = TAM;
};

bool isFull(Queue p)
{
    return (p.ini == 0 && p.fim == p.length - 1);
}

bool isEmpty(Queue p)
{
    return (p.ini == -1);
}

void push(Queue &p, ItemType n)
{
    if (isFull(p))
    {
        cout << "Fila cheia.\n";
    }
    else
    {
        // inserção do 'primeiro valor'
        if (p.ini == -1)
        {
            p.ini = 0; // set o valor ini pra primeira posição do array
        }

        p.fim++; // e coloca o fim uma posição a frente
        p.data[p.fim] = n; // estando no 0, coloca o valor na posição
        //cout << n << " ";
    }
}

ItemType pop(Queue &p)
{

    if (isEmpty(p))
    {
        cout << "Queue is empty!!\n" << endl;
        return false;
    }
    else
    {
        ItemType n = p.data[p.ini]; // o valor que está na posição n != -1;
        if (p.ini >= p.fim)
        { //only one element in queue
            p.ini = -1;
            p.fim = -1;
        }
        else
        {
            p.ini++;
        }
        cout << "Deleted => " << n << " from p.data\n";
        return n;
    }
}

void desc(Queue p)
{
    int i;
    if (isEmpty(p))
    {
        cout << "Queue is Empty!!\n";
    }
    else
    {
        cout << "p.ini = " << p.ini << endl;
        cout << "Queue elements : ";

        for (i = p.ini; i <= p.fim; i++)
            cout << p.data[i] << " ";
        cout << endl;
        cout << "p.fim = " << p.fim << endl;
    }
}


int main()
{
    Queue f1;
    //cout << f1.ini << ',' << f1.fim<< endl;


    push(f1,'a');
    push(f1,'b');
    push(f1,'c');
    push(f1,'d');
    push(f1,'e');
    desc(f1);
    pop(f1); // libero espaço pro r entrar
    desc(f1);
    push(f1,'r'); // teoricamente acessa, mas no indice errado.
    // ele coloca no indice [5] sendo que o máximo permitido é o [4]
    desc(f1);
    pop(f1);
    pop(f1);
    pop(f1);
    push(f1,'m'); // aqui ele segue colocando [6]
    push(f1,'n'); //[7]
    push(f1,'o'); // [8]
    desc(f1);
    
    // faço com % do valor pra sempre pegar o indice valid
    // EX: se o meu contador está 5 eu acesso com [i%5] => 0 que é valido...


    
}
