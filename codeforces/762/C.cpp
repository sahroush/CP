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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string a , b;
int l[maxn] , r[maxn];

int n , m;

pii ans = {0 , 0};
int sz = 0;

int32_t main(){
    migmig;
	cin >> a >> b;
	n = a.size() , m = b.size();
	b = "a" + b, a = "a" + a;
	int pa = 1;
	for(int i = 1 ; i <= m ; i ++){
		while(a[pa] != b[i] and pa <= n)pa++;
		if(pa > n)l[i] = -1;
		else l[i] = pa , pa ++;
	}
	pa = n;
	for(int i = m ; i >= 1 ; i --){
		while(a[pa] != b[i] and pa >= 1)pa--;
		if(!pa)r[i] = -1;
		else r[i] = pa , pa --;
	}
	for(int i = 1 ; i <= m ; i ++){
		if(l[i] != -1){
			if(i > sz){
				sz = i;
				ans = {i , 0};
			}
		}
		if(r[i] != -1){
			if(m - i + 1 > sz){
				sz = m - i + 1;
				ans = {0 , m - i + 1};
			}
		}
	}
	int p2 = m;
	for(int i = 1 ; i <= n ; i ++){
		if(l[i] == -1)break;
		while(p2 > i and r[p2 - 1] > l[i])p2--;
		while(p2 <= m and (r[p2] <= l[i] or p2 <= i))p2++;
		if(p2 > m)break;
		if(p2 > i and r[p2] > l[i]){
			int SZ = m - p2 + 1 + i;
			if(SZ > sz){
				sz = SZ;
				ans = {i , m - p2 + 1};
			}
		}
	}
	if(sz == 0)dokme("-");
	for(int i = 1 ; i <= ans.first ; i ++)
		cout << b[i];
	for(int i = m - ans.second + 1 ; i <= m ; i ++)
		cout << b[i];
	
    return(0);
}
