#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

ll n;
ll a[maxn];
ll zr = 0;
map< ll , ll > cnt;
ll ans = 2;

int main(){
    migmig
    cin >> n;
    for (int i = 0 ; i < n ; i ++){
        cin >> a[i];
        cnt[a[i]]++;
        if(a[i] == 0){
            zr++;
        }
    }
    ans = max(ans , zr);
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < n ; j ++){
            if((a[i] == 0 and a[j] == 0) or i==j){
                continue;
            }
            ll len = 2;
            vector < ll > tof;
            tof.clear();
            tof.pb(a[i]);
            tof.pb(a[j]);
            cnt[a[i]]--;
            cnt[a[j]]--;
            ll f1 = a[j];
            ll f2 = a[i] + a[j];
            for (int i = 0 ; i < 100 ; i ++){
                if(cnt[f2]){
                    cnt[f2]--;
                    tof.pb(f2);
                    len++;
                    f2+=f1;
                    f1 = f2-f1;
                    if(f2 == f1 and f1 == 0){
                        ans+=cnt[0];
                        break;
                    }
                }
                else{
                    break;
                }
            }
            ans = max(ans , len);
            for(auto i : tof){
                cnt[i]++;
            }
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
