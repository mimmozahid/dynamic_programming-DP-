#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int N = 1e3 + 9, inf = 1e9;
int n, m, l, dp[N][N];
string a, b, c;

int f (int i, int j, int k)
{
    if (k >= l)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    
    int ans = inf;
    
    if (i < n)
    {
        if (a[i] == c[k])
            ans = min (ans, f (i+1, j, k+1));
        else
           ans = min (ans, 1+f(i+1, j, k+1));
    }

    if (j < m)
    {
        if (b[j] == c[k])
            ans = min (ans, f (i, j+1, k+1));
        else
            ans = min (ans, 1+f(i, j+1, k+1));
    }

    return dp[i][j] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        n = a.size(), m = b.size(), l = c.size();
        memset(dp, -1, sizeof (dp));
        cout << f (0, 0, 0) << endl;
    }
    
    return 0;
}