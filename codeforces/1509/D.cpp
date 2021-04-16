//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
string s[3];

int common(int a){
	int cnt[2] = {0 , 0};
	for(int i = 0 ; i < 2*n ; i ++)cnt[s[a][i] == '1']++;
	return cnt[1] > cnt[0];
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> q;
	while(q--){
		cin >> n;
		for(int i = 0 ; i < 3 ; i ++)cin >> s[i];
		int a = -1 , b = -1;
		for(int i = 0 ; i < 3 ; i ++)
			for(int j = 0 ; j < 3 ; j ++)
				if(i^j)
					if(common(i) == common(j))
						a = i , b = j;
		int x = common(a);
		int p1 = 0 , p2 = 0;
		n<<=1;
		while(p1 < n or p2 < n){
			if(p1 == n)
				cout << s[b][p2] , p2++;
			else if(p2 == n)
				cout << s[a][p1] , p1++;
			else{
				if(s[a][p1] == char(x + '0') and s[b][p2] == char(x + '0')){
					cout << x;
					p1 ++ , p2 ++;
				}
				else if(s[a][p1] == s[b][p2]){
					cout << 1-x;
					p1 ++ , p2 ++;
				}
				else if(s[a][p1] != char(x + '0')){
					cout << 1-x , p1++;
				}
				else{
					cout << 1-x , p2++;
				}
			}
		} 
		cout << endl;
	}

	return(0);
}
