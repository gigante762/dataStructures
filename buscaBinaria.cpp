#include <iostream>

using namespace std;


void printArray(int array[], int tam)
{
    cout << "|";
    for (int i = 0; i < tam; i++)
    {
        cout << " " << array[i] << " |";
    }
    cout << endl;
}

void printArray(int array[], int ini, int fim)
{
    cout << "|";
    for (int i = ini; i < fim; i++)
    {
        cout << " " << array[i] << " |";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void selectSort(int v[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int menor = i;
        for (int j = i; j < size; j++)
            if (v[j] < v[menor])
               menor = j;
               
        swap(v[i],v[menor]);
        
    }
}

void selectBidirect(int array[], int tam)
{

    int start = 0;
    int end = tam;

    while(end-start > 2)
    {
        //printf("end-start: %d-%d => %d\n", end,start,(end-start));
        int imaior = end-1;
        int imenor = start;

        //printf("maior: %d\n", array[imaior]);
        //printf("menor: %d\n", array[imenor]);

        for (int j = start; j < end; j++)
        {

            if (array[j] > array[imaior])
            {
                //printf("\t%d > %d\n", array[j], array[imaior]);
                imaior = j;
                //printf("\tmaior: %d\n", array[imaior]);
            }

            if (array[j] < array[imenor])
            {
                //printf("\t%d < %d\n", array[j], array[imaior]);
                imenor = j;
                //printf("\tmenor: %d\n", array[imenor]);
            }
        }

        if (start == imaior)
        {
            imaior = imenor;
        }

        //printf("start -> imenor: %d -> %d \n", array[start], array[imenor]);
        swap(array[start], array[imenor]);
        //describe(array, tam);
        //printf("end -> imaior: %d -> %d \n", array[end-1], array[imaior]);
        swap(array[end-1], array[imaior]);
        //describe(array, tam);
        start++;
        end--;

        //describe(array, tam);
    }

    if (tam == 2 && array[0] > array[1])
    {
        swap(array[0], array[1]);
    }
}


bool buscaBinariaR(int array[], int v, int min, int max)
{

    int index = (min+max)/2;

    cout << "Procurando "<< v << " no indice: " << index << endl;"\t";
    printArray(array,min,max);

    //cout << " no indice: " << index << endl;
    if (min > max)
        return false;

    if (array[index] == v)
    {
        cout << "encontrei\n";
        return true;

    }
    else if (array[index] > v)
    {
        //procura na sub da direita
        return buscaBinariaR(array, v, min, index-1);
    }
    else if (array[index] < v)
    {
        //procura na sub da esquerda
        return buscaBinariaR(array,  v, index+1, max);
    }
    
    cout << "nao encontrei\n";
    return false;
}

// busca não recursiva
bool buscaBinariaNr(int array[], int v, int min, int max)
{
    int mmin = min;
    int mmax = max;

    while (mmin < mmax)
    {
        int index = (mmin+mmax)/2;

        cout << "Procurando "<< v << " no indice: " << index << endl;"\t";
        printArray(array,mmin,mmax);

        if (array[index] == v)
        {
            cout << "encontrei\n";
            return true;

        }
        else if (array[index] > v)
        {
            //procura na sub da direita
            mmax = index-1;
            //return buscaBinariaR(array, v, min, index-1);
        }
        else if (array[index] < v)
        {
            mmin = index+1;
            //procura na sub da esquerda
            //return buscaBinariaR(array,  v, index+1, max);
        }

    }
    cout << "nao encontrei\n";
    return false;
}


int main()
{
    int array[] = {7, 6, 10, 5, 9, 2, 1, 15, 8};
    int tam = sizeof(array) / sizeof(int);

    cout << "Array incial: ";
    printArray(array, tam);

    selectBidirect(array, tam);
    cout << "Array final:  ";
    printArray(array, tam);

    cout << (int) buscaBinariaNr(array, 10, 0, tam) << endl;

    return 0;
}