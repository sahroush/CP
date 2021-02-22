#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , ll> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 1;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

struct que{
	int q[maxn];
	int l = 0 , r = 0;
	void push(int x){
		q[r++] = x;
	}
	void pop(){
		l++;
	}
	int front(){
		return(q[l]);
	}
	int size(){
		return(r - l);
	}
}q;

const int sigma = 26;

int n , cnt[maxn] , endpoint[maxn];
vector < int > ed[maxn];
int nxt[sigma][maxn] , f[maxn] , ext[maxn] , pos[maxn] , sz = 0;
string s[maxn];
bitset < maxn > bs;
unordered_map < int , ll > mp[maxn];

int add(int i){
	string s = ::s[i];
	int cur = 0;
	for(char c : s){
		if(!nxt[c - 'a'][cur])nxt[c - 'a'][cur] = ++sz;
		cur = nxt[c - 'a'][cur];
	}
	endpoint[cur] = 1;
	ed[cur].pb(i);
	return cur;
}

bool mark[maxn];

void build(){
	for(int i = 0 ; i < sigma ; i ++)if(nxt[i][0])q.push(nxt[i][0]);
	while(q.size()){
		int v = q.front();
		q.pop();
		if(endpoint[f[v]])ext[v] = f[v];
		else ext[v] = ext[f[v]];
		for(int i = 0 ; i < sigma ; i ++)
			if(nxt[i][v])f[nxt[i][v]] = nxt[i][f[v]] , q.push(nxt[i][v]);
			else nxt[i][v] = nxt[i][f[v]];
	}
}

ll ans[maxn];

vector < pii > L[maxn] , R[maxn];

void make(int i){
	if(mark[pos[i]])return;
	sort(L[pos[i]].begin() , L[pos[i]].end());
	reverse(L[pos[i]].begin() , L[pos[i]].end());
	sort(R[pos[i]].begin() , R[pos[i]].end());
	reverse(R[pos[i]].begin() , R[pos[i]].end());
	mark[pos[i]] = 1;
	int cur = 0 ;
	for(char c : s[i]){
		cur = nxt[c - 'a'][cur];
		int x = cur;
		while(x){
			if(endpoint[x])
				for(auto j : ed[x])cnt[j]++ , bs[j] = 1;
			x = ext[x];
		}
	}
	ll sum = 0;
	for(int j = bs._Find_first() ; j < maxn ; j = bs._Find_next(j)){
		while(L[pos[i]].size() and j >= L[pos[i]].back().first)ans[L[pos[i]].back().second]-=sum , L[pos[i]].pop_back();
		while(R[pos[i]].size() and j >  R[pos[i]].back().first)ans[R[pos[i]].back().second]+=sum , R[pos[i]].pop_back();
		sum += cnt[j];
		cnt[j] = 0;
		bs[j] = 0;
	}
	while(L[pos[i]].size() )ans[L[pos[i]].back().second]-=sum , L[pos[i]].pop_back();
	while(R[pos[i]].size() )ans[R[pos[i]].back().second]+=sum , R[pos[i]].pop_back();
}

int l[maxn] , r[maxn] , k[maxn];


int32_t main(){
	migmig;
	int q;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i], pos[i] = add(i);
	build();
	for(int i = 1 ; i <= q ; i ++){
		cin >> l[i] >> r[i] >> k[i];
		L[pos[k[i]]].pb({l[i] , i});
		R[pos[k[i]]].pb({r[i] , i});
	}
	for(int i = 1 ; i <= n ; i ++)
		make(i);
	for(int i = 1 ; i <= q ; i ++)
		cout << ans[i] << endl;
	return(0);
}
