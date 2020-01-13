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

	buildTree(arr,tree,start,mid,2*treeIndex);
	buildTree(arr,tree,mid+1,end,2*treeIndex+1);

	tree[treeIndex] = tree[2*treeIndex] + tree[2*treeIndex+1];
}

void update(int arr[], int tree[], int start, int end, int diff, int update_index, int treeIndex) {
	if(update_index<start || update_index>end) {
		return;
	}

	tree[treeIndex]+=diff;
	
	if(start!=end) {
		int mid=(start+end)/2;
		update(arr,tree,start,mid,diff,update_index,2*treeIndex);
		update(arr,tree,mid+1,end,diff,update_index,2*treeIndex+1);
	}
}

int query(int arr[], int tree[], int start, int end, int query_start, int query_end, int treeIndex) {
	if(start>=query_start && end<=query_end) {
		return tree[treeIndex];
	}

	if(start>query_end || end<query_start) {
		return 0;
	}

	int mid=(start+end)/2;
	return query(arr,tree,start,mid,query_start,query_end,2*treeIndex)+query(arr,tree,mid+1,end,query_start,query_end,2*treeIndex+1);
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

	int tree[2*n+1];

	buildTree(arr,tree,0,n-1,1);

	for(int i=1;i<2*n;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

	//Update Tree
	int update_index,new_val;
	cin>>update_index>>new_val;

	int diff=new_val-arr[update_index];
	update(arr,tree,0,n-1,diff,update_index,1);

    for(int i=1;i<2*n;i++){
        cout<<tree[i]<<" ";
    }
	return 0;
}