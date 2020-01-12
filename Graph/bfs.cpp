//Prateek Saraswat
#include <iostream> 
#include <iterator> 
#include <map>
#include <vector>
#include<queue>

#define ll long long int
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int n,m;
vector<int>adj[100005];

void bfs(int u) {
	queue<int> q;
	q.push(u);

	int visited[n+1];
	memset(visited,0,sizeof(visited));
	visited[u]=1;

	while(!q.empty()) {
		int a=q.front();
		cout<<a<<" ";
		q.pop();

		for(int i=0;i<adj[a].size();i++) {
			if(visited[adj[a][i]]==0) {
				q.push(adj[a][i]);
				visited[adj[a][i]]=1;
			}
		}
	}
}

int main() {
	quick;
	//code
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	bfs(1);
	
	return 0;
}