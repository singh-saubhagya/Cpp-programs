#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int vertex, cost;
};

vector<vector<Node>> graph;

bool loadGraph(const string &file, int &n)
{
    ifstream in(file);
    if (!in)
        return false;
    in >> n;
    if (n <= 0)
        return false;

    graph.assign(n + 1, {});
    for (int i = 1; i <= n; i++)
    {
        int deg;
        in >> deg;
        for (int j = 0; j < deg; j++)
        {
            int v, w;
            in >> v >> w;
            graph[i].push_back({v, w});
        }
    }
    in.close();
    return true;
}

void primAlgorithm(int n)
{
    vector<int> dist(n + 1, INT_MAX), parent(n + 1, -1);
    vector<int> used(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    dist[1] = 0;
    minHeap.push({0, 1});

    while (!minHeap.empty())
    {
        int u = minHeap.top().second;
        minHeap.pop();
        if (used[u])
            continue;
        used[u] = 1;

        for (auto &edge : graph[u])
        {
            int v = edge.vertex, w = edge.cost;
            if (!used[v] && w < dist[v])
            {
                dist[v] = w;
                parent[v] = u;
                minHeap.push({w, v});
            }
        }
    }

    int total = 0;
    cout << "Prim's MST:\n";
    for (int i = 2; i <= n; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << " - " << i << " (" << dist[i] << ")\n";
            total += dist[i];
        }
    }
    cout << "Total weight = " << total << "\n";
}

int main()
{
    int n;
    string inputFile = "Q1_input.txt";
    if (loadGraph(inputFile, n))
        primAlgorithm(n);
    else
        cout << "Error reading input.\n";
    return 0;
}
