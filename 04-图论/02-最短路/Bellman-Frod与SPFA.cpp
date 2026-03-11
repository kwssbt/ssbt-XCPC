//Bellman-Frod，时间复杂度 O(NM)

const int N=10005;
const int INF=0x3f3f3f3f;
// 边
struct e{
    int v,w;
};
vector<e>gra[N];
int dis[N];
 
void init(int n){
    for(int i=1;i<=n;++i){
        gra[i].clear();
        dis[i]=INF;
    }
}
void bellman_frod(int s,int n){
    dis[s]=0;
    for(int _=1;_<n;++_){//松弛 n-1 次
        for(int u=1;u<=n;++u){
            if(dis[u]==INF)continue;
            for(auto [v,w]:gra[u]){
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                }
            }
        }
    }
}

//SPFA，时间复杂度 O(NM) ，常数优化效果明显

const int N=10005;
const int INF=0x3f3f3f3f;
// 边
struct e{
    int v,w;
};
vector<e>gra[N];
int dis[N];
bool in[N]; // in[u]=1：结点 u 在队列中
 
void init(int n){
    for(int i=1;i<=n;++i){
        gra[i].clear();
        in[i]=0;
        dis[i]=INF;
    }
}
void spfa(int s){
    queue<int>q;
    dis[s]=0;
    q.push(s);
    in[s]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        in[u]=0;
        for(auto [v,w]:gra[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(in[v]==0){
                    q.push(v);
                    in[v]=1;
                }
            }
        }
    }
}

//检查负环

//记录每个节点的松弛次数
int cnt[N];
//有负环返回 1  
bool spfa(int s,int n){
    queue<int>q;
    q.push(s);
    in[s]=1;
    cnt[s]=1;
    dis[s]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        in[u]=0;
        for(auto [w,v]:gra[u]){
            if(dis[v]>dis[u]+w){
                if(cnt[v]==n)return 1;
                cnt[v]++;
                dis[v]=dis[u]+w;
                if(!in[v]){
                    q.push(v);
                    in[v]=1;
                }
            }
        }
    }
    return 0;
}