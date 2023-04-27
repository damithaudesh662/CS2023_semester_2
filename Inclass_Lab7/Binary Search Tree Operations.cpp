#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  
    if (root == nullptr)
        return;
    
    traverseInOrder(root->left);
    
    cout << root->key << " ";
    traverseInOrder(root->right);

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == nullptr) {
        //defining new node
        struct node *newNode = new struct node;
        newNode->key = key;
        //pointing both sides of node to null
        newNode->left = newNode->right = nullptr;
        return newNode;
    }
    // If key is less than the current node's key, go to the left subtree
    if (key <= node->key)
        node->left = insertNode(node->left, key);
        
    // If key is greater than the current node's key, go to the right subtree
    else if (key > node->key)
        node->right = insertNode(node->right, key);

    return node;

}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == nullptr)
        return root;
    // If key is less than the current node's key, go to the left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    // If key is higher than the current node's key, go to the right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // If the node has no left child, replace it with its right child
        if (root->left == nullptr) {
            struct node *temp = root->right;
            delete root;
            return temp;
        }
        // If the node has no right child, replace it with its left child
        else if (root->right == nullptr) {
            struct node *temp = root->left;
            delete root;
            return temp;
        }
        // If the node has both left and right children
        struct node *current = root->right;
        while (current->left != nullptr)
            current = current->left;

        root->key = current->key;
        // If the node has both left and right children
        root->right = deleteNode(root->right, current->key);
    }

    return root;
 
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}