#include<stdio.h> 
    int main()
    {
    int e[10][10],k,i,j,n,m,t1,t2,t3;
    int inf=1e6; //用inf(infinity的缩写)存储一个我们认为的正无穷值
    //读入n和m，n表示顶点个数，m表示边的条数
    printf("输入点的个数和边的个数\n");
        scanf("%d %d",&n,&m);
    //初始化
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(i==j) e[i][j]=0;
    else e[i][j]=inf;
    //读入边
    printf("输入两点及两点间的距离\n");
    for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&t1,&t2,&t3);
            e[t1][t2]=t3;
        }
    //Floyd-Warshall算法核心语句
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(e[i][j]>e[i][k]+e[k][j] )
                        e[i][j]=e[i][k]+e[k][j];
    //输出最终的结果
    printf("the distance matrix is:");
    for(i=1;i<=n;i++)
        {
    for(j=1;j<=n;j++)
            {
                printf("%10d",e[i][j]);
            }
            printf("\n");
        }
    return 0;
    }
/*
4 8
4 1 5
1 4 4
4 3 12
3 4 1
3 1 7
1 3 6
1 2 2
2 3 3
*/
