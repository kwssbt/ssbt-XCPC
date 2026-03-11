// 空间复杂度 O(N+M)

const int N=1e5+5;// 结点
const int M=1e6+5;// 边

int tot;
int head[N];
int nex[M];
int to[M];
int weight[M];
// 初始化
void built(int n){
    tot=1;
    for(int i=1;i<=n;++i){
        head[i]=0;
    }
}
// 加边
void addEdge(int u,int v,int w){
    nex[tot]=head[u];
    to[tot]=v;
    weight[tot]=w;
    head[u]=tot++;
}
// 遍历
for(int ei=head[u];ei;ei=nex[ei]){
    int v=to[ei];
    int w=weight[ei];
}