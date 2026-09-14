#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 1e2 + 9, SN = 1e5 + 9;
int n, a[mxN], dp[mxN][SN];

int dyP (int i, int sum)
{
    if (i == n)
        return sum == 0;

    if (dp[i][sum] != -1)
        return dp[i][sum];
    
    int ans = 0;

    if (a[i] <= sum)
        ans += dyP (i+1, sum-a[i]);

    ans += dyP (i+1, sum);

    return dp[i][sum] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    ll sum = 0;
    memset (dp, -1, sizeof (dp));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> ans;
    for (int targetSum = 1; targetSum <= sum; targetSum++)
    {
        if (dyP (0, targetSum))
        {
            ans.push_back (targetSum);
        }
    }

    
    cout << ans.size () << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}