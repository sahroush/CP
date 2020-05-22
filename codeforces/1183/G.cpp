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
#define heap priority_queue
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q , n;
int f[maxn] , a[maxn];
heap < pii > h;

int main(){
    migmig
    cin >> q;
    while(q --){
		cin >> n;
		for(int i = 0 ; i < n ;i ++)
			cin >> a[i] >> f[i];
		vector < int > cnt(n+1 , 0) , want(n+1 , 0);
		for(int i = 0 ; i < n ;i ++)
			cnt[a[i]]++;
		for(int i = 0 ; i < n ;i ++)
			if(f[i])want[a[i]]++;
		for(int i = 0 ; i <= n ; i ++)
			if(cnt[i])
				h.push({cnt[i], want[i]});
		int mx = 0 , f1 = 0 , cur = n+1;
		while(!h.empty()){
			auto [f , s] = h.top();
			h.pop();
			if(f < cur){
				mx+=f;
				f1+=s;
				cur=f;
			}
			else{
				if(f > 1){
					h.push({f-1 , min(f - 1 , s)});
				}
			}
		}
		cout << mx << ' ' << f1 << endl;
	}
    
    
    
    
    return(0);
}