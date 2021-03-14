#include <iostream>
#include <vector>
//���ɴ����
const int INF = 1000000;
//��ͼ��
const int V = 6; //������֮��
//������ʶ����鿴
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
        int sum_distance = 0;//�ܺ�
        int index = 0;
        int dest[V] = {0}; //��ÿ�������̾���
        int visit[V] = {0};//��¼��Щ���Ѿ�������              
        int i = 0, j = 0; //ѭ������
        int min_dist; //��С�����м����

        visit[target] = true;//���Լ����������Լ����Ѿ���������
//��targetΪ������ܱ�����
        while(i < V)
        {
                dest[i] = map[target][i];//�����������̾���
                ++i;
        }
        for(i = 1;i < V; ++i)
        {
            	std::cout<<add[index];
                min_dist = INF;
                for(j = 0; j < V;++j)//̰���㷨,Ѱ��ÿ��dest����̵�
                {
                        if(!visit[j] && min_dist > dest[j])
                        {
                                min_dist = dest[j];
                                index = j; //��¼�ǵ���һ���ط�����Լ���̾���
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
                                dest[j] = map[index][j];//����dest
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
