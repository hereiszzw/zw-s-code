#include<stdio.h>
int main(){
	int i,j,n,x;
	printf("��������������Ͳ�����\n"); 
	scanf("%d %d",&n,&x); 
	int T[n];
	printf("����������Ԫ��\n");
	for(i=0;i<n;i++){
		scanf("%d",&T[i]);
	}
	for(j=0;j<n;j++){
	if(x==T[j])  {
	printf("�������±�Ϊ%d",j);
	break;}
} 
	if(j==n){
	printf("��������������"); 
}
	return 0;
}
/*
��������������Ͳ�����
6 4
����������Ԫ��
1 5 4 2 6 7
�������±�Ϊ2
*/
