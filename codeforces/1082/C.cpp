#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
ll s[maxn] , r[maxn];
vector < ll > vec[maxn];

int main(){
    migmig
    cin >> n >> m;
    for(int i =0 ;i < n ; i ++){
		cin >> s[i] >> r[i];
		vec[s[i]].pb(r[i]);
	}
    for(int i = 1 ; i <= m ; i ++){
		sort(vec[i].begin() , vec[i].end());
		reverse(vec[i].begin() , vec[i].end());
		ll sum = 0;
		for(int j = 0 ; j <(int)vec[i].size() ; j ++){
			sum += vec[i][j];
			vec[i][j] = sum;
		}
	}
	//2d prt
    for(int i = 0 ; i < (int)vec[1].size() ; i ++)
		vec[1][i] = max(vec[1][i] , 0LL);
	for(int i = 2 ; i <= m ; i ++){
			if(vec[i].size()<=vec[1].size()){
				for(int j = 0 ; j < (int)vec[i].size() ; j ++)
					vec[1][j]+=max(0LL , vec[i][j]);
				continue;
			}
			for(int j = 0 ; j < (int)vec[1].size() ; j ++)
				vec[1][j]+=max(0LL , vec[i][j]);
			for(int j = vec[1].size() ; (int)j < vec[i].size() ; j ++)
				if(vec[i][j]>0)
					vec[1].pb(vec[i][j]);
	}
    cout << *max_element(vec[1].begin() , vec[1].end());
    return(0);
}