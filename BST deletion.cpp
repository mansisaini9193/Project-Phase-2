#include <bits/stdc++.h>
using namespace std;
struct Node {
   int data;
   struct Node *left, *right;
};
struct Node* newNode(int data) {
   struct Node* temp = new Node;
   temp->data = data;
   temp->left = temp->right = NULL;
   return temp;
};
void inorder(struct Node* node) {
   if (node == NULL) {
      return;
   }
   inorder(node->left);
   cout << node->data << " ";
   inorder(node->right);
}
void deleteDeepestNode(struct Node* root, struct Node* deleting_node){
   queue<struct Node*> nodes;
   nodes.push(root);
   struct Node* temp;
   while (!nodes.empty()) {
      temp = nodes.front();
      nodes.pop();
      if (temp == deleting_node) {
         temp = NULL;
         delete (deleting_node);
         return;
      }
      if (temp->right) {
         if (temp->right == deleting_node) {
            temp->right = NULL;
            delete deleting_node;
            return;
         }
         else {
            nodes.push(temp->right);
         }
      }
      if (temp->left) {
         if (temp->left == deleting_node) {
            temp->left = NULL;
            delete deleting_node;
            return;
         }
         else {
            nodes.push(temp->left);
         }
      }
   }
}
Node* deleteNode(struct Node* root, int key) {
   if (root == NULL){
      return NULL;
   }
   if (root->left == NULL && root->right == NULL) {
      if (root->data == key) {
         return NULL;
      }
      else {
         return root;
      }
   }
   queue<struct Node*> nodes;
   nodes.push(root);
   struct Node* temp;
   struct Node* key_node = NULL;
   while (!nodes.empty()) {
      temp = nodes.front();
      nodes.pop();
      if (temp->data == key) {
         key_node = temp;
      }
      if (temp->left) {
         nodes.push(temp->left);
      }
      if (temp->right) {
         nodes.push(temp->right);
      }
   }
   if (key_node != NULL) {
      int deepest_node_data = temp->data;
      deleteDeepestNode(root, temp);
      key_node->data = deepest_node_data;
   }
   return root;
}
int main() {
   struct Node* root = newNode(1);
   root->left = newNode(2);
   root->left->left = newNode(3);
   root->left->right = newNode(4);
   root->right = newNode(5);
   root->right->left = newNode(6);
   root->right->right = newNode(7);
   root->right->left->left = newNode(8);
   root->right->left->right = newNode(9);
   cout << "Tree before deleting key: ";
   inorder(root);
   int key = 5;
   root = deleteNode(root, key);
   cout << "\nTree after deleting key: ";
   inorder(root);
   cout << endl;
   return 0;
}
