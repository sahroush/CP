#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
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

string a , b , c;
vector <int> adj[maxn];
int d[maxn];

int main(){
    migmig
    cin >> a >> b >> c;
    if(a == "A>B" or a == "B<A"){
        adj[0].pb(1);
        d[0]++;
        d[1]--;
    }
    if(a == "B>A" or a == "A<B"){
        adj[1].pb(0);
        d[1]++;
        d[0]--;
    }
    if(a == "C>B" or a == "B<C"){
        adj[2].pb(1);
        d[1]--;
        d[2]++;
    }
    if(a == "B>C" or a == "C<B"){
        adj[1].pb(2);
        d[1]++;
        d[2]--;
    }
    if(a == "C>A" or a == "A<C"){
        adj[2].pb(0);
        d[0]--;
        d[2]++;
    }
    if(a == "A>C" or a == "C<A"){
        adj[0].pb(2);
        d[0]++;
        d[2]--;
    }
    a = b;
    if(a == "A>B" or a == "B<A"){
        adj[0].pb(1);
        d[0]++;
        d[1]--;
    }
    if(a == "B>A" or a == "A<B"){
        adj[1].pb(0);
        d[1]++;
        d[0]--;
    }
    if(a == "C>B" or a == "B<C"){
        adj[2].pb(1);
        d[1]--;
        d[2]++;
    }
    if(a == "B>C" or a == "C<B"){
        adj[1].pb(2);
        d[1]++;
        d[2]--;
    }
    if(a == "C>A" or a == "A<C"){
        adj[2].pb(0);
        d[0]--;
        d[2]++;
    }
    if(a == "A>C" or a == "C<A"){
        adj[0].pb(2);
        d[0]++;
        d[2]--;
    }
    a = c;
    if(a == "A>B" or a == "B<A"){
        adj[0].pb(1);
        d[0]++;
        d[1]--;
    }
    if(a == "B>A" or a == "A<B"){
        adj[1].pb(0);
        d[1]++;
        d[0]--;
    }
    if(a == "C>B" or a == "B<C"){
        adj[2].pb(1);
        d[1]--;
        d[2]++;
    }
    if(a == "B>C" or a == "C<B"){
        adj[1].pb(2);
        d[1]++;
        d[2]--;
    }
    if(a == "C>A" or a == "A<C"){
        adj[2].pb(0);
        d[0]--;
        d[2]++;
    }
    if(a == "A>C" or a == "C<A"){
        adj[0].pb(2);
        d[0]++;
        d[2]--;
    }
    string ans = "ABC";
    //cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
    for (int i = 0 ; i < 3 ; i ++ ){
        for (int j = i + 1; j < 3 ; j ++){
            if(d[i] > d[j]){
                swap(d[i], d[j]);
                swap(ans[i] , ans[j]);
            }
            if(d[i] == d[j]){
                dokme("Impossible")
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
