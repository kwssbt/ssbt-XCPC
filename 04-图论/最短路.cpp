默认 n 个点的编号为 0 ~ n-1

Floyd

const int N=105;
int dis[N][N]; // dis[u][v]： u到v的距离
const int INF=0x3f3f3f3f;
void init(int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j)dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }
}
void floyd(int n){
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            if(i==k||dis[i][k]==INF)continue;
            for(int j=0;j<n;++j){
                if(j==k||dis[k][j]==INF)continue;
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}
bool check_floyd(int n){
    floyd(n);
    for(int i=0;i<n;++i){
        if(dis[i][i]<0){
            return 1; // 有负环
        }
    }
    return 0; // 无负环
}

Dijkstra

int dis[N]; // dis[u] = 起点到 u 的最短距离
bool vis[N];// vis[u]=1 : 起点到 u 在最短距离已结算
void init(int n){
    for(int i=0;i<n;++i){
        dis[i]=INF;
        vis[i]=0;
    }
}
void dijkstra(int start){
    // 堆里存 { cost, u } :起点到 u 的距离为 cost
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    dis[start]=0;
    pq.push({0,start});
    while(pq.size()){
        auto [c,u]=pq.top();
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int ei=head[u];ei!=-1;ei=nex[ei]){
            int v=to[ei];
            int w=weight[ei];
            int nc=c+w;
            if(dis[v]>nc){
                dis[v]=nc;
                pq.push({nc,v});
            }
        }
    }
}

SPFA

int dis[N]; // dis[u] = 起点到 u 的最短距离
bool in[N]; // in[u]=1 ：点 u 在队列中
void init(int n){
    for(int i=0;i<n;++i){
        in[i]=0;
        dis[i]=INF;
    }
}
void spfa(int start){
    queue<int>q;
    dis[start]=0;
    q.push(start);
    in[start]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        in[u]=0;
        for(int ei=head[u];ei!=-1;ei=nex[ei]){
            int v=to[ei];
            int w=weight[ei];
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

检查负环

int cnt[N] // cnt[u] : 从起点到 u 的最短路上的边数
bool spfa_check(int s, int n){
    for(int i=0;i<n;++i){
        dis[i]=INF;
        in[i]=0;
        cnt[i]=0;
    }
    queue<int> q;
    q.push(s);
    in[s]=1;
    cnt[s]=0;
    dis[s]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        in[u] = 0;
        for(int ei=head[u];ei!=-1;ei=nex[ei]){
            int v=to[ei];
            int w=weight[ei];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n)return 1; // 有负环
                if(in[v]==0){
                    q.push(v);
                    in[v]=1;
                }
            }
        }
    }
    return 0; // 无负环
}
