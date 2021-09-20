#include <iostream>
using namespace std;


typedef int ItemType;


/* Exemple Tree looks like
          (4)
     (2)       (6)
  (1)   (3) (5)   (7)
*/

struct Node{
    int value;
    Node *right = NULL, *left = NULL;
};

void deleteNode(Node *& node);
void removeNode(Node*& node, ItemType n);
void getSucessor(Node* node, ItemType &n);
int countStepsToFind(Node* node, int val, int &counterSteps);
int countStepsToFind(Node* node, int val);

Node* newNode(ItemType value = 0)
{
    Node *new_node = new Node;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}


void insert(Node*& node, ItemType val)
{

    if (node == NULL)
    {
        node = newNode(val);
    }
    else if (val < node->value)
    {
        insert(node->left,val);
    }
    else if (val > node->value)
    {
        insert(node->right,val);
    }
}

/* Without recursion */
void insertNomRecursive(Node*& node, ItemType val)
{
    Node *current = node;

    // just for the first call
    if( current == NULL ){
        node  = newNode(val);
        return ;
    }

    while(current != NULL){
        if(val < current->value){
            if(current->left == NULL){
                current->left = newNode(val);
                return;
            }
            current = current->left;
        } else {
            if(current->right == NULL){
                current->right = newNode(val);
                return;
            } 
            current = current->right;
        }
    }
}

void describeInOrder(Node* node)
{
    if (node->left != NULL)
        describeInOrder(node->left);

    cout << node->value << " ";

    if (node->right != NULL)
        describeInOrder(node->right);

}
void describePreOrder(Node* node)
{
    cout << node->value << " ";

    if (node->left != NULL)
        describePreOrder(node->left);

    if (node->right != NULL)
        describePreOrder(node->right);

}

void removeNode(Node*& node, ItemType n)
{
    if (node->value == n)
    {
       deleteNode(node);
    }
    else if (n > node->value  )
    {
        removeNode(node->right, n);
    }
    else if ( n < node->value )
    {
        removeNode(node->left, n);
    }
}

void getSucessor(Node* node, ItemType &n)
{
    node = node->right;

    while (node->left != NULL)
    {
        node = node->left;
    }
    
    n = node->value;
}

void deleteNode(Node *& node)
{
    Node* tmp = node;
    
    /* Caso um dos dois seja null, um filho apenas ou nenhum */
    if (node->left == NULL)
    {
        node = node->right;
        delete tmp;
    }
    else if (node->right == NULL)
    {
        node = node->left;
        delete tmp;
    }
    else
    {
        ItemType antV;
        getSucessor(node,antV); // recebe o valor em antV, modificado por referência
        node->value = antV;
        removeNode(node->right, antV);
    }
}

/* have bug */
void destroyNode(Node *&node)
{
    if (node != NULL)
    {
        /* deleteNode(node->left);
        deleteNode(node->right);
        deleteNode(node); */
        //node = NULL;
    }
}

bool have(Node* node, int val)
{
    if (node->value == val)
        return true;

    if (val < node->value)
    {
        if ( node->left != NULL)
            return have(node->left, val);
        return false;
    }
    else if (val > node->value)
    {
        if ( node->right != NULL)
            return have(node->right, val);
        return false;
    }

    return false;

}

int countStepsToFind(Node* node, int val)
{
    int counterSteps = 1;

    if (node->value == val)
        return counterSteps;

    if (val < node->value)
    {
        if ( node->left != NULL)
            return countStepsToFind(node->left, val, counterSteps);
        return counterSteps;
    }
    else if (val > node->value)
    {
        if ( node->right != NULL)
            return countStepsToFind(node->right, val, counterSteps);
        return counterSteps;
    }

    return counterSteps;

}

int countStepsToFind(Node* node, int val, int &counterSteps)
{
    counterSteps += 1;
   

    if (node->value == val)
        return counterSteps;

    if (val < node->value)
    {
        if ( node->left != NULL)
            return countStepsToFind(node->left, val, counterSteps);
        return counterSteps;
    }
    else if (val > node->value)
    {
        if ( node->right != NULL)
            return countStepsToFind(node->right, val, counterSteps);
        return counterSteps;
    }

    return counterSteps;

}

int main()
{

    Node *tree = NULL;

    /* Exemple Tree looks like
            (4)
        (2)       (6)
    (1)   (3) (5)   (7)
    */
    /* insertNomRecursive(tree,4);
    insertNomRecursive(tree,2);
    insertNomRecursive(tree,6);

    insertNomRecursive(tree,1);
    insertNomRecursive(tree,5);
    insertNomRecursive(tree,3);
    insertNomRecursive(tree,7); */


    /*  Recursion vs non-recursion insert */
    /* insertNomRecursive é melhor porque não criar chamadas na stack ao inserir.
        no código abaixo quando chega para inserir o 10 a stack está com 9 processos de inserção
        recursiva na stack. Assim a stack de itens a serem inseridos nesse caso fica crescendo junto
        junto com o tamanho dos depenada valores a serem inseridos, que mais vira um lista linkada.
        Sendo assim não é viável usar o processo de inserção recursiva.
    */
    /* for (int i = 1; i <= 10; i++)
    {
        insertNomRecursive(tree,i*2);
    } */

    /* describePreOrder(tree);
    cout << endl ;
    //destroyNode(tree);
    //removeNode(tree,4);
    //removeNode(tree,2);
    describePreOrder(tree);
    cout << endl ;
    
    insertNomRecursive(tree,7);
 */
    


    /* insert(tree,1);
    insert(tree,2);
    insert(tree,3);
    insert(tree,4);
    insert(tree,5);
    insert(tree,6);
    insert(tree,7);
    describePreOrder(tree); */

    //Conta quantos passos foram necessários para encontrar o número
    //cout << endl << countStepsToFind(tree,14) << endl;

  
    // must free all the memory!!!

    return 0;
}