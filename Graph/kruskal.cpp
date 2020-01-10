//Prateek Saraswat
#include<bits/stdc++.h>
using namespace std;

int arr[10005];

//Disjoint set
void initialize() {
	for(int i=0;i<10005;i++) {
		arr[i]=i;
	}
}

int root(int x) {
	while(arr[x]!=x) {
		arr[x]=arr[arr[x]];  
		x=arr[x];
	}
	return x;
}