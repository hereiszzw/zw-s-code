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
    printf("\n��������Ҫ���ҵ�Ԫ��:\n");
    scanf("%d",&val);
    j = binarySearch(T,8,val);
    if(j == -1)
        printf("����ʧ�� \n");
    else{
    	printf("Ԫ�ص��±�Ϊ%d",j);
	}
        
    return 0;
}
/*
��������Ҫ���ҵ�Ԫ��:
13
Ԫ�ص��±�Ϊ3
*/ 
