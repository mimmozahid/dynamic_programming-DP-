#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int ans = INT_MIN;
int a[15][15];
int n,m;
vector<pair<int, int>> d = {{0, 1}, {1, 0}};

bool valid (int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    return true;
}

void dfs (int si, int sj, int cur)
{
    cur += a[si][sj];
    if (si == n-1 && sj == m-1)
    {
        ans = max (cur, ans);
        return;
    }

    for (auto x : d)
    {
        int ci = si + x.first;
        int cj = sj + x.second;

        if (valid (ci, cj))
            dfs (ci, cj, cur);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    dfs (0, 0, 0);

    cout << ans << endl;
    
    return 0;
}