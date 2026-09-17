#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 1e5 + 9, inf = INT_MAX;
int n, k;
int a[mxN], dp[mxN];

int f (int i)
{
    if (i >= n) return 0;

    if (dp[i] != -1)
        return dp[i];

    int ans = inf;

    for (int j = i+1; j <= min (n, i+k); j++)
    {
        ans = min (ans, abs (a[i]-a[j])+f(j));
    }
    
    return dp[i] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset (dp, -1, sizeof (dp));
    cin >> n >> k;
    for (int i = 1; i<=n;i++)
    {
        cin >> a[i];
    }
    
    cout << f (1) << endl;
    
    return 0;
}