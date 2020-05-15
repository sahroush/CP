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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s;
int k , n;
int cost[600][600];
int dp[600][600];
string pol[600][600];
int par[600][600];

void solve(int pos ,int  limit){
	if(pos == 0)
		return;
	solve(par[pos][limit] , limit-1);
	if(par[pos][limit])
		cout << '+';
	int l = par[pos][limit] , r = pos-1;
	for( ; ; l ++ , r --){
		if(l >= r)break;
		if(s[l]!=s[r])
			s[l]=s[r];
	}
	for(int i = par[pos][limit] ; i < pos ; i ++)
		cout << s[i];
}

int main(){
    migmig
    cin >> s >> k;
    n = s.size();
    for(int i = n-1 ; i >= 0 ; i -- )
		for(int j = i + 1 ; j < n ; j ++)
			if(s[i] == s[j])
				cost[i][j] = cost[i+1][j-1];
			else
				cost[i][j] = cost[i+1][j-1]+1;
    ms(dp , 63);
    dp[0][0] = 0;
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < k ; j ++)
			for(int h = i ; h < n ; h ++)
				if(dp[i][j] + cost[i][h] < dp[h+1][j+1])
					dp[h+1][j+1] = dp[i][j] + cost[i][h] , par[h+1][j+1] = i;
   int mn = 0;
	for(int i = 0 ; i <= k ; i ++)
		if(dp[n][i] < dp[n][mn])
			mn = i;
	cout << dp[n][mn] << endl;
	solve(n,  mn);
    return(0);
}