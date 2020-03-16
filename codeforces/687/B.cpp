#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =1e6+10;
const ll mod = 1e9+7;//998244353;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

ll maxtav[maxn];
ll tajk[maxn];
ll n , k;
vector < ll > mg[maxn];

void solve(ll x){
    for (int i : mg[x]){
        ll cnt = 0;
        while(x%i == 0){
            cnt++;
            x/=i;
        }
        maxtav[i] = max(maxtav[i] , cnt);
    }
    maxtav[x]=max(maxtav[x] , (ll)1);
}

int main(){
    migmig
    cin >> n >> k;
    if(k == 1){
        dokme("Yes");
    }
    for (int i = 2 ; i < maxn ; i ++){
        if(mg[i].size())continue;
        for (int j = i ; j < maxn ; j +=i){
            mg[j].pb(i);
        }
    }
    for (int i : mg[k]){
        while(k%i == 0){
            tajk[i]++;
            k/=i;
        }
    }
    tajk[k]++;
    while(n -- ){
        ll x ;
        cin >> x;
        solve(x);
    }
    for (int i = 0 ; i < maxn ; i ++){
        if(tajk[i] > maxtav[i]){
            dokme("No");
        }
    }
    cout << "Yes";
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
