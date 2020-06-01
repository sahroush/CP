#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 9e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
string s;
int ch[maxn][27];
int cur , ans[maxn] , sum;
int cnt[maxn];
vector < int > vec[maxn][2];
int vl[maxn];

void add(int ind , int t = 0){
	int pos = 0;
	for(auto i : s){
		if(!ch[pos][i-'a']){
			ch[pos][i-'a'] = ++cur;
		}
		pos = ch[pos][i-'a'];
		cnt[pos]++;
	}
	vec[pos][t].pb(ind);
}

void merge(int v , int u){
	if(!u)return;
	for(auto i : vec[u][0])vec[v][0].pb(i);
	for(auto i : vec[u][1])vec[v][1].pb(i);
}

void dfs(int v = 0 , int h = 0){
	int mx = v;
	for(int i = 0 ; i < 26 ;i ++){
		if(ch[v][i]){
			dfs(ch[v][i] , h + 1);
			if(vl[ch[v][i]] > vl[mx])mx = ch[v][i];
		}
	}
	swap(vec[v][0] , vec[mx][0]);
	swap(vec[v][1] , vec[mx][1]);
	for(int i = 0 ; i < 26 ; i ++){
		merge(v , ch[v][i]);
	}
	sum+=min((int)vec[v][0].size(),(int)vec[v][1].size())*h;
	while(vec[v][0].size() and vec[v][1].size()){
		ans[vec[v][0].back()] = vec[v][1].back();
		vec[v][0].pop_back() , vec[v][1].pop_back();
	}
}

int main(){
    migmig
    cin >> n;
    for(int i  = 1 ; i <= n ; i ++){
		cin >> s;
		add(i);
	}
	for(int i = 1 ; i <= n ; i ++){
		cin >> s;
		add(i,1);
	}
	dfs();
	cout << sum << endl;
	for(int i = 1 ; i <= n ; i ++){
		cout << i << ' ' << ans[i] << endl;
	} 
    return(0);
}