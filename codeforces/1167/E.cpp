#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;//AmShZ
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);
}

ll n , x;
ll first[maxn] , last[maxn];
ll a[maxn];
bool mark[maxn];
vector < ll > adad;

int main(){
    migmig
    cin >> n >> x;
    ms(first , -1);
    ms(last , -1);
    for(ll i =1 ; i <= n; i ++){
        cin >> a[i];
        if(first[a[i]] == -1){
            first[a[i]] = i;
        }
        last [a[i]] = i;
        mark[a[i]] = 1;
        adad.pb(a[i]);
    }
    sort(adad.begin() , adad.end());
    adad.resize(unique(adad.begin() , adad.end()) - adad.begin());
    first[x+1] = n+1;
    for(ll i = x ; i >= 1 ; i --){
        if(first[i] == -1){
            first[i] = first[i+1];
        }
    }
    ll ans = 0;
    ll l = 1 , r = x;
    while(r > 1 and first[r] >= last[r-1]){
        r--;
    }
    ans = (x - r + 2);
    if(r == 1){
        ans--;
    }
    for(ll i = 1 ; i <= x ; i ++){
        if(last[i] == -1){
            last[i] = last[i - 1];
        }
    }
    for(ll i = 1 ; i <= x ; i ++){
        l = i;
        if(first[l]<= last[l-1] and mark[l]){
            break;
        }
        r = max(r , l+1);
        while(first[r]  <= last[l] and r<= x){
            r++;
        }
        ans+=(x - r + 2);
        if(l == r-1){
            ans--;
        }
    }
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
