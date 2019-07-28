#include <bits/stdc++.h>

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

int lps( string & s ) {
	int m = s.length();
	vector <int> a(m,0);
	int backup;
	for( int i = m-1; i >= 0; i-- ) {
		backup = 0;
		for( int j = i; j < m; j++ ) {
			if( i == j ) {
				a[i] = 1;
			} else if( s[i] == s[j] ) {
				int temp = a[j];
				a[j] = backup+2; 
				backup = temp;
			} else {
				backup = a[j];
				a[j] = max(a[j],a[j-1]);
			}
		}
	}
	return a[m-1];
}

int main() { 
	string str = "GEEKSFORGEEKS"; 
    cout << lps(str); 
	return 0;
}

