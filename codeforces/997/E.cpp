#include <iostream>
#include <vector>

using namespace std;

const int maxn = 120010;

typedef long long ll;
typedef pair < int , int > pii;

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)
#define ff first
#define ss second

struct stack{
	int a[maxn];
	int sz = 0;
	int operator [] (int x){
		return(a[x]);
	}
	void push(int x){
		a[++sz] = x;
	}
	void pop(){
		sz--;
	}
	int top(){
		return(a[sz]);
	}
	int size(){
		return(sz);
	}
}mn , mx;

int n , m , a[maxn];
ll ans[maxn];
vector < pii > q[maxn];

struct node{
	int lazy , sum , num , cnt;
	ll ans;
}seg[maxn << 2];

void build(int v = 1 , int l = 1 , int r = n + 1){
	seg[v].sum = l, seg[v].num = 1;
	if(r - l == 1)
		return;
	build(lc , l , mid);
	build(rc , mid , r);
}

void add(int v , int x){
	seg[v].sum += x , seg[v].lazy += x;
}

void Add(int v , int x){
	seg[v].cnt += x , seg[v].ans += 1LL * x * seg[v].num;
}

void shift(int v , int l , int r){
	if(seg[v].lazy and r - l > 1)
		add(lc , seg[v].lazy) , add(rc , seg[v].lazy);
	if(seg[v].cnt  and r - l > 1){
		if(seg[v].sum == seg[lc].sum)
			Add(lc , seg[v].cnt);
		if(seg[v].sum == seg[rc].sum)
			Add(rc , seg[v].cnt);
	}
	seg[v].lazy = seg[v].cnt = 0;
}

void update(int L , int R , int x , int v = 1, int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(R <= l or r <= L)return;
	if(L <= l and r <= R){
		add(v , x);
		return;
	}
	update(L , R , x , lc , l , mid);
	update(L , R , x , rc , mid , r);
	seg[v].sum = min(seg[lc].sum , seg[rc].sum);
	seg[v].ans = seg[lc].ans + seg[rc].ans;
	seg[v].num = 0;
	if(seg[v].sum == seg[lc].sum)seg[v].num += seg[lc].num;
	if(seg[v].sum == seg[rc].sum)seg[v].num += seg[rc].num;
}

ll query(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)return(0);
	if(L <= l and r <= R)return(seg[v].ans);
	return(query(L , R , lc , l , mid) + query(L , R , rc , mid , r));
}

int32_t main(){
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	cin >> m;
	for(int i = 1 ; i <= m ; i ++){
		int l , r;
		cin >> l >> r;
		q[r].push_back({l , i});
	}
	build();
	for(int i = 1 ; i <= n ; i ++){
		add(1 , -1);
		while(mx.size() and a[mx.top()] < a[i])
			update(mx[mx.sz - 1] + 1, mx.top() + 1, a[i] - a[mx.top()]) , mx.pop();
		mx.push(i);
		while(mn.size() and a[mn.top()] > a[i])
			update(mn[mn.sz - 1] + 1, mn.top() + 1, a[mn.top()] - a[i]) , mn.pop();
		mn.push(i);
		Add(1 , 1);
		for(auto [ l , ind ] : q[i])
			ans[ind] = query(l , i + 1);
	}
	for(int i = 1 ; i <= m ; i ++)
		cout << ans[i] << endl;
    return(0);
}
