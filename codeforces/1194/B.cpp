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

int q , n , m;
string s[maxn];
int x[maxn] , y[maxn];

int main(){
    migmig
    cin >> q;
    while(q -- ){
		cin >> n >> m;
		for(int i = 0 ; i < n ; i ++)
			cin >> s[i];
		int ans = 1e9;
		for(int i= 0 ; i < n ; i ++){
			int cnt = 0;
			for(int j = 0 ; j < m ; j++ ){
				if(s[i][j] == '*')cnt++;
			}
			x[i] = cnt;
		}
		for(int i= 0 ; i < m ; i ++){
			int cnt = 0;
			for(int j = 0 ; j < n ; j++ ){
				if(s[j][i] == '*')cnt++;
			}
			y[i] = cnt;
		}
		for(int i = 0 ; i < n ; i ++){
			for(int j = 0 ; j < m ; j ++){
				int sifid = m - x[i] + n - y[j];
				if(s[i][j] == '.')sifid--;
				ans = min(ans , sifid);
			}
		}
		cout << ans << endl;
	}
    
    
    
    
    return(0);
}