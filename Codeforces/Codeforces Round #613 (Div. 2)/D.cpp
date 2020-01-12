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

vector<int>v;

int func(vector<int> v, int bit) {
	if(bit<0) return 0;

	vector<int>l,r;
	for(int i=0;i<v.size();i++) {
		if(v[i]&1<<bit)l.push_back(v[i]);
		else r.push_back(v[i]);
	}

	if(l.size()==0)
		return func(r,bit-1);
	if(r.size()==0)
		return func(l,bit-1);

	return min(func(r,bit-1),func(l,bit-1)) + (1<<bit);

}

int main() {
	quick;
	//code
	int n;cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i];

	cout<<func(v,30);
	return 0;
}