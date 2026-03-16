const int N=100005; // 点的数量
const int M=400005; // 边的数量

int tot;
int head[N];
int nex[M];
int to[M];
int weight[M];

// 初始化
void init(int n){
    tot=0;
    for(int i=0;i<n;++i){
        head[i]=-1;
    }
}
// 加有向边 u -> v,边权为 w
void addEdge(int u,int v,int w){
    nex[tot]=head[u];
    to[tot]=v;
    weight[tot]=w;
    head[u]=tot++;
}
// 遍历从 u 出发的边
for(int ei=head[u];ei!=-1;ei=nex[ei]){
    int v=to[ei];
    int w=weight[ei];
}