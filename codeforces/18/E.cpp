#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =4e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m;
string s[600];
int dp[600][30][30];
pii ans[600] ,udp[600][30][30];

int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i < n ; i ++){
        cin >> s[i];
    }
    ms(dp , 0);
    for (int i = 0 ; i < n ; i ++){
        for (int a = 0 ; a < 26 ; a ++){
            for (int b = 0 ; b < 26 ; b ++){
                dp[i][a][b] = INF;
                if(a == b){
                    continue;
                }
                dp[i][a][b] = 0;
                for (int j = 0 ; j < m ; j ++){
                    if(j%2){
                        if(s[i][j] - 'a'!= a ){
                            dp[i][a][b]++;
                        }
                    }
                    else{
                        if(s[i][j] - 'a'!=b){
                            dp[i][a][b]++;
                        }
                    }
                }
                if(i == 0){
                    continue;
                }
                int c = dp[i][a][b];
                dp[i][a][b] = INF;
                for (int x = 0 ; x < 26 ; x ++){
                    if(x == a){
                        continue;
                    }
                    for (int y = 0 ; y < 26 ; y ++){
                        if(x == y or y == b){
                            continue;
                        }
                        if(dp[i - 1][x][y] < dp[i][a][b]){
                            dp[i][a][b] = dp[i - 1][x][y];
                            udp[i][a][b] = pii(x , y);
                        }
                    }
                }
                dp[i][a][b] += c;
            }
        }
    }
    int mn = 600*600;
    for (int i = 0 ; i < 26 ; i ++){
        for (int j = 0 ; j < 26 ; j ++){
            if(i == j){
                continue;
            }
            if(dp[n - 1][i][j] < mn){
                ans[n - 1] = pii(i , j);
                mn = dp[n - 1][i][j];
            }
        }
    }
    for (int i = n-2 ; i >= 0 ; i --){
        ans[i] = udp[i + 1][ans[i + 1].first][ans[i + 1].second];
    }
    cout << mn << endl;
    for(int i = 0 ; i < n;  i ++){
        for (int j= 0 ; j < m ; j ++){
            if(j%2 == 1){
                cout << (char) ('a' + ans[i].first);
            }
            else{
                cout << (char)('a' + ans[i].second);
            }
        }
        cout << '\n';
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
