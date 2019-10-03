#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int dp[32][32][52];

int main(){
    migmig
    for (int i  = 0 ; i < 31 ; i ++){
        for (int j = 0 ; j < 31 ; j ++){
            dp[i][j][0] = 0;
            for (int k = 0 ; k < 51 ; k ++){
                dp[i][j][k] = 0;
            }
        }
    }
    for (int n = 1 ; n < 31;n++ ){
        for (int m = 1 ; m < 31 ; m ++){
            for (int k = 1 ; k < 51 ; k ++){
                int mn = 1e8;
                if (m*n < k){
                    dp[m][n][k] = 0;
                    mn = 0;
                }
                if (n*m == k){
                    dp[m][n][k] = 0;
                    mn = 0;
                }
                if (mn != 0){
                    for (int i = 0; i <= k; i ++){
                        for (int j = 1; j < n; j ++){
                            if (j*m >= i and n*m - j*m >= k-i) mn = min(mn, m * m + dp[j][m][i] + dp[n- j][m][k - i]);
                        }
                    }
                    for (int i = 0; i <= k; i ++){
                        for (int j = 1; j < m; j ++){
                            if (n*j >= i and n*m - n*j >= k-i) mn = min(mn, n*n + dp[n][j][i] + dp[n][m - j][k-i]);
                        }
                    }
                }

                dp[n][m][k] = mn;
            }

        }
    }


    int n , m , k;
    int q;
    cin >> q;
    for (int i = 0 ; i < q ; i ++){
        cin >> n >> m >> k;
        cout << dp[max(n,m)][min(n ,m)][k]  << endl;
    }


}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
