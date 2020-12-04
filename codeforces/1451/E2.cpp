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
//#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int Xor(int a , int b){
	cout << "XOR" << ' ' << a << ' ' << b << endl;
	int ans ;
	cin >> ans;
	return(ans);
}
int And(int a , int b){
	cout << "AND" << ' ' << a << ' ' << b << endl;
	int ans ;
	cin >> ans;
	return(ans);
}

int n;

int a[maxn];
int xr[maxn];

int pos[maxn];

int32_t main(){
    migmig;
	cin >> n;
	pii boz = {-1 , -1};
	for(int i = 2 ; i <= n ; i ++){
		xr[i] = Xor(1 , i);
		if(pos[xr[i]])
			boz = {pos[xr[i]] , i};
		pos[xr[i]] = i;
	}
	if(boz != pii(-1 , -1)){
		int v = And(boz.first , boz.second);
		a[1] = xr[boz.first]^v;
	}
	else{
		int a = 1;
		int b = 1;
		for(int i = 1 ; i <= n ; i ++) if(xr[i] == n-1)b = i;
		int c = 1;
		while(c == a or c == b) c = rng()%n + 1;
		int axb = xr[b];
		int axc = xr[c];
		int bxc = axb ^ axc;
		int aac = And(a , c);
		int bac = And(b , c);
		int apb = n-1;
		int apc = axc + 2*aac;
		int bpc = bxc + 2*bac;
		::a[1] = (apb + apc - bpc)/2;
	}
	for(int i = 1 ; i <= n ; i ++)
		a[i] = xr[i]^a[1];
	cout << "! ";
	for(int i = 1 ; i <= n ; i ++)
		cout << a[i] << ' ';
	cout.flush();
    return(0);
}
