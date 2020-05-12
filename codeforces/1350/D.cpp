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
int k;
int a[maxn];
int kdar[maxn] , prt[maxn];
map < int , int > sum;

int main(){
    migmig
    cin >> q;
    while(q -- ){
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i];
		}
		bool oke = 0;
		for(int i = 1 ; i <= n ; i ++){
			kdar[i] = kdar[i-1]+(a[i] == k);
			prt[i] = prt[i - 1];
			if(a[i] > k){
				prt[i]++;
			}
			if(a[i] < k){
				prt[i]--;
			}
		}
		if(kdar[n] == 0){
			cout << "no" << endl;
			continue;
		}
		if(n == 1){
			cout << "yes" << endl;
			continue;
		}
		int lastbig = 0;
		for(int i = 1 ;  i <= n ; i ++){
			if(lastbig!=0 and a[i]>=k and i - lastbig <= 2){
		
				oke = 1;
				break;
			}
			if(a[i]>=k){
				lastbig = i;
			}
		}
		if(oke){
			cout << "yes" << endl;
			continue;
		}	
		cout << "no" << endl;
	}
    
    
    
    
    return(0);
}