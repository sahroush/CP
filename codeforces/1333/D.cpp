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

int n , k ;
string s;
vector < int > ans[maxn];
vector < int > dick;

int main(){
    migmig
    cin >> n >> k;
    cin >> s;
    for(int i = 0 ; i < n ; i  ++)
		for(int j = 1 ; j < n ; j ++)
			if(s[j - 1]=='R' and  s[j] == 'L'){
				dick.pb(j - 1);
				swap(s[j] , s[j - 1]);
				j++;
			}
	if((int)dick.size() < k)
		dokme(-1);
	int l = 0;
	for(int i = 1 ; i <= k ; i ++){
		int r = l + 1;
		while(r < (int)dick.size() and dick[r- 1] < dick[r] and k - i < (int)dick.size() - r)
			r++;
		while(r < (int)dick.size() and dick[r] < dick[l]-1 and k - i < (int)dick.size() - r)
			r++;
		for(int j = l ; j < r ; j ++){
			ans[i].pb(dick[j]);
		}
		l = r;
	}
    if(l < (int)dick.size())
		dokme(-1);
	for(int i = 1 ; i <= k ; i ++){
		cout << ans[i].size() << ' ';
		for(int j : ans[i])
			cout << j+1 << ' ';
		cout << endl;
	}
    
    
    
    return(0);
}