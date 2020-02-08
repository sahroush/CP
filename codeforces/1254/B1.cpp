#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
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

int n;
bitset <maxn> a;
int sum = 0 ;

ll solve (int x){
    if(x == 1){
        return(1e18);
    }
    ll sum = 0;
    ll ans = 0;
    queue < int > q;
    int boz;
    for (int i = 1 ; i <= n ; i ++){
        if(a[i]){
            q.push(i);
            sum+=i;
            if(q.size() == (x + 1 ) / 2){
                boz = i;
            }
        }
        if(q.size() == x){
            sum = 0;
            while(!q.empty()){
                ans+=abs(q.front() - boz);
                q.pop();
            }
        }
    }
    return(ans);
}

int main(){
    migmig
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        bool f;
        cin >> f;
        a[i] = f;
        sum+=f;
    }
    ll ans = 1e18;
    for (int i = 1 ; i * i <= sum ; i ++){
        if(sum%i == 0){
            ans = min(ans , solve(i));
            ans = min(ans , solve(sum / i));
        }
    }
    if(ans == 1e18){
        dokme(-1);
    }
    cout << ans;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
