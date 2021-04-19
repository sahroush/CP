//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e5+10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n, q;
int a[maxn];

#define mid ((l+r)>>1)



int l[maxn]  ,r[maxn];

vector < int > query[maxn];
int cnt[maxn];
vector < int > pos[maxn];

int fen[maxn];

void add(int pos , int x){
	for (pos += 5 ; pos < maxn ; pos += pos & -pos)
		fen[pos] += x;
}

int get(int pos){
	int res = 0;
	for(pos += 5 ; pos ; pos -= pos & -pos)
		res += fen[pos];
	return res;
}

int get(int l , int r){
	return get(r) - get(l - 1);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	//offlie we go bitch!
	for(int i = 1 ; i <= n ; i ++)cin >> a[i] , pos[a[i]].pb(i);
	for(int i = 1 ; i <= q ; i ++){
		cin >> l[i] >> r[i];
		int sz = (r[i] - l[i] + 1);
		for(int j = 0 ; j < 20 ; j ++){ 
			int x = a[l[i] + (rng()%sz)];
			query[x].pb(i);
		}
		/*
		if(mx == -1){
			cout << 1 << endl;
			continue;
		}
		int l = 1 , r = n;
		while(r - l > 1){
			int rmn = cnt - (mid - 1);
			if(rmn <= (sz - (mid - 1) + 1)/2)r = mid;
			else l = mid;
		}
		cout << r << endl;
		*/
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int x : pos[i])add(x , 1);
		for(int x : query[i]){
			int sz = (r[x] - l[x] + 1);
			int res = get(l[x] , r[x]);
			if(res > (sz + 1)/2)cnt[x] = res;
		}
		for(int x : pos[i])add(x , -1);
	}
	for(int i = 1 ; i <= q ; i ++){
		if(cnt[i] == 0){
			cout << 1 << endl;
		}
		else{
			int sz = ::r[i] - ::l[i] + 1;
			int l = 1 , r = n;
			while(r - l > 1){
				int rmn = cnt[i] - (mid - 1);
				if(rmn <= (sz - (mid - 1) + 1)/2)r = mid;
				else l = mid;
			}
			cout << r << endl;
		}
	}
	return(0);
}
