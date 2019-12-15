#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =4e5;
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
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i]+1 << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

ll n , sy , sx;
ll x[maxn] , y[maxn];
ll a = 0 , b = 0 , c = 0 , d = 0;

int main(){
    migmig;
    cin >> n >> sx >> sy;
    for (int i = 0 ; i < n ; i ++){
        cin >> x[i] >> y[i];
        if(y[i] > sy){
            a++;
        }
        if(y[i] < sy){
            c++;
        }
        if(x[i] > sx){
            b++;
        }
        if(x[i] < sx){
            d++;
        }
    }
    ll arr[] = {a , b , c , d};
    ll mx = *max_element(arr , arr+4);
    cout << mx << endl;
    if(a == mx){
        cout << sx  << ' '<< sy + 1;
        return(0);
    }
    if(b == mx){
        cout << sx+1  << ' '<< sy;
        return(0);
    }
    if(c == mx){
        cout << sx  << ' '<< sy - 1;
        return(0);
    }
    if(d == mx){
        cout << sx  - 1 << ' '<< sy;
        return(0);
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
