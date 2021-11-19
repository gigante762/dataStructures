#include <iostream>
using namespace std;

#define TAM 5
typedef char ItemType;

struct Queue
{
    ItemType data[TAM];
    int ini = 0 , fim = 0;
    int length = TAM;
};

bool isEmpty(Queue p)
{

    return (p.ini == p.fim) && p.ini == 0;
}

bool isFull(Queue p)
{
    //return (p.fim - p.ini) == p.length;
    //return ( (p.fim +1) % p.length == p.ini);
    //return (p.ini == p.fim && p.ini != 0 && p.fim != 0) || (p.fim +1)%p.length == p.ini;
    //return (p.fim  % p.length == p.ini && p.fim != 0) || ((p.fim + 1)%p.length == p.ini) ;
    return ((p.fim % p.length) == p.ini) && p.fim != 0;
}

/* Adiciona sempre no final da fila */
void push(Queue &p, ItemType n)
{
    if (!isFull(p))
    {
        p.data[p.fim % p.length] = n;

        // quando puder alocar e for igual ao tamnho reduz o numero do contador
        if (p.fim == p.length)
        {
            p.fim = 0;
        }
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

        ItemType tmp = p.data[p.ini];
        p.ini++;

        p.ini = p.ini % p.length;


        if (p.ini == p.fim && isFull(p))
        {
            //levo os dois pra 0 0
            p.ini = 0;
            p.fim = 0;
        }
        /*
        if (p.ini == p.fim && p.ini != p.length)
        {
            ItemType tmp2 = p.data[p.ini];
            p.ini = 0;
            p.fim = 1;

            p.data[0] = tmp2;
        }
        else if (p.ini == p.fim && p.ini == p.length)
        {
            p.ini = 0;
            p.fim = 0;
        }
        */


        return tmp;
        //p.ini %= p.length *2; // reduz o tamanho do contador
        //return p.data[(p.ini-1) % p.length]; // % pra ficar dentro do range
    }
    else
    {
        cout << "Fila vazia." << endl;
        return false;
    }
}

void desc( Queue p)
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

    /*
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



    */
    //cout << pop(f1) << endl;
    //cout << "pop: " << pop(f1) << endl;
    //cout << pop(f1) << endl;
   /*  f1.ini = 0;
    f1.fim = 4; */


    //describe(f1);
    //cout << f1.ini << ',' << f1.fim<< endl;

    ItemType c;
    cin.get(c);

    while(c != '\n')
    {
        push(f1,c);
        cin.get(c);
        desc(f1);
    }

    while(!isEmpty(f1))
    {
        cout << pop(f1);
    }

    return 0;
}
