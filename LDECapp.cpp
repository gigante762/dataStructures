#include <iostream>
#include <cstring>
using namespace std;

#define SISTEMA "linux" // windows , linux

/* 
    Lista duplamente encadeada circular aplicada a um crud.

    Cadastro simples cursos para um escola de cursos.
    
    curso: {
        string nome PK... -- pois é
        int duracao(meses) -- tempo do curso
        desc string -- descrição
    }

    Autor: Kevin R.
*/

/* 

    Check list de desenvolvimento. Em ordem de prioridade.

    ----- Projeto ----- 
    Adicionar novo curso
    exibir todos os cursos
    navegar por cursos
    editar cursos
    remover cursos 
    ---------

*/

struct Curso{
    string nome;
    int duracao = 0;
    string desc;
};


//Node duplamente encadeado
struct NodeD{
    Curso c;
    NodeD* prev = NULL;
    NodeD* next = NULL;
};

//Lista duplamente circular
struct ListaDEC{
    // ponteiro para o inicio, default NULL
    NodeD* first = NULL;
};

/*Mostra todos os valores partindo de l->first*/
void describeAll(ListaDEC* l)
{
    
    if(l->first == NULL)
    {
        cout << "Lista vazia\n";
        return;
    }
    
    NodeD* aux = l->first;
    
    do{
         cout << aux->c.nome << " ";
         aux = aux->next;
    }while(aux != l->first);
    
    
    cout << endl;
}

/* Retorna se a lista está vazia */
bool isEmpty(ListaDEC* l)
{
    return (l->first == NULL);
}

/* Retorna se a lista está cheia */
bool isFull(ListaDEC* l)
{
    //Cria um novo node;
    try{
        NodeD* newnode = new NodeD;
        delete newnode;
        return false;
    }catch(std::bad_alloc e)
    {
        cout << "Memoria cheia" << endl;
        return true;
    }
}

/*Funçõe para a Lista Duplamente Encadeada Circular*/

/*insert, insere um valor na lista após o node first da lista*/
void insert(ListaDEC*& l,  Curso c)
{
    
    if (isFull(l))
    {
        cout << "Memoria cheia" << endl;
        return;
    }

    NodeD* newnode = new NodeD;
    //copias os valores
    newnode->c.nome = c.nome;
    newnode->c.duracao = c.duracao;
    newnode->c.desc = c.desc;


    // checar o primeiro elemento
    if (l->first == NULL)
    {
        // ajusta os ponteiros
        newnode->next = newnode;
        newnode->prev = newnode;
        
        l->first = newnode;
    }
    else
    {
        newnode->next = l->first->next;
        l->first->next = newnode;
        
        newnode->next->prev = newnode;
        
        newnode->prev = l->first;
        
    }
}


/*Buscar um valor na lista e retorna uma NodeD*/
NodeD* buscarValor(ListaDEC* l, string nomeCurso)
{
    NodeD* result = NULL;

    if (l->first == NULL)
    {
        return result;
    }
    
    NodeD* aux = l->first;

    do{
        if(aux->c.nome.compare(nomeCurso) == 0)
        {
            result = aux;
        }
         aux = aux->next;
    }while(aux != l->first);
    
    return result;
}

/*Atualiza um curso com base no nome do curso, passa o nome do curso a ser atualizado e um curso com os novos dados.*/
NodeD* atualizarValor(ListaDEC*& l, string nomeCurso, Curso cursoAtualizado)
{
    NodeD* result = buscarValor(l, nomeCurso);
    
    if(result)
    {
        result->c.nome = cursoAtualizado.nome;
        result->c.duracao = cursoAtualizado.duracao;
        result->c.desc = cursoAtualizado.desc;
    }
    return result;
}

bool removeValor(ListaDEC*& l, string nomeCurso)
{
    NodeD* result = buscarValor(l, nomeCurso);

    if (!result)
    {
        cout << "Curso '" << nomeCurso << "' nao localizado para remocao\n";
        return false;
    }
    
    // remoção do elemento da ponta direita...
    if (result->next == l->first && result != l->first)
    {
        l->first->prev = result->prev;
        result->prev->next = l->first;
        delete result;
        return true;
    }
    
    // remoção do elemento first...
    // verificar se há outro ou só um elemento na lista
    if (result == l->first)
    {
        //verifica se há outro além dele, nesse caso remove se só há um;
        if (result->next == l->first && result->prev == l->first)
        {
            
            delete l->first;
            l->first = NULL;
            return true;
        }
        else
        {
            //faz o first ser o proximo da lista;
            l->first = l->first->next;

            // como agora ele não é o first pode chamar o método novamente para cuidar
            // dessa remoção, ou será meio ou direita;
            return removeValor(l, nomeCurso);
        }
    }

    
    // caso de remoção de elemento ao meio
    result->next->prev = result->prev;
    result->prev->next = result->next;
    
    delete result;
    
    return true;
}


