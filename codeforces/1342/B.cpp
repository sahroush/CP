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
string s;

int main(){
    migmig
    cin >> q;
    while(q -- ){
		cin >> s;
		int z = 0 , o = 0;
		for(int i = 0 ; i < s.size() ; i ++){
			if(s[i] == '0')z=1;
			if(s[i] == '1')o = 1;
		}
		if(z + o !=2){
			for(int i = 0 ; i < s.size() ; i ++ ) cout << s[i];
			cout << endl;
			continue;
		}
		for(int i = 0 ; i < s.size() * 2 ; i ++)cout << i%2;
		cout << endl;
	}
    
    
    
    return(0);
}
