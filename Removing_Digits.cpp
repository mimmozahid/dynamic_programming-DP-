#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 1e6 + 9, inf = 1e9;
vector<int> dp (mxN, -1);

int f (int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = inf;
    int a = n;

    while (a > 0)
    {
        int rem = a%10;
        if (rem > 0)
        {
            ans = min (ans, 1 + f (n-rem));
        }
        a/=10;
    }
    return dp[n] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    cout << f (n) << endl;
    
    return 0;
}