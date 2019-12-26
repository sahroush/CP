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
bool f[30][30];
int prt[30][30];

int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i < n ; i ++){
        string s;
        cin >> s;
        for (int j = 0 ;j < m ; j ++){
            if(s[j] == '1'){
                f[i][j] = 1;
            }
        }
    }
    for (int i = 0 ; i < n ; i ++){
        prt[i][0] = 0;
        for (int j = 0; j < m ; j ++){
            prt[i][j + 1] = prt[i][j] + f[i][j];
        }
    }
    int mx = 0;
    pii xy;
    for (int i = 0 ; i < n; i ++){
        for (int j = 0 ; j < m ; j ++){
            for (int k = j + 1 ; k <= m ; k ++){
                //alan bala chap ro fix kardim k taa miaim jolo;
                int pos = i;
                while(prt[pos][k] - prt[pos][j] == 0 and pos < n){
                    pos ++;
                }
                int area = k - j;
                area+=pos - i;
                if(pos - i == 0){
                    area = 0;
                }
                area*=2;
                if(area > mx){
                    mx = area;
                }
            }
        }
    }
    //dokme(xy.second);
    cout << mx;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
