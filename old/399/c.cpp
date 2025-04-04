#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> g;
vector<int> vis;

void dfs(int c) {
  vis[c] = true;
  for (auto& d : g[c]) {
    if (vis[d]) continue;
    dfs(d);
  }
}

int main() {
  cin >> N >> M;
  g.resize(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int ans = 0;
  vis.resize(N);
  for (int i = 0; i < N; i++) {
    if (!vis[i]) ans++, dfs(i);
  }
  cout << M - (N-ans) << endl; 

}
