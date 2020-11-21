/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
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
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
string a , b;
int k;
int cnt[40][2];


int32_t main(){
    migmig;
	cin >> q;
	while(q --){
		ms(cnt , 0);
		cin >> n >> k;
		cin >> a >> b;
		if(a == b){
			cout << "Yes" << endl;
			continue;
		}
		sort(a.begin() , a.end());
		sort(b.begin() , b.end());
		for(int i = 0 ; i < n ; i ++){
			cnt[a[i] - 'a'][0] ++;
			cnt[b[i] - 'a'][1] ++;
		}
		bool ok = 1;
		for(int i = 0 ; i < 27 ; i ++){
			while(cnt[i][0] > cnt[i][1]){
				cnt[i][0]-=k;
				cnt[i+1][0]+=k;
			}
			ok&= (cnt[i][0] == cnt[i][1]);
		}
		cout << ((ok)?"Yes" : "No") << endl;
	}
	



    return(0);
}
