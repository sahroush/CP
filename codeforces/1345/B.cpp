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

int q;
int n;
ll boz[maxn];

int main(){
    migmig
    boz[1] = 2;
    for(ll i = 2 ; i < 2e5 ; i ++){
		boz[i] = boz[i - 1] + 2*i + i - 1;
	} 
    int len = 1e5+100;
    cin >> q;
    while(q -- ){
		cin >> n;
		if(n == 2){
			cout << 1 << endl;
			continue;
		}
		if(n < 2){
			cout << 0 << endl;
			continue;
		}
		int cnt = 0;
		while(n >= 2){
			int x = (upper_bound(boz , boz + len , n) - boz);
			x--;
			cnt++;
			n-=boz[x];
			
		}
		cout << cnt << endl;
		
		
	}
    
    
    
    return(0);
}

