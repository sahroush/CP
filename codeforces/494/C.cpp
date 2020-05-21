#include <bits/stdc++.h>

using namespace std;

typedef double ld;

const int maxn  = 1e5+100;

#define pb push_back
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct seg{
	int l , r;
	ld p;
}s[5111];

bool cmp (seg x, seg y){
	if (x.l == y.l)
		return (x.r > y.r);
	return (x.l < y.l);
}

int n , q;
int a[maxn][21];
ld dp[5111][5111] , pd[5111][5111] , ans;
int mx[5111];
vector < int > stk;
int par[5111];
vector < int > ch[5111];

void dfs(int v = 0){
	int sz = s[v].r-s[v].l+1;
	mx[v] = max(a[s[v].l][int(log2(sz))] , a[s[v].r - (1 << int(log2(sz)))+1][int(log2(sz))]);
	for(auto u : ch[v])dfs(u);
	for(int i = 0 ; i <= q ; i++){
		dp[i][v] += pd[i][v] * (1 - s[v].p);
		if(i)dp[i][v]+=pd[i-1][v]*s[v].p;
	}
	if(v==0)return;
	int diff = mx[par[v]] - mx[v];
	for(int i = diff ; i<=q; i ++ )
		pd[i-diff][par[v]]*=dp[i][v];
}

int main(){
    migmig
	cin >> n >> q;
	for(int i = 0 ; i < q+5;i++)
    for(int j = 0 ; j < q+5;j++)
    pd[i][j]=1;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i][0];
	for(int i = 1 ; (1 << i) <= n ; i ++)
		for(int j = 1 ; j + (1 << i) - 1 <= n ; j ++)
			a[j][i] = max(a[j][i-1] ,a[j+(1 << (i-1))][i-1]);
	s[0].l = 1 , s[0].r = n , s[0].p = 0;
	for(int i = 1 ; i <= q ; i ++)
		cin >> s[i].l >> s[i].r >> s[i].p;
	sort(s+1 , s + q + 1, cmp);
    stk.pb(0);
    for(int i = 1 ; i <= q ;i ++){
		while(stk.size() and s[i].l > s[stk.back()].r)
			stk.pop_back();
		par[i] = stk.back();
		ch[stk.back()].pb(i);
		stk.pb(i);
	}
	dfs();
	for(int i = q ; i ; i --){
		dp[i][0] -= dp[i-1][0];
	}
	for(int i = 0 ; i <= q ; i ++ )
		ans+=dp[i][0] * ld(mx[0] + i);
	cout << fixed << setprecision(9) << ans;
    return(0);
}