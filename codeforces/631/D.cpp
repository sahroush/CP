#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

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

vector < pii > s , t;
int n , m;

void add(string x ,int st = 0){
	string num = "";
	int boz = x.size();
	int chr = x[boz-1] - 'a';
	ll r = 0;
	for(int i = 0 ; i < boz - 2 ; i ++){
		r*=10;
		r += (x[i]-'0');
	}
	if(!st){
		while(s.size() and s.back().second == chr){
			r+=s.back().first;
			s.pop_back();
		} 
		s.pb({r , chr});
	}
	else{
		while(t.size() and t.back().second == chr){
			r+=t.back().first;
			t.pop_back();
		} 
		t.pb({r , chr});
	}
}

bool chk(int i , int j){
	if(i!=0){
		return(t[i] == t[j]);
	}
	if(t[i].second!=t[j].second)return(0);
	return(t[i].first <= t[j].first);
}

bool check(int i , int j){
	if(j!= 0 and j!=t.size() - 1){
		return(s[i] == t[j]);
	}
	if(s[i].second!=t[j].second)return(0);
	return(s[i].first >= t[j].first);
}

ll kmp(){
	if(t.size() > s.size())
		return(0);
    int n = t.size();
    vector < ll > f(n + 1);
    f[0] = -1;
    for (int j = 2 ; j <= n ; j ++){
		int i = f[j-1];
        while(i!=-1 and chk(i , j-1)==0)
            i = f[i];
        f[j] = ++i;
    }
    ll ans = 0;
    int i = 0 , j = 0;
    while(i < (int)s.size()){
		while(i < (int)s.size() and j < n and check(i , j))
			i++ , j ++;
		if(j == n){
			ans++;
			j = f[j];
			while(j>1 and t[j-1]!=s[i-1]){
				j = f[j];
			}
			continue;
		}
		if(j == 0)
			i++;
		else
			j = f[j];
	}
    return(ans);
}

int main(){
    migmig
    cin >> n >> m;
    while(n -- ){
		string inp;
		cin >> inp;
		add(inp);
	}
    while(m -- ){
		string inp;
		cin >> inp;
		add(inp , 1);
	}
	ll ans = 0 ;
	if(t.size() == 1){
		for(int i = 0 ; i < (int)s.size() ; i ++){
			if(s[i].second == t[0].second and s[i].first >= t[0].first)
				ans += s[i].first - t[0].first + 1;
		}
		dokme(ans);
	}
	cout << kmp();
    return(0);
}