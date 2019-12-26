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

int n , m;
int dp[maxn];
int a[maxn];
set <int> p;
int val[maxn];
vector <pii> taj;

void zie(int n){
    if(n <=1 ){
        return;
    }
    int pos = 2;
    taj.pb(pii(1 , 1));
    while(n!=1 and pos <= 31623){
        while(n%pos == 0){
            n/=pos;
            if(taj.back().first!=pos){
                taj.pb(pii(pos , 1));
            }
            else{
                pii boz = taj.back();
                taj.pop_back();
                taj.pb(pii(pos , boz.second + 1));
            }
        }
        pos++;
    }
    if(n!=1){
        taj.pb(pii(n , 1));
    }
}

int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i < n ; i ++){
        cin >> a[i];
    }
    for (int i = 0 ; i  < m ; i ++){
        int v;
        cin >> v;
        p.insert(v);
    }
    dp[0] = a[0];
    for (int i = 1 ; i < n ; i ++){
        dp[i] = __gcd(a[i] , dp[i - 1]);
    }
    for (int i = n - 1 ; i >= 0 ;  i -- ){
        int val = 0;
        taj.clear();
        zie(dp[i]);
        for (int j = 1 ; j < taj.size() ; j ++){
            if(p.count(taj[j].first)){
                val+=(i + 1) * taj[j].second;
            }
            else{
                val-=(i + 1) * taj[j].second;
            }
        }
        int boz = dp[i];
        if(val > 0){
            for (int j = i ; j>=0 ; j --){
                dp[j]/=boz;
                a [j]/=boz;
            }
        }
    }
    ll sum = 0;
    for (int i = 0 ; i < n ; i ++){
        taj.clear();
        zie(a[i]);
        for (int j = 1 ; j < taj.size() ; j ++){
            if(p.count(taj[j].first)){
                sum-=taj[j].second;
            }
            else{
                sum+=taj[j].second;
            }
        }
    }
    cout << sum;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
