//Prateek Saraswat
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[1000];
int dist[1000];

void dijkstra(int u,int n) {
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
	pq.push({0,u});
	for(int i=0;i<100;i++)dist[i]=9999;
	dist[u]=0;

	while(!pq.empty()) {
		pair<int,int> top1 = pq.top();
        int top = top1.second;
		pq.pop();

		for(int i=0;i<graph[top].size();i++) {
			int w=graph[top][i].second;
			int v=graph[top][i].first;
			if(dist[v] > dist[top]+w) {
				dist[v]=dist[top]+w;
                pq.push({dist[v],v});
			}
		}
	}
}

int main() {
	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++) {
		int x,y,wt;
		cin>>x>>y>>wt;
		graph[x].push_back(make_pair(y,wt));
		graph[y].push_back(make_pair(x,wt));
	}

	dijkstra(1,6);
	for(int i=1;i<=n;i++)
		cout<<dist[i]<<" ";
	return 0;
}