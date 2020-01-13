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

int arr[100005],BIT[100005];

void update(int z,int x) {
	for(;x<=n;x+=x&(-x)){
		BIT[x]+=z;
	}
}

int query(int x) {
	int sum=0;
	for(;x>0;x-=x&(-x)) {
		sum+=BIT[x];
	}
	return sum;
}

int main() {
	quick;
	//code
	int n;cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
		update(arr[i],i);
	}
	return 0;
}