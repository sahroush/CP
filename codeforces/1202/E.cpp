/*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2e5 + 1;

#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int sigma = 26;

int n;
string t , s[maxn];

struct aho{
	int ch[sigma][maxn];
	int trie = 0;
	int link[sigma * maxn] , cnt[sigma * maxn] , par[sigma * maxn] , chr[sigma * maxn] , ans[maxn] , sum[maxn];
	int cache[sigma][maxn];
	void add(string s){
		int pos = 0;
		int n = s.size();
		for(int i = 0 ; i < n ; i ++){
			if(!ch[s[i] - 'a'][pos])ch[s[i] - 'a'][pos] = ++trie , par[trie] = pos , chr[trie] = s[i] - 'a';
			pos = ch[s[i] - 'a'][pos];
		}
		cnt[pos] ++;
	}
	int findlink(int pos);
	int getlink(int pos , int chr){
		if(cache[chr][pos] != -1)return(cache[chr][pos]);
		if(ch[chr][pos])return(ch[chr][pos]);
		if(pos == 0)return(0);
		return((cache[chr][pos] = getlink(findlink(pos) , chr)));
	}
	void suffixlink(){
		memset(link , -1 , sizeof link);
		memset(cache , -1 , sizeof cache);
		link[0] = 0;
		for(int i = 1 ; i <= trie ; i ++){
			findlink(i);
		}
	}
	int findexit(int pos){
		if(sum[pos] != -1)return(sum[pos]);
		sum[pos] = cnt[pos];
		return((sum[pos] = sum[pos] + findexit(link[pos])));
	}
	void exitlink(){
		memset(sum , -1 , sizeof sum);
		for(int i = 1 ; i <= trie ; i ++)
			sum[i] = findexit(i);
	}
	void debug(int pos){
		while(pos){
			cout << char(chr[pos] + 'a');
			pos = par[pos];
		}
		exit(0);
	}
	void solve(){
		int n = t.size();
		int pos = 0;
		for(int i = 0 ; i < n ; i ++){
			if(ch[t[i] - 'a'][pos])pos = ch[t[i] - 'a'][pos];
			else pos = getlink(pos , t[i] - 'a');
			ans[i+1] = sum[pos];
		}
	}
	void init(){
		suffixlink();
		exitlink();
		solve();
	}
};

int aho::findlink(int pos){
	if(link[pos] != -1)
		return(link[pos]);
	int res = getlink(findlink(par[pos]) , chr[pos]);
	if(res == pos)res = 0;
	return((link[pos] = res));
}

aho norm , rev;

int32_t main(){
	migmig;
	cin >> t;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i],
		norm.add(s[i]) , reverse(s[i].begin() , s[i].end()) , rev.add(s[i]);
	norm.init(), reverse(t.begin() , t.end()) , rev.init() , n = t.size();
	int64_t ans = 0;
	for(int i = 1 ; i < n ; i ++)
		ans += norm.ans[i] * 1ll * rev.ans[n - i];
	cout << ans;
	return(0);
}
