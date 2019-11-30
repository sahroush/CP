#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int ,int > pii;

const ll maxn =3e5+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}
struct edge{
    int x , y;
};

int n , m , k , s , t;
bool ct[maxn] , mark[maxn];
edge e[maxn];
int dist[maxn] , dp[maxn];
vector <int> vec[maxn];

bool chk(int mid) {
	fill(dp, dp + n, 1e6);
	memset(mark, 0, sizeof mark);
	queue<int> q;
	q.push(s);
	dp[s] = 0;
	mark[s] = 1;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		mark[v] = 0;
		int d = dp[v] + 1;
		for(int i = 0 ;i < vec[v].size() ; i ++){
            int u = vec[v][i];
			if(d <= mid and checkmin(dp[u], ct[u] ? 0 : d)) {
				if(!mark[u]) {
					q.push(u);
				}
			}
		}
	}
	return (dp[t] <= mid);
}

int main(){
    migmig
    cin >> n >> m >> k;
    for(int i = 0 ; i < k ; i ++){
        int inp;cin >> inp;
        ct[--inp] = 1;
    }
    for (int i =0 ;  i < m ; i ++){
        int x , y;
        cin >> x >> y;
        x--,y--;
        vec[x].pb(y);
        vec[y].pb(x);
    }
    cin >> s >> t;
    s--,t--;
    int l = 0 , r = n , ans = -1;
    while (r - l > 1){
        int mid = (l + r) / 2;
        if(chk(mid)){
            ans = mid;
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << ans;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
