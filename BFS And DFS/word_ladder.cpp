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

vector<string> adj[100005];

int bfs(string start, string end, int n) {
	queue< pair<string,int> >q;
	q.push(make_pair(start,0));

	int visited[n];
	memset(visited,0,sizeof(visited));
	while(!q.empty()) {
		pair<string,int> p;
		p=q.front();


	}
}

int main() {
	quick;
	//code
	int n;cin>>n;
	string arr[n];
	for(int i=0;i<n;i++) {
		string s;cin>>s;
		arr[i]=s;
	}

	for(int i=0;i<n;i++) {
		for(int j=i+1;i<n;i++) {
			if(arr[i].length()==arr[j].length()) {
				int cnt=0;
				for(int k=0;k<arr[i].length();k++) {
					if(arr[i][k]!=arr[j][k])cnt++;
				}
				if(cnt==1) {
					//cout<<arr[i]<<" "<<arr[j]<<endl;
					adj[i].push_back(arr[j]);
					adj[j].push_back(arr[i]);
				}
			}
		}
	}

	string start,end;
	cin>>start>>end;

	//cout<<bfs(start,end,n);
	return 0;
}