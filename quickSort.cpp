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

int partition(int arr[], int i, int s)
{
    //int pivot = arr[(i+s)/2];
    int pivot = arr[i];
    int b = i; //begin
    int e = s; //end

    while (b < e)
    {
        while (arr[b] <= pivot)
            b++;

        while (arr[e] > pivot)
            e--;

        /* cout << "pivot: " << pivot << endl;
        cout << "\tB: " << arr[b] << endl;
        cout << "\tE: " << arr[e] << endl; */

        if (b < e)
        {
            int tmp = arr[b];
            arr[b] = arr[e];
            arr[e] = tmp;
        }
    }

    //swap pivot and end;
    int tmp = arr[i];
    arr[i] = arr[e];
    arr[e] = tmp;

    return e;
}

void quickSortK(int arr[], int i, int s)
{
    if (i < s)
    {
        int loc = partition(arr, 0, s);
        quickSortK(arr, i, s - 1);
        quickSortK(arr, i + 1, s);
    }
}

void quickSort(int vetor[], int i, int s)
{
    int b = i, e = s;
    int pivot = vetor[((b + e) / 2)];
    //int pivot = vetor[b];
    while (b <= e)
    {
        while (vetor[b] < pivot)
            b++;
        while (vetor[e] > pivot)
            e--;
        if (b <= e)
        {
            int aux; // Variável auxiliar para as trocas
            aux = vetor[b];
            vetor[b] = vetor[e];
            vetor[e] = aux;
            e--;
            b++;
        }
    }
    if (e - i > 0)
        quickSort(vetor, i, e);
    if (s - b > 0)
        quickSort(vetor, b, s);
}

void quickSort(int vetor[], int tam)
{
    quickSort(vetor, 0, tam-1);
}



int main()
{
    int array[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int tam = sizeof(array) / sizeof(int);

    cout << "Array incial: ";
    printArray(array, tam);

    quickSort(array, tam);

    cout << "Array final:  ";
    printArray(array, tam);
    return 0;
}