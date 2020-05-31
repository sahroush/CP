#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1005;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int x , n;
vector < int > adj[maxn];
int d[maxn];
set < int > st , bad;

int main(){
    migmig
    cin >> q;
    while(q -- ){
		cin >> n >> x;
		for(int i = 1 ; i <= n ; i ++){
			adj[i].clear();
		}
		int cnt = 0;
		ms(d , 0);
		for(int i = 1 ; i < n ; i ++){
			int u , v;
			cin >> u >>  v;
			adj[u].pb(v);
			adj[v].pb(u);
			d[u]++;
			d[v]++;
		}
		//ms(mark , 0);
		//ms(lose , 0);
		int cur = 0;
		if(d[x]<=1){
			cur = 0;
		}
		else{
			n-=3;
			cur = 1 - (n%2);
		}
		if(cur == 1){
			cout << "Ashish" << endl;
		}
		else{
			cout << "Ayush" << endl;
		}
	}
    
    
    
    
    return(0);
}