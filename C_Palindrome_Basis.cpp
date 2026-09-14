#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 4e4+9, M = 5e2;
vector<int> palindrom;
ll dp[M][mxN];

void palin ()
{
    for (int i = 1; i <= mxN; i++)
    {
        string s = to_string(i), t = s;
        reverse(t.begin(), t.end());
        if (t == s)
        palindrom.push_back (i);
    }
}

ll dyP (int i, int sum)
{
    if (i >= palindrom.size())
        return (sum == 0);

    if (dp[i][sum] != -1)
        return dp[i][sum];
    
    ll ans = 0;
    
    if (palindrom[i] <= sum)
        ans += dyP (i, sum - palindrom[i]) % MOD;
    
    ans += dyP (i+1, sum) % MOD;
    
    return dp[i][sum] = ans % MOD;
}

void solve ()
{
    int n;
    cin >> n;
    cout << dyP(0, n) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    palin();
    memset (dp, -1, sizeof (dp));
    int t = 1;
    cin >> t;
    while (t--)
        solve ();

    return 0;
}

