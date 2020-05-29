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

string s;
int cur = 0;

vector < string > a[2];

char get(){
	return(s[cur++]);
}

int main(){
    migmig
    cin >> s;
    s+=";$";
    string ans = "";
    bool oke = 1;
    while(1){
		char bz = get();
		if(bz == '$')
			break;
		if(bz == ',' or bz == ';'){
			if(ans.size() == 0)oke=0;
			a[oke].pb(ans);
			oke = 1;
			ans = "";
			continue;
		}
		if(!(bz>='0' and bz <='9')){
			oke = 0;
		}
		ans+=bz;
		if(ans.size() > 1 and ans[0] == '0')oke = 0;
	}
	if(a[1].size() == 0){
		cout << '-' << endl;
	}
	else{
		cout << '"';
		for(int i = 0 ; i < a[1].size() ; i ++){
			cout << a[1][i];
			if(i!=a[1].size()-1)
				cout << ',';
		}
		cout  << '"'<< endl;
	}
    if(a[0].size() == 0){
		cout << '-' << endl;
	}
	else{
		cout << '"';
		for(int i = 0 ; i < a[0].size() ; i ++){
			cout << a[0][i];
			if(i!=a[0].size()-1)
				cout << ',';
		}
		cout  << '"'<< endl;
	}
    
    return(0);
}