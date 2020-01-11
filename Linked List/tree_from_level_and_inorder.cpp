//Prateek Saraswat
//Construct a tree from Inorder and Level order traversals
#include <iostream> 
#include <iterator> 
#include <map>
#include <vector>

#define ll long long int
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

struct node {
	int data;
	struct node *right, *left;
};

struct node* getNode(int data) {
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	return temp;
}

int *extrackKeys(int in[], int level[], int m, int n) 
{ 
    int *newlevel = new int[m], j = 0; 
    for (int i = 0; i < n; i++) 
        if (search(in, 0, m-1, level[i]) != -1) 
            newlevel[j] = level[i], j++; 
    return newlevel; 
} 

struct node* construct_tree(int in[], int level[], int start, int end, int n) {
	if(start > end)return NULL;

	struct node* root = getNode(level[0]);
	if(start==end) {
		return root;
	}

	int inIndex;
	for(int i=start;i<=end;i++) {
		if(in[i]==level[0]){
			inIndex=i;
			return;
		}
	}

	int new_level1[end-start+1];
	int new_level2[end-start+1];

	int *llevel  = extrackKeys(in, level, inIndex, n); 
    int *rlevel  = extrackKeys(in + inIndex + 1, level, n-inIndex-1, n);


	root->left = construct_tree(in,new_level1,start,inIndex-1,n);
	root->right = construct_tree(in,new_level2,inIndex+1,end,n);

	return root;

}

int main() {
	quick;
	//code
	int n;   //number of nodes
	cin>>n;

	int in[n],level[n];
	for(int i=0;i<n;i++)cin>>in[i];
	for(int i=0;i<n;i++)cin>>level[i];

	struct node* root=NULL;

	root = construct_tree(in,level,0,n-1,n);
	return 0;
}