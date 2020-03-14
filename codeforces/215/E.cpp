#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =3e6+1000;
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

ll l , r;

ll calc (ll sz){
    ll res = (ll)1<<(sz-1);
    for (ll i = 1 ;i < sz; i ++ ){
        if(sz%i==0){
            res-=calc(i);
        }
    }
    return(res);
}

ll fff(ll sz , ll lim , ll cnt){
    ll pre = lim>>(cnt - sz);
    ll ans , boz;
    boz = pre;
    ans = pre - ((ll)1<<(sz - 1));
    for (ll i = 1 ; i < cnt/sz ; i ++){
        boz<<=sz;
        boz|=pre;
    }
    //ba oon pattern addad sakhtim
    if(boz <= lim){
        ans++;
    }
    for (ll i = 1 ; i < sz ; i ++){
        if(sz%i == 0){
            ans-=fff(i , lim , cnt);
            //shoomool
        }
    }
    return(ans);
}

ll solve(ll x){
    if(x == 0){
        return(0);
    }
    ll sz=log2(x)+1;
    ll ans = 0;
    for (ll i = 1 ; i < sz ; i ++){
        ans+=calc(i);
    }
    ans+=fff(sz , x , sz);
    return(x - ans);
}

int main(){
    migmig
    cin >> l >> r;
    cout << solve(r) - solve(l - 1);
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.