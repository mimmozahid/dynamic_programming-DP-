#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 1e5 + 9, INF = 2e9;
int n, a[mxN], dp[mxN];

int dyP (int i)
{
    if (i == n)
        return 0;
    
    if (dp[i] != -1)
        return dp[i];
    
    int ans = INF;

    if (i+1 <= n)
        ans = min (ans, abs (a[i] - a[i+1]) + dyP(i+1));

    if (i+2 <= n)
        ans = min (ans, abs (a[i] - a[i+2]) + dyP(i+2));

    return dp[i] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) dp[i] = -1;
    
    cout << dyP(1) << endl;
    
    return 0;
}