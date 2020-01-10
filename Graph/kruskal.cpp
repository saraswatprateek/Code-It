//Prateek Saraswat
#include<bits/stdc++.h>
using namespace std;

pair<int,pair<int,int>> p[10005];
int arr[10005];
int n,m;

//Disjoint set
void initialize() {
	for(int i=0;i<10005;i++) {
		arr[i]=i;
	}
}

int root(int x) {
	while(arr[x]!=x) {
		arr[x]=arr[arr[x]];  //While computing the root of A, set each i to point to its grandparent (thereby halving the path length), where i is the node which comes in between path, while computing root of A.
		x=arr[x];
	}
	return x;
}

void union1(int x,int y) {
	int root_x=root(x);
	int root_y=root(y);

	arr[root_x] = root_y   //setting parent of root_x as root_y
}

int kruskal() {
	int x,y,wt;
	int min_cost=0;
	for(int i=0;i<m;i++) {
		x=p[i].second.first;
		y=p[i].second.second;
		wt=p[i].first;

		if(root(x)!=root(y)) {
			union1(x,y);
			min_cost+=wt;
		}
	}
	return min_cost;
}

int main() {
	cin>>n>>m;

	for(int i=0;i<m;i++) {
		int x,y,wt;
		cin>>x>>y>>wt;
		p[i]=make_pair(wt,make_pair(x,y));
	}
	sort(p,p+m);
	cout << kruskal();
}