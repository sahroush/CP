/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


const int maxn = 2e5 + 100;

#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int sigma = 26;

struct aho{
	int nxt[sigma][maxn] , trie = 0 , cnt[maxn] , f[maxn] , q[maxn];
	void add(string &s){
		int pos = 0;
		for(char c : s){
			if(!nxt[c-'a'][pos])nxt[c-'a'][pos] = ++trie;
			pos = nxt[c-'a'][pos];
		}
		cnt[pos]++;
	}
	void build(){
		int l = 0 , r = 0;
		for(int i = 0 ; i < sigma ; i ++)if(nxt[i][0])q[r++] = nxt[i][0];
		while(l < r){
			int v = q[l++];
			cnt[v] += cnt[f[v]];
			for(int i = 0 ; i < sigma ; i ++)
				if(!nxt[i][v]) nxt[i][v] = nxt[i][f[v]];
				else f[nxt[i][v]] = nxt[i][f[v]] , q[r++] = nxt[i][v];
		}
	}
};

aho norm , rev;
int n;
string t , s[maxn];
int ans[maxn] , ansr[maxn];

void solve(int *ans , string &t , aho &ah){
	int pos = 0 , cnt = 0;
	for(char c : t){
		ans[cnt++] = ah.cnt[pos];
		pos = ah.nxt[c - 'a'][pos];
	}
}

int32_t main(){
	migmig;
	cin >> t;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i],
		norm.add(s[i]) , reverse(s[i].begin() , s[i].end()) , rev.add(s[i]);
	norm.build(), rev.build() , n = t.size();
	string tr = t;
	reverse(tr.begin() , tr.end());
	solve(ans , t , norm), solve(ansr , tr , rev);
	int64_t sum = 0;
	for(int i = 1 ; i < n ; i ++)
		sum += ans[i] * 1ll * ansr[n - i];
	cout << sum;
	return(0);
}
