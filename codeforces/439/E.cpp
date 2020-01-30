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


int q;
ll fact[maxn] , inv[maxn];
vector < ll > mg[maxn];
map < pll , ll > mp;

ll calc(ll a , ll b){
    if(mp.count(pll(a , b))){
        return(mp[pll(a , b)]);
    }
    if(a==0){
        return(b < 1);
    }
    a-- , b--;
    if(b > a){
        return((ll)0);
    }
    ll c = ((fact[a] * inv[b])%mod * inv[a - b])%mod;
    a++ , b++;
    for (int i = 0 ; i < mg[a].size() ; i ++){
        c-=calc(a/mg[a][i] , b);
        c+=mod*mod;
        c%=mod;
    }
    mp[pll(a , b)] = c;
    return(c);
}

int main(){
    migmig
    fact[0] = inv[0] = 1;
    for (int i = 1 ; i <= 4e5 ; i ++ ){
        fact[i] = i*fact[i-1];
        fact[i]%=mod;
        inv[i] = pw(fact[i] , mod - 2) % mod;
    }
    for (int i = 1 ; i < 4e5 ; i ++){
        for (int j = 2 ; j * j <= i ; j ++){
            if(i%j == 0){
                mg[i].pb(j);
                if(i/j!=j){
                    mg[i].pb(i/j);
                }
            }
        }
        sort(mg[i].begin() , mg[i].end());
    }
    cin >> q;
    while(q--){
        ll n , k , ans = 0;
        cin >> n >> k;
        ans = calc(n , k);
        if(k == 1 and n > 1){
            cout << 0 << endl ;
            continue;
        }
        cout << calc(n , k) << endl;
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
