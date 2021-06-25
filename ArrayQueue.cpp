#include <iostream>
using namespace std;

class QueueK
{
    int ocupations;
    int* queue;
    int total = 0;

public:
    QueueK(int totali)
    {
        ocupations = 0;
        total = totali;
        queue = new int[total];
        cout << "Fila criada com " << total << " vagas." << endl;
    }
    //remove the first queue's element
    int pop()
    {
        cout << "Pop \n";
        int returnValue = queue[0];
        if (ocupations == 0)
        {
            cout << "\tA fila esta vazia."<<endl;
            return returnValue;
        }
        //pop the first element and shift all the others to the left
        else
        {
            for (int i = 0; i < ocupations - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            ocupations--;
        }
        cout << "\tpopndo o elemento " << returnValue <<".\n";
        return returnValue;
    }
    //print the queue state
    void print()
    {
         cout << "Print \n";
        if (ocupations == 0)
        {
            cout << "\t A fila esta vazia."<<endl;
            return;
        }

        cout << "\t";
        for (int i = 0; i < ocupations; i++)
        {
            cout << queue[i];
            if(i < ocupations-1) cout << " < ";
        }

        // show the remains spaces
        if (ocupations < total)
        {
            cout << " < (" << total-ocupations << " vagas).";
        }
        cout << endl;
    }

    //add new element at end of the queue
    void push(int n)
    {
        // cout << "Vagas: " << total  << endl;
        cout << "push " << n << endl;
        if ( ocupations + 1  > total  )
        {
            cout << "\tVai estourar!!!\n";

            // realocar a array
            int *newArray = new int[total+1];
            cout << "\tAlocando mais memoria...\n";


            // copia todos os valores
            cout << "\tCopiando os valores...\n";
            for(int i = 0; i< total; i++)
            {
                newArray[i] = queue[i];
            }
            //atualiza o novo total
            cout << "\tAtualizando o total...\n";
            total ++;
            cout << "\tNovo total de vagas: " << total << endl;

            //liberar antigo chunk de memoria
            cout << "\tLiberando antigo chunk de memoria...\n";
            int *pauxquee = queue;
            queue = newArray;
            delete[] pauxquee;
        }

        cout<< "\tTem vaga, pushicionando o valor " << n << "\n";
        queue[ocupations] = n;
        ocupations++;
    }
    // return queue adress
    int* returQueueAdress()
    {
        return queue;
    }

};

int main()
{
    QueueK q(5);
    q.pop();
    q.push(42);
    q.push(2);
    q.push(8);
    q.push(1);
    q.push(5);
    q.push(89);
    q.print();
    q.pop();
    q.push(128);
    q.print();
    q.pop();
    q.pop();
    q.print();

    delete[] q.returQueueAdress();

    return 0;
}
