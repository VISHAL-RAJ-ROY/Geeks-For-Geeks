/*
You are given an array A of size N. Your task is to find the length of largest dividing sub sequence.
A dividing sequence is a sequence a1, a2, �, aN where ai divides aj whenever i < j. 
For example, 3, 15, 60, 720 is a dividing sequence.
*/
#include <bits/stdc++.h>

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

class UF
{
private:
	int N;
	vector<int> r, p;

public:
	UF(int n)
	{
		r.assign(n, 0);
		p.assign(n, -1);
		for (int i = 0; i < n; i++)
			p[i] = i;
		N = n;
	}
	bool issame(int i, int j)
	{
		return findset(i) == findset(j);
	}
	int findset(int i)
	{
		return (p[i] == i) ? i : (p[i] = findset(p[i]));
	}
	void join(int i, int j)
	{
		int x = findset(i), y = findset(j);
		if (r[x] < r[y])
		{
			p[x] = y;
		}
		else
		{
			p[y] = x;
			if (r[x] == r[y])
				r[x]++;
		}
	}
};

int lds(int A[], int n)
{
	int dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = 1;
	int ma = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[i] % A[j] == 0)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ma = max(dp[i], ma);
	}
	return ma;
}

int main()
{
	int arr[] = {2, 11, 16, 12, 36, 60, 71, 17,
				 29, 144, 288, 129, 432, 993};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Length of lds is %d\n", lds(arr, n));
	return 0;
}
