#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int val[1005], weight[1005];
int dp[1005][1005];

int Knapsack (int i, int w)
{
    if (i < 0 || w <= 0)
        return 0;
    
    if (dp[i][w] != -1)
        return dp[i][w];

    if (weight[i] <= w)
    {
        int op1 = Knapsack (i-1, w - weight[i]) + val[i];
        int op2 = Knapsack (i-1, w);
        return dp[i][w] = max (op1, op2);
    }
    else
    {
        return dp[i][w] = Knapsack (i-1, w);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> val[i];
    }
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    cout << Knapsack (n-1, w) << endl;
    
    return 0;
}