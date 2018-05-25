//минимальное остовное дерево

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<tiii> vtiii;


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
    void print()
    {
        for (int i = 0; i < p.size(); ++i)
        {
            if (p[i] != -1)
                cout << i << "->" << p[i] << endl;
            else
                cout << i << endl;
        }
    }
    void reset(int n)
    {
        p.resize(n);
        r.assign(n, 1);
        for (int i = 0; i < n; ++i)
        {
            p[i] = i;
        }
    }
};
int main()
{
    string s;
    int n = 0, m, x, y;
    dsu dsu_;
    while (cin >> s)
    {
        if (s == "RESET")
        {
            cin >> n;
            dsu_.reset(n + 1);
            if (n != 0)
                cout << "RESET DONE" << endl;
        }
        if (s == "JOIN")
        {
            cin >> x >> y;
            if (dsu_.find_root(x) != dsu_.find_root(y))
            {
                dsu_.union_(x, y);
            }
            else
            {
                cout << "ALREADY " << x << " " << y << endl;
            }
        }
        if (s == "CHECK")
        {
            cin >> x >> y;
            if (dsu_.find_root(x) != dsu_.find_root(y))
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }

        }
    }
};