#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

ll val[1005], wig[1005];

ll dp[105][100005];

ll knapsack (int i, int w)
{
    if (i < 0 || w <= 0)
        return 0;

    if (dp[i][w] != -1)
        return dp[i][w];
    
    if (wig[i] <= w)
    {
        ll op1 = knapsack (i-1, w-wig[i]) + val[i];
        ll op2 = knapsack (i-1, w);

        return dp[i][w] = max (op1, op2);
    }
    else
        return dp[i][w] = knapsack (i-1, w);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, w;
    cin >> n >> w;

    
    for (int i = 0; i < n; i++)
    {
        cin >> wig[i];
        cin >> val[i];
    }
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack (n-1, w) << endl;
    
    return 0;
}
