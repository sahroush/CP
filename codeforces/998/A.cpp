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
int a[20];

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++ )cin >> a[i];
    for(int i = 1 ; i < 1 << n ; i ++)
		{
			int su = 0 , sd = 0;
			for(int j = 0 ;j < n; j ++)
				{
					if(i & (1 << j))su+=a[j];
					else sd += a[j];
				}
			if(su!=sd and su > 0 and sd > 0){
				cout << __builtin_popcount(i) << endl;
				for(int j = 0 ;j < n; j ++)
				{
					if(i & (1 << j))cout << j+  1;
				}
				return(0);
			}
			
		}
    cout << -1;
    
    
    
    return(0);
}

