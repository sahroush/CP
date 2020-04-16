/// IN THE NAME OF METAL
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pll;

#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second

ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}

const ll MAXN = 2e3 + 5;
const ll INF = 8e18;
const ll MOD = 1e9 + 7;
int n, m, mark[MAXN][MAXN], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char C[] = { '^', '<', 'v', '>' };
string A[MAXN];
pll mx = {0, 0};

int DFS(int x, int y) {
    int ans = 0;
    mark[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;/*
        if ((nx == mp[A[nx][ny]].F + x) && (ny == mp[A[nx][ny]].S + y)) {
            DFS(nx, ny);
            H[x][y] = max(H[x][y], H[nx][ny] + 1);
        }*/
        if (C[i] != A[nx][ny-1]) continue;
        int res = DFS(nx, ny) + 1;
        if (A[x][y-1] == '#') {
            if (res > mx.S) mx.S = res;
            if (mx.S > mx.F) swap(mx.S, mx.F);
        } else 
            ans = max(res, ans);
    }
    return ans;
}

int main() {
    //scanf("%d%d", &n, &m)
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        for (int j = 1; j <= m; j++) {
            if (A[i][j - 1] != '>' && A[i][j - 1] != '<' && A[i][j - 1] != '#' && A[i][j - 1] != '^' && A[i][j - 1] != 'v') {
                j--;
                continue;
            }
            //A[i][j] = c;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i][j-1] == '#') DFS(i, j);
        }
    }/*
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (A[i][j] == '#') mx = max(mx, H[i][j]);
        }
    }*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (mark[i][j] == 0) return !printf("-1\n");
    }
    if (mx.F == mx.S) printf("%d\n", mx.F + mx.S);
    else  printf("%d\n", mx.F + mx.F - 1);
    return 0;
}
