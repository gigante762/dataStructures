#include <iostream>
using namespace std;


/* Exemple Tree looks like
          (4)
     (2)       (6)
  (1)   (3) (5)   (7)
*/

struct Node{
    int value;
    struct Node *right;
    struct Node *left;
};

void print(Node *node)
{
    cout << node->left->value <<" <- "<<node->value << " -> " << node->right->value;
}

Node* newNode(int value = 0)
{
    Node *new_node = new Node;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int main()
{

    /*
    Node *root = new Node;
    root->value = 4;
    root->left = NULL;
    root->right = NULL;

    Node *n1 = new Node;
    n1->value = 2;
    n1->left = NULL;
    n1->right = NULL;

    Node *n2 = new Node;
    n2->value = 6;
    n2->left = NULL;
    n2->right = NULL;

    // plug the nodes

    root->left = n1;
    root->right = n2;
    */

    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);

    root->left->left = newNode(1);
    root->left->right = newNode(3);

    root->right->left = newNode(5);
    root->right->right = newNode(7);


    print(root);
  
    // must free all the memory!!!

    return 0;
}

