//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 510;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int p[maxn];
int ans[maxn][maxn];
int cnt[maxn];
int pos[maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> p[i] , pos[p[i]] = i;
	for(int i = 1 ; i <= n ; i ++){
		int x = i , y = i;
		while(cnt[p[i]] < p[i]){
			ans[x][y] = p[i];
			cnt[p[i]]++;
			if(y > 1 and ans[x][y-1] == 0){
				y--;
			}
			else{
				x++;
			}
		}
		
	}


	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= i ; j ++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
	return(0);
}
