#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int i){
  struct node* node = new struct node;
  node->data = i;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void printLeafNodes(node *root) //leaf nodes
{
    // if node is null, return
    if (!root)
        return;

    // if node is leaf node, print its data
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }

    // if left child exists, check for leaf
    // recursively
    if (root->left)
       printLeafNodes(root->left);

    // if right child exists, check for leaf
    // recursively
    if (root->right)
       printLeafNodes(root->right);
}

void printFullNode(node *root){ //full nodes
   if (root != NULL){
      printFullNode(root->left);
      if (root->left != NULL && root->right != NULL)
         cout<<root->data<<"\t";
      printFullNode(root->right);
   }
}

void printNodes(node* root)
{
	// return is tree is empty
	if (root == nullptr)
		return;

	// print root node
	cout << root->data << " ";

	// create a two empty queues and enqueue root's left and
	// right child respectively
	queue<node*> q1, q2;
	q1.push(root->left);
	q2.push(root->right);

	// loop till queue is empty
	while (!q1.empty())
	{
		// calculate number of nodes in current level
		int n = q1.size();

		// process every node of current level
		while (n--)
		{
		   // pop front node from first queue and print it
		   node* x = q1.front();
		   q1.pop();

		   cout << x->data << " ";

		   // push left and right child of x to first queue
		   if (x->left)
				q1.push(x->left);

		   if (x->right)
				q1.push(x->right);


		   // pop front node from second queue and print it
		   node* y = q2.front();
		   q2.pop();

		   cout << y->data << " ";

		   // push right and left child of y to second queue
		   if (y->right)
				q2.push(y->right);

		   if (y->left)
				q2.push(y->left);
		}
	}
}

int main(){
struct node *root = newNode(9);
root->left = newNode(8);
root->right = newNode(7);
root->left->left = newNode(6);
root->left->right = newNode(5);
root->right->left = newNode(4);
root->right->right = newNode(3);

printLeafNodes(root);
cout<<endl;
printFullNode(root);
printNodes(root);
  return 0;
}
