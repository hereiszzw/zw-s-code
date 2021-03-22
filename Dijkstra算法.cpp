#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
const int inf = 0x3f3f3f3f;

int n,m,k,idx;
int mp[110][110],dis[110],vis[110],pre[110];
map<char,int>a;
map<int,char>b;
char st,ed;

void add(int u,int v,int w) {
    mp[u][v] = min(mp[u][v],w);
}


int get(char ch) {
    if (!a[ch]) {
        a[ch] = ++idx;
        b[idx] = ch;
    }
    return a[ch]; 
}

/**
 * Dijkstra�㷨
 */
int dijkstra(int st,int ed) {
    memset(dis,inf,sizeof dis);
    for (int i=1;i<=n;i++) {
        dis[i] = mp[st][i];
        if (dis[i] != inf && i != st) {
            pre[i] = st;
        }
    }
    vis[st] = 1;
    for (int i=1;i<n;i++) {

        /**
         * Ѱ��δ����ǣ��ҵ�ǰ����Դ������ĵ�k
         */
        int mi = inf, k;
        for (int j=1;j<=idx;j++) {
            if (!vis[j] && dis[j] < mi) {
                mi = dis[j];
                k = j;
            }
        }

        /**
         * ��k����
         */
        vis[k] = 1;

        /**
         * ��k�����ڵı߽����ɳڲ���,��
         * ����Դ�㵽��ÿ��j�����̾���
         */
        for (int j=1;j<=n;j++) {
            if (dis[j] > dis[k] + mp[k][j]) {
                dis[j] = dis[k] + mp[k][j];
                pre[j] = k;
            }
        }
    }
    return dis[ed];
}

/**
 * ��ӡ���·��
 */
void getPath(int u) {
    if (get(st) == u) {
        printf("The shortest path is %c",b[u]);
        return;
    }
    getPath(pre[u]);
    printf("->%c",b[u]);
}

void run() {
	printf("�����ͱߵĸ���\n");
	scanf("%d %d",&n,&m);
    char u,v;
    int w;
    memset(mp,inf,sizeof mp);
    for (int i=1;i<=n;i++) mp[i][i] = 0;
    printf("��������ͱ�\n");
    for (int i=1;i<=m;i++) {
        scanf(" %c %c %d",&u,&v,&w);
        add(get(u),get(v),w);
    }
    scanf(" %c %c",&st,&ed);
    int res = dijkstra(get(st),get(ed));
    if (res == inf) {
        puts("No path");
        return;
    }
    printf("The shortest distance From %c To %c = %d\n",st,ed,res);
    getPath(get(ed));
}

int main() {
    run();
    return 0;
}

