#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n+1), dp(n+1, -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dp[1] = 0;
    dp[2] = abs (a[1]-a[2]);
    
    for (int i = 3; i <= n; i++)
    {
        dp[i] = min (dp[i-1] + abs (a[i-1]-a[i]), dp[i-2] + abs (a[i-2]- a[i]));
    }
    
    cout << dp[n] << endl;
    
    return 0;
}