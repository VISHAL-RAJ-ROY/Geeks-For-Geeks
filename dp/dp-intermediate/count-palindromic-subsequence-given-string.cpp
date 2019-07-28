/*
gfg has not missed any cases in the dp statement below 

Else if (str[i] == str[j)]
return countPS(i+1, j) + countPS(i, j-1) + 1;
else
return countPS(i+1, j) + countPS(i, j-1) - countPS(i+1, j-1)

Reason:

Case 1
Lets suppose our string looks like this A..............A. Let the A at front is at ith position and the A at end is at jth position.

Since str[i] == str[j] 
Let countPS[i+1][j-1] = x be no of palindromic subsequences in string str between i+1 and j -1.

Now if we append and prepend A on both sides of each of these x palindromic subsequences we get new 
x no of palindromic subsequences in range i to j which are different from previous x no of subsequences between i+1 and j-1.

Now till now how many substrings we have between i and j = x+x+1
(1 because of subsequences AA)

We now need to consider subsequences coming from

countPS(i+1, j) (here x no of subsequence are repeatedly counted)
countPS(i, j-1) (here x no of subsequence are repeatedly counted)

So new palindromic subsequence we got

(countPS(i+1, j) - x) + (countPS(i, j-1) -x)+(x+x+1)
= . countPS(i+1, j) + countPS(i, j-1) + 1 . So though we need to consider the contribution of countPS(i+1, j-1) or x but it gets cancelled . 
Thats why the above equation is correct .

Case 2
Lets suppose our string looks like this A..............B. Let the A at front is at ith position and the A at end is at jth position. A != B.

Since str[i] != str[j] 
Let countPS[i+1][j-1] = x be no of palindromic subsequences in string str between i+1 and j -1.

Now we donot get new x no of palindromic subsequences in range i to j by appending A on both sides of previous
 x no of subsequences between i+1 and j-1 because A != B.

So now x will be addedonly once and substracted twice .
So we see it as a negative term in the statement.
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

int countPS( string & s ) {
	int n = s.length();
	int dp[n+1][n+1]; init(dp,0);
	for( int i = 0; i < n; i++ ) dp[i][i] = 1;
	for( int l = 2; l <= n; l++ ) {
		for( int i = 0; i+l-1 < n; i++ ) {
			int j = i+l-1;
			if( s[i] == s[j] ) dp[i][j] = 1+dp[i][j-1]+dp[i+1][j];
			else dp[i][j] = dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
		}
	} 
	return dp[0][n-1];
}

int main() {
	string str = "abcb"; 
	cout << "Total palindromic subsequence are : "
		<< countPS(str) << endl; 
	return 0;
}

