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

vector < ll > order;
ll sum;
char ch;
ll n;
ll ans[maxn];

int main(){
    migmig
    ll cur = 1;
    cin >> ch;
    while(ch != '='){
		if(ch == '-') cur = 0;
		if(ch == '+') cur = 1;
		if(ch == '?') order.pb(cur);
		cin >> ch;
	}
	cin >> n;
	ll pos = 0 , neg = 0;
	for(ll i : order)
		if(i)
			pos++;
	neg = order.size() - pos;
	if(pos - neg * n > n) dokme("Impossible");
	if(pos * n - neg < n) dokme("Impossible");
	//cout << "Possible" << endl;
    ll cursum = n - (pos - neg);
    for(int i = 0 ; i < (int)order.size() ; i ++){
		if(order[i]){
			if(cursum > 0 ){
				//if(i)cout << "+ ";
				ans[i] = min(n , 1 + cursum) ;
				cursum -= min(n , 1 + cursum)-1;
			}
			else{
				//if(i)cout << "+ ";
				ans[i] = 1;
			}
		}
		else{
			if(cursum < 0 ){
				//cout << "- ";
				ans[i] =  min(n , 1 - cursum) ;
				cursum += min(n , 1 - cursum)-1;
			}
			else{
				//cout << "- ";
				ans[i] = 1;
			}
		}
	}
	if(cursum) dokme("Impossible");
	if(*max_element(ans , ans + (int)order.size()) > n)dokme("Impossible");
	cout << "Possible" << endl;
	for(int i = 0 ; i < order.size() ; i ++){
		if(!i){
			cout << ans[i] << ' ';
			continue;
		}
		if(order[i])cout << "+ " << ans[i] << ' ';
		if(!order[i])cout << "- " << ans[i] << ' ';
	}
    cout << "= " << n;
    return(0);
}



