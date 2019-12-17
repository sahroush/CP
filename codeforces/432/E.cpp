#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =4e5;
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
int ans[200][200];

int solve(int x , int y){
    //cout << 2;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    if(ans[x][y]!=-1){
        return(-10);
    }

    int res;
    for(int i = 0; i < 26; i ++){
        bool f = 1;
        for(int d = 0; d < 4; ++d){
            if(ans[x + dx [d]][ y+ dy [d]] == i ){
                f = 0;
            }
        }
        if(f){
            res = i;
            break;
        }
    }
    return (res);
}

int main(){
    //migmig
    cin >> n >> m;

    ms(ans , -1);
    //cout << 2;
    //                 ans[1][1] = 'A';
    //cout << 2;
    for (int i = 1; i <= n ; i ++){
        for (int j = 1 ; j <= m ; j ++){
            if(ans[i][j] == -1){
                int col = solve(i , j);
                int x = n - i + 1;
                int y = 1;
                for (int k = j + 1 ; k <= m ; k ++){
                    if(col == solve(i , k)){
                        y ++;
                    }
                    else{
                        break;
                    }
                }
                int mn = min(x , y);
                for (x = i ; x < i + mn ; x++){
                    for (y = j ; y < j+mn ; y ++){
                        ans[x][y] = col;
                    }
                }
            }
        }
    }
    for(int i =1 ; i <= n ; i ++){
        for (int j = 1 ; j <= m ; j ++){
            ans[i][j] += (int)'A';
            cout << (char)ans[i][j];
        }
        cout << '\n';
    }
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
