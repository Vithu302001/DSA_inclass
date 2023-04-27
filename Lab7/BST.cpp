#include <iostream>
using namespace std;

struct node {
   int key;
   struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) { 
    if (root == NULL){ // if root is NULL ,do nothing
        return ;
    }else{
        traverseInOrder(root->left);
        printf("%d ",root->key);
        traverseInOrder(root->right);
    }

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == NULL){  // create new node to link in case node is NULL
        struct node *insertingNode = new struct node;
        insertingNode->key = key;
        return insertingNode;
    }else{
        if (node->key > key){   // if key to insert is less than  node key value add to left tree using recursion
            node->left = insertNode(node->left,key);
            return node;
        }else{ // if key to insert is greater than  node key value add to right tree using recursion
            node->right = insertNode(node->right,key);
            return node;
        }
    }
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL){ // if root is null do nothing
        return root;
    }else if(root->key>key ) { // find the node with value equal to key value in left sub tree using recursion and delete
        root->left = deleteNode(root->left,key);
    }else if(root->key<key){   // find the node with value equal to key value in left sub tree using recursion and delete
            root->right = deleteNode(root->right,key);
    }else {
            if (root->left == NULL && root->right != NULL ){  // if node which wanted to delete has only right child node
                struct node *temporaryNode = root->right;
                delete root;
                return temporaryNode;
            }else if (root->right == NULL && root->left != NULL){// if node which wanted to delete has only right child node
                struct node *temporaryNode = root->left;
                delete root;
                return temporaryNode;
            }else if(root->left == NULL && root->right == NULL){ // if node which wanted to delete has no child node
                delete root;
                root = NULL;
            }else{
                struct node *maxValNode = root->left;
                while (maxValNode->right != NULL) {// find the maximum value in the left subtree
                    maxValNode = maxValNode->right;
                }
      
                root->key = maxValNode->key;  //replace the  node which wanted to delete with  maximum value node in left sub tree
                root->left = deleteNode(root->left ,maxValNode->key);
                
            }
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

