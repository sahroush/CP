#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int par[maxn];
int sz[maxn];
vector < int > vec;
vector < pii > v;
int cnt[maxn];
int dp[maxn];

int getpar(int v){
	return((v == par[v])?v:par[v] = getpar(par[v]));
}

void merge(int u , int v){
	u = getpar(u) , v = getpar(v);
	if(u == v)
		return;
	if(sz[u] > sz[v])
		swap(u , v);
	par[u] = v;
	sz[v] += sz[u];
}

bool lucky(int x){
	while(x){
		if(x%10 != 4 and x%10!=7)
			return(0);
		x/=10;
	}
	return(1);
}

int main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++){
		par[i] = i;
		sz[i] = 1;
	}
	for(int i = 0 ; i < m ; i ++){
		int u , v;
		cin >> u >> v;
		merge(u , v);
	}
	for(int i = 1 ; i <= n ; i ++){
		if(sz[getpar(i)]){
			cnt[sz[getpar(i)]] ++;
			if(cnt[sz[getpar(i)]] == 1)
				vec.pb(sz[getpar(i)]);
			sz[getpar(i)] = 0;
		}
	}
    sort(vec.begin() , vec.end());
    for(int i : vec){
		int sum = 0;
		for(int j = 0 ; j < 18 ; j ++){
			sum+=(1 << j);
			if(sum > cnt[i]){
				sum-=(1 << j); 
				break;
			}
			v.pb(pii(i * (1 << j) , (1 << j) - 1));
		}
		cnt[i]-=sum;
		v.pb(pii(i * cnt[i] , cnt[i] - 1));
	}
	ms(dp , 63);
	dp[0] = 0;
	for(auto u : v){
		for(int i = n ; i > u.first ; i --)
			dp[i] = min(dp[i] , dp[i - u.first] + u.second + 1);\
		dp[u.first] = min(dp[u.first] , u.second);
	}
    int mn = dp[n+1];
    for(int i = 1 ; i <= n ; i ++)
		if(lucky(i))
			mn = min(mn , dp[i]);
	cout << ((mn == dp[n + 1]?-1:mn));
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
