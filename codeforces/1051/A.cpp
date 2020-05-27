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
string s;

int main(){
    migmig
    cin >> q;
    while(q -- ){
		cin >> s;
		int n = s.size();
		int low = 0 , up = 0 , dig = 0;
		for(int i = 0 ; i < n ; i ++){
			if(s[i]<='9' and s[i]>='0')
				dig ++;
			if(s[i]<='z' and s[i]>='a')
				low++;
			if(s[i]<='Z' and s[i]>='A')
				up++;
		}
		if(low and up and dig){
			cout << s << endl;
			continue;
		}
		//cout << low << ' ' << up << ' ' << dig << endl;
		for(int i = 0 ; i < n ; i ++){
			if(s[i]<='9' and s[i]>='0' and dig > 1){
				//dig ++;
				int boz = 0;
				if(low == 0){
					s[i] = 'a';
					boz++;
				}
				if(up == 0){
					s[i+boz] = 'A';
				}
				break;
			}
			if(s[i]<='z' and s[i]>='a' and low > 1){
				int boz = 0;
				if(dig == 0){
					s[i] = '0';
					boz++;
				}
				if(up == 0){
					s[i+boz] = 'A';
				}
				break;
			}
			if(s[i]<='Z' and s[i]>='A' and up > 1){
				int boz = 0;
				if(low == 0){
					s[i] = 'a';
					boz++;
				}
				if(dig == 0){
					s[i+boz] = '0';
				}
				break;
			}
			
		}
		cout << s << endl;
	}
    
    
    
    
    return(0);
}