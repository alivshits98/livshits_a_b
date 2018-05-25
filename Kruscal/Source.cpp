//минимальное остовное дерево
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<tiii> vtiii;

struct Graph
{
    struct dsu
    {
        vector<ll>p, r;

        dsu() {};

        dsu(ll n)
        {
            p.resize(n);
            r.assign(n, 1);
            for (ll i = 0; i < n; ++i)
                p[i] = i;
        }

        ll find_root(ll ind)
        {
            ll res = ind;
            while (res != p[res])
                res = p[res];

            while (res != ind)
            {
                ll temp = ind;
                ind = p[ind];
                p[temp] = res;
            }
            return res;
        }

        void union_(ll a, ll b)
        {
            a = find_root(a);
            b = find_root(b);
            if (a == b)
                return;
            if (r[a] < r[b])
                swap(a, b);
            p[b] = a;
            r[a] += r[b];
        }
    };

    ll n; //number of vertices
    vtiii g; //graph

    Graph(vtiii edge, ll n)
        : g(edge)
        , n(n)
    {
    }

    ll kruscall()
    {
        sort(g.begin(), g.end());
        dsu d(n);
        ll res = 0;

        for (ll i = 0; i < g.size(); ++i)
        {
            ll from = get<1>(g[i]),
                to = get<2>(g[i]),
                w = get<0>(g[i]);
            if (d.find_root(from) != d.find_root(to))
            {
                res += w;
                d.union_(from, to);
            }
        }
        return res;
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;

    vvpii g(n, vpii());
    vtiii edge(m);
    ll b, e, w;
    for (ll i = 0; i < m; ++i)
    {
        cin >> b >> e >> w;
        b--;
        e--;
        edge[i] = tie(w, b, e);
    }
    Graph gr(edge, n);
    cout << gr.kruscall() << endl;

    return 0;
}
