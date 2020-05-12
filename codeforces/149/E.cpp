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

string s , t;
string sr;
vector < int > f1 , f2;
int n , m;
int ans = 0;

vector < int > kmp(string s){
    int i = -1 ;
    vector < int > f(s.size() + 1);
    f[0] = -1;
    for (int j = 0 ; j < (int)s.size() ; j ++){
        while(s[j]!=s[i] and i!=-1){
            i = f[i];
        }
        f[j + 1] = ++i;
    }
    return(f);
}

int main(){
    migmig
    cin >> s;
    n = s.size();
    cin >> m;
    sr = s;
    reverse(sr.begin() , sr.end());
    for(int i = 0 ; i < m ; i ++){
		cin >> t;
		f1 = kmp(t + "$%#" + s);
		reverse(t.begin() , t.end());
		f2 = kmp(t + "$%#" + sr);
		reverse(f2.begin() , f2.end());
		if(t.size()==1)continue;
		int mx = 0;
		int boz = t.size() + 4;
		for(int i = 0 ; i < n ; i ++){
			if(f2[i] + mx >= t.size()){
				ans++;
				break;
			}
			mx = max(mx , f1[boz++]);
		}
	}
	cout << ans;
    return(0);
}