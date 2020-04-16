#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair< ll  , ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
ll n[3];
vector <ll> c[3];

int main(){
    migmig
    cin >> q;
    while(q --){
        for(int i = 0 ; i < 3 ; i ++){
            cin >> n[i];
        }
        for(int i = 0 ; i < 3 ; i ++){
            c[i].clear();
            for(int j = 0 ; j < n[i] ; j ++){
                ll inp;
                cin >> inp;
                c[i].pb(inp);
            }
            sort(c[i].begin() , c[i].end());
        }
        ll ans = 8e18;
        for(int i = 0 ; i < 3; i ++){
            for(int j = 0 ; j < 3 ; j ++){
                if(i == j){
                    continue;
                }
                int k = 3 - (i + j);
                for(ll mid : c[i]){
                    if(lower_bound(c[j].begin() , c[j].end() , mid) == c[j].end()){
                        continue;
                    }
                    ll mn = *lower_bound(c[j].begin() , c[j].end() , mid);
                    if((--(upper_bound(c[k].begin() , c[k].end() , mid)))-c[k].begin() < 0 ){
                        continue;
                    }
                    ll mx = *(--(upper_bound(c[k].begin() , c[k].end() , mid)));
                    ll sum = abs(mn - mx)*abs(mn - mx);
                    sum+=abs(mx - mid) * abs(mx - mid);
                    sum+=abs(mn -mid)*abs(mn - mid);
                    ans = min(ans , sum);
                }
            }
        }
        cout << ans << endl;
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
