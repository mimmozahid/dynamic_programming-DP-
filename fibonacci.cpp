#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

vector<ll> dp;

ll fibo (int n)
{
    if (n == 1 || n == 0)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fibo (n-1) + fibo (n-2);

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;

    dp.assign (n+9, -1);
    
    cout << fibo (n) << endl;
    
    return 0;
}