#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , k;
string s;
vector< string > vec;
int cnt[27];

int main(){
    migmig
    cin >> q;
    while(q -- ){
		cin >> n >> k;
		cin >> s;
		vec.clear();
		sort(s.begin() , s.end());
		for(int i = 0 ; i < k ; i ++){
			string f = "";
			f += s[i];
			vec.pb(f);
		}
		for(int i = k ; i < n ; i ++){
			vec[i%k]+=s[i];
		}
		string ans =*max_element(vec.begin() , vec.end());
		string dick = "";
		dick+=s[0];
		for(int i=k ; i < n ; i ++){
			dick+=s[i];
		}
		string boz = "";
		boz+=s[k - 1];
		dick = max(dick , boz);
		ans = min(ans , dick);
		cout << ans <<endl;
	}
    
    
    
    return(0);
}

