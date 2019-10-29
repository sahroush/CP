#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e6+100;
const ll ZERO = 0;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll n , m ;
string s[maxn];
vector <ll> vec[maxn] , tree[maxn];
map <pair <ll , ll > , ll > mp;
map <ll , pair <ll , ll> > ver;
bool mark[maxn];
vector <pair <char , ll > > ans;
pair <ll , ll > a[maxn];
ll crnt;

void dfs(ll v){
    mark[v] = 1;
    for (ll i  =0 ; i < vec[v].size() ; i ++){
        ll u = vec[v][i];
        if (!mark[u]){
            tree[v].push_back(u);
            tree[u].push_back(v);
            dfs(u);
        }
    }
	if(v!=crnt){
		ans.push_back(make_pair('D', v));
		ans.push_back(make_pair('R', v));
	}
}


int main (){
    migmig
    cin >> n >> m;
    for (ll  i =0 ; i < n ; i ++){
        cin >> s[i];
    }
    ll cnt = 1;
    for (ll i = 0 ; i < n; i ++ ){
        for (ll j = 0 ; j < m ; j ++){
            if (s[i][j] == '.'){
                ans.push_back(make_pair('B' , cnt));
                mp[make_pair(i+1 , j+1)] = cnt;
                a[cnt] = make_pair(i+1 , j+1);
                cnt++;

            }
        }
    }
    for (ll i = 0 ; i  < n; i ++){
        for (ll j = 0 ; j < m ; j ++){
            if (i){
                if (s[i-1][j] == '.'){
                    vec[mp[make_pair(i+1 , j+1)]].push_back(mp[make_pair(i , j+1)]);
                }
            }
            if (j){
                if (s[i][j-1] == '.'){
                    vec[mp[make_pair(i+1 , j+1)]].push_back(mp[make_pair(i+1 , j)]);
                }
            }
            if (i < n-1){
                if (s[i+1][j] == '.'){
                    vec[mp[make_pair(i+1 , j+1)]].push_back(mp[make_pair(i + 2, j+1)]);
                }
            }
            if (j < m-1){
                if (s[i][j+1] == '.'){
                    vec[mp[make_pair(i+1 , j+1)]].push_back(mp[make_pair(i + 1, j+2)]);
                }
            }
        }
    }
    for (ll i = 1 ; i < cnt ; i ++){
        if (!mark[i]){
            crnt = i;
            dfs(i);
        }
    }
    cout << ans.size() << endl;
    for (ll i = 0 ; i < ans.size() ; i ++){
        pair <ll , ll > p = a[ans[i].second];
        cout << ans[i].first << '\t' << p.first << '\t' << p.second << endl;
    }

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
