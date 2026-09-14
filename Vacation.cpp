#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 1e5 + 9;
int n, a[mxN][3], dp[mxN][3];

int dyP (int i, int last)
{
    if (i == n)
    {
        return 0;
    }
    int ans = INT_MIN;

    if (dp[i][last] != -1)
    {
        return dp[i][last];
    }

    for (int k = 0; k < 3; k++)
    {
        if (k == last) continue;

        ans = max (ans, a[i][k] + dyP(i+1, k));
    }
    return dp[i][last] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2]; 
    }

    memset (dp, -1, sizeof(dp));

    cout << dyP (0, 4) << endl;
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
    // }
    
    return 0;
}