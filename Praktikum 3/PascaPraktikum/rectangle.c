/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 5 November 2024
*/

#include <stdio.h>
#include "rectangle.h"

RECTANGLE MakeRectangle(float width, float height){
    RECTANGLE R;
    R.width = width;
    R.height = height;
    return R;
}

void readRectangle(RECTANGLE *R){
    float width, height;
    scanf("%f %f",&width,&height);
    (*R) = MakeRectangle(width,height);
}

void printRectangle(RECTANGLE R){
    printf("R(%.2fx%.2f)\n",R.width,R.height);
}

boolean isSquare(RECTANGLE R){
    return(R.width == R.height);
}

boolean isNotSquare(RECTANGLE R){
    return(R.width != R.height);
}

float area(RECTANGLE R){
    return(R.width * R.height);
}

float perimeter(RECTANGLE R){
    return(2*(R.width+R.height));
}

void swap(RECTANGLE *R){
    float temp;
    temp = (*R).width;
    (*R).width = (*R).height;
    (*R).height = temp;
}

void add(RECTANGLE *R, float deltaWidth, float deltaHeight){
    (*R).width = (*R).width + deltaWidth;
    (*R).height = (*R).height + deltaHeight;
}

RECTANGLE plusRectangle(RECTANGLE R,float deltaWidth,float deltaHeight){
    RECTANGLE newR;
    newR.width = R.width + deltaWidth;
    newR.height = R.height + deltaHeight;
    return newR;
}