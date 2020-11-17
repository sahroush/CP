/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1000;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , m;
string s[maxn];

struct tr{
	int a , b , c , d , e , f;
	tr(int x , int y , int z ,int t , int p , int q):
		a(x) , b(y) , c(z) , d(t) , e(p) , f(q){};
};

vector < tr > ans;

void flip(int i , int j){
	if(s[i][j] == '1')s[i][j] = '0';
	else s[i][j] = '1';
}	

void solve(int x , int y){ // for 2*2
	int a[2][2];
	vector < tr > tmp;
	for(int i = 0 ; i < (1 << 4) ; i ++){
		tmp.clear();
		a[0][0] = (s[x][y] == '1');
		a[0][1] = (s[x][y+1] == '1');
		a[1][0] = (s[x+1][y] == '1');
		a[1][1] = (s[x+1][y+1] == '1');
		if(i&(1)){
			tmp.pb({x , y , x + 1 , y , x , y + 1});
			a[0][0] = !a[0][0];
			a[0][1] = !a[0][1];
			a[1][0] = !a[1][0];
		}
		if(i&(2)){
			tmp.pb({x , y , x + 1 , y , x+1 , y + 1});
			a[0][0] = !a[0][0];
			a[1][1] = !a[1][1];
			a[1][0] = !a[1][0];
		}
		if(i&(4)){
			tmp.pb({x , y+1 , x + 1 , y , x+1 , y + 1});
			a[0][1] = !a[0][1];
			a[1][1] = !a[1][1];
			a[1][0] = !a[1][0];
		}
		if(i&(8)){
			tmp.pb({x , y , x + 1 , y +1, x , y + 1});
			a[0][0] = !a[0][0];
			a[1][1] = !a[1][1];
			a[0][1] = !a[0][1];
		}
		int sum = 0;
		for(int i = 0 ; i <2 ; i ++)
			for(int j = 0 ; j < 2 ; j ++)
				sum += a[i][j];
		if(sum == 0){
			for(auto i : tmp)
				ans.pb(i);
			return;
		}
	}
}

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		ans.clear();
		cin >> n >> m;
		for(int i = 0 ; i < n ; i ++)
			cin >> s[i];
		int go = n - 2;
		for(int i = 0 ; i < go ; i ++){
			for(int j = 0 ; j < m ; j ++){
				if(s[i][j] == '1'){
					flip(i , j);
					flip(i + 1 , j);
					if(j == 0){
						flip(i + 1 , j + 1);
						ans.pb({i , j , i+1 , j , i +1 , j + 1});
					}
					else{
						flip(i + 1 , j - 1);
						ans.pb({i , j , i+1 , j , i +1 , j - 1});
					}
				}
			}
		}
		//2 * m
		//n-2 , n-1
		go = m - 2;
		for(int j = 0 ; j < go ; j ++ ){
			for(int i = n-2 ; i < n ; i ++){
				if(s[i][j] == '1'){
					flip(i , j);
					flip(i , j + 1);
					if(i == n-2){
						flip(i + 1 , j+1);
						ans.pb({i , j , i , j + 1 , i + 1 , j + 1});
					}
					else{
						flip(i-  1 , j  + 1);
						ans.pb({i , j , i , j + 1 , i - 1 , j + 1});
					}
				}
			}
		}
		//2*2
		solve(n-2 , m-2);
		cout << ans.size() << endl;
		for(auto x : ans){
			cout << x.a+1 << ' ' << x.b+1 << ' ' << x.c+1 << ' ' << x.d+1 << ' ';
			cout << x.e+1 << ' ' << x.f+1 << endl;
		}
	}




    return(0);
}
