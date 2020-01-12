//Prateek Saraswat
#include <iostream> 
#include <iterator> 
#include <map>
#include <vector>
#include <queue>

#define ll long long int
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main() {
	quick;
	//code
	ll t; cin>>t;
	while(t--) {
		ll n,y=0,a=0;cin>>n;
		ll arr[n];
		for(ll i=0;i<n;i++) {
			cin>>arr[i];y+=arr[i];
		}

		//kandane algo{}
		ll curr=0;
		ll start=0,end;
		for(ll i=0;i<n;i++) {
			curr+=arr[i];
			if(curr>a){
				a=curr;
				end=i;
			}
			if(curr<=0){
				start=i+1;
				curr=0;
			}
		} 

		if(y>a) cout<<"YES"<<endl;
		else{
			//cout<<start<<" "<<end<<endl;
			if(start==0&&end==n-1&&(y>a-arr[0] || y>a-arr[n-1]))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		} 
	}
	return 0;
}