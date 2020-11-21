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

int32_t main(){
    migmig;
	cin >> n;
	int axb = Xor(1 , 2);
	int axc = Xor(1 , 3);
	int cxd = Xor(3 , 4);
	int aab = And(1 , 2);
	int bac = And(2 , 3);
	int aac = And(1 , 3);
	int apb = axb + aab*2;
	int apc = axc + aac*2;
	int bpc = bac*2 + (axb^axc);
	a[1] = (apb - bpc + apc)/2;
	a[2] = apb - a[1];
	a[3] = apc - a[1];
	a[4] = a[3]^cxd;
	for(int i = 5 ; i <= n ; i ++){
		int x = Xor(i , 1);
		a[i] = x^a[1];
	}
	cout << "! ";
	for(int i = 1 ; i <= n ; i ++)
		cout << a[i] << ' ';
	cout.flush();
    return(0);
}
