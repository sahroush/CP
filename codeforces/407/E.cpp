/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e5+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);


#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

pii pos[maxn];
int a[maxn];
int n , k , d;

stack < int > mn , mx;

struct segment{
    int lazy[maxn*4] , seg[maxn*4] , cnt[maxn*4];
    int& ans = cnt[1];
    void build(int v = 1 , int l = 1 , int r = maxn){
        if(r - l == 1){
            cnt[v] = 1;
            return;
        }
        int mid = (l + r) /2;
        build(2*v , l , mid);
        build(2*v + 1 , mid , r);
        cnt[v] = cnt[2*v] + cnt[2*v + 1];
    }
    void shift(int v , int l , int r){
        if(lazy[v] == 0)
            return;
        seg[v] += lazy[v];
        if(r - l == 1){
            lazy[v] = 0;return;}
        lazy[2*v] += lazy[v];
        lazy[2*v + 1] += lazy[v];
        lazy[v] = 0;
    }
    void update(int L , int R , int val , int v = 1 , int l = 1 , int r = maxn){
        shift(v , l , r);
        if(l >= R or r <= L)
            return;
        if(l >= L and r <= R){
            lazy[v] += val;
            shift(v, l , r);
            return;
        }
        int mid = (l + r)/2;
        update(L , R , val , 2*v , l , mid);
        update(L , R , val , 2*v+1 , mid , r);
        if(seg[2*v] < seg[2*v + 1]){
            seg[v] = seg[2*v];
            cnt[v] = cnt[2*v];
        }
        else if(seg[2*v] == seg[2*v + 1]){
            seg[v] = seg[2*v];
            cnt[v] = cnt[2*v] + cnt[2*v + 1];
        }
        else{
            seg[v] = seg[2*v+1];
            cnt[v] = cnt[2*v+1];
        }
    }
    int solve(int pos , int v = 1 , int l = 1,  int r = maxn){
		shift(v , l , r);
		if(r - l == 1){
			if(seg[v] <= 0)return(l);
			else return(maxn);
		}
		int mid = (l + r) / 2;
		shift(2*v , l , mid);
		shift(2*v + 1 , mid , r);
		if(seg[2*v] <= 0)
			return(solve(pos ,  2*v , l , mid));
		return(solve(pos ,  2*v + 1 , mid , r));
	}
}seg;

int rmn[maxn];
map < int , int > lst;

int A[maxn];

void solve(){
	int L =1 , ans = 1, cur;
	cin >> cur;
	int cnt = 1;
	for(int i = 2 ; i <= n ; i ++){
		cin >> a[i];
		if(a[i] == cur)
			cnt ++ ;
		else
			cur = a[i] , cnt = 1;
		if(cnt > ans)
			L = i , ans = cnt;
	}
	cout << L - ans + 1 << ' ' << L;
	exit(0);
}

int32_t main(){
    migmig
    cin >> n >> k >> d;
    if(d == 0)
		solve();
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i] ,a[i] += 1e9 , A[i] = a[i] , rmn[i] = a[i]%d , a[i] -= rmn[i] , a[i]/=d;
    seg.build();
    int ans = 1;
    int L = 1;
    seg.update(1 , maxn , -k);
    for(int i = 1 ; i <= n ; i ++){
		if(rmn[i]!=rmn[i-1]){
			seg.update(1 , i , 1e10);
			while(mx.size())mx.pop();
			while(mn.size())mn.pop();
		}
		seg.update(1 , lst[A[i]]+1,1e10);
		lst[A[i]] = i;
        seg.update(1 , i , -1);
        int cur = i;
        while(!mx.empty() and a[i] > a[mx.top()]){
            int bz = mx.top();
            mx.pop();
            if(mx.size()){
                seg.update(mx.top()+1 , cur , a[i] - a[bz]);
                cur = mx.top()+1;
            }
            else{
                seg.update(1, cur , a[i] - a[bz]);
            }
        }
        cur = i;
        while(!mn.empty() and a[i] < a[mn.top()]){
            int bz = mn.top();
            mn.pop();
            if(mn.size()){
                seg.update(mn.top()+1 , cur , a[bz] - a[i]);
                cur = mn.top()+1;
            }
            else{
                seg.update(1, cur , a[bz] - a[i]);
            }
        }
        int res = i - seg.solve(i) + 1;
        if(res > ans)
			L = i , ans = res;
        mn.push(i);
        mx.push(i);
    }
    cout << L - ans + 1 << ' ' << L;
    return(0);
}
