/// IN THE NAME OF GUITAR
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
const ll MAXN = 2e5 + 10;
const ll INF  = 8e18;
const ll MOD  = 1e9 + 7;
ll q, n;

int main() {
	scanf("%lld", &q);
	while (q--) {
		scanf("%lld", &n); ll c[3] = {0, 0, 0}, turn = 1;
		while (n) {
			if (n == 4) {
				n >>= 1;
				c[turn] += n;
				turn = 3 - turn;
				continue;
			}
			if (n & 1) {
				n--;
				c[turn]++;
				turn = 3 - turn;
			} else {
				if ((n / 2) % 2 == 0) {
					c[turn]++;
					n--;
					turn = 3 - turn;
				} else {
					n >>= 1;
					c[turn] += n;
					turn = 3 - turn;
				}
			}
		}
		printf("%lld\n", c[1]);
	}
    return 0;
}

