/*
Given an array of integers of size N, you have to divide it into the minimum number of �strictly increasing subsequences�
For example: let the sequence be {1, 3, 2, 4}, then the answer would be 2. 
In this case, the first increasing sequence would be {1, 3, 4} and the second would be {2}.

Dilworth's theorem
https://en.wikipedia.org/wiki/Dilworth's_theorem

https://www.quora.com/What-will-be-the-best-algorithm-to-find-the-minimum-number-of-moves-to-completely-remove-all-elements-of-a-list-so-that-in-each-move-we-are-allowed-to-delete-any-increasing-subsequence-of-the-list
tldr; 
For any sequence the maximum length of a non-increasing subsequence is equal to the 
minimum number of increasing subsequences required to cover the sequence.

The minimum number of chains (aka 'the width') of a partially ordered set is the length of the longest 'antichain' in the partially ordered set.  
To apply this to your problem let i<pj be defined as i<j and ai<aj.

You're looking for the longest 'antichain'; the largest subset of elements from your partially ordered set that are all mutually uncomparable.  
Suppose we have an antichain and we order it by index and look at the corresponding values of a.  
The values of a must be non-increasing, otherwise they would be comparable.  
Therefore the longest antichain is the longest non-increasing subsequence.

There's actually an extension of this result where you can find the maximum number of elements you can cover with
 any fixed number of increasing subsequences using the RSK algorithm.
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

int MinimumNumIncreasingSubsequences( int A[], int n ) {
	int lis = 0; int L[n];
	for( int i = n-1; i >= 0; i-- ) {
		int pos = upper_bound(L,L+lis,A[i])-L;
		L[pos] = A[i];
		lis = max(lis,pos+1);
	} return lis;
}

int main() {
	int arr[] = { 8, 4, 1, 2, 9 }; 
    int n = sizeof(arr) / sizeof(int); 
    cout << "Minimum number of increasing subsequences are : "
         << MinimumNumIncreasingSubsequences(arr, n);
	return 0;
}

