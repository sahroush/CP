//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
int b[maxn];
int dp[20100][110];

int sum = 0;

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i] >> b[i], sum += b[i] , 
		a[i]*= 2;
	ms(dp , -1);
	dp[0][0] = 0;
	for(int i = 0 ; i < n ; i ++){
		for(int k = i ; k >= 0 ; k --){
			for(int j = 0 ; j <= 20000 ; j ++)
				if(dp[j][k] != -1){
					dp[j + a[i]][k + 1] = max(dp[j + a[i]][k + 1] , dp[j][k] + b[i]);
				}
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		int mx = 0;
		for(int j = 0 ; j <= 20000 ; j ++)
			if(dp[j][i]!=-1)mx = max(mx , min(j , sum +  dp[j][i]));
		
		cout << fixed << setprecision(10) << mx/2.0 << ' ';
	}
    return(0);
}
