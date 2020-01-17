//Search an element in a sorted and rotated array
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

//find pivot
//2nd method is to find pivot and then use binary func1 on 2 halves
int func2(int arr[], int n, int key) {
	int low=0,high=n-1;
	int mid=(low+high)/2;
	if(arr[high]>arr[low])return -1;

	while(high-low>1) {
		mid=(low+high)/2;
		if(arr[low]<arr[mid]) {
			low=mid;
		}
		else {
			high=mid;
		}
	}
	return low;
}

int func1(int arr[], int l, int h, int key) 
{ 
    if(l>h)
    return -1; 
  
    int mid=(l+h)/2; 
    if(arr[mid]==key)return mid; 
 
    if(arr[l] <= arr[mid]) {
        if(key >= arr[l] && key <= arr[mid]) return func1(arr, l, mid-1, key);
        else return func1(arr, mid+1, h, key); 
    } 

    if(key >= arr[mid] && key <= arr[h]) 
        return func1(arr, mid+1, h, key); 
  
    return func1(arr, l, mid-1, key); 
} 

int main() {
	quick;
	//code
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int key;cin>>key;

	cout<<func1(arr,0,n-1,key);
	return 0;
}