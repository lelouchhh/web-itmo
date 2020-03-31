
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
int n, m, fa[2][20010][20], dist[20010], val[20010];
vector<int> G[20010];

int bfs(int x, int k)
{
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(x); dist[x] = 0;
    int ret = x, len = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (dist[v] != -1) continue;
            q.push(v);
            dist[v] = dist[u] + 1;
            fa[k][v][0] = u; 
            if (dist[v] > len) len = dist[v], ret = v;
        }
    }
    for (int i = 1; i < n+1; i++)
        val[i] = max(val[i], dist[i]);
    return ret;
}

int query(int vi, int di, int k)
{
    int r = 19;
    while (di)
    {
        while ((1 << r) > di) r--;
        vi = fa[k][vi][r];
        di -= (1 << r);
    }
    return vi;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++)
        G[i].clear();
    int u, v, vi, di;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    memset(val, 0, sizeof(val));
    memset(fa, -1, sizeof(fa));
    int st, ed;
    st = bfs(1, 0); ed = bfs(st, 0); bfs(ed, 1);
    fa[0][st][0] = st;
    fa[1][ed][0] = ed;
    for (int k = 0; k < 2; k++)
        for (int j = 1; j < 20; j++)
            for (int i = 1; i < n + 1; i++)
                if (fa[k][i][j - 1] != -1)
                    fa[k][i][j] = fa[k][fa[k][i][j - 1]][j - 1];

    while (m--)
    {
        cin >> vi >> di;
        if (val[vi] < di) cout << "0" << endl;
        else if (dist[vi] == val[vi]) cout << query(vi, di, 1) << endl;
        else cout << query(vi, di, 0) << endl;
    }

    return 0;
}