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

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int main() {
	quick;
	//code
	ll x;
	cin >> x;
    ll ans;
    for(ll i = 1 ; i * i <= x ; i++){
        if(x % i == 0 && lcm(i, x / i) == x){
            ans = i;
        }
    }
    cout << ans << " " << x / ans << endl;
	return 0;
}