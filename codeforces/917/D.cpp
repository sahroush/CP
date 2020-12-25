/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 120;
const ll mod = 1e9 + 7;
const ld PI = acos((ld) - 1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x, exit(0)
#define migmig ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ms(x, y) memset(x, y, sizeof x)
ll pw(ll a, ll b, ll md = mod) {ll res = 1;while (b) {if (b & 1) {res = (a * res) % md;}a = (a * a) % md;b >>= 1;}return (res);}

int n;
vector < int > adj[maxn];
int fact[maxn], inv[maxn];
int ans[maxn];

int C(int r, int n) {
    return (((fact[n] * 1LL * inv[r]) % mod * 1LL * inv[n - r]) % mod);
}

int dp[maxn][maxn][maxn];
int sz[maxn];

void dfs(int v = 1, int par = 0) {
    sz[v] = dp[v][0][1] = 1;
    for (int u: adj[v])
        if (u != par) {
            dfs(u, v);
            for (int i = sz[v] - 1; ~i; i--)
                for (int k = i + 1; k; k--) {
                    ll x = dp[v][i][k];
                    dp[v][i][k] = 0;
                    for (int j = sz[u] - 1; ~j; j--)
                        for (int l = j + 1; l; l--)
                            dp[v][i + j][k] = (dp[v][i + j][k] + ((x * 1LL * dp[u][j][l]) % mod * l) % mod) % mod,
                            dp[v][i + j + 1][k + l] = (dp[v][i + j + 1][k + l] + (x * 1LL * dp[u][j][l]) % mod) % mod;
                }
            sz[v] += sz[u];
        }
}

int32_t main() {
    migmig;
    cin >> n;
    fact[0] = inv[0] = 1;
    for (int i = 1; i < maxn; i++)
        fact[i] = (i * 1LL * fact[i - 1]) % mod, inv[i] = pw(fact[i], mod - 2);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= i + 1; j++)
            ans[i] = ((n >= i + 2) ? (ans[i] + (dp[1][i][j] * 1LL * j) % mod * pw(n, n - i - 2)) % mod : (ans[i] + dp[1][i][j]) % mod);
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            ans[i] = (ans[i] - ans[j] * 1LL * C(i, j) + mod * 10LL) % mod;
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    return (0);
}
