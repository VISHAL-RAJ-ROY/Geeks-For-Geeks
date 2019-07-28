#include <bits/stdc++.h>/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <priority_queue>
#include <bits/stdc++.h>*/

using namespace std;

#define pb push_back
#define count_ones __builtin_popcountl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pow2(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;
vector <int> in,de;

void inc( int A[], int n ) {
	int lis = 0; in[0] = 0;
	vector <int> L(n,0);
	for( int i = 0; i < n; i++ ) {
		int pos = lower_bound(L.begin(),L.begin()+lis,A[i])-L.begin();
		L[pos] = A[i];
		if( pos+1>lis ) lis = pos+1; in[i+1] = lis;
	}
}

void dec( int A[], int n ) {
	de[n] = 0; int lis = 0;
	vector <int> L(n,0);
	for( int i = n-1; i >= 0; i-- ) {
		int pos = lower_bound(L.begin(),L.begin()+lis,A[i])-L.begin();
		L[pos] = A[i];
		if( pos+1>lis ) lis = pos+1; de[i] = lis;
	}
}

int main() {
	int arr[] = {80, 60, 30, 40, 20, 10}; 
  	int n = sizeof(arr)/sizeof(arr[0]); in.assign(n+1,0); de.assign(n+1,0); 
  	inc(arr,n); dec(arr,n); int ma = -1;
  	for( int i = 0; i < n+1; i++ ) ma = max(ma, in[i]+de[i]);
  	cout<<ma<<"\n";
	return 0;
}

