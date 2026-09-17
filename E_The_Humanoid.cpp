#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 2e5+9;
int n;
vector<ll> a;

int f (int i, int g, int b, ll h)
{
    while (i < n && a[i] < h)
    {
        h += a[i]/2;
        i++;
    }

    int ans = i;

    if (g == 0 && b == 0) return ans;

    if (g > 0)
    {
        ans = max (ans, f (i, g-1, b, h*2));
    }

    if (b > 0)
    {
        ans = max (ans, f (i, g, b-1, h*3));
    }

    return ans;
}

void solve ()
{
    ll h;
    cin >> n >> h;
    a.assign(n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort (a.begin(), a.end());

    cout << f(0, 2, 1, h) << endl;

    // for (auto x : a) cout << x << " ";
    // cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--)
        solve ();

    return 0;
}

