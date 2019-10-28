#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5 + 10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);


ll n , k;
vector <int> vec[maxn];
ll dp[maxn][510];
bool mark[maxn];
ll first[maxn], nxt[maxn], pre[maxn];
ll ans  = 0 ;

void dfs1(int v, int p) {
	for (int y = 1; y <= k; y++) {
		dp[v][y] = 0;
	}
	for (int u = first[v]; u != 0; u = nxt[u]){
		if (pre[u] == p) continue;
		dfs1(pre[u], v);
		for (int y = 1; y <= k; y++) {
			dp[v][y] += dp[pre[u]][y-1];
		}
	}
}

void dfs2(int v, int p) {
	for (int u = first[v]; u != 0; u = nxt[u]) {
		if (pre[u] == p) continue;
		dfs2(pre[u], v);
	}
    ll t = 0;
	for (int i = 0; i <= k; i++) {
		t += dp[v][i] * dp[v][k-i];
		if (0 < i && i < k) {
			for (int u = first[v]; u != 0; u = nxt[u]) {
				if (pre[u] == p) continue;
				t -= dp[pre[u]][i-1] * dp[pre[u]][k-i-1];
			}
		}
	}
	ans += t / 2;
}

int main (){
    migmig;
    cin >> n >> k;
    for (int  i =0 ; i  < n-1 ; i ++){
        int a , b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
        nxt[i+1] = first[a];
		first[a] = i+1;
		pre[i+1] = b;
		nxt[i+n] = first[b];
		first[b] = i+n;
		pre[i+n] = a;
    }
    for (int i = 1 ; i <= n ; i ++){
        dp[i][0]= 1;
    }

    dfs1(1 , 0);
    dfs2(1 , 0);
    dokme(ans);


    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
