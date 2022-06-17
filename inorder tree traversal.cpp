
#include<bits/stdc++.h>
using namespace std;


struct N
{
	int data;
	struct N* left;
	struct N* right;
	N (int data)
	{
		this->data = data;
		left = right = NULL;
	}
};


void inOrder(struct N *root)
{
	stack<N *> r;
	N *curr = root;

	while (curr != NULL || r.empty() == false)
	{
		
		while (curr != NULL)
		{
			
			r.push(curr);
			curr = curr->left;
		}

		
		curr = r.top();
		r.pop();

		cout << curr->data << " ";

		
		curr = curr->right;

	} 
}


int main()
{

	
	struct N *root = new N(6);
	root->left	 = new N(8);
	root->right	 = new N(9);
	root->left->left = new N(2);
	root->left->right = new N(1);

	inOrder(root);
	return 0;
}
