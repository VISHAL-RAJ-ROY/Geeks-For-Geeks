/*
Given an array, the task is to find to LIS (Longest Increasing Subsequence) in a circular way.

Example:
Input : arr[] = {5, 4, 3, 2, 1}
Output : 2
Although there is no LIS in a given array 
but in a circular form there can be
{1, 5}, {2, 5}, ...... 

Input : arr[]= {5, 6, 7, 1, 2, 3}
Output : 6
{1, 2, 3, 5, 6, 7} will be the LIS in the
circular manner.
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define count_ones __builtin_popcountl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pow2(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define init(A,val) memset(A,val,sizeof(A))

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;

int lis( int a[], int j, int n ) {
	int lis = 0; int l[n]; 
	for( int i = 0; i < n; i++, j++ ) {
		int pos = lower_bound(l,l+lis,a[j%n])-l;
		l[pos] = a[j%n];
		lis = max(lis,pos+1);
	}
	return lis;
}

int LICS( int arr[], int n ) {
	int ma = 1;
	for( int i = 0; i < n; i++ ) ma = max(ma,lis(arr,i,n));
	return ma;
}

int main() {
	int arr[] = { 1, 4, 6, 2, 3 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Length of LICS is " << LICS( arr, n ); 
	return 0;
}

