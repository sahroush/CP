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

ll n , q;
char ch;

ll len(int x){
	if(!n)return(1);
	int cnt = 0;
	while(x){
		cnt++;
		x/=10;
	}
	return(cnt);
}

int main(){
    migmig
    cin >> q;
    while(q --){
		string s;
		cin >> s;
		int boz = s.size() - 4;
		int n = 0;
		int t10 = 1;
		int sum = 0;
		for(int  i = 4 ; i < s.size() ; i ++){
			sum+=t10;
			n = n *10 + (s[i] - '0');
			t10*=10;
		}
		while(n < 1988 + sum)
			n+=t10;;
		cout << n << endl;
	}
    
    
    
    
    return(0);
}



