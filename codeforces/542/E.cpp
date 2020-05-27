#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

const ll maxn =1e3+2;
const ld SADAT = 7.84e-17;
const ll INF = 1e18;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define all(x) x.begin() , x.end()
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}
template<typename T>
class Queue
{
private:
    int m_capacity;
    int m_size;
    int m_startIndex;
    int m_endIndex;
    T* m_buffer;
 
    void expand_queue() {
        int newCapacity = m_capacity * 2;
        T* newBuffer = new T[newCapacity];
        if (m_endIndex <= m_startIndex) {
            int cnt = 0;
            for (int i = m_startIndex; i < m_capacity; i++) {
                newBuffer[cnt++] = m_buffer[i];
            }
 
            for (int i = 0; i < m_endIndex; i++) {
                newBuffer[cnt++] = m_buffer[i];
            }
        } else {
            int cnt = 0;
            for (int i = m_startIndex; i < m_endIndex; i++) {
                newBuffer[cnt++] = m_buffer[i];
            }            
        }
 
        delete[] m_buffer;
        m_buffer = newBuffer;
        m_startIndex = 0;
        m_endIndex = m_size;
        m_capacity = newCapacity;
    }
 
    void init_queue(int capacity) {
        m_capacity = capacity;
        m_size = 0;
        m_startIndex = 0;
        m_endIndex = 0;
 
        m_buffer = new T[capacity];
    }
 
public:
    Queue() {
        init_queue(32);
    }
 
    Queue(int capacity) {
        init_queue(capacity);
    }
 
    void push(T element) {
        if (m_endIndex == m_startIndex && m_size > 0) {
            // expand queue
            expand_queue();
        }
 
        m_buffer[m_endIndex] = element;
        m_endIndex = (m_endIndex + 1) % m_capacity;
        m_size++;
    }
 
    void pop() {
        if (m_size == 0) {
            return;
        }
 
        m_startIndex = (m_startIndex + 1) % m_capacity;
        m_size--;
    }
 
    T front() {
        if (m_size == 0) {
            throw;
        }
 
        return m_buffer[m_startIndex];
    }
 
    T back() {
        if (m_size == 0) {
            throw;
        }
 
        if (m_endIndex == 0) {
            return m_buffer[m_capacity - 1];
        } else {
            return m_buffer[m_endIndex - 1];
        }
    }
	bool empty(){
		return m_size==0;
	}
    int size() {
        return m_size;
    }
};
int n , m ;
bool mark[maxn] , col[maxn];
vector < int > adj[maxn];
Queue <int> q;
vector <int> comp[maxn];
int cnt = 1;
int dist[maxn];

int bfs(int cmp){
	int mx = 0;
	for (int i =0 ; i < comp[cmp].size() ; i ++){
		ms(dist , 0 );
		ms(mark , 0 );
		int v = comp[cmp][i];
		dist[v] =0;
		q.push(v);
		mark[v] = 1;
		while(!q.empty()){
			v = q.front();
			q.pop();
			for (auto u : adj[v]){
				if(!mark[u]){
					mark[u] = 1;
					dist[u] = dist[v] + 1;
					q.push(u);
					mx = max(mx , dist[u]);	
				}
			}
		}
	}
	return(mx);
}

int main(){
    migmig
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i ++ ){
    	int v, u ;
    	cin >> v >> u;
    	adj[v].pb(u);
    	adj[u].pb(v);
	}    
	for (int i = 1 ; i <= n ; i ++){
		if(!mark[i]){
			q.push(i);
			col[i] = 1;
			mark[i] = 1;
			while(!q.empty()){
				int u = q.front();
				q.pop();
				for (auto v : adj[u]){
					if(!mark[v]){
						q.push(v);
						mark[v] = 1;
						col[v] = !col[u];
					}
				}
			}	
		}
	}
    for (int i = 1 ; i <= n ; i ++){
    	for (auto u : adj[i]){
    		if(col[u] == col[i]){
    			dokme(-1);
			}
		}
	}
	ms(mark , 0 );
	for (int i = 1 ; i <= n ; i ++){
		if(!mark[i]){
			q.push(i);
			comp[cnt].pb(i);
			mark[i] = 1;
			while(!q.empty()){
				int u = q.front();
				q.pop();
				for (auto v : adj[u]){
					if(!mark[v]){
						q.push(v);
						mark[v] = 1;
						comp[cnt].pb(v);
					}
				}
			}	
			cnt++;
		}
	}
	int ans = 0;
	for (int i = 1 ; i < cnt ; i ++){
		ans+=bfs(i);
	}
	cout << ans;
	
	
	
    return(0);
}
