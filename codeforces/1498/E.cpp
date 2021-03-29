#include "bits/stdc++.h"
#define FI first.first
#define SE first.second
#define TH second
#define fi first
#define se second
#define th second

using namespace std;

string to_string(const string& str) {
  return str;
}

template<typename T>
string to_string(const set<T>& mys) {
  if(mys.empty()) return "{}";
  string ret = "{";
  for(auto el: mys) ret += to_string(el) + ", ";
  ret.pop_back(), ret.pop_back(); // Remove last space and comma
  ret += "}";
  return ret;
}

template<typename T>
string to_string(const pair<T, T>& pr) {
  return "(" + to_string(pr.fi) + "," + to_string(pr.se) + ")";
}

template<typename T>
string to_string(const vector<T>& vc, int w) {
  if(vc.empty()) return "";
  if(w + 1 == vc.size()) return to_string(vc[w]);
  return to_string(vc[w]) + "," + to_string(vc, w + 1);
}

template<typename T>
string to_string(const vector<T>& vc) {
  return "{" + to_string(vc, 0) + "}";
}

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class DebugStream {}LOG;
template <typename T>DebugStream &operator<<(DebugStream &s, const T&) { return s; }
#ifdef DEBUG
#define LOG clog
#endif

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 1e5 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20, bs = 29;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  #ifdef DEBUG
  //freopen("input.txt", "r", stdin);
  #endif

  int n;
  cin >> n;
  vector<int> inc(n), inds(n);
  iota(inds.begin(), inds.end(), 0);
  for(auto& el: inc) cin >> el;
  sort(inds.begin(), inds.end(), [&](int a, int b) {
    return inc[a] < inc[b];
  });

  for(int u = n - 1; u >= 0; u--) {
    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        if(inc[inds[j]] - inc[inds[i]] != u) continue;
        cout << "? " << inds[j] + 1 << ' ' << inds[i] + 1 << '\n';
        cout.flush();
        string resp;
        cin >> resp;
        if(resp == "Yes") {
          cout << "! " << inds[i] + 1 << ' ' << inds[j] + 1 << '\n';
          exit(0);
        }
      }
    }
  }
  cout << "! 0 0\n";
}

