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

int q;
string s , t , p;
int cnt[30];

int main(){
    migmig
    cin >> q;
    while(q --){
		ms(cnt , 0);
		cin >> s >> t >> p;
		for(int i = 0 ; i < s.size() ; i ++)
			cnt[s[i] - 'a']++;
		for(int i = 0 ; i < p.size() ; i ++)
			cnt[p[i] - 'a']++;
		for(int i = 0 ; i < t.size() ; i ++)
			cnt[t[i] - 'a']--;
		if(*min_element(cnt , cnt + 29) < 0){
			cout << "NO" << endl;
			continue;
		}
		int p1 = 0 , p2 = 0;
		while(1){
			if(s[p1] == t[p2]){
				p1++ , p2++;
			}
			else{
				p2++;
			}
			if(p1 == s.size() or p2 == t.size())
				break;
		}
		cout << ((p1 == s.size())?"YES" : "NO") << endl;
	}
    return(0);
}