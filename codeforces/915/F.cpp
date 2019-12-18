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


int n;
ll a[maxn];
vector <int> vec[maxn];
ll sz[maxn];
int par[maxn];
ll minsum = 0 , maxsum = 0;
int srt[maxn];
vector <int> handle;
int prt[maxn];
bool mark[maxn];

bool cmp(int i , int j ){
    return(a[i] < a[j]);
}

int getpar(int v){
    if(v == par[v]){
        return(v);
    }
    par[v] = getpar(par[v]);
    return(par[v]);
}

void merge(int x , int y){
    x = getpar(x) , y = getpar(y);
    if(x == y){
        return;
    }
    handle.pb(sz[y]);
    par[y] = x;
    sz[x]+=sz[y];
    sz[y] = 0;
}

int main(){
    migmig
    cin >> n;
    for (int i =1 ;  i <= n ; i ++){
        cin >> a[i ];
        srt[i ] = i ;
    }
    sort(srt + 1 , srt + n + 1 , cmp);
    for(int i = 0 ; i < n - 1 ; i ++){
        int x , y;
        cin >> x >> y;
        vec[x].pb(y);
        vec[y].pb(x);
    }
    for (int i =1 ; i <= n ; i ++){
        sz[i] = 1;
        par[i] = i;
    }
    mark[srt[1]] = 1;
    for (int i = 2 ; i <= n ; i ++){
        handle.clear();
        mark[srt[i]] = 1;
        for (int j = 0 ; j < vec[srt[i]].size() ; j ++){
            int u = vec[srt[i]][j];
            if(mark[u]){
                merge(srt[i] , u);
            }
        }
        maxsum+=(sz[srt[i]] - 1)*a[srt[i]];
        ll sum = 0;
        for(int j = 0 ; j < handle.size() ; j ++){
            sum+=handle[j];
        }
        for (int j = 0 ; j < handle.size() ; j ++){
            sum-=handle[j];
            maxsum+=(handle[j] * sum )*a[srt[i]];
        }
    }
    ms(mark , 0);
    for (int i =1 ; i <= n ; i ++){
        sz[i]  = 1;
        par[i] = i;
    }
    reverse(srt + 1 , srt + n + 1 );
    mark[srt[1]] = 1;
    for (int i = 2 ; i <= n ; i ++){
        handle.clear();
        mark[srt[i]] = 1;
        for (int j = 0 ; j < vec[srt[i]].size() ; j ++){
            int u = vec[srt[i]][j];
            if(mark[u]){
                merge(srt[i] , u);
            }
        }
        minsum+=(sz[srt[i]] - 1) *a[srt[i]];
        ll sum = 0;
        for(int j = 0 ; j < handle.size() ; j ++){
            sum+=handle[j];
        }
        for (int j = 0 ; j < handle.size() ; j ++){
            sum-=handle[j];
            minsum+=(handle[j] * sum)*a[srt[i]];
        }
    }

    cout << maxsum - minsum  ; //wtf!!!
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
