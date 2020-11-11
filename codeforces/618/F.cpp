/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
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
ll a[maxn] , b[maxn];
ll diff[maxn];
int ind[maxn];
int cnt[maxn];

void range(int l , int r){
	cout << r - l + 1 << endl;
	for(int i = l ; i <= r ; i ++)
		cout << i << ' ' ;
	cout << endl;
}

int32_t main(){
    migmig;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , a[i] += a[i - 1];
	for(int i = 1 ; i <= n ; i ++)
		cin >> b[i] , b[i] += b[i - 1];
	int f = 0;
	if(a[n]>b[n])swap(a , b) , f = 1;
	int pos = 0;
	for(int i = 1 ; i <= n ; i ++){
		while(b[pos] < a[i] )pos++;
		if(a[i] == b[pos]){
			if(f)
				range(1 , pos) , range(1,  i);
			else
				range(1 , i) , range(1 , pos);
			return(0);
		}
		ind[i] = pos;
		int x = b[pos] - a[i];
		if(cnt[x]){
			if(f)
				range(ind[cnt[x]]+1 , pos) , range(cnt[x]+1 , i) ;
			else
				range(cnt[x]+1 , i) , range(ind[cnt[x]]+1 , pos);
			return(0);
		}
		cnt[x] = i;
	}
    return(0);
}
