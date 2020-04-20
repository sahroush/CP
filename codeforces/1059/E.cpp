#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll l , s;
ll w[maxn];
int par[maxn];
//vector < int > child[maxn];
//int sum[maxn];
//int len[maxn];
int ans[maxn];

/*
void dfs(int v){
	len[v] = 1;
	sum[v] = w[v][0];
	for(auto u : child[v])dfs(u);
	int mn = -1 , val = 0;
	for(auto u : child[v]){
		if(len[u] < l and sum[u] + w[v][0] <= s){
			if(mn == -1){
				mn = u;
				val = solve(u);
			}
			else if(solve(u) > val){
				mn = u;
				val = solve(u);
			}
		}
		ans[v]+=ans[u];
	}
	if(mn == -1)ans[v]++;
	else{
		sum[v]+=sum[mn];
		len[v] += len[mn];
	}
}
*/
int main(){
    migmig
    cin >> n >> l >> s;
    for(int i = 1;  i <= n; i ++ )
		cin >> w[i];
	for(int i = 2 ; i  <= n ; i ++){
		cin >> par[i];
		//child[par[i][0]].pb(i);
	}
	//for(int i = 1 ; i < 30 ; i ++)
		//for(int j = 1 ; j <= n ; j ++){
			//par[j][i] = par[par[j][i - 1]][i - 1];
			//w[j][i] = w[j][i - 1] + w[par[j][i - 1]][i - 1];
	//	}
	for(int i = 1 ; i <= n ; i ++)
		if(w[i]>s){
			dokme(-1);
		}
	//dfs(1);
	//cout << ans[1];
	ll res = 0;
	for(int i = n ; i > 0 ; i --){
		if(!ans[i]){
			res++;
			int cur = i;
			ll sum = s , len = l;
			while(cur!=0 and len > 0 and sum >= w[cur]){
				ans[cur] = 1;
				len--;
				sum-=w[cur];
				cur = par[cur];
			}
		}
	}
	cout << res;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
