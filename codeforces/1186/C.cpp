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

string a , b;
int cnt[maxn] , ob ;

int main(){
    migmig
    cin >> a >> b;
    a = '-'+a;
    b = '-'+b;
    int n = a.size()-1;
    for(int i = 1 ; i <= n ; i ++)
		cnt[i] = cnt[i - 1] + (a[i] - '0');
	for(int i = 1 ; i < (int)b.size() ; i ++)
		ob+=b[i]-'0';
	ob%=2;
	int k = b.size()-1;
	int ans = 0;
	for(int i = k ; i <= n ; i ++)
		ans+=(ob==(cnt[i] - cnt[i-k])%2);
	cout << ans;
    
    
    
    
    return(0);
}