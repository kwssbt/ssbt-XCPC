默认 n 个点的编号为 0 ~ n-1

Kruskal

class UF{
    vector<int>fa;
    int cnt; // 连通分量数量
public:
    UF(int n):fa(n),cnt(n){
        for(int i=0;i<n;++i){
            fa[i]=i;
        }
    }
    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }
    bool merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)return 0;
        fa[a]=b;
        cnt--;
        return 1;
    }
    int count(){
        return cnt;
    }
};

从 u 指向 v ，边权为 w 的边
struct edge{
    int u,v;
    int w;
};

连通：返回最小生成树的边权和
不连通：返回 -1

int kruskal(int n,vector<edge>&Edges){
    UF st(n);
    int sum=0;
    for(auto&[u,v,w]:Edges){
        if(st.merge(u,v)){
            sum+=w;
        }
    }
    if(st.count()==1){
        return sum;
    }
    return -1;
}

Prim

连通：返回最小生成树的边权和
不连通：返回 -1

int prim(int start,int n){
    // 堆里存 { cost，u } : u -> “生成树” 的距离为 cost
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    // vis[i]=1 : 编号为 i 的点在 “生成树” 中
    vector<char>vis(n,0);
    int sum=0;
    int cnt=0;
    pq.push({0,start});
    while(pq.size()){
        auto [d,u]=pq.top();
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        sum+=d;
        cnt++;
        if(cnt==n){
            return sum;
        }
        for(int ei=head[u];ei!=-1;ei=nex[ei]){
            int v=to[ei];
            if(!vis[v]){
                pq.push({weight[ei],v});
            }
        }
    }
    return -1;
}
