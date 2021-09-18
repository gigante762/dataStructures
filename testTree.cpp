#include <iostream>
using namespace std;


/* Exemple Tree looks like
          (4)
     (2)       (6)
  (1)   (3) (5)   (7)
*/

struct Node{
    int value;
    struct Node *right = NULL;
    struct Node *left =NULL;
};

Node* newNode(int value = 0)
{
    Node *new_node = new Node;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}


void insert(Node*& node, int val)
{

    if (node == NULL)
    {
        node = newNode(val);
        return;
    }

    if (val < node->value)
    {
        insert(node->left,val);
    }
    else if (val > node->value)
    {
        insert(node->right,val);
    }
}


void describe(Node* node)
{
    if (node->left != NULL)
        describe(node->left);

    if (node->right != NULL)
        describe(node->right);
    
    cout << node->value << endl;

}

/* Must be implemented */
void delete_node(Node* node)
{
    if (node->left != NULL)
    {
        delete_node(node->left);
    }

    if (node->right != NULL)
    {
        delete_node(node->right);
    }

    delete node;

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

    Node *tree = newNode(0);

    insert(tree,4);
    insert(tree,2);
    insert(tree,6);
    insert(tree,1);
    insert(tree,5);
    insert(tree,3);
    insert(tree,7);

    /* insert(tree,1);
    insert(tree,2);
    insert(tree,3);
    insert(tree,4);
    insert(tree,5);
    insert(tree,6);
    insert(tree,7);
 */
    //describe(tree);

    //Conta quantos passos foram necessários para encontrar o número
    int counter = 0;
    int* pc = &counter;

    countStepsToFind(tree,7,pc);
    cout << counter << endl;

    


   /*  cout << tree->value << endl;
    cout << tree->left->value << endl;
    cout << tree->right->value << endl; */


  
    // must free all the memory!!!

    return 0;
}

