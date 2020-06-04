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
string s;

int main(){
    migmig
    cin >> n;
    int cnt[2] = { 0 , 0 };
    cin >> s;
    for(int i = 0 ; i < n ; i ++){
        cnt[s[i] - '0'] ++ ;
    }
    if(cnt[1]!=cnt[0]){
        cout << 1 << endl;
        dokme(s);
    }
    cout << 2 << endl;
    cout << s[0] << ' ';
    for(int i = 1 ; i < n ; i ++)
        cout << s[i];




    return(0);
}