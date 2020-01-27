#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5+5;
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

int n , k;
int a[maxn];
int cnt = 0;
bool mark[maxn];
vector < int > adj[maxn];
vector < int > vec;

void dfs(int v){
    mark[v] = 1;
    for (auto u : adj[v]){
        if(!mark[u]){
            dfs(u);
        }
    }
}

int main(){
    migmig
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        adj[i].pb(a[i]);
        adj[a[i]].pb(i);
    }
    cin >> k;
    for (int i = 1 ; i <= n ; i ++ ){
        if(!mark[i]) cnt++ , dfs(i) , vec.pb(i);
    }
    cout << abs(n - k - cnt) << endl;
    sort(vec.begin() , vec.end());
    if(cnt < n - k){
        int i = 1 ;
        while(cnt < n - k and i <= n){
            int p[3100];
            ms(p , -1);
            int pos = 1;
            //dumb idiot
            for (int j = a[i] ; j != i ; j = a[j]){
                p[j] = pos;
                pos++;
            }
            p[i] = pos;

            pos = 1;
            int j = i+1;
            while(cnt < n - k and j<=n){
                if(p[j]>=pos){
                    cout << i << ' ' << j << ' ';
                    cnt++;
                    pos = p[j];
                    swap(a[i] , a[j]);
                }
                j++;
            }
            i++;
        }
    }

    if(cnt > n - k){
        for (int i = 1 ; i <= abs(n - k - cnt) ; i ++){
            cout << 1 << ' ' <<  vec[i] << ' ';
        }
    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
