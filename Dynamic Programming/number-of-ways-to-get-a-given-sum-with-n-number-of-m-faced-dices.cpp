//Number of ways to get a given sum with n number of m-faced dices
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

int dp[1005][1005];
int func(int n,int throws, int sum) {
	if(sum<0)return 0;
	if(throws==0&&sum==0)return 1;
	if(throws==0&&sum!=0)return 0;

	if(dp[throws][sum]>0) return dp[throws][sum];

	int cnt=0;
	for(int i=1;i<=n;i++) {
		dp[throws][sum]+=func(n,throws-1,sum-i);
	}
	return dp[throws][sum];
}

int main() {
	quick;
	//code

	int faces,throws,sum;
	cin>>faces>>throws>>sum;
	//memset(dp,0,sizeof(dp));
	for(int i=0;i<1005;i++){
		for(int j=0;j<1005;j++) {
			dp[i][j]=0;
		}
	}

	cout<<func(faces,throws,sum);
	return 0;
}