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

ll pre_compute( ll a[], ll n, int index, int k ) {
	ll dp[n][n] = {0}; dp[0][0] = a[0];
	for( int i = 1; i < n; i++ ) dp[0][i] = a[i] + (a[i] > a[0] ? a[0] : 0);
	for( int i = 1; i < n; i++ ) {
		for( int j = 0; j < n; j++ ) {
			if( a[j] > a[i] && j > i && a[j]+dp[i-1][i] > dp[i-1][j] ) dp[i][j] = a[j]+dp[i-1][i];
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[index][k];
}

int main() {
	ll a[] = { 1, 101, 2, 3, 100, 4, 5 }; 
    ll n = sizeof(a) / sizeof(a[0]); 
    ll index = 4, k = 6; 
    printf("%lld", pre_compute(a, n, index, k));
	return 0;
}

