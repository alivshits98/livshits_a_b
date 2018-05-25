#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <algorithm>
#include <tuple>
#include <Windows.h>

#define endl "\n"
#define ft first
#define sd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define deb(x) for(auto temp : (x))cout<<temp<<" ";cout<<endl;
#define debs(x) cout<<(x).size()<<": ";for(auto temp : (x))cout<<temp<<" ";cout<<endl;
#define cin_ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef tuple<int, int, int> t3;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<db> vdb;
typedef vector<vpii> vvpii;
typedef vector<pair<int, pii>> vpipii;
typedef vector<vector<pll>> vvpll;

const int inf = 1e9 + 7;
const db eps = 1e-9;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main()
{
    cin_;

#ifndef _DEBUG
    freopen("INPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);
#endif

    long long n, //verteces
        //m, //edges
        s, //start
        f; //finish
    cin >> n >> s >> f;
    --s;
    --f;
    vi I, J, H, L, W;
    H.assign(n, -1);
    //I.assign(m, 0);
    //J.assign(m, 0);
    //W.assign(m, 0);
    //L.assign(m, 0);
    
    //vvpll g(n);
    ll w;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> w;
            if (w == -1)
            {
                continue;
            }
            I.push_back(i);
            J.push_back(j);
            W.push_back(w);
            //g[i].push_back(mp(j, w));
        }
    }
    //long long u, v, w;
    //for (long long i = 0; i < m; ++i)
    //{
    //    cin >> v >> u >> w;
    //    --v;
    //    --u;
    //    g[v].push_back(mp(u, w));
    //    //g[u].push_back(mp(v, w));
    //    I[i] = v;
    //    J[i] = u;
    //    W[i] = w;
    //}
    L.assign(I.size(), -1);

    for (int k = 0; k < I.size(); ++k)
    {
        int i = I[k];
        L[k] = H[i];
        H[i] = k;
    }

    //ll v, u;
    //vl  d1(n, inf), 
    //    p1(n, -1);
    //d1[s] = 0;

    //priority_queue<pll> q1;
    //q1.push(mp(0, s));
    //while (!q1.empty())
    //{
    //    v = q1.top().second;
    //    int dv1 = -q1.top().first;
    //    q1.pop();
    //    if (dv1 > d1[v])
    //        continue;
    //    //standard algorithm
    //    for (ll j = 0; j < g[v].size(); j++)
    //    {
    //        u = g[v][j].first;
    //        w = g[v][j].second;
    //        if (d1[u] > d1[v] + w)
    //        {
    //            d1[u] = d1[v] + w;
    //            p1[u] = v;
    //            q1.push(mp(-d1[u], u));
    //        }
    //    }
    //}

    ll v, u;

    //using arc beams
    vl  d2(n, inf),
        p2(n, -1);
    d2[s] = 0;

    priority_queue<pll> q2;
    q2.push(mp(0, s));
    while (!q2.empty())
    {
        v = q2.top().second;
        int dv2 = -q2.top().first;
        q2.pop();
        if (dv2 > d2[v])
            continue;

        for (ll j = H[v]; j != -1; j = L[j])
        {
            u = J[j];
            w = W[j];
            if (d2[u] > d2[v] + w)
            {
                d2[u] = d2[v] + w;
                p2[u] = w;
                q2.push(mp(-d2[u], u));
            }
        }
    }
    if (d2[f] == inf)
        cout << -1 << " ";
    else
        cout << d2[f] << " ";


    //cout << "Dijkstra with arc beams: " << endl;
    //for (int i = 0; i < d2.size(); ++i)
    //    cout << d2[i] << " ";

    //cout << endl << "Standard Dijkstra algorithm: " << endl;
    //for (int i = 0; i < d1.size(); ++i)
    //    cout << d1[i] << " ";

    ////dist from s to all
    //for (int i = 0; i < d.size(); ++i)
    //{
    //    if (d[i] == inf)
    //        cout << -1 << " ";
    //    else
    //        cout << d[i] << " ";
    //}
    //cout << endl;

    //if (d[f] == inf)
    //    cout << -1 << endl;
    //else
    //{
    //    long long x = f;
    //    vector<int> ans;
    //    //ans.push_back(x);

    //    while (x != s)
    //    {
    //        ans.push_back(x);
    //        x = p[x];
    //    }

    //    ans.push_back(x);
    //    cout << ans.size() << endl;
    //    reverse(ans.begin(), ans.end());
    //    for (int i = 0; i<ans.size(); ++i)
    //        cout << ans[i] << " ";

    return 0;
}