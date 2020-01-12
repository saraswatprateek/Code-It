//Prateek Saraswat
#include <iostream> 
#include <iterator> 
#include <map>
#include <vector>
#include <queue>

#define ll long long int
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;


void buildTree(int arr[], int tree[], int start, int end, int treeIndex) {
	if(start==end) {
		tree[treeIndex]=arr[start];
		return;
	}
	int mid = (start+end)/2;

	buildTree[arr,tree,start,mid,2*treeIndex];
	buildTree[arr,tree,mid+1,end,2*treeIndex+1];

	tree[treeIndex] = tree[2*treeIndex] + tree[2*treeIndex+1];
}

int main() {
	quick;
	//code
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}

	int tree[2*n];

	//buildTree(arr,tree,0,n-1,1);

    for(int i=0;i<2*n;i++){
        cout<<tree[i]<<" ";
    }
	return 0;
}