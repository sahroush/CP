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

int q;
int n;
int cnt[200];

int main(){
    migmig
    cin >> q;
    while(q --){
		cin >> n;
		ms(cnt , 0);
		int cn[2] = {0 , 0 };
		for(int i = 0 ; i < n ; i ++){
			int x;
			cin >> x;
			cnt[x]++;
			cn[x%2]++;
		}
		if(cn[0]%2 == 0 and cn[1]%2 == 0){
			cout << "YES" << endl;
			continue;
		}
		bool boz = 0;
		for(int i = 0 ; i < 150 ; i ++)
			if(cnt[i] and cnt[i+1])
				boz = 1;
		if(boz){
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}
    
    
    
    
    return(0);
}