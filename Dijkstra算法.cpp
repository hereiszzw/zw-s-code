#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
const int inf = 1e6;
map<char,int>a;
map<int,char>b;
int n,m,k,h;
int f[110][110],d[110],visit[110],p[110];
char s,l;

void add(int u,int v,int w) {
    f[u][v] = min(f[u][v],w);
}

int g(char t) {
    if (!a[t]) {
        a[t] = ++h;
        b[h] = t;
    }
    return a[t]; 
}
  //Dijkstra算法// 
int dijkstra(int st,int ed) {
    memset(d,inf,sizeof d);
    for (int i=1;i<=n;i++) {
        d[i] = f[st][i];
        if (d[i] != inf && i != st) {
            p[i] = st;
        }
    }
    visit[st] = 1;
    for (int i=1;i<n;i++) {

    //寻找未被标记，且当前距离源点最近的点k    
        int min = inf, k;
        for (int j=1;j<=h;j++) {
            if (!visit[j] && d[j] < min) {
                min = d[j];
                k = j;
            }
        }
        //将k点标记 
        visit[k] = 1;

        //更新源点到达每个j点的最短距离
        for (int j=1;j<=n;j++) {
            if (d[j] > d[k] + f[k][j]) {
                d[j] = d[k] + f[k][j];
                p[j] = k;
            }
        }
    }
    return d[ed];
}
//打印 
void Path(int u) {
    if (g(s) == u) {
        printf("最短距离 %c",b[u]);
        return;
    }
    Path(p[u]);
    printf("->%c",b[u]);
}

int main() {
    cout<<"请输入点和边的个数"<<endl;
	cin>>n>>m;
    char u,v;
    int w;
    memset(f,inf,sizeof f);
    for (int i=1;i<=n;i++) f[i][i] = 0;
    printf("输入两点和边\n");
    for (int i=1;i<=m;i++) {
        scanf(" %c %c %d",&u,&v,&w);
        add(g(u),g(v),w);
    }
    scanf(" %c %c",&s,&l);
    int res = dijkstra(g(s),g(l));
    if (res == inf) {
        puts("No path");
        return 0;
    }
    printf("从 %c 到 %c 的最短距离= %d\n",s,l,res);
    Path(g(l));
    return 0;
}
/*8 11
a b 1
b d 2
c a 2
d c 1
e d 2
d f 8
f e 2
e g 2
g f 3
h f 2
g h 3
a h*/
