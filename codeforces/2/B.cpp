#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =1002;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int two[maxn][maxn] , five[maxn][maxn];
int val[maxn][maxn];
int dp2[maxn][maxn] , dp5[maxn][maxn];
pii zero = {-1 , -1};
int par[maxn][maxn][2];
int n;

int main(){
    migmig
    cin >> n;
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < n ; j ++){
            cin >> val[i][j];
            if(!val[i][j]){
                zero = {i , j};
                continue;
            }
            while(val[i][j]%2 == 0){
                val[i][j]/=2;
                two[i][j]++;
            }
            while(val[i][j]%5 == 0){
                val[i][j]/=5;
                five[i][j]++;
            }
        }
    }
    ms(dp2 , 63);
    ms(dp5,63);
    dp2[0][0] =two[0][0];
    dp5[0][0] = five[0][0];
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < n ; j ++){
            if(i){
                if(dp2[j][i] > dp2[j][i - 1] + two[j][i]){
                    dp2[j][i] = dp2[j][i - 1] + two[j][i];
                    par[j][i][0] = 1;
                }
                if(dp5[j][i] > dp5[j][i - 1] + five[j][i] ){
                    dp5[j][i] = dp5[j][i - 1] + five[j][i];
                    par[j][i][1] = 1;
                }
            }
            if(j){
                if(dp2[j][i] > dp2[j-1][i] + two[j][i]){
                    dp2[j][i] = dp2[j-1][i] + two[j][i];
                    par[j][i][0] = 0;
                }
                if(dp5[j][i] > dp5[j-1][i] + five[j][i] ){
                    dp5[j][i] = dp5[j-1][i] + five[j][i];
                    par[j][i][1] = 0;
                }
            }
        }
    }
    bool x= 1;
    if(zero!=pii(-1 , -1) and  min(dp5[n-1][n-1] , dp2[n-1][n-1]) > 1){
        cout << 1 << endl;
        for (int i = 0 ; i < zero.first ; i ++){
            cout << "D";
        }
        for (int i = 0 ; i < zero.second ; i ++){
            cout << "R";
        }
        for (int i = zero.first+1 ; i < n ; i ++){
            cout << "D";
        }
        for (int i =  zero.second+1 ; i <n ; i ++){
            cout << "R";
        }
        return(0);
    }
    cout << min(dp5[n-1][n-1] , dp2[n-1][n-1]) << endl;
    if(dp2[n-1][n-1] > dp5[n-1][n-1]){
        x=0;
    }
    x = !x;
    string ans = "";
    pii pos = {n-1 , n-1};
    while(pos!=pii(0 , 0)){
        if(par[pos.first][pos.second][x]){
            pos.second--;
            ans+="R";
        }
        else{
            pos.first--;
            ans+="D";
        }
    }
    reverse(ans.begin() , ans.end());
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
