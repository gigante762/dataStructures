#include <iostream>
using namespace std;

#define TAM 5
typedef char ItemType;

struct Queue
{
    ItemType data[TAM];
    // contadores positivos, visto que sempre o fim será >= ini.
    // Esse é o modo que eu penso.
    unsigned int ini = 0 , fim = 0;
    unsigned int length = TAM;
};

bool isEmpty(Queue p)
{
    // se estiverem na mesma posição, indica vazio.
    return (p.ini == p.fim);
}

bool isFull(Queue p)
{
    //se a difença do mais distante pro menor for igual ao tamanho.
    return (p.fim - p.ini) == p.length;
}

/* Adiciona sempre no final da fila */
void push(Queue &p, ItemType n)
{
    if (!isFull(p))
    {
        p.data[p.fim % p.length] = n;
        p.fim++;
    }
    else
    {
        cout << "Fila cheia." << endl;
    }
}

/* Retira sempre do inicio da fila, ou posição inicial da fila. */
ItemType pop(Queue &p)
{
    if (!isEmpty(p))
    {
        p.ini++;

        //diminui o contador por um valor equivalente pra não dar integer-overflow,
        //teoricamente se os valores seguirem almentando isso poderia ocorrer
        if (p.ini > p.length && p.fim > p.length)
        {
            p.ini -= p.length;
            p.fim -= p.length;
        }
        return p.data[(p.ini-1) % p.length]; // % pra ficar dentro do range
    }
    else
    {
        cout << "Fila vazia." << endl;
        return false;
    }
}

void desc(Queue p)
{
    cout << p.ini << ',' << p.fim<< endl;
    for (int i = p.ini; i < p.fim; i++)
    {
        cout << p.data[i % p.length] << ' ';
    }
    cout << endl;
    
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
    push(f1,'r'); // fila cheia
    desc(f1);
    pop(f1);
    desc(f1);
    
    //treta
    push(f1,'f');
    desc(f1);
    pop(f1);
    pop(f1);
    pop(f1);
    desc(f1);
    pop(f1);
    pop(f1);
    desc(f1);
    pop(f1);

    cout << "-------------------\n";

    push(f1, 'a');
    push(f1, 'b');
    push(f1, 'c');
    push(f1, 'd');
    push(f1, 'e');
    desc(f1);


    

    //cout << pop(f1) << endl;
    //cout << "pop: " << pop(f1) << endl;
    //cout << pop(f1) << endl;
   /*  f1.ini = 0;
    f1.fim = 4; */


   /*  describe(f1);
    cout << f1.ini << ',' << f1.fim<< endl;

    ItemType c;
    cin.get(c);

    while(c != '\n')
    {
        push(f1,c);
        cin.get(c);
        describe(f1);
    }
    
    
    while(!isEmpty(f1))
    {
        cout << pop(f1);
    } */

    

    return 0;
}