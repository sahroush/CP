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
//#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}


struct edge{
    ll u , v ;
    ll w;
}e[maxn];

ll n , m ;
ll sum[maxn] , cnt = 0;
vector <pll> adj[maxn] , vec;
vector <pair <ll , pll> > ans;

int main(){
    migmig
    ms(sum ,  0);
    cin >> n >> m;
    for (ll i =0 ; i < m ; i ++){
        ll v , u;
        cin >> v >> u;
        ll w;
        cin >> w;
        adj[u].pb(pll(v , w));
        adj[v].pb(pll(u , -w));
        e[i].v = v;
        e[i].u = u;
        e[i].w = w;
    }
    for (ll i = 1 ; i <= n ; i ++){
        for (ll j = 0 ; j < adj[i].size() ; j ++){
            sum[i]+=adj[i][j].second;
        }
        if(sum[i]!=0){
            vec.pb(pll(sum[i] , i));
        }
    }
    sort(vec.begin() , vec.end());
    int l = 0 , r = vec.size()-1;
    while(l<r){
        if(abs(vec[l].first) > vec[r].first){
            vec[l].first+=vec[r].first;
            ans.pb(make_pair(vec[l].second , pll(vec[r].second , vec[r].first)));
            vec[r].first = 0;
            r--;
        }
        else if (abs(vec[l].first) == vec[r].first){
            vec[l].first+=vec[r].first;
            ans.pb(make_pair(vec[l].second , pll(vec[r].second , vec[r].first)));
            vec[r].first = 0;
            r--;
            l++;
        }
        else{
            ans.pb(make_pair(vec[l].second , pll(vec[r].second , -vec[l].first)));
            vec[r].first += vec[l].first;
            vec[l].first+=vec[r].first;
            l++;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0 ; i < ans.size() ; i ++){
        cout << ans[i].first << ' ' << ans[i].second.first << ' ' << ans[i].second.second << endl;
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
