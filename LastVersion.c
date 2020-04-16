#include <stdio.h>
#include <stdlib.h>

//二元关系性质的判断
 
void input(int ***arr,int n);
void zifan(int **arr,int n); 		//自反性判断
void fanzifan(int **arr,int n);		//反自反性判断
void duichen(int **arr,int n);		//对称性判断
void fanduichen(int **arr,int n);	//反对称性判断
void chuandi(int **arr,int n);		//传递性判断

int main(){
	int **arr;
	int n;

	printf("请输入总行(列)数：");
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
	printf("请输入关系矩阵:\n");
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			scanf("%d",&temp);
			(*(arr))[i][j] = temp;
		}
	}
	
}
void zifan(int **arr,int n){
                int i;//i 行
	int temp = 0;

	for(i=0;i<n;i++){
		if(arr[i][i] == 1)
		temp++;
	}

	if(temp==n)
	printf("此二元关系具有自反性.\n");
	else
	printf("此二元关系不具有自反性.\n");

	
} 
void fanzifan(int **arr,int n){

	int i;//i 行
	int temp = 0;

	for(i=0;i<n;i++){
		if(arr[i][i] == 0)
		temp++;
	}

	if(temp==n)
	printf("此二元关系具有反自反性.\n");
	else
	printf("此二元关系不具有反自反性.\n");

}

void duichen(int **arr,int n){
	int i,j;//i为行 ，j为列

	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(arr[i][j]!=arr[j][i]){
				printf("此二元关系不具有对称性\n");
				return;
			}

		}
	}
	printf("此二元关系具有对称性\n");
}

void fanduichen(int **arr,int n){

	int i,j;//i为行 ，j为列

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i][j]!=arr[j][i]){
			printf("此二元关系具有反对称性\n");
			return ;
			}
		}
	}
	printf("此二元关系不具有反对称性\n");



}

void chuandi(int **arr,int n){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(arr[i][j] == 1){
				for(int k = 0;k < n;k++){
					if(arr[j][k] == 1){
						if(arr[i][k] != 1){
							printf("此二元关系不具有传递性");
							return;
						}
					}

				}
			}

		}
	}
	printf("此二元关系具有传递性");
}
