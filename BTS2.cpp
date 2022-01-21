#include <iostream>
using namespace std;


typedef int ItemType;


/* Exemple Tree looks like
          (4)
     (2)       (6)
  (1)   (3) (5)   (7)
*/

struct Node{
    int v;
    Node *right = NULL, *left = NULL;
};

struct Tree{
    Node* root = NULL;
};

void deleteNode(Node *& node);
void removeNode(Node*& node, ItemType n);
void getSucessor(Node* node, ItemType &n);
int countStepsToFind(Node* node, int val, int &counterSteps);
int countStepsToFind(Node* node, int val);

bool isFull(Tree* tree)
{
    try
    {
        Node* newnode = new Node;
        delete newnode;
        return false;
    }
    catch(std::bad_alloc e)
    {
        cout << "Memoria cheia" << endl;
        return true;
    }
    
}
bool isFull(Node* node)
{
    try
    {
        Node* newnode = new Node;
        delete newnode;
        return false;
    }
    catch(std::bad_alloc e)
    {
        cout << "Memoria cheia" << endl;
        return true;
    }
    
}

/* Chamada de insert pela tree passando o node */
void insertNode(Node*& n, ItemType v)
{
    if (n == NULL)
    {
        if (!isFull(n))
        {
            Node* newnode = new Node;
            newnode->v = v;
            n = newnode;
        }
    }
    else if (v < n->v)
    {
        insertNode(n->left,v);
    }
    else if (v > n->v)
    {
        insertNode(n->right,v);
    }
}

/* Chamada de insert pelo usuário passando a tree */
void insert(Tree*& tree, ItemType v)
{
   insertNode(tree->root, v);
}

/* Without recursion */
void insertNomRecursive(Tree*& tree, ItemType v)
{
    Node *current = tree->root;

    // just for the first call
    if( current == NULL ){
        tree->root  = new Node;
        tree->root->v = v;
        return ;
    }

    while(current != NULL){
        if(v < current->v){
            if(current->left == NULL){
                current->left = new Node;
                current->left->v = v;

                return;
            }
            current = current->left;
        } else {
            if(current->right == NULL){
                current->right = new Node;
                current->right->v = v;
                return;
            } 
            current = current->right;
        }
    }
}

/* l, n , r */
void describeInOrder(Node* node)
{
    if (node->left != NULL)
        describeInOrder(node->left);

    cout << node->v << " ";

    if (node->right != NULL)
        describeInOrder(node->right);

}

/* n, l , r */
void describePreOrder(Node* node)
{
    cout << node->v << " ";

    if (node->left != NULL)
        describePreOrder(node->left);

    if (node->right != NULL)
        describePreOrder(node->right);

}

/* Chamada da tree */
void removeNode(Node*& node, ItemType n)
{
    if (node->v == n)
    {
       deleteNode(node);
    }
    else if (n > node->v  )
    {
        removeNode(node->right, n);
    }
    else if ( n < node->v )
    {
        removeNode(node->left, n);
    }
}

/* Chamada do usuário */
void removeNode(Tree*& tree, ItemType n)
{
    removeNode(tree->root,n);
}

void getSucessor(Node* node, ItemType &n)
{
    node = node->right;

    while (node->left != NULL)
    {
        node = node->left;
    }
    
    n = node->v;
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
        getSucessor(node, antV); // recebe o valor em antV, modificado por referência
        node->v = antV;
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
        //node = NULL;
    }
}

bool have(Node* node, int val)
{
    if (node->v == val)
        return true;

    if (val < node->v)
    {
        if ( node->left != NULL)
            return have(node->left, val);
        return false;
    }
    else if (val > node->v)
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

    if (node->v == val)
        return counterSteps;

    if (val < node->v)
    {
        if ( node->left != NULL)
            return countStepsToFind(node->left, val, counterSteps);
        return counterSteps;
    }
    else if (val > node->v)
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

    if (node->v == val)
        return counterSteps;

    if (val < node->v)
    {
        if ( node->left != NULL)
            return countStepsToFind(node->left, val, counterSteps);
        return counterSteps;
    }
    else if (val > node->v)
    {
        if ( node->right != NULL)
            return countStepsToFind(node->right, val, counterSteps);
        return counterSteps;
    }

    return counterSteps;

}

int main()
{

    Tree* tree = new Tree;


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

    describePreOrder(tree->root);


    return 0;
}