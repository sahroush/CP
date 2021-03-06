/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 210;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)

const int sigma = 27;

int n , nxt[sigma][maxn * maxn], f[maxn*maxn] , a[maxn] , aho = 0 , val[maxn*maxn];
ll l;
string s[maxn];

struct que{
	int l = 0, r = 0, q[maxn];
	int pop(){
		return(q[l++]);
	}
	void push(int x){
		q[r++] = x;
	}
	int size(){
		return(r - l);
	}
}q;

void add(int i){
	int cur = 0;
	for(char c : s[i]){
		if(!nxt[c - 'a'][cur])nxt[c - 'a'][cur] = ++aho;
		cur = nxt[c - 'a'][cur];
	}
	val[cur] += a[i];
}

void build(){
	for(int i = 0 ; i < sigma ; i ++)if(nxt[i][0])q.push(nxt[i][0]);
	while(q.size()){
		int v = q.pop();
		val[v] += val[f[v]];
		for(int i = 0 ; i < sigma ; i ++)
			if(nxt[i][v]) f[nxt[i][v]] = nxt[i][f[v]], q.push(nxt[i][v]);
			else nxt[i][v] = nxt[i][f[v]];
	}
}

struct matrix{
	ll a[maxn][maxn];
	int n , m;
	matrix():
		n(0), m(0){ms(a , -1);}
	matrix(int N , int M):
		n(N), m(M){ms(a , -1);}
	void dia(){
		for(int i = 0 ; i < maxn ; i ++)a[i][i] = 0;
	}
	friend matrix operator * (matrix &a , matrix &b){
		matrix ans(a.n , b.m);
		for(int k = 0 ; k < a.m ; k ++)
			for(int i = 0 ; i < a.n ; i ++)
				for(int j = 0 ; j < b.m ; j ++)
					if(a.a[i][k]^-1 and b.a[k][j]^-1)
						ans.a[i][j] = max(ans.a[i][j] , a.a[i][k] + b.a[k][j]);
		return(ans);
	}
	friend matrix operator ^ (matrix &a, ll &b){matrix res(a.n , a.m);res.dia();while(b){if(b&1){res=(a*res);}a=(a*a);b>>=1;}return(res);}
};

int32_t main(){
	migmig;
	cin >> n >> l;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i] , add(i);
	build();
	matrix mat(aho+1 , aho+1);
	for(int i = 0 ; i <= aho ; i ++)
		for(int j = 0 ; j < sigma ; j ++)
			mat.a[nxt[j][i]][i] = max(mat.a[nxt[j][i]][i] , 1LL * val[nxt[j][i]]);
	mat = mat ^ l;
	matrix res(aho+1 , 1+1);
	res.a[0][0] = 0;
	res = mat * res;
	ll ans = 0;
	for(int i = 0 ; i <= aho ; i ++)
		ans = max(ans , res.a[i][0]);
	cout << ans;
	return(0);
}
