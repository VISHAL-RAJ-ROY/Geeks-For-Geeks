/*
Given an array of n positive integers. 
We need to find the largest increasing sequence of consecutive positive integers.
*/
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define pb push_back
#define count_ones __builtin_popcountl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pow2(x) ((x) * (x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define init(A, val) memset(A, val, sizeof(A))

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0 / 0.0;

void findLIS(int A[], int n)
{
	unordered_map<int, int> m;
	m[A[0]] = 1;
	int ma = 1;
	for (int i = 1; i < n; i++)
		m[A[i]] = m[A[i] - 1] + 1, ma = max(ma, m[A[i]]);
	cout << ma << "\n";
	return;
}

int main()
{
	int A[] = {2, 5, 3, 7, 4, 8, 5, 13, 6};
	int n = sizeof(A) / sizeof(A[0]);
	findLIS(A, n);
	return 0;
}



