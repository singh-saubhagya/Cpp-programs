#include <bits/stdc++.h>
using namespace std;

struct EdgeInfo {
    int src, dest, cost;
};

vector<EdgeInfo> edgeList;
vector<int> leader, depthRank;

int getRoot(int x) {
    if (leader[x] != x) leader[x] = getRoot(leader[x]);
    return leader[x];
}

void mergeSets(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a == b) return;
    if (depthRank[a] < depthRank[b]) swap(a, b);
    leader[b] = a;
    if (depthRank[a] == depthRank[b]) depthRank[a]++;
}

bool loadData(const string &file, int &n) {
    ifstream in(file);
    if (!in) return false;
    in >> n;
    if (n <= 0) return false;

    for (int i = 1; i <= n; i++) {
        int deg;
        in >> deg;
        for (int j = 0; j < deg; j++) {
            int v, w;
            in >> v >> w;
            if (i < v) edgeList.push_back({i, v, w});
        }
    }
    in.close();
    return true;
}

void kruskalMST(int n) {
    sort(edgeList.begin(), edgeList.end(), [](auto &a, auto &b) {
        return a.cost < b.cost;
    });

    leader.resize(n + 1);
    depthRank.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) leader[i] = i;

    int totalWeight = 0;
    cout << "Kruskal's MST:\n";
    for (auto &e : edgeList) {
        if (getRoot(e.src) != getRoot(e.dest)) {
            mergeSets(e.src, e.dest);
            totalWeight += e.cost;
            cout << e.src << " - " << e.dest << " (" << e.cost << ")\n";
        }
    }
    cout << "Total weight = " << totalWeight << "\n";
}

int main() {
    int n;
    string fileName = "Q2_input.txt";
    if (loadData(fileName, n)) kruskalMST(n);
    else cout << "Error reading input file.\n";
    return 0;
}
