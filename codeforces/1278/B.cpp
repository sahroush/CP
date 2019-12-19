#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =4e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}



int q;


int main(){
    migmig
    cin >> q;
    while(q -- ){
        ll a , b;
        cin >> a >> b;
        if(b > a){
            swap(a , b);
        }
        ll diff = a - b;
        if(diff == 0){
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;
        ll l = 0 , r = 9e8 + 9e7;
        while(r - l > 1){
            ll mid = (l + r) / 2 + ans;
            if(mid*(mid + 1) / 2 >= diff ){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        ans += r;
        ll p = abs(diff  - r * (r + 1) / 2);
        if(p / 2 <= r and p%2 == 0){
            cout << r << endl;
            continue;
        }
        while(p%2 == 1){
            r++;
            p = abs(diff  - r * (r + 1) / 2);
        }
        cout << r << endl;


    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
