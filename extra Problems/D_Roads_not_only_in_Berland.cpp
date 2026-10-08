#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

struct DSU
{
    vector<int> par, rank, siz, mini, maxi;
    int component;

    DSU (int n) : par(n+1), rank (n+1, 0), siz (n+1, 1), component(n), mini (n+1, -1), maxi (n+1, -1)
    {
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            mini[i] = maxi[i] = i;
        }
    }

    int find (int i)
    {
        return par[i] == i ? i : (par[i] = find (par[i]));
    }

    bool isSame (int u, int v)
    {
        return find(u) == find (v);
    }

    int getSize (int v)
    {
        return siz[find (v)];
    }

    int cntComponent()
    {
        return component;
    }

    void _union (int u, int v)
    {
        if ((u = find (u)) == (v = find (v)))
        {
            return;
        }
        else
        {
            component--;
        }

        if (rank[u] > rank[v])
        {
            swap (u, v);
        }
        else if (rank[u] == rank[v])
        {
            rank[v]++;
        }

        par[u] = par[v];
        siz[v] += siz[u];
        mini[v] = min (mini[u], mini[v]);
        maxi[v] = max (maxi[u], maxi[v]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    DSU d(n);

    vector<pair<int, int>> rv, cre;

    for (int i = 0; i < n-1; i++)
    {
        int u , v;
        cin >> u >> v;
        if (d.isSame(u, v))
        {
            rv.push_back ({u, v});
        }
        else
            d._union (u, v);
    }
    
    for (int i = 2; i <= n; i++)
    {
        if (!d.isSame (1, i))
        {
            cre.push_back ({1, i});
            d._union (1, i);
        }
    }
    
    cout << rv.size () << endl;
    for (int i = 0; i < rv.size(); i++)
    {
        cout << rv[i].first << " " << rv[i].second << " " << cre[i].first << " " << cre[i].second << endl;
    }
    
    
    return 0;
}