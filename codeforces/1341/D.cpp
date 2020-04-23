#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
int num[maxn];
int gaav[10];
int dp[2100][2100];
int par[2100][2100];
string fuck[] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string ss[] = {"0" , "1" , "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9"};
int a[maxn];

int tonum(string s){
    int ans = 0;
    for(int i = 0 ; i < 7 ; i ++){
        if(s[i] == '1'){
            ans += (1 << i);
        }
    }
    return(ans);
}

int main(){
    migmig
    ms(num , -1);
    ms(dp , -1);
    cin >> n >> k;
    for(int i = 0 ; i <= 9 ; i ++){
        num[tonum(fuck[i])] = i;
        gaav[i] = tonum(fuck[i]);
    }
    dp[n + 1][0] = 0;
    for(int i = 1 ; i <= n ; i ++){
        string inp;
        cin >> inp;
        a[i] = tonum(inp);
    }
    for(int i = n; i >= 1 ; i --){
        for(int j = 0 ; j <= k ; j ++){
            for(int l = 0 ; l <= 9 ; l ++){
                if(((a[i]|gaav[l])^gaav[l]))continue;
                int need = __builtin_popcount(((a[i]|gaav[l])^a[i]));
                if(need > j){
                    continue;
                }
                if(dp[i + 1][j - need]!=-1){
                    dp[i][j] = l;
                    par[i][j] = j - need;
                }
            }
        }
    }
    if(dp[1][k] == -1){
        dokme(-1);
    }
    for(int i = 1;  i <= n ; i ++){
        cout << dp[i][k];
        k=par[i][k];

    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
