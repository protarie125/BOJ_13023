#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;

ll n, m;
vvl adj;

vl added{};
vb visit{};
bool dfs(ll idx, ll b) {
  if (added.size() == 5) {
    return true;
  }

  for (const auto& y : adj[idx]) {
    if (visit[y]) continue;

    added.push_back(y);
    visit[y] = true;
    const auto& ans = dfs(y, b);
    if (ans) {
      return true;
    }
    added.pop_back();
    visit[y] = false;
  }

  return false;
}

bool solve() {
  for (auto i = 0; i < n; ++i) {
    added = vl{i};
    visit = vb(n, false);
    visit[i] = true;
    const auto& ans = dfs(i, i);
    if (ans) {
      return true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;
  adj = vvl(n, vl{});
  for (auto i = 0; i < m; ++i) {
    ll a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  const auto& ans = solve();
  if (ans) {
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}