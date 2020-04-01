#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;//AmShZ
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int n;
ld a[maxn];
ld su[maxn] , rpc[maxn];

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        int inp;
        cin >> inp;
        a[i] = inp;
    }
    su[n] = a[n];
    rpc[n] = n;
    for(int i = n - 1 ; i > 0 ; i --){
        int cnt = i + 1;
        ld boz = a[i];
        while(cnt <= n and a[cnt] < boz/(cnt-i)){
            boz+=su[cnt];
            cnt = rpc[cnt]+1;
        }
        su[i] = boz;
        boz/=ld(cnt-i);
        a[i] = boz;
        rpc[i] = --cnt;
    }
    cout << fixed << setprecision(10);
    ll cur = rpc[1];
    ld val = a[1];
    for(int i = 1 ; i <= n ; i ++){
        if(cur < rpc[i]){
            val = a[i];
            cur = rpc[i];
        }
        cout << val << endl;
    }




    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
