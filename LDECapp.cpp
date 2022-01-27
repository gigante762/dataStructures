#include <iostream>
using namespace std;

#define OS 'windows' // windows , linux

/* 
    Lista duplamente encadeada circular aplicada a um crud.

    Cadastro simples de cursos
    
    curso: {
        string nome PK... -- pois é
        int duracao(meses) -- tempo do curso
        desc string -- descrição

        preRequisito: curso;
    }

    Autor: Kevin R.
*/

/* 

    Check list de desenvolvimento. Em ordem de prioridade.

    ----- Projeto ----- 

    Adicionar novo curso
    exibir todos os cursos
    pesquisar por cursos
    navegar por cursos
    editar cursos
    remover cursos {
        checar integridade referencial...
    }



    
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
    
    // checar o primeiro elemento
    if (l->first == NULL)
    {
        NodeD* newnode = new NodeD;
        newnode->c = c;
        
        // ajusta os ponteiros
        newnode->next = newnode;
        newnode->prev = newnode;
        
        l->first = newnode;
    }
    else
    {
        NodeD* newnode = new NodeD;
        newnode->c = c;
        
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



int main()
{

    // Criação da lista
    ListaDEC* listaDEC = new ListaDEC;


    

   
    //fim do programa, vai liberar toda a memória
    delete listaDEC;
    return 0;
}
