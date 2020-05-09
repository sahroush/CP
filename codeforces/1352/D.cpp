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
int s[maxn];

int main(){
    migmig
    cin >> q;
    while(q -- ){
		int a = 0 , b = 0;
		cin >> n;
		int sum = 0;
		for(int i = 0 ; i < n ; i ++){
			cin >> s[i];
			sum+=s[i];
		}
		int p1=1 , p2 = n - 1;
		int cnt = 1;
		a+=s[0];
		bool boz = 1;
		int pa = s[0] , prb = 0;
		while(a+b<sum){
			//cout << a + b;
			if(boz){
				prb+=s[p2];
				b+=s[p2--];
				
				if(prb > pa){cnt++,boz = 0 , pa= 0;}
				else if(sum == a + b)cnt++;
				
			}
			else if(boz == 0){
				pa+=s[p1];
				a+=s[p1++];
				if(pa > prb){cnt++,boz =1 , prb = 0;}
				else if(sum == a + b)cnt++;
				
			}
			
		}
		cout << cnt << ' ' << a << ' ' << b << endl;
	}
    
    
    
    
    return(0);
}