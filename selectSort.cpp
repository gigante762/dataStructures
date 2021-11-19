#include <iostream>

using namespace std;


void describe(int v[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout  << endl;
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





int main()
{
   int v[] = {5,3,7,6,1,2,0,4,8,9};

   describe(v,10);
   selectBidirect(v,10);
   describe(v,10);


   return 0;
}
