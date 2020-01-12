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
	int n;cin>>n;
	string s;
	cin>>s;

	int l=0,r=0;
	for(int i=0;i<n;i++) {
		if(s[i]=='L')l++;
		else r++;
	}
	cout<<l+r+1;
	
	return 0;
}