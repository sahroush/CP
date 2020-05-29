#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
int win[maxn] , lose[maxn];
string s;

int ch[maxn][26];
int cur = 0;

void add(string s){
	int pos = 0;
	for(auto i : s){
		if(ch[pos][i - 'a'] == 0){
			ch[pos][i - 'a'] = ++cur;
		}
		pos = ch[pos][i - 'a'];
	}
} 

void dfs(int v){
	bool l = 1;
	for(int i = 0 ; i < 26 ; i ++)
		if(ch[v][i]){
			dfs(ch[v][i]);
			l = 0;
			win[v] |= (!win[ch[v][i]]);
			lose[v]|= (!lose[ch[v][i]]);
		 }
	if(l)
		lose[v] = 1;
}


int main(){
    migmig
    cin >> n >> k;
    for(int i = 0 ; i < n ; i ++){
		cin >> s;
		add(s);
	}
    dfs(0);
    lose[0]|=k%2;
    if(win[0] and lose[0])dokme("First")
    dokme("Second")
    return(0);
}