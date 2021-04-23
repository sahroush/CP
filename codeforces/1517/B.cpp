//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , m;
ll a[110][110];
pii x[maxn];
int own[110][110];
int ans[110][110];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> q;
	while(q --){
		cin >> n >> m;
		int cnt = 0;
		for(int i = 0 ; i < n ; i ++)
			for(int j = 0 ; j < m ; j ++)
				cin >> a[i][j] , x[++cnt] = {a[i][j] , i * (m + 1) + j} , ans[i][j] = 0;
		sort(x + 1 , x + cnt + 1);
		for(int i = 1 ; i <= m ; i ++)
			ans[x[i].second/(m+1)][i-1] = x[i].first , own[x[i].second/(m+1)][x[i].second%(m+1)] = 1;
			

		for(int i = 0 ; i < n ; i ++){
			int cur = 0;
			for(int j = 0 ; j < m ; j ++)if(!own[i][j]){
				while(ans[i][cur])cur++;
				ans[i][cur] = a[i][j];
			}
		}
	
		for(int i = 0 ; i < n ; i ++){
			for(int j = 0 ; j < m ; j ++)
				cout << ans[i][j] << ' ';
			cout << endl;
		}
			
		for(int i = 1 ; i <= m ; i ++)
			own[x[i].second/(m+1)][x[i].second%(m+1)] = 0;
	}

	return(0);
}
