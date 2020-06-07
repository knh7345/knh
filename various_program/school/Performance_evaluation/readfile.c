#include <stdio.h>
#define N 20

int main(){
    FILE *fp = NULL;
    int c;
    int opinion[N]={0, };

    fp =fopen("input.txt", "r");


    if (fp ==NULL){
        printf("open failed\n");
    }
    else{
        printf("file opened\n");
    }


	for(int i = 0; i < N; i++) fscanf(fp, "%d", &opinion[i]);

	for (int i = 0; i < N; i++){
		printf("%d\n", opinion[i]);
	}
	

    fclose(fp);
    return 0;
}