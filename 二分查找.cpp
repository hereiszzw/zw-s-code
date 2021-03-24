#include<stdio.h>
binarySearch(int T[], int n, int key){
    int min = 0;
    int max = n - 1;
    while(min<= max){
        int mid = (min + max)/2;
        int midVal = T[mid];
        if(midVal<key)
            min = mid + 1;
        else if(midVal>key)
            max = mid - 1;
        else
            return mid;
    }
    return -1;
}
int main(){
    int val,j,T[6]={1,5,6,13,45,68};
    printf("\n请输人所要查找的元素:\n");
    scanf("%d",&val);
    j = binarySearch(T,8,val);
    if(j == -1)
        printf("查找失败 \n");
    else{
    	printf("元素的下标为%d",j);
	}
        
    return 0;
}
/*
请输人所要查找的元素:
13
元素的下标为3
*/ 
