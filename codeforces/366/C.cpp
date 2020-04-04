// IN THE NAME OF METAL
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

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

const ll MAXN = 1e6 + 10;
const ll MX = 1e5;
const ll INF = 8e18;
const ll MOD = 1e9 + 7;
ll dp[110][MAXN / 5], C[110], A[110], B[110], n, k;

int main() {
    scanf("%lld%lld", &n, &k);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &B[i]), B[i] *= k;
    for (ll i = 1; i <= n; i++) {
        C[i] = A[i] - B[i];
    }
    memset(dp, -63, sizeof dp);
    dp[0][MX] = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = -MX; j <= MX; j++) {
            dp[i][MX + j] = max(dp[i - 1][MX + j], dp[i][MX + j]);
            dp[i][j + MX] = max(dp[i][j + MX], dp[i - 1][j + MX - C[i]] + A[i]);
        }
    }
    printf("%lld\n", (dp[n][MX] <= 0 ? -1 : dp[n][MX]));
    return 0;
}
