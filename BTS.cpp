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
        destroyNode(node->left);
        destroyNode(node->right);
        delete node;
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

bool countStepsToFind(Node* node, int val,int* counterSteps)
{
    *counterSteps += 1;
   

    if (node->value == val)
        return true;

    if (val < node->value)
    {
        if ( node->left != NULL)
            return countStepsToFind(node->left, val, counterSteps);
        return false;
    }
    else if (val > node->value)
    {
        if ( node->right != NULL)
            return countStepsToFind(node->right, val, counterSteps);
        return false;
    }

    return false;

}

int main()
{

    Node *tree = NULL;

    /* Exemple Tree looks like
            (4)
        (2)       (6)
    (1)   (3) (5)   (7)
    */
    insert(tree,4);
    insert(tree,2);
    insert(tree,6);

    insert(tree,1);
    insert(tree,5);
    insert(tree,3);
    insert(tree,7);
    describePreOrder(tree);
    cout << endl;
    removeNode(tree,4);
    describePreOrder(tree);



    /* insert(tree,1);
    insert(tree,2);
    insert(tree,3);
    insert(tree,4);
    insert(tree,5);
    insert(tree,6);
    insert(tree,7);
    describePreOrder(tree); */

    //Conta quantos passos foram necessários para encontrar o número
   /*  int counter = 0;
    int* pc = &counter;

    countStepsToFind(tree,7,pc);
    cout << endl << counter << endl; */

    


   /*  cout << tree->value << endl;
    cout << tree->left->value << endl;
    cout << tree->right->value << endl; */


  
    // must free all the memory!!!

    return 0;
}