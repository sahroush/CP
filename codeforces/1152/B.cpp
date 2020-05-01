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

ll x , n = 0;
vector < int > ans;

int main(){
    //migmig
    cin >> x;
    if(x == 1)dokme(0);
    int cnt = 0;
    int boz = log2(x);
		n = pw(2 , ++boz) - 1;
    while(x!=n){
		//cout << x;
		int boz = log2(x);
		n = pw(2 , ++boz) - 1;
		x^=n;
		ans.pb(boz);
		cnt++;
		boz = log2(x);
		n = pw(2 , ++boz) - 1;
		if(x == n)break;
		x++;
		cnt++;
		boz = log2(x);
		n = pw(2 , ++boz) - 1;
	}
    cout << cnt << endl;
    for(int i : ans)cout << i << ' ';
    
    
    
    return(0);
}

