#include <iostream>
#include <algorithm>

#define maxRoad 1000
using namespace std;

const int V = 6; //六个点之间
const int Wght = 9;//连接路个数
char add[V] = {'A','B','C','D','E','F'};

struct Road
{
        int Start;
        int End;
        int Weight;
};

struct Road road[Wght] = {
{1,3,4},
{2,1,7},{2,4,2},{2,6,4},
{3,2,6},{3,5,9},{3,6,8},
{4,6,7},
{5,6,1}
};


bool comp(const Road& c1,const Road& c2)
{
        return c1.Weight < c2.Weight;
}

int find(int* Root, int val)
{
        int temp = val;
        while(Root[temp] != temp)
        {
                temp = Root[temp];
        }

        if(Root[val] != val && Root[val] != temp)
        {
                Root[val] = temp;
        }

        return Root[temp];
}

void unionRoot(int *Root,int x,int y)
{
        int temp;
        if(find(Root,x) != find(Root,y))
        {
                temp = find(Root,y);
                Root[temp] = x;;
        }

}

int main()
{
        sort(road,road+Wght,comp);


        int Root[maxRoad] = {0};
        int i, j;  //循环变量
        int sum = 0;


        for(i = 0; i <= V; ++i)
         {
                Root[i] = i;
        //      std::cout<<"  "<< road[i].Weight<<endl;
        }

        for(i = 0; i < Wght; ++i)
        {
                if(find(Root,road[i].Start) != find(Root,road[i].End))
                {
                        unionRoot(Root,road[i].Start,road[i].End);
                        sum += road[i].Weight;
                        std::cout<<"start  end  "<< road[i].Start<<"  "<<road[i].End<<endl;
                }

        }


        cout<<"Shortest path is :"<< sum <<endl;

        return 0;
}

