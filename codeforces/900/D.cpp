#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5+5;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

ll x , y;
map <ll , ll > val;

ll calc(ll a){
    if(a == 1){
        return(1);
    }
    if(val.count(a)){
        return(val[a]);
    }
    ll ans = pw(2 , a - 1);
    for (int i = 2 ; i * i <= a ;  i ++){
        if(a%i == 0){
            ans-=calc(a / i);
            ans+=mod*100;
            ans%=mod;
            if(a/i!=i){
                ans-=calc(i);
            }
            ans+=mod*100;
            ans%=mod;
        }
    }
    val[a] = (ans - 1 + mod*mod)%mod;
    return((ans - 1 + mod*mod)%mod);
}

int main(){
    migmig
    //ms(val , -1);
    cin >> x >> y;
    if(y%x != 0){
        dokme(0);
    }
    ll n = y/x;
    //find p(n);
    cout << calc(n);




    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
