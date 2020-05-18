#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e7+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , l , r;
bool mark[maxn];
int ans[200];
vector < pair < pii , int > > vec;

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
		cin >> l >> r , vec.pb({{r , l } , i });
	sort(vec.begin() , vec.end());
    for(auto [seg , ind] : vec){
		while(mark[seg.second])
			seg.second++;
		ans[ind] = seg.second;
		mark[seg.second]=1;
	}
    for(int i = 0 ; i < n ; i ++)
		cout << ans[i] << ' ';
    return(0);
}