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

int las( int A[], int n ) {
	int in[n], de[n]; for( int i = 0; i < n; i++ ) in[i] = de[i] = 1; int ma = -1; 
	for( int i = 1; i < n; i++ ) {
		for( int j = 0; j < i; j++ ) {
			if( A[i] > A[j] ) in[i] = max(1+de[j],in[i]);
			else if( A[j] > A[i] ) de[i] = max(1+in[j],de[i]); 
			ma = max3(ma,in[i],de[i]);
		}
	} 
	return ma;
}

int main() {
	int arr[] = {1, 5, 4};// {1, 4, 5};//{ 10, 22, 9, 33, 49, 50, 31, 60 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Length of Longest alternating subsequence is %d\n", 
            las(arr, n) ); 
	return 0;
}

