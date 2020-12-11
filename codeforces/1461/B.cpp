/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 600;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , m;
string s[maxn];

int lst[maxn][maxn];

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i ++)
			cin >> s[i] , s[i] = '&' + s[i];
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= m ; j ++){
				if(s[i][j] == '*')lst[i][j] = lst[i][j - 1] + 1;
				else lst[i][j] = 0;
			}
		}
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= m ; j ++){
				if(s[i][j]!='*')continue;
				int x = i;
				int y = j;
				int cur = 1;
				while(x <= n and y <= m){
					if(lst[x][y] >= cur)ans++;
					else break;
					x++;
					y++;
					cur+=2;
				}
			}
		}
		cout << ans << endl;
	}




    return(0);
}
