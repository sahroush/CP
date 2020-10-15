/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
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
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int ord[maxn];
int a[maxn];
int b[maxn];
int c[maxn];

struct BIT{
    int maxn;
    vector < int > fen;
    BIT(int n):
        maxn(n + 100),
        fen(maxn){};
    void add(int x , int pos){
        for(pos += 5 ; pos < maxn ; pos += pos & -pos)
            fen[pos] += x;
    }

    int get(int pos){
        int ans = 0;
        for(pos += 5; pos ; pos -= pos & -pos)
            ans += fen[pos];
        return(ans);
    }
};

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


int32_t main(){
    migmig
    cin >> n;
    oset st(n);
    BIT A(n) , B(n);
    for(int i = 0 ; i < n ; i  ++)  
        cin >> a[i];
    for(int i = 0 ; i < n ; i ++)
        cin >> b[i];
    for(int i = 0 ; i < n ; i ++)
        ord[n - i - 1] = a[i] - A.get(a[i]) + b[i] - B.get(b[i]),
        A.add(1 , a[i]),
        B.add(1 , b[i]),
        st.insert(i+1);
    for(int i = 0 ; i < n ; i ++ )
        ord[i+1] += ord[i]/(i+1) , ord[i] %= (i + 1);
    for(int  i = n - 1 ; i >= 0 ; i -- )
        cout << st.find_by_order(ord[i]+1)-1 << ' ',
        st.erase(st.find_by_order(ord[i]+1));
    return(0);
}