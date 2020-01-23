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

void func(int arr[], int nge[], int n) {
	for(int i=0;i<n;i++)nge[i]=-1;

	stack<int>s;
	s.push(0);
	for(int i=1;i<n;i++) {
		if(s.empty()) { 
      		s.push(arr[i]); 
      		continue; 
    	}
		int curr=arr[i];
		int top=s.top();
		while(s.empty()==false && curr>arr[s.top()]) {
			arr[s.top()]=curr;
			s.pop();
		}
		s.push(i);
	}
}

int main() {
	quick;
	//code
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int nge[n];
	func(arr,nge);
	return 0;
}