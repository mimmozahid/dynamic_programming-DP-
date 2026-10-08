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

int KnapSack (int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
        return 0;

    if (dp[i][mx_weight] != -1)
        return dp[i][mx_weight];
    
    if (weight[i] <= mx_weight)
    {
        int op1 = KnapSack (i-1, mx_weight - weight[i]) + val[i];
        int op2 = KnapSack (i-1, mx_weight);
        return dp[i][mx_weight] = max (op1, op2);
    }
    else
    {
        int op2 = KnapSack (i-1, mx_weight);
        return dp[i][mx_weight] = op2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    
    int mx_weight;
    cin >> mx_weight;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= mx_weight; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << KnapSack (n, mx_weight) << endl;
    
    return 0;
}