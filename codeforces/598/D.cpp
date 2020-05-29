#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n ,  m,  q;
string s[maxn];
int mark[4000][4000];
int val[maxn];
int cur = 1;
void dfs(int x , int y){
	if(x == n or x < 0 or y == m or y < 0)return;
	if(s[x][y] == '*'){
		val[cur]++;
		return;
	}
	if(mark[x][y])return;
	mark[x][y]=cur;
	dfs(x-1 , y);
	dfs(x , y-1);
	dfs(x+1 , y);
	dfs(x , y+1);
}

int main(){
    migmig
    cin >> n >> m >> q;
    for(int i = 0 ;  i < n ; i ++)
		cin >> s[i];
    while(q--){
		int x , y;
		cin >> x >> y;
		x-- , y--;
		if(!mark[x][y])dfs(x,y);
		cur++;
		cout << val[mark[x][y]] << endl;
	}
    
    
    
    
    return(0);
}