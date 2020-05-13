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

ll n , m;
vector < int > f , fr;
string p;
int a;

vector < int > hsh(string s){
	int n = s.size();
    vector < int > f(n);
	ll cur = 0;
    for(int i = 0; i < n ; i ++){
		cur = cur * 43LL;
		cur%=mod;
		cur+=s[i]-'a';
		f[i] = cur;
	}
    return(f);
}
vector < int > rhsh(string s){
	int n = s.size();
    vector < int > f(n);
	ll cur = 0;
	ll p = 1;
    for(int i = 0; i < n ; i ++){
		cur+=((ll(s[i]-'a') * p))%mod;
		cur%=mod;
		p*=43LL;
		p%=mod;
		f[i] = cur;
	}
    return(f);
}

int main(){
    migmig
    cin >> n >> m;
    cin >> p;
    string pr = p;
    reverse(pr.begin() , pr.end());
    f=hsh(p);
    fr = rhsh(pr);
    int len = p.size();
	int l=0 , r=0;
    for(int i = 0 ; i < m ; i ++){
		cin >> a;
		a--;
		if(!i)
			n-=len;
		else{
			if(a > r)
				n-=len;
			else if (f[r-a] == fr[r - a])
				n-= a - l;
			else 
				dokme(0);
		}
		l = a;
		r =l+len-1;
	}
		
    cout << pw(26LL , n);
    
    return(0);
}