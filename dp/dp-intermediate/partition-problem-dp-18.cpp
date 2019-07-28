/*
Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.
Also print the sets.
*/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define pb push_back

void print( vector <int> & v ) {
	for( int i = 0; i < v.size(); i++ ) cout<<v[i]<<" "; cout<<"\n";
}

int decide( int A[], int n ) {
	int sum = 0;
	for( int i = 0; i < n; i++ ) sum += A[i]; if( sum%2 == 1 ) return 0;
 	vector <vector <int> > dp(sum/2+1,vector <int>(n,0));
	dp[0][A[0]] = 1; for( int i = 0; i < n; i++ ) dp[i][0] = 1;
	for( int i = 1; i < n; i++ ) {
		for( int j = 1; j < sum/2+1; j++ ) {
			dp[i][j] = dp[i-1][j];
			if( j >= A[i] ) dp[i][j] = dp[i][j] || dp[i-1][j-A[i]]; 
		}
	}
	cout<<dp[n-1][sum/2]<<"\n";
	int h = n-1;
	int s = sum/2;
	vector <int> s1,s2;
	while( h >= 0 ) {
		if( !s ) {
			s2.pb(h); h--;	
		} else if( h > 0 ) { 
			if(dp[h-1][s-A[h]]) s1.pb(A[h]), s -= A[h];
			else if( dp[h-1][s] ) s2.pb(A[h]);
			h--;
		} else if( !h ) {
			if( s > 0 ) s1.pb(A[0]); else s2.pb(A[0]); break;
		}
	}
	print(s1); print(s2);
	return dp[n-1][sum/2];
}

int main() {
	int arr[] ={5, 5, 1, 11}; 
  	int n = sizeof(arr)/sizeof(arr[0]);
  	cout<<decide(arr,n)<<"\n";
	return 0;
}
