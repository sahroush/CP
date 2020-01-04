#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =2e6;
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

ll n , l;
vector <ll> vec[maxn];
pii mx [maxn] , mn[maxn];
bool f[maxn];
set <ll> st;
vector <ll> vmx , vmn;

int main(){
    migmig
    cin >> n;
    ll ans = 0;
    ll k = 0;
    for (ll i = 0 ; i < n ; i ++){
        cin >> l;
        for (ll j = 0 ; j < l ; j ++){
            ll inp;
            cin >> inp;
            vec[i].pb(inp);
        }
        mx[i] = pii(*max_element(vec[i].begin() , vec[i].end()) , i);
        mn[i] =  pii(*min_element(vec[i].begin() , vec[i].end()) , i );
        ll maxx = 0 , minn = 0;
        for (ll j = 1 ; j < l ; j ++){
            if(vec[i][j] > vec[i][j - 1]){
                f[i] = 1;
                break;
            }
        }
        if(f[i]){
            k++;
        }
        else{
            vmx.pb(mx[i].first);
            vmn.pb(mn[i].first);
        }
    }
    //dokme(f[0]);
    ll pos = 0;
    ll cnt = 0;
    sort(vmn.begin() , vmn.end());
    sort(vmx.begin() , vmx.end());
    for (ll i = 0;  i < vmx.size(); i ++){
        for (ll j = pos ; j < vmn.size() ; j++){
            if(vmn[j] < vmx[i] ){
                cnt++;
            }
            else{
                break;
            }
        }

        pos = cnt;
        ans+=cnt;
        //pos = max(pos , 0);
    }
    if(k){
        ans+= k * (n - k) * 2;
        ans+=k*k;
    }

    cout << ans;



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
