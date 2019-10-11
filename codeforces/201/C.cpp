#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
int n;
int a[maxn];
ll c[maxn], dp[maxn], suml[maxn], sumr[maxn];
int main() {
    migmig;
    cin >> n;
    for (int i = 1; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        if (a[i] > 1)
            c[i] = a[i] - (a[i] & 1) + c[i - 1];
        suml[i] = suml[i - 1] + ((a[i] & 1) ? a[i] : (a[i] - 1));
    }

    for (int i = n - 1; i > 0; i--) {
        if (a[i] > 1) dp[i] = a[i] - (a[i] & 1) + dp[i + 1];
        sumr[i] = sumr[i + 1] + ((a[i] & 1) ? a[i] : (a[i] - 1));
    }

    ll sol = 0, vmax = 0;

    for (int i = 1; i < n; i++) {
        sol = max(sol, suml[i] + sumr[i + 1]);
        sol = max(sol, suml[i] + dp[i + 1]);
        sol = max(sol, c[i] + sumr[i + 1]);
        vmax = max(c[i], vmax + ((a[i] & 1) ? a[i] : (a[i] - 1)));
        sol = max(sol, vmax + dp[i + 1]);
    }

    cout << sol ;

    return (0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
