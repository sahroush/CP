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

string s , t , v;
int dp[200][200][200];
vector < int > f;

vector < int > kmp(string s){
    int n = s.size();
    vector < int > f(n);
    for(int i = 1; i < n ; i ++){
		int j = f[i-1];
		while(j and s[i]!=s[j])
			j = f[j-1];
		j+=(s[i]==s[j]) , f[i] = j;
	}
    return(f);
}

int memo(int i = 0, int j = 0, int k = 0 ){
	if(k == (int)v.size())
		return(-200);
	if(i == (int)s.size() or j == (int)t.size())
		return(0);
	if(dp[i][j][k] > -1)
		return(dp[i][j][k]);
	dp[i][j][k] = max(memo(i+1 , j , k) , memo(i , j + 1 , k));
	if(s[i] == t[j]){
		int pos = k;
		while(pos and v[pos]!=s[i])
			pos = f[pos-1];
		pos+=(v[pos] == s[i]);
		dp[i][j][k] = max(dp[i][j][k] ,memo(i+1 , j+1 , pos)+1);
	}
	return(dp[i][j][k]);
}

void solve(int i = 0, int j = 0, int k = 0 ){
	if(i == (int)s.size() or j == (int)t.size())
		return;
	int res = memo(i , j , k);
	if(!res)
		return;
	if(memo(i + 1 , j , k ) == res){
		solve(i + 1 , j , k);return;}
	if(memo(i , j + 1, k ) == res){
		solve(i , j + 1 , k);return;}
	cout << s[i];
	int pos = k;
	while(pos and v[pos]!=s[i])
		pos = f[pos-1];
	pos+=(v[pos] == s[i]);
	solve(i+1 , j + 1 , pos);
}

int main(){
    migmig
    cin >> s >> t >> v;
    ms(dp , -1);
    f = kmp(v);
    if(memo() == 0)
		dokme(0);
	solve();
    return(0);
}