#include <stdio.h>
#include <stdlib.h>

//��Ԫ��ϵ���ʵ��ж�
 
void input(int ***arr,int n);
void zifan(int **arr,int n); 		//�Է����ж�
void fanzifan(int **arr,int n);		//���Է����ж�
void duichen(int **arr,int n);		//�Գ����ж�
void fanduichen(int **arr,int n);	//���Գ����ж�
void chuandi(int **arr,int n);		//�������ж�

int main(){
	int **arr;
	int n;

	printf("����������(��)����");
	scanf("%d",&n);
	input(&arr,n);
	zifan(arr,n);
	fanzifan(arr,n);
	duichen(arr,n);
	fanduichen(arr,n);
	chuandi(arr,n);
	
	return 0;
}
void input(int ***arr,int n){
	int i,j;
	int temp;
	
	*(arr) = (int**)malloc(sizeof(int*)*n);
	for(i = 0;i < n;i++){
		(*(arr))[i] = (int*)malloc(sizeof(int)*n);
		
	}
	printf("�������ϵ����:\n");
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			scanf("%d",&temp);
			(*(arr))[i][j] = temp;
		}
	}
	
}
void zifan(int **arr,int n){
                int i;//i ��
	int temp = 0;

	for(i=0;i<n;i++){
		if(arr[i][i] == 1)
		temp++;
	}

	if(temp==n)
	printf("�˶�Ԫ��ϵ�����Է���.\n");
	else
	printf("�˶�Ԫ��ϵ�������Է���.\n");

	
} 
void fanzifan(int **arr,int n){

	int i;//i ��
	int temp = 0;

	for(i=0;i<n;i++){
		if(arr[i][i] == 0)
		temp++;
	}

	if(temp==n)
	printf("�˶�Ԫ��ϵ���з��Է���.\n");
	else
	printf("�˶�Ԫ��ϵ�����з��Է���.\n");

}

void duichen(int **arr,int n){
	int i,j;//iΪ�� ��jΪ��

	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(arr[i][j]!=arr[j][i]){
				printf("�˶�Ԫ��ϵ�����жԳ���\n");
				return;
			}

		}
	}
	printf("�˶�Ԫ��ϵ���жԳ���\n");
}

void fanduichen(int **arr,int n){

	int i,j;//iΪ�� ��jΪ��

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i][j]!=arr[j][i]){
			printf("�˶�Ԫ��ϵ���з��Գ���\n");
			return ;
			}
		}
	}
	printf("�˶�Ԫ��ϵ�����з��Գ���\n");



}

void chuandi(int **arr,int n){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(arr[i][j] == 1){
				for(int k = 0;k < n;k++){
					if(arr[j][k] == 1){
						if(arr[i][k] != 1){
							printf("�˶�Ԫ��ϵ�����д�����");
							return;
						}
					}

				}
			}

		}
	}
	printf("�˶�Ԫ��ϵ���д�����");
}
