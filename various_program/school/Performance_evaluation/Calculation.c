#include <stdio.h>
#include <math.h>

int main(){
    int num = 1000;      //총원
    float mun_ratio = 0.24, hong_ratio = 0.76;      //여론조사 데이터 비율
    float Standard_error = sqrt(mun_ratio * hong_ratio);      //표준편차
    float Standard_Deviation = (Standard_error/Standard_error) * sqrt(num) * 100;     //표준오차
}