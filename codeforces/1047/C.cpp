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

int n;
int a[maxn];
int ans = 0;
vector < int > vec;
int cnt[(int)(1.5*1e7)+10];
bool mark[(int)(1.5*1e7)+10];
int t[(int)(1.5*1e7)+10];

int main(){
    migmig
    cin >> n;   
    for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	sort(a , a + n);	
    int gc = a[0];
    for(int i = 0 ; i < n ; i ++)
		gc = __gcd(gc , a[i]);
    for(int i = 0 ; i < n ; i ++)
		a[i]/=gc;
	for(int i = 0 ; i < n ; i ++)
		if(a[i] == 1)
			ans++;
	if(ans == n)dokme(-1);
	for(int i = 0 ; i < n ; i ++)
		if(a[i] > 1)cnt[a[i]]++;
	for(int i = 2 ; i < (int)(1.5*1e7)+5 ; i ++)
		if(!mark[i]){
			mark[i] = 1;
			for(int j = i ; j < (int)(1.5*1e7)+5 ; j += i){
				t[i] += cnt[j];
				mark[j] = 1;
			}
		}
	cout << n - *max_element(t + 2 , t + (int)(1.5*1e7)+5);
    return(0);
}

