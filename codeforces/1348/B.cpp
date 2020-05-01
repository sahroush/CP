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

int a[maxn];
int n , k;
int q;
set < int > st;
vector < int > ans;
queue < int > qu;

int main(){
    migmig
    cin >> q;
    while(q -- ){
		cin >> n >> k;
		st.clear();
		for(int i = 0 ; i < n ; i ++){
			cin >> a[i];
			st.insert(a[i]);
		}
		if((int)st.size() > k){
			cout << -1 << endl;
			continue;
		}
		ans.clear();
		while(qu.size())qu.pop();
		for(int i  : st)
			qu.push(i);
		while(qu.size()!=k)
			qu.push(*st.begin());
		int cur = 0;
		int x = qu.size();
		for(int i = 0 ; i < n ; i ++)
			for(int j = 0 ; j < x ; j ++)
				{
					ans.pb(qu.front());
					qu.pop();
					qu.push(ans.back());
				}
		cout << ans.size() << endl;
		for(int i : ans )
			cout << i << ' ';
		cout << endl;
	}
    
    
    
    
    return(0);
}

