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
//#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

ll n;
ll k;

bool chk(ll l , ll r){
    cout << l << ' ' << r << endl;
    string inp;
    cin >> inp;
    return(inp == "Yes");
}

int main(){
    migmig
    cin >> n >> k;
    ll l = 1 , r = n;
    ll i = 0 , j = 65;
    while(1){
        ll mid = (l+r)/2;
        if(chk(l , mid)){
            if(l == mid){
                return(0);
            }
            r = min(n , mid+k);
            l = max((ll)1 , l - k);
        }
        else{
            l = max((ll)1 , mid - k);
            r = min(n , r + k);
        }
        if(i%5==0){
            j++;
        }
        i++;
        if(r - l <= 100){
            ll dist = r-l+1;
            ll num = (i*j)%dist;
            if(chk((l+num) , (l+num))){
                return(0);
            }
            //cout << "boz "<<  l << ' ' << r << endl;
            r = min(n , r+k);
            l = max((ll)1 , l - k);
        }
    }


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
