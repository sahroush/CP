//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q , sz;
vector < int > d[maxn];
bool mark[maxn];

#define curbit ((x & (1 << i)) > 0)
struct node{
	int mn;
	node* ch[2];
	node():
		mn(1e9) , ch{nullptr , nullptr}{}
	node* operator [] (int x){if(!ch[x])ch[x] = new node();return ch[x];}
	void add(int x , int i = 17){
		mn = min(mn , x);
		if(i == -1)return;
		(*this)[curbit]->add(x , i-1);
	}
	int get(int x , int lim , int i = 17){
		if(mn > lim)return -1;
		if(i == -1)return mn;
		if((*this)[!curbit]->mn <= lim)return (*this)[!curbit]->get(x , lim , i-1);
		return (*this)[curbit]->get(x , lim , i-1);
	}
};
node* trie [maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> q;
	for(int i = 1 ; i < maxn ; trie[i] = new node() , i ++)
		for(int j = i ; j < maxn ; j += i)
			d[j].pb(i);
	while(q --){
		int t , x;
		cin >> t >> x;
		if(t == 1 and !mark[x]){
			mark[x] = 1;
			for(auto y : d[x])trie[y]->add(x);
		}
		if(t == 2){
			int k , s;
			cin >> k >> s;
			if(x % k)
				cout << -1 << endl;
			else
				cout << trie[k]->get(x , s-x) << endl;
		}
	}
	return(0);
}
