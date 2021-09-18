#include <iostream>
using namespace std;

#define TAM 30
typedef char ItemType;

struct Stack
{
    ItemType data[TAM];
    int length = 0 ;

};

bool isEmpty(Stack p)
{
    return ( p.length == 0 );
}

bool isFull(Stack p)
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

int prio(char op)
{
    switch(op)
    {
        case '(': return 1; break;
        case '+': return 2; break;
        case '-': return 2; break;
        case '*': return 3; break;
        case '/': return 3; break;
    }

    return 0;
}

bool isLetra(ItemType c)
{
    return (c >= 65 && c <= 65+26);

}

bool isOperator(ItemType c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int varsVal[26];

int getValFromVar(ItemType c)
{
    return varsVal[(int)c %  65 % 26];

}

void setValFromVar(ItemType c, int val)
{
    varsVal[(int)c %  65 % 26]  = val;
}


int* infixPrecendentToNpr(string exp, int &tamArrInt)
{
    
    Stack opStack;

    /* Contar os espacos */
    int tamArrBrace = 0;
    for (int i = 0; i < exp.length(); i++)
        if (exp[i] == '(' || exp[i] == ')' || exp[i] == ' ')
            tamArrBrace++;
    
    tamArrInt = (exp.length() - tamArrBrace);

    //cout << "TAM: " << tamArrInt << endl;
    int *arrInt = new int[tamArrInt];
    int index = 0;


    for (int i = 0; i < exp.length() ; i++)
    {
        
        char c = exp[i];
        if (isLetra(c))
        {
           arrInt[index] = c;
           index++;
           //cout << c;
        }
        else if (isOperator(c))
        {
            push(opStack,c);
            //cout << c;
        }
        else if (c == ')')
        {
            arrInt[index] = pop(opStack);
            index++;
        }
    }
    cout << endl;
    return arrInt;

}

int evalNPR(int op1, int op2, char op)
{

    switch(op)
    {
        case '+': {return op1 + op2; break;}
        case '-': {return op1 - op2; break;}
        case '*': {return op1 * op2; break;}
        case '/': {return op1 / op2; break;}
    }

    return -1;
}

int evaluateArrPointNpr(int *arrInt,int tamArrInt)
{
    Stack opStack;

    int *p = arrInt;
    for (int i = 0; i < tamArrInt; i++)
    {
        if (isLetra(*p))
        {
            push(opStack, getValFromVar(*p));
            //cout << "Emplihar: " << (char)*p << " = " << getValFromVar(*p) << endl;
            
        }
        else
        {
            int op2 = pop(opStack);
            int op1 = pop(opStack);

            //setValFromVar('.', evalNPR(op1,op2,(char) *p));
            int result = evalNPR(op1,op2,(char) *p);
            //cout << "Emplihar: " <<  result << endl;
            push(opStack, result);

        }
        p++;
       
    }

    return pop(opStack);
}

int main()
{
    /* 1. Inicie com uma pilha vazia. */
    string express = "((( A + B ) / ( C - D )) * E)";


    /* Vejamos um exemplo na expressão em NPR: AB+CD-/E*
        Vamos atribuir valores numéricos às variáveis da expressão a ser avaliada:
        A= 7; B= 3; C= 6; D= 4; E= 9. */

    setValFromVar('A',7);
    setValFromVar('B',3);
    setValFromVar('C',6);
    setValFromVar('D',4);
    setValFromVar('E',9);

    //string postfix = infixPrecendentToNpr(express);
    int tamArrInt = 0;
    int* postfixArrInt = infixPrecendentToNpr(express,tamArrInt);
    
    int *p = postfixArrInt;
    for (int i = 0; i < tamArrInt; i++)
    {
        cout << (char)*p;
       *p++;
    }
    cout << endl;
    
    cout << "RES: " << evaluateArrPointNpr(postfixArrInt, tamArrInt);
    

    delete[] postfixArrInt;



    
    

    

}