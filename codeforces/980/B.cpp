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

int n , k;
bool oke[4][200];

int main(){
    migmig
    cin >> n >> k;
    cout << "YES" << endl;
    if(k == 2*(n - 2)){
		oke[1][n/2] = 1;
		k--;
	}
    if(k%2){
		oke[2][n/2 ] = 1;
		k--;
	}
	for(int i = 1 ; i <= 2 ; i ++){
		for(int j = 1 ; j < n/2 ; j ++){
			if(k){
				k-=2;
				oke[i][j] = oke[i][n - j - 1] = 1;
			}
		}
	}
    for(int i = 0 ; i < 4 ; i ++){
		for(int j = 0 ; j < n ; j ++)
			cout << ((oke[i][j])?'#' : '.');
		cout << endl;
	}
    
    
    return(0);
}

