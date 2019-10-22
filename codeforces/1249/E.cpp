#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef long double     ld;
typedef string          str;
#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define endl            '\n'
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAX1 = 3e5 + 7;

ll a, b, T, d, e, l, r, z, x, y, cnt, flag, mod = 1e9+7, num[MAX1], p[MAX1], dp[2][MAX1];
string s, t;

int main(){
	fast_io;
	cin >> a >> b;
	for (int i = 1; i < a; ++i) cin >> num[i];
	for (int i = 1; i < a; ++i) cin >> p[i];
	dp[0][0] = 0;
	dp[1][0] = b;
	cout << 0 << sep;
	for (int i = 1; i < a; ++i){
        dp[0][i] = min(num[i]+dp[0][i-1], num[i]+dp[1][i-1]);
        dp[1][i] = min(p[i]+dp[1][i-1], p[i]+dp[0][i-1]+b);
        cout << min(dp[0][i], dp[1][i]) << sep;
	}
    return 0;
}
//ablah
/*                          now or never                         */
