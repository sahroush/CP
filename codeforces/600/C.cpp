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

int cnt[27];
string s;
vector < int > vec;

int main(){
    migmig
    cin >> s;
    for(auto i : s){
		cnt[i - 'a']++;
	}
    for(int i = 0 ; i < 26 ; i ++){
		if(cnt[i]%2)vec.pb(i);
	}
	for(int i = 0 ; i < (int)vec.size()/2 ; i ++){
		cnt[vec[i]]++;
		cnt[vec[(int)vec.size() - i - 1]]--;
	}
	int cur = 0;
	for(int i = 0 ; i < 26 ; i ++){
		for(int j = 0 ; j < cnt[i]/2 ; j ++ ){
			s[cur] = char('a' + i);
			s[int(s.size()) - cur - 1]= char('a' + i);
			cur++;
		}
		cnt[i]%=2;
		if(cnt[i])
			s[(int)s.size()/2]=char('a' + i);
	}
    cout << s ;
    return(0);
}