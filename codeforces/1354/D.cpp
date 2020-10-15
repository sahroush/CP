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

struct oset{
    int maxn;
    vector < int > fen;
    oset(int n):
        maxn(n+100),
        fen(maxn){}
        
    void add(int x , int pos){
        for( ; pos < maxn ; pos += pos & -pos)
            fen[pos] += x;
    }
    int get(int pos){
        int sum = 0 ;
        for( ; pos ; pos -= pos & -pos)
            sum += fen[pos];
        return(sum);
    }
    
    void insert(int x , int cnt = 1){
        add(cnt , x);
    }
    void erase(int x , int cnt = 1){
        add(-cnt , x);
    }
    
    int find_by_order(int k){ // k-th element
        int sum = 0 , pos = 0;
        for(int i = log2(maxn) ; i >= 0 ; i --)
            if(pos + (1 << i) < maxn and sum + fen[pos + (1 << i)] < k)
                pos += (1 << i),
                sum += fen[pos];
        return(pos + 1);
    }
    int order_of_key(int key){ // number of elements <= key
        return(get(key));
    }
};


oset f(maxn);

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
            f.erase(f.find_by_order(-x));
        else
            f.insert(x);
    }
    if(f.get(maxn - 1) == 0)
        dokme(0);
    dokme(f.find_by_order(1));
    return(0);
}