#include <bits/stdc++.h>
using namespace std;
class T {
    public:
        int data;
        T* left = NULL,*right = NULL;
        
        T(int y) {
            data = y;
            left = NULL;
            right = NULL;
        }
};
void postorder_traversal (T *root) {
    if (root == NULL) return;
    
    postorder_traversal(root -> left);
    
    postorder_traversal(root -> right);
   
    cout << root -> data << ” “;
}
int main() {
    T *root = new T(14);
    root -> left = new T(22);
    root -> right = new T(66);
    root -> left -> left = new T(6);
    root -> left -> right = new T(84);
    root -> left -> left -> left = new T(2);
    root -> right -> left = new T(19);
    postorder_traversal(root);
    return 0;
}
