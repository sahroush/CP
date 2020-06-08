#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e6+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;

struct ofen{
    int fen[maxn] , size = 0;
    ofen(int x){
        ms(fen , 0);
    }
    void insert(int x){
        size++;
        for(;x < maxn;x+=x&(-x))
            fen[x]++;
    }
    void erase(int x){
        size--;
        for(;x<maxn;x+=x&(-x))
            fen[x]--;
    }
    int val(int x){
        int pos = 0;
        int sum = 0;
        for(int i = 20 ; i>=0 ; i --){
            if(pos+(1 << i) < maxn and sum+fen[pos+(1 << i)] < x)
                pos += (1 << i), sum += fen[pos];
        }
        return(pos+1);
    }
};

ofen f(0);

int main(){
    migmig
    cin >> n >> q;
    for(int i = 0 ; i < n ; i ++){
        int x;
        cin >> x;
        f.insert(x);
    }
    for(int i = 0 ; i < q ; i ++){
        int x;
        cin >> x;
        if(x < 0)
            f.erase(f.val(-x));
        else
            f.insert(x);
    }
    if(f.size == 0)
        dokme(0);
    dokme(f.val(1));
    return(0);
}