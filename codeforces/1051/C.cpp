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

int n;
int cnt[200];
char ans[200];

int a[maxn];
int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		cnt[x]++;
		a[i] = x;
	}
	int dick = 0;
    for(int i = 0 ; i < 150 ; i ++){
		dick += (cnt[i]==1);
	}
	
    if(dick%2 == 0){
		cout << "YES" << endl;
		dick/=2;
		for(int i = 0 ; i < n ; i ++){
			if(dick == 0)cout << "A";
			else if(cnt[a[i]] == 1){
				cout << "B";
				dick--;
			}
			else 
				cout << "A";
		}
		return(0);
	}
    int boz = 0;
    for(int i = 0 ; i < 150 ; i ++){
		boz += (cnt[i]>2);
	}
    if(boz == 0)
		dokme("NO")
	cout << "YES" << endl;
	bool bz = 0;
	int p1 = 0;
	for(int i = 0 ; i < n ; i ++){
		if(cnt[a[i]] == 1 and p1 < (dick + 1 )/2){
			cout << "A";p1++;}
		else if(cnt[a[i]] == 1)
			cout << "B";
		else if(cnt[a[i]] > 2 and !bz){
			cout << "B" ;
			bz = 1;
		}
		else
			cout << "A";
	}
    return(0);
}