/* Funções para o projeto */

/* Exibe um menu com opções */
void printOpcoes()
{
    cout << "1- Criar Curso" << endl;
    cout << "2- Ver todos os cursos" << endl;
    cout << "3- Navegas pelos cursos" << endl;
    cout << "4- Ordenar cursos em ordem alfabetica" << endl;
    cout << "0- Sair do programa" << endl;
   
}

/* Limpra o terminal com base no sistem operacional */
void cls()
{
    if ( strcmp(SISTEMA, "linux") == 0)
        system("cls");
    else
        system("lmp");
}


int menu()
{
    short int op;
    cout << "==== Bem vindo a sua escola de cursos ==== \n";
    cout << "Escolha uma opcao: \n";
    printOpcoes();
    cout << "> ";
    cin >> op;
    cout << "==== ----------------------- ==== \n";

    return op;
}

/* Verifica se um numero esta entre um minimo e maximo */
bool checkeBetween(int val, int min, int max)
{
    return (val >= min && val <= max);
}

/* Retonar faz as perguntas e retorna um curso com base nas respostas, usado no insert e edit */
Curso colherDadosDoCurso(){
    
    
    cout << "Nome do curso: ";
    string tmpName;
    cin.ignore();
    getline(cin, tmpName);

    cout << "Duracao em meses do curso: ";
    //cin.ignore();
    int tmpDuracao;
    cin >> tmpDuracao;

    cout << "Descricao do cuso: ";
    string tmpDesc;
    cin.ignore();
    getline(cin, tmpDesc);

    //cria o curso
    Curso c;
    c.nome = tmpName;
    c.duracao = tmpDuracao;
    c.desc = tmpDesc;

    return c;


}

void criarNovoCurso(ListaDEC*& l)
{
    //cria o curso
    Curso c = colherDadosDoCurso();
   
    //insere na listaDEC
    insert(l, c);

}


/*Mostra todos os cursos*/
void verTodosCursos(ListaDEC*& l)
{
    if (l->first == NULL)
    {
        cout << "Nao ha cursos\n";
        return;
    }

    int contador = 1;

    NodeD* aux = l->first;

    // t é o titulo do primeiro curso
    string t = aux->c.nome;

    cout << "Cursos:\n";

    cout << contador << ") "<<   aux->c.nome << endl;
    
    aux = aux->next;
    contador++;

    while(aux->c.nome.compare(t) != 0)
    {
       cout << contador << ") "<<   aux->c.nome << endl;

        aux = aux->next;
        contador++;
    }
    
}

/*Mostra todos os cursos*/
void navegarEntreCursos(ListaDEC*& l)
{
    string textoCabecalho =  "Use 'd' e 'a' para avancar e voltar. \nUse 'e' para editar o curso \nUse 'r' para remover um curso \nUse 'q' para sair\n\n";
    /* Não consegui fazer um modo de apertar a,d e 
    já enviar a opcao, o problema é que preciso apertar o enter. */

    if (l->first == NULL)
    {
        cout << "Nao ha cursos\n";
        return;
    }

    cls();
    cout << textoCabecalho;

    NodeD* aux = l->first;

    // t é o titulo do primeiro curso
    string t = aux->c.nome;

    cout << "Nome do curso: " << aux->c.nome << endl;
    cout << "\tDuracao: " << aux->c.duracao << " meses"<< endl;
    cout << "\tDescicao: " << aux->c.desc << endl;
    cout << "---------"  << endl;

    cin.ignore();
    char opcao = cin.get();

    cls();
    cout << textoCabecalho;


    while(opcao != 'q')
    {
        if (opcao == 'a')
        {
            aux = aux->prev;
        }
        else if (opcao == 'd')
        {
            aux = aux->next;
        }
        else if (opcao == 'r')
        {
            aux = aux->next;
            removeValor(l,aux->prev->c.nome);
        }
        else if (opcao == 'e')
        {
            cout << "Atulizando curso '" << aux->c.nome << "'\n";
            //atualizar curso
            Curso cursoatt = colherDadosDoCurso();
            
            cursoatt.nome = (cursoatt.nome == "") ? aux->c.nome : cursoatt.nome;
            cursoatt.desc = (cursoatt.desc == "") ? aux->c.desc : cursoatt.desc;


            cls();
            cout << textoCabecalho;
            atualizarValor(l, aux->c.nome, cursoatt);
        }

        if (l->first != NULL)
        {
            cout << "Nome do curso: " << aux->c.nome << endl;
            cout << "\tDuracao: " << aux->c.duracao << " meses"<< endl;
            cout << "\tDescicao: " << aux->c.desc << endl;
            cout << "---------"  << endl;
        }
        // caso remova até o ultimo curso não há como navegar mais.
        else
        {
            cout << "Nao ha cursos\n";
            return;
        }


        //cin.ignore();
        opcao = cin.get();

        cls();
        cout << textoCabecalho;
    }

}

/* Carrega alguns dados já prontos */
void montarCenarioTest(ListaDEC*& l)
{
        Curso a;
        a.nome = "Calculo 1";
        a.duracao = 2;
        a.desc = "Limites e Derivadas";
        insert(l, a);

        a.nome = "Calculo 2";
        a.duracao = 4;
        a.desc = "Derivadas e Integral";
        insert(l, a);

        a.nome = "Algebra Linear";
        a.duracao = 1;
        a.desc = "Matrizes, vetores, espacos, subespacos, bases e transformacoes";
        insert(l, a);

        a.nome = "Estrutura de dados I";
        a.duracao = 1;
        a.desc = "Ponteiros, Complexidade, Listas encadeadas ...";
        insert(l, a);

        a.nome = "Organizacao da Educacao";
        a.duracao = 3;
        a.desc = "Historia da Educacao, pensadores, leis e diretrizes...";
        insert(l, a);

        a.nome = "Oficina de Leitura e Escrita";
        a.duracao = 3;
        a.desc = "Leitura, criatividade, construcao do saber...";
        insert(l, a);

        a.nome = "Introducao a computacao";
        a.duracao = 3;
        a.desc = "Ordenacao, atividades desplugadas, areas de atuacao...";
        insert(l, a);
}

/* Metodo de ordenação buble sort para ordenar a lista */
void ordenarLista(ListaDEC*& l)
{
    // null ou verifica se tem apenas um valor
    if (l->first == NULL || l->first == l->first->next)
    {
        return;
    }

    //faz o aux ser o first
    NodeD* aux = l->first;

    /*  Cara fiquei uma meio hora pra achar o bug kkkkk
        Pelo fato de ser circular vai dar isso [1,2,3...9], quando for
        varrer novamente vai ter a comparação 9 1 e isso gera um swap dai fica infinito! kkkk
        Uma maneira é setar o ponto de partida tendo o menor valor como o first, afinal
        ela é circular o first não faz diferença de quem é. Sendo assim eu consido ordenar
        e quando chegar ao fim eu rodo novamente garantindo que first(o menor), nunca passará
        pelo swap, quebrando o loop infinito.
    */

    // vou pegar o menor valor da lista para ser o meu ponto de partida;

    NodeD* nodeMenorValor = l->first;
    for(NodeD* auxI = l->first; auxI->next != l->first; auxI = auxI->next )
    {
        if(auxI->c.nome < nodeMenorValor->c.nome)
        {
            nodeMenorValor = auxI;
        }
    }

    //cout << "Node de menor valor " << nodeMenorValor->c.nome << endl;
    l->first = nodeMenorValor;

    //repete enquanto nao der uma volta ou seja aux != l->first

    // considere toda lista ordenada até que se prove o contrário.
    bool isOrdened = true;
    aux = l->first;
    do {
        isOrdened = true;
        while(aux->next != l->first)
        {
            bool needSpaw = aux->c.nome > aux->next->c.nome;
            isOrdened = isOrdened && !needSpaw;
            if(needSpaw)
            {
                //cout << "Trocando " << aux->c.nome << " por " << aux->next->c.nome << endl;
                isOrdened = false;

                //swap, a e b pra facilitar o pensamento kkk
                NodeD* a = aux;
                NodeD* b = aux->next;

                a->next = b->next;
                b->prev = a->prev;
                a->prev = b;
                b->next = a;
                a->next->prev = a;
                b->prev->next = b;
            }

            aux = aux->next;
        }

        // reseta o aux para o primeiro
        aux = l->first;
       

    } while(!isOrdened);


    /*putz grila!! tô muito feliz !!!! funcionou!!! Com orgulho eu digo*/
    cout << "Lista ordenada com sucesso!\n";
}



int main()
{
    // Criação da lista
    ListaDEC* listaDEC = new ListaDEC;

    char garbage;      // Para segurar o continue do menu
    montarCenarioTest(listaDEC);

    while (true)
    {
        cls();
        int opMenu = menu();

        while (!checkeBetween(opMenu, 0, 4))
        {
            cls();
            cout << "Valores invalidos...\n";
            opMenu = menu();
        }

        cls();
       
       if (opMenu == 1)
       {
           criarNovoCurso(listaDEC);
       }
       else if (opMenu == 2)
       {
           // mostra o titulo de todos os cursos
           verTodosCursos(listaDEC);
       }
       else if (opMenu == 3)
       {
           //passa os cursos um a um.
           navegarEntreCursos(listaDEC);
       }
       else if (opMenu == 4)
       {
           ordenarLista(listaDEC);
       }
       else if (opMenu == 0)
       {
           return 0;
       }

        cout << "\nDigite 'a' + Enter para continuar ";
        cin >> garbage;

    }

   
    //fim do programa, vai liberar toda a memória
    delete listaDEC;
    return 0;
}
