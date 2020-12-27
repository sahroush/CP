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

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
int a[maxn];

int mark[maxn];

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		int sml = 0, bg = 0; //Dnsh case
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i] , sml += (a[i] <= n) , bg += (a[i] > n);
		for(int i = 1 ; i <= 2*n ; i ++)mark[i] = 0;
		for(int i = 1 ; i <= n ; i ++)
			mark[a[i]] = 1;
		int cnt = 0 , cur = n+n , mn = 0;
		for(int i = 1 ; i <= 2*n ; i ++){
			if(mark[i] == 0)cnt++;
			else if (mark[i] == 2)continue;
			else{
				if(cnt)cnt--;
				else{
					mn++;
					while(mark[cur] != 0)cur--;
					mark[cur] = 2;
				}
			}
		}
		for(int i = 1 ; i <= 2*n ; i ++)mark[i] = 0;
		for(int i = 1 ; i <= n ; i ++)
			mark[2*n - a[i] + 1] = 1;
		int mx = 0;
		cur = n + n , cnt = 0;
		for(int i = 1 ; i <= 2*n ; i ++){
			if(mark[i] == 0)cnt++;
			else if (mark[i] == 2)continue;
			else{
				if(cnt)cnt--;
				else{
					mx++;
					while(mark[cur] != 0)cur--;
					mark[cur] = 2;
				}
			}
		}
		mx = n - mx;
		cout << mx - mn + 1 << endl;
	}
    return(0);
}
