#include <iostream>
using namespace std;

#define TAM 5
typedef char ItemType;

struct Stack
{
    ItemType data[TAM];
    int length = 0 ;

};

bool isEmpty(Stack &p)
{
    return ( p.length == 0 );
}

bool isFull(Stack &p)
{
    return ( p.length == TAM );
}

void push(Stack &p, ItemType n)
{
    if (!isFull(p))
    {
        p.data[p.length] = n;
        p.length++;
    }
    else{
        cout <<  "Stack cheia!"<<endl;
    }
}

ItemType pop(Stack &p)
{
    if (!isEmpty(p))
    {
        int tmp = p.data[p.length-1];
        p.length--;
        return tmp;
    }
    else
    {
        cout <<  "Stack vazia!"<<endl;
        return false;
    }
}

void describe(Stack p)
{
    if (isEmpty(p))
    {
        cout << "Stack: vazia" << endl;
        return;
    }

    cout << "Stack: ";
    for (int i = 0; i < p.length; i++)
    {
        cout << p.data[i] << " ";
    }
    cout << endl;
}

int main()
{

    Stack p;
    describe(p);

    ItemType c;

    cin.get(c);

    while(c != '\n')
    {
        push(p,c);
        cin.get(c);
    }
    
    
    while(!isEmpty(p))
    {
        cout << pop(p);;
    }

    

    return 0;
}