#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 3e3 + 100;//AmShZ
const ll mod = 1e9 + 7;
const ld PI = acos((ld) -1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x, y) memset(x , y , sizeof x);

ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;
    while (b) {
        if (b & 1) { res = (res) % md; }
        a = (a) % md;
        b >>= 1;
    }
    return (res);
}

int n, m, k, s;
vector<pii> a[maxn];
ll A[maxn][maxn], Mx[2][maxn], mx[maxn][maxn];
ll ans = 0;

int main() {
    migmig
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    memset(Mx, 63, sizeof Mx);
    for (ll i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (ll l = 1; l <= k; l++) {
                mx[A[i][j]][l] = max(mx[A[i][j]][l], i + j - Mx[0][l]);
                mx[A[i][j]][l] = max(mx[A[i][j]][l], i - j - Mx[1][l]);
                mx[l][A[i][j]] = max(mx[l][A[i][j]], i + j - Mx[0][l]);
                mx[l][A[i][j]] = max(mx[l][A[i][j]], i - j - Mx[1][l]);
            }
            Mx[0][A[i][j]] = min(i + j, Mx[0][A[i][j]]);
            Mx[1][A[i][j]] = min(i - j, Mx[1][A[i][j]]);
        }
    }
    ll last;
    cin >> last;
    ll cur;
    for (int i = 1; i < s; i++) {
        cin >> cur;
        ans = max(ans, mx[last][cur]);
        last = cur;
    }
    cout << ans;
    return (0);
}
