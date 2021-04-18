//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

#define endl '\n'

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
		return ((((*this)[!curbit]->mn <= lim)) ? (*this)[!curbit]->get(x , lim , i-1) : (*this)[curbit]->get(x , lim , i-1));
	}
};
node* trie [maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> q;
	for(int i = 1 ; i < maxn ; trie[i] = new node() , i ++)
		for(int j = i ; j < maxn ; j += i)
			d[j].push_back(i);
	while(q --){
		int t , x , k , s;
		cin >> t >> x;
		if(t == 1 and !mark[x]){
			mark[x] = 1;
			for(auto y : d[x])trie[y]->add(x);
		}
		if(t == 2)
			cin >> k >> s , cout << ((x % k) ? -1 : trie[k]->get(x , s-x)) << endl;
	}
	return(0);
}
