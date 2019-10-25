#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e4+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int q[300];
char r[300];
ld dp[300][300];

int main (){
    int n, m;
    ll t;
    cin >> n >> m >> t;
    memset (q, 63, sizeof (q));
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ; j++) {
            int p;
            cin >> p;
            q[i + j] = min (q[i + j], p);
        }
        int l = n + m - 1;
        vector <pair <int, int> > v;
        for (int i = 0; i < l; i++) {
            v.push_back (make_pair (q[i], i));
        }
        sort (v.begin (), v.end ());
        --t;
        for (int i = 0; i < l; i++) {
            r[v[i].second] = '(';
            for (int j = 0; j <= l; j++)
                for (int k = 0; k <= l; k++)
	                  dp[j][k] = 0;
            dp[0][0] = 1;
            for (int j = 0; j < l; j++) {
                for (int k = 0; k < l; k++) {
	                 if (r[j] != ')') dp[j + 1][k + 1] += dp[j][k];
	                 if (r[j] != '(' && k > 0) dp[j + 1][k - 1] += dp[j][k];
                }
            }
            if (dp[l][0] <= t) {
                t -= (ll)dp[l][0];
                r[v[i].second] = ')';
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << r[i+j] ;
            cout << endl;
        }
  return (0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
