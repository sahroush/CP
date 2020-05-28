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

int n;
string s;
int l[maxn] , r[maxn];
vector < int > sz;

int main(){
    migmig
    cin >> n >> s;
    s = "F"+s;
    for(int i = 1 ; i <= n ; i ++){
		if(s[i] == 'G'){
			l[i] = l[i-1]+1;
		}
	}
	for(int i = n ; i ; i--){
		if(s[i] == 'G'){
			r[i] = r[i+1]+1;
		}
	}
    int cnt = 0;
    for(int i = 1 ; i <= n ; i ++){
		if(s[i] == 'G'){
			cnt++;
		}
		else{
			if(cnt)sz.pb(cnt);
			cnt = 0;
		}
	}
	if(cnt)sz.pb(cnt);
    if(sz.size() == 0)dokme(0);
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++){
		if(s[i] == 'S'){
			int val = 1;
			val += l[i-1];
			if(sz.size()==1)val--;
			val+=r[i+1];
			if(sz.size()==1)val--;
			if(sz.size()==2 and r[i+1] and l[i-1])val--;
			
			ans = max(ans , val);
		}
	}
	ans = max(ans , *max_element(sz.begin() , sz.end()));
    cout << ans;
    
    return(0);
}