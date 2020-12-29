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

ll a , b , n , x;

struct matrix{
	vector < vector < int > > mat;
	int n , m;
	matrix (int N , int M){
		n = N , m = M;
		mat.resize(n);
		for(int i = 0 ; i < n ; i ++)mat[i].resize(m);
		for(int i = 0 ; i < n ; i ++)
			for(int j = 0 ; j < m ; j ++)
				mat[i][j] = 0;
	}
	friend matrix operator * (matrix &A , matrix &B){
		assert(A.m == B.n);
		int &n = A.n , &m = B.m;
		int &K = A.m;
		matrix C(n , m);
		auto &c = C.mat;
		auto &a = A.mat;
		auto &b = B.mat;
		for(int i = 0 ; i < n ; i ++)
			for(int k = 0 ; k < K ; k ++)
				for(int j = 0 ; j < m ; j ++)
					c[i][j] = (1LL * c[i][j] + 1LL * a[i][k] * b[k][j])%mod;
		return(C);
	}
	friend matrix operator ^ (matrix a , ll b){
		matrix res(a.n , a.n);
		for(int i = 0 ; i < a.n ; i ++)res.mat[i][i] = 1;
		while(b){
			if(b&1)res = a*res;
			b>>=1;
			a = a * a;
		}
		return(res);
	}
};

int32_t main(){
    migmig;
	cin >> a >> b >> n >> x;
	matrix m(2 , 2);
	m.mat[0][0] = m.mat[1][0] = 1;
	m.mat[1][1] = a;
	m = m^n;
	matrix ans(2 , 1);
	ans.mat[0][0] = b;
	ans.mat[1][0] = x;
	ans = m * ans;
	cout << ans.mat[1][0];
    return(0);
}
