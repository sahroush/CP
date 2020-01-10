#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =2e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e18;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define all(x) x.begin() , x.end()
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

ll x;
vector < ll > di;

int main(){
    migmig
    cin >> x;
    ll boz = x;
    for (int i = 2 ; i <=1e6+10 ; i ++){
        ll cnt = 1;
        while(x%i == 0){
            cnt*=i;
            x/=i;
        }
        if(cnt!=1){
            di.pb(cnt);
        }
    }
    if(x!=1){
        di.pb(x);
    }
    if(di.size() == 0){
        cout << 1 << ' ' <<  x;
        return(0);
    }
    sort(all(di));
    reverse(all(di));
    ll a = 1 , b = 1;
    for (int i = 0 ; i < di.size() ; i ++){
        if(a < b){
            a*=di[i];
        }
        else{
            b*=di[i];
        }
    }
    ll mn = 1e12;
    pair < ll , ll > ans , cur;
    for (int i = 0 ; i <= pw(2 , di.size()) ; i ++){
        cur.first =cur.second= 1;
        for (int j = 0 ; j < di.size() ; j ++){
            if(i & (1 << j)){
                cur.first*=di[j];
            }
            else{
                cur.second*=di[j];
            }
        }
        if(max(cur.first , cur.second) < mn){
            ans.first = cur.first;
            ans.second = cur.second;
            mn = max(cur.first , cur.second);
        }
    }
    cout << ans.first << ' ' << ans.second;

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
