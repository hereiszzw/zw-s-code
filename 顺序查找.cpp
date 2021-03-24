#include<stdio.h>
int main(){
	int i,j,n,x;
	printf("请输入数组个数和查找数\n"); 
	scanf("%d %d",&n,&x); 
	int T[n];
	printf("请输入数组元素\n");
	for(i=0;i<n;i++){
		scanf("%d",&T[i]);
	}
	for(j=0;j<n;j++){
	if(x==T[j])  {
	printf("该数的下标为%d",j);
	break;}
} 
	if(j==n){
	printf("该数不在数组中"); 
}
	return 0;
}
/*
请输入数组个数和查找数
6 4
请输入数组元素
1 5 4 2 6 7
该数的下标为2
*/
