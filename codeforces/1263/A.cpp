#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int ,int > pii;

const ll maxn =3e5+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int t;

ll chk(ll x , ll r , ll g , ll b){
    if(r - x < 0){
        return(0);
    }
    ll cnt = 0;
    ll mn;
    r-=x;
    b-=x;
    cnt+=x;
    mn = min(g , r);
    g-=mn , r-=mn;
    cnt += mn;
    mn = min(b , r);
    b-=mn , r-=mn;
    cnt += mn;
    mn = min(b , g);
    g-=mn , b-=mn;
    cnt += mn;
    if (r < 0 or g < 0 or b < 0){
        return(0);
    }
    return(cnt);
}

int main(){
    migmig
    cin >> t;
    while(t -- ){
        ll a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a , a+3);
        ll l =0 , r = a[0];
        while(r - l > 1){
            ll mid = (l + r) / 2;
            if(chk(mid , a[0] , a[1] , a[2]) > chk(mid + 1, a[0] , a[1] , a[2])){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        //cout << r;
        cout << chk(r , a[0] , a[1] , a[2]) << endl;
    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
