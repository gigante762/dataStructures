#include <iostream>

using namespace std;

void describe(string v[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << endl;
    }
}

void describe(int v[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void buble_sort_string(string v[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void bubble_sort_int(int v[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void improvedBubble(int array[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        bool ordenado = true;
        //cout << i + 1 << endl;
        for (int j = 0; j < tam - 1; j++)
        {
            //cout << i+1 << " | " << j <<  endl;
            ordenado = (ordenado && (array[j] <= array[j + 1]));
            if (array[j] > array[j + 1])
            {
                //printf("\t troca %d <-> %d\n", array[j], array[j + 1]);
                swap(array[j], array[j + 1]);
            }
        }
        if (ordenado)
        {
            //cout << "Array ja ordenada, pode interromper." << endl;
            return;
        }
    }
}

int main()
{
    string v[] = {"douglas", "abelha", "melhor", "azul", "absurdo" ,"conejo", "bajo"};

    int ints[] = {5, 1, 2, 6, 3};
    int tam = sizeof(ints)/ sizeof(int);

    describe(ints,tam);

    improvedBubble(ints, tam);
    describe(ints, tam);

    /* int x = 20, y = 14;

    cout << x << " " << y << endl;

    swap(x,y);

    cout << x << " " << y << endl ; */

    return 0;
    /*  describe(v,3);

    buble_sort_int(v,3);

    describe(v,3); */

    return 0;
}
