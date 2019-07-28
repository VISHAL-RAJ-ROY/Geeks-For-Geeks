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

int CountPS( string & s ) {
	int n = s.length();
	int P[n][n], dp[n][n]; init(P,0); init(dp,0); for( int i = 0; i < n; i++ ) P[i][i] = dp[i][i] = 1;
	for( int i = 0; i < n-1; i++ ) if( s[i] == s[i+1] ) P[i][i+1] = 1;
	for( int l = 2; l <= n; l++ ) {
		for( int i = 0; i+l-1 < n; i++ ) {
			int j = i+l-1;
			if( s[i] == s[j] && P[i+1][j-1] ) P[i][j] = 1;
			dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+P[i][j];
		}
	} 
	return dp[0][n-1];
}

int main() {
	string s = "abaab"; 
    cout << CountPS(s) << endl; 
	return 0;
}

