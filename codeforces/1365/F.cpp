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
int a[maxn];
int b[maxn];
int q;
map < int , int > cnt;

int main(){
    migmig
    cin >> q;
    while(q --){
        cin >> n;
        cnt.clear();
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i];
        for(int i = 0 ; i < n ; i ++)
            cin >> b[i];
        if(n%2)
            if(a[n/2]!=b[n/2]){
                cout << "No" << endl;
                continue;
            }
        for(int i = 0 ; i < n ; i ++)
            cnt[a[i]]++;
        for(int i = 0 ; i < n ; i ++)
            cnt[b[i]]--;
        int ok = 1;
        for(auto [f , s] : cnt)
            if(s!=0)ok=0;
        if(ok==0){
            cout << "No" << endl;
            continue;
        }
        vector < pii > v1 , v2;
        v1.clear();
        v2.clear();
        for(int i = 0 ; i < n/2 ; i ++){
            v1.pb({min(a[i] , a[n - i - 1]) , max(a[i] , a[n - i - 1])});
            v2.pb({min(b[i] , b[n - i - 1]) , max(b[i] , b[n - i - 1])});
        }
        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());
        for(int i = 0 ; i < n/2 ; i ++)
            if(v1[i]!=v2[i])
               ok = 0;
        if(ok==0){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return(0);
}