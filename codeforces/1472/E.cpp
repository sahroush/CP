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

struct node{
	int h , w , id;
	void inp(int x){
		cin >> h >> w;
		id = x;
	}
};

bool cmpw(node a , node b){
	if(a.w == b.w)
		return(a.h > b.h);
	return(a.w < b.w);
}
bool cmph(node a , node b){
	if(a.h == b.h)
		return(a.w < b.w);
	return(a.h < b.h);
}
bool cmpid(node a , node b){
	return(a.id < b.id);
}

node a[maxn];
int n , q;
int ans[maxn];

int M[maxn];

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
			a[i].inp(i) , ans[i] = -1;
		sort(a + 1 , a + n + 1 , cmpw);
		int mn = 1;
		for(int i = 2 ; i <= n ; i ++){
			if(a[i - 1].h < a[mn].h and a[i - 1].w != a[i].w)mn = i - 1;
			if(a[mn].h < a[i].h and a[mn].w < a[i].w)ans[a[i].id] = a[mn].id;
		}
		M[1] = 1;
		for(int i = 2 ; i <= n ; i ++){
			M[i] = M[i - 1];
			if(a[i].h < a[M[i]].h)M[i] = i;
		}
		for(int i = 1 ; i <= n ; i ++){
			int l = 1 , r = n+1;
			while(r - l > 1){
				int mid = (l + r)/2;
				if(a[mid].w < a[i].h)
					l = mid;
				else
					r = mid;
			}
			if(a[l].w >= a[i].h)continue;
			if(a[M[l]].h < a[i].w)ans[a[i].id] = a[M[l]].id;
		}
		sort(a + 1 , a + n + 1 , cmpid);		
		for(int i = 1 ;  i <= n ; i ++){
			if(ans[i]!=-1)assert((a[i].h > a[ans[i]].h and a[i].w > a[ans[i]].w) or 
			(a[i].h > a[ans[i]].w and a[i].w > a[ans[i]].h) );
			cout << ans[i] << ' ' ;
			
		}
		cout << endl;
	}
    return(0);
}
