#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =9e5+1000;
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
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n;
vector <pii> vec[maxn];
vector < int > ans ;
vector <int> odd;
map <pii , int > mp;
bool mark[maxn], mrk[maxn];
int ind[maxn];
int c[maxn];

void dfs(int v){
    for (int i ; ind[v] < (int)vec[v].size() ; i){
        ind[v]++;
        if(!mrk[vec[v][ind[v]- 1].second]){
            mrk[vec[v][ind[v]- 1].second] = 1;
            dfs(vec[v][ind[v]- 1].first);
        }
    }
    ans.pb(v);
    //cout << v;
}

int main(){
    migmig
    //ms(ind , 0);
    cin >> n;
    int cnt = 0;

    for (int i = 0; i < n; i ++){
        int a , b;
        cin >> a >> b;
        b+=500000;
        vec[a].pb(mkp(b , i));
        vec[b].pb(mkp(a , i));
        mp[mkp(a , b)] = i;
        mp[mkp(b , a)] = i;
    }

    for (int i =0 ;  i < maxn ;i  ++){
        if((int)vec[i].size()%2 == 1){
            odd.pb(i);
        }
    }
    int mx = 500000;

    //cout << odd.size();
    while(odd.size()){
        int v = odd.back();
        odd.pop_back();
        int u = odd.back();
        odd.pop_back();
        vec[v].pb(mkp(u , ++mx));
        vec[u].pb(mkp(v , mx));
        mp[mkp(u , v)] = mx;
        mp[mkp(v , u)] = mx;
        mark[mx] = 1;
    }
    //cout << 2;
    for (int i =0 ; i < maxn ; i ++){
        ans.clear();
        dfs(i);

        int pos = 0;

        for (int i = 0 ; i+1 <(int)ans.size() ; i ++ ){
            if (mark [mp [ mkp ( ans[i], ans[i + 1 ] ) ] ] ){
                pos = i;
                break;
            }
        }
        vector <int> res;
        for (int i = pos ; i < ans.size() ; i ++){
            res.pb(ans[i]);
        }
        for (int i = 1 ; i <= pos ; i ++){
            res.pb(ans[i]);
        }
        for (int i = 0 ; i + 1 <(int) res.size() ; i ++){
            (c[mp [ mkp ( res [ i ] , res[i + 1] ) ] ] = i%2);
        }
    }

    for(int i = 0 ; i < n; i ++){
        if(c[i]){
            cout << 'r';
        }
        else{
            cout <<'b';
        }
    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
