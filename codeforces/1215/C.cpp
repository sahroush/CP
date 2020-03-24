#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e6;
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

string s , t;
int n;
int cnta , cntb;
int wt[maxn] , moo[maxn];

int main(){
    //migmig
    cin >> n;
    cin >> s;
    cin >> t;
    for (auto i : s){
        if(i=='a')cnta++;
        else cntb++;
    }
    for (auto i : t){
        if(i=='a')cnta++;
        else cntb++;
    }
    if(cnta%2 or cntb%2){
        dokme(-1);
    }
    int l=0 , r=0;
    for (int i = 0 ; i < n ; i ++){
        if(s[i]!=t[i]){
            if(s[i] == 'a'){wt[l++] = i + 1;}
            else {moo[r++]=i+1;}
        }
    }
    int ans = l/2+r/2;
    if(l%2)ans+=2;
    cout << ans << endl;
    for (int i = 1 ; i < l ; i += 2){
        cout << wt[i-1] << ' ' << wt[i] << endl;
    }
    for (int i = 1 ; i < r ; i += 2){
        cout <<moo[i-1] << ' ' << moo[i] << endl;
    }
    if(l%2){
        cout << wt[l-1]  << ' '<< wt[l-1] << endl;
        cout << wt[l-1]  << ' '<< moo[r-1] << endl;
    }


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
