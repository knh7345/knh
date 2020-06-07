#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <wisndows.h>

#define N 20

void Read_Opinion();        //여론조사 데이터를 읽어오는 함수 
void Read_Vote();       //실제 득표 데이터를 읽어오는 함수

void Calculation_Opinion();      //여론조사 데이터를 기반으로 표준오차, 표준편차를 계산
void Calculation_Vote();     //실제 득표 데이터를 기반으로 표준오차, 표준편차를 계산


FILE *fp = NULL;
int c;      //파일에서 숫자를 읽어올 때 잠시 저장할 변수
int Opinion[N]={0, };
int Vote[N]={0, };
int Average_Opinion = 0, Average_Vote = 0;      //평균
int Standard_Deviation_Opinion = 0, Standard_Deviation_Vote = 0;        //표준편차
int Standard_error_Opinion = 0, Standard_error_Vote = 0;        //표준오차

float mun_ratio = 0, hong_ratio = 0;      //여론조사 데이터 비율
int num = 1000;      //총원

int main(){

    pirntf("이 프로그램은 여론조사 데이터를 기반으로 실제 득표 결과의 신뢰도를 분석하는 프로그램입니다");


    return 0;
}

//데이터 읽어오기 시작
void Read_Opinion(){        //여론조사 데이터를 읽어오는 함수
    
    fp =fopen("Opinion.txt", "r");        //여론조사 데이터 파일 열기

    if (fp ==NULL){       //파일을 여는데 실패하면 프로그램 종료
        printf("file open failed\n");
        printf("프로그램을 종료합니다.\n 데이터 파일이 이 프로그램과 같은 폴더에 있는지 확인하세요");
        exit(0);
    }
    else{       //파일을 여는데 성공하면 게속 진행
        printf("file opened\n");
    }
    
	for(int i = 0; i < N; i++) fscanf(fp, "%d", &Opinion[i]);       //파일의 데이터를 읽어와 앞서 만들어둔 여론조사 배열에 저장
}


void Read_Vote(){       //실제 득표 데이터를 읽어오는 함수
    
    fp =fopen("Vote.txt", "r");        //득표수 데이터 파일 열기

    if (fp ==NULL){       //파일을 여는데 실패하면 프로그램 종료
        printf("file open failed\n");
        printf("프로그램을 종료합니다.\n 데이터 파일이 이 프로그램과 같은 폴더에 있는지 확인하세요");
        exit(0);
    }
    else{       //파일을 여는데 성공하면 게속 진행
        printf("file opened\n");
    }
    
	for(int i = 0; i < N; i++) fscanf(fp, "%d", &Vote[i]);       //파일의 데이터를 읽어와 앞서 만들어둔 득표수 배열에 저장
}
//데이터 읽어오기 끝


//계산 시작
void Calculation_Opinion(){      //여론조사 데이터를 기반으로 표준오차, 표준편차를 계산
    float Standard_error = sqrt(mun_ratio * hong_ratio);      //표준편차
    float Standard_Deviation = (Standard_error/Standard_error) * sqrt(num) * 100;     //표준오차

}

void Calculation_Vote(){     //실제 득표 데이터를 기반으로 표준오차, 표준편차를 계산

}
//계산 끝








/*
할일
평균 지우기, 표준오차 변수명 통일, 파일 읽어올 때 총원 받아오기 등등

*/