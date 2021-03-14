#include <iostream>
#include <vector>
//不可达距离
const int INF = 1000000;
//地图表
const int V = 6; //六个点之间
//输出点标识方便查看
char add[V] = {'A','B','C','D','E','F'};

int map[V][V] = {
                {INF,  7,  4,INF,INF,INF},
                {  7,INF,  6,  2,INF,  4},
                {  4,  6,INF,INF,  9,  8},
                {INF,  2,INF,INF,INF,  7},
                {INF,INF,  9,INF,INF,  1},
                {INF,  4,  8,  7,  1,INF}
        };


int prim(int target)
{
        int sum_distance = 0;//总和
        int index = 0;
        int dest[V] = {0}; //到每个点的最短距离
        int visit[V] = {0};//记录那些点已经被访问              
        int i = 0, j = 0; //循环变量
        int min_dist; //最小距离中间变量

        visit[target] = true;//从自己出发所以自己是已经遍历过的
//以target为起点向周边运算
        while(i < V)
        {
                dest[i] = map[target][i];//到各个点的最短距离
                ++i;
        }
        for(i = 1;i < V; ++i)
        {
            	std::cout<<add[index];
                min_dist = INF;
                for(j = 0; j < V;++j)//贪心算法,寻找每次dest中最短的
                {
                        if(!visit[j] && min_dist > dest[j])
                        {
                                min_dist = dest[j];
                                index = j; //记录是到哪一个地方最短以及最短距离
                        }
                }
				std::cout<<"----->"<<add[index]<<std::endl;
                sum_distance += min_dist;
                visit[index] = true;
                std::cout <<min_dist<< std::endl;
                for(j = 0;j < V; ++j)
                {
                        if(!visit[j] && dest[j] > map[index][j])
                        {
                                dest[j] = map[index][j];//更新dest
                        }
                }
        }

        return sum_distance;
}

int main()
{

        std::cout <<"Shortest distance: "<<prim(0)<<std::endl;

        return 0;
}
