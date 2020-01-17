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

int main() {
	quick;
	//code

	//max priority_queue
	priority_queue<int> a;
	//min priority_queue
	priority_queue<int, vector<int>, greater<int> > b;

	int n,x;
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>x;
		if(a.size()==0 && b.size()==0) {
			a.push(x);
			cout<<x<<"|| ";
		}
		else {
			if(b.size()==0) {
				int y=a.top();
				if(x < y) {
					a.pop();
					b.push(y);
					a.push(x);
					cout<<(x+y)/2.0<<"|| ";
				}else {
					b.push(x);
					cout<<(x+y)/2.0<<"|| ";
				}
			}
			else {
				if(a.size()==b.size()) {
					int g1=a.top(),g2=b.top();
					if(x<=g2) {
						a.push(x);
						cout<<a.top()<<"|| ";
					}else {
						b.push(x);
						cout<<b.top()<<"|| ";
					}
				}
				else if(a.size()>b.size()) {
					int g1=a.top(),g2=b.top();
					if(x>=g1) {
						b.push(x);
						cout<<(a.top()+b.top())/2.0<<"|| ";
					}else {
						a.pop();
						b.push(g1);
						a.push(x);
						cout<<(a.top()+b.top())/2.0<<"|| ";
					}
				}
				else {
					int g1=a.top(),g2=b.top();
					if(x<=g2) {
						a.push(x);
						cout<<(a.top()+b.top())/2.0<<"|| ";
					}else {
						b.pop();
						a.push(g2);
						b.push(x);
						cout<<(a.top()+b.top())/2.0<<"|| ";
					}
				}
			}
		}

	}
	return 0;
}