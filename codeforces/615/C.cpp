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

vector < int > kmp(string s){
	int n = s.size();
	vector < int > f(n);
	for(int i = 1 ; i < n ; i ++){
		int j = f[i-1];
		while(j and s[i]!=s[j])
			j = f[j - 1];
		j+=(s[i] == s[j]) , f[i] = j;
	}
	return(f);
}

string s , r;
string t;
int cnt[27] , ans;
vector < int > f , fr;
vector < pii > an;

int main(){
    migmig
    cin >> s >> t;
	r = s;
	reverse(r.begin() , r.end());
	for(auto i : t)
		cnt[i-'a']=1;
	for(auto i : s)
		cnt[i-'a'] = 0;
	for(int i = 0 ; i < 27 ; i ++ )if(cnt[i])dokme(-1);
	while(t.size()){
		int m = t.size() , n = s.size();
		f = kmp(t + "&" + s);
		fr = kmp(t + "&" + r);
		int l = 0, r = 0;
		int mx = 0;
		for(int i = m+1 ; i < (int)f.size() ; i ++){
			if(f[i] > mx){
				r = i-m;
				l = i-m-f[i]+1;
				mx = f[i];
			}
			if(fr[i] > mx){
				r = i-m;
				l = i-m-fr[i]+1;
				mx = fr[i];
				l = n - (l - 1);
				r = n - (r - 1);
			}
		}
		string boz = "";
		for(int i = 0 ; i < m ; i ++)if(i >= mx)boz+=t[i];
		an.pb({l , r});
		t = boz;
		ans++;
	}
	cout << ans << endl;
	for(auto [i , j] : an)
		cout << i << ' ' << j << endl;
    return(0);
}