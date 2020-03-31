#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

ll n , m , k , s;
ll d[maxn]  ,p[maxn];
ll mnd[maxn] , mnp[maxn];
vector < pll > g[2];

bool chk(ll x){
    ll boz = k;
    ll ans = 0;
    int p1 = 0 , p2 = 0;
    while(boz--){
        if(p1 < g[0].size() and p2 < g[1].size()){
            if(g[0][p1].first*mnd[x] < g[1][p2].first*mnp[x]){
                ans += g[0][p1++].first*mnd[x] ;
            }
            else{
                ans += g[1][p2++].first*mnp[x] ;
            }
        }
        else if(p1 < g[0].size()){
            ans += g[0][p1++].first*mnd[x] ;
        }
        else{
            ans += g[1][p2++].first*mnp[x] ;
        }
    }
    return(ans <= s);
}

void solve(ll x){
    ll boz = k;
    ll ans = 0;
    int p1 = 0 , p2 = 0;
    int dl , po;
    for(int i = 1 ; i <= x ; i ++){
        if(d[i] == mnd[x]){
            dl = i;
            break;
        }
    }
    for(int i = 1 ; i <= x ; i ++){
        if(p[i] == mnp[x]){
            po = i;
            break;
        }
    }
    while(boz--){
        if(p1 < g[0].size() and p2 < g[1].size()){
            if(g[0][p1].first*mnd[x] < g[1][p2].first*mnp[x]){
                cout << g[0][p1++].second << ' ' << dl << endl;
            }
            else{
                cout << g[1][p2++].second << ' ' << po << endl;
            }
        }
        else if(p1 < g[0].size()){
            cout << g[0][p1++].second << ' ' << dl << endl;
        }
        else{
            cout << g[1][p2++].second << ' ' << po << endl;
        }
    }
}

int main(){
    migmig
    cin >> n >> m >> k >> s;
    for(int i = 1 ; i <= n ; i ++){
        cin >> d[i];
        mnd[i] = d[i];
        if(i > 1){
            mnd[i] = min(mnd[i] , mnd[i - 1]);
        }
    }
    for(int i = 1 ; i <= n ; i ++){
        cin >> p[i];
        mnp[i] = p[i];
        if(i > 1){
            mnp[i] = min(mnp[i] , mnp[i - 1]);
        }
    }
    for(int i = 0 ; i < m ; i ++){
        ll t , pr;
        cin >> t >> pr;
        g[--t].pb(pll(pr , i + 1));
    }
    sort(g[1].begin() , g[1].end());
    sort(g[0].begin() , g[0].end());
    ll l = 1, r = n;
    if(chk(n) == 0){
        dokme(-1);
    }
    while(r - l > 1){
        ll mid = (l + r)/2;
        if(chk(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    while(chk(r-1) and r>1){
        r--;
    }
    cout << r << endl;
    solve(r);
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
