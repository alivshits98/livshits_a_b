#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>

using namespace std;

int main()
{
#ifndef _DEBUG
    freopen("INPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);
#endif
    //unordered_set<int> q1, q2;
    int n, m;
    cin >> n >> m;

    //матрица смежности
    unordered_map<int, unordered_map<int, int>> g;
    int from, to, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> from >> to >> w;
        if ((g[from].find(to) == g[from].end())||(g[from].find(to) != g[from].end() && g[from][to] > w))
            g[from][to] = w;
    }

    vector<int> r(n + 1, 30000);
    r[1] = 0;
    deque<int>q;
    q.push_back(1);

    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (auto it = g[v].begin(); it != g[v].end(); ++it)
        {
             to = it->first;
             w = it->second;
             if (r[v] + w < r[to])
             {
                 r[to] = r[v] + w;
                 q.push_back(to);
             }
        }
    }

    for (int i = 1; i < n + 1; ++i)
    {
        cout << r[i] << " ";
    }

    return 0;
}