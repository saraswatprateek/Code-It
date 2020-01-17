//Each node in a tree generally has utmost 1 parent and 2 children, in the given tree each node can have utmost 2 parents and 2 children. Each node had a value associated with it. I had to find the maximum sum that I can get by traversing from the root to the leaf most efficient manner. The values of each node can be negative too. I had to solve this in O(n).
//Prateek Saraswat
#include <iostream> 
#include <iterator> 
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm> 

#define ll long long int
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

struct node {
	int data;
	struct node *left, *right;
	int max_sum_below;
};

struct node* getNode(int data) {
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->max_sum_below=-1;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}

int func(struct node* root) {
	if(!root)return 0;

	if(!root->left && !root->right) {
		root->max_sum_below=root->data;
		return root->data;
	}

	int x=INT_MIN,y=INT_MIN;
	if(root->left!=NULL && root->left->max_sum_below==-1) {
		x=func(root->left);
	}
	else if(root->left!=NULL && root->left->max_sum_below!=-1) {
		x=root->left->max_sum_below;
	}
	if(root->right!=NULL && root->right->max_sum_below==-1) {
		y=func(root->right);
	}
	else if(root->right!=NULL && root->right->max_sum_below!=-1) {
		y=root->left->max_sum_below;
	}
	//cout<<root->data<<" "<<x<<" "<<y<<endl;
	root->max_sum_below = root->data + max(x,y);

	return root->data + max(x,y);
}

int main() {
	quick;
	//code
	struct node* root=getNode(5);
	root->left=getNode(-1);
	root->right=getNode(2);
	root->left->right=getNode(7);
	root->right->left=root->left->right;
	root->left->left=getNode(1);
	cout<<func(root)<<endl;
	return 0;
}