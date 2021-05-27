//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , a[maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	if(a[n])dokme("NO");
	int lst = -1;
	for(int i = 1 ; i <= n ; i ++)
		if(a[i])lst = i;
	if(lst == -1){
		if(n == 2)dokme("NO");
		cout << "YES" << endl;
		if(n % 2){
			for(int i = 1 ; i < n ; i ++)cout << "0->";
			dokme(0);
		}
		cout << "0->(0->0)";
		for(int i = 3 ; i < n ; i ++)cout << "->0";
		return 0;
	}
	if(lst%2 != n%2){
		cout << "YES" << endl;
		for(int i = 1 ; i < n ; i ++)cout << a[i] << "->";
		dokme(a[n]);
	}
	int sum = 0;
	for(int i = 1 ; i <= n ; i ++)sum += a[i];
	if(sum == n - 2)dokme("NO");
	cout << "YES" << endl;
	if(a[n] == 0 and a[n-1] == 0 and a[n - 2] == 0){
		for(int i = 1 ; i <= n - 3 ; i ++)
			cout << a[i] << "->";
		dokme("(0->0)->0");
	}
	while(lst > 1 and a[lst - 1] == 1)lst --;
	for(int i = 1 ; i < n ; i ++){
		if(i == lst - 1){
			cout << "(0->(";
		}
		else if(i > lst and a[i] == 0){
			lst = n+1;
			cout << "->0))->";
		}
		else if(i >= lst and a[i + 1] == 0)
			cout << a[i];
		else
			cout << a[i] << "->";
	}
	dokme(0);
	return(0);
}
