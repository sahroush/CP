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

string s ;
int prt[maxn] , n;
map < int , int > mp;

int main(){
    migmig
    cin >> s;
    n = s.size();
    for(int i = 0 ; i < n ; i ++)
        if(s[i] == 'a' or s[i] == 'i' or s[i] == 'u' or s[i] == 'e' or s[i] == 'o')
            prt[i+1] = -1;
        else if (s[i] == 'A' or s[i] == 'I' or s[i] == 'U' or s[i] == 'E' or s[i] == 'O')
            prt[i+1]=-1;
        else
            prt[i+1] = 2;
    int mx = 0;
    for(int i = 1 ; i <= n ; i ++){
        prt[i]+=prt[i-1];
        if(prt[i]>=0){
            mx = i;continue;}
        auto it = mp.lower_bound(-prt[i]);
        if(it!=mp.end())
            mx = max(mx , i - (*it).second);
        else
            mp[-prt[i]] = i;
    }
    if(mx == 0)dokme("No solution");
    cout << mx << ' ';
    int cnt = 0;
    for(int i = 1 ; i <= n - mx + 1; i ++)
        cnt+=((prt[i + mx - 1]-prt[i-1])>=0);
    cout << cnt;
    return(0);
}