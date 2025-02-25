#include <stdio.h>
#include "Matrix.h"
list l;

mat dingyi(){
    float i=0;
    int x1,y1=0;
    mat c;
    c.x=3;
    c.y=2;
    for(y1=0;y1<c.y;y1++){
        for(x1=0;x1<c.x;x1++){
            i++;
            c.mat[y1][x1]=i;
        }
    }
    return c;
}

mat dingyi2(){
    float i=0;
    int x1,y1=0;
    mat c;
    c.x=2;
    c.y=3;
    for(y1=0;y1<c.y;y1++){
        for(x1=0;x1<c.x;x1++){
            i++;
            c.mat[y1][x1]=i;
        }
    }
    return c;
}



int main(void) {
    determinant hls;
    int x1,y1=0;
    mat matb;
    mat a =dingyi();
    mat b =dingyi2();
    printf("a\n");
    mat_print(a);
    printf("\n");
    printf("b\n");
    mat_print(b);
    l= mat_daql(a,0);
    printf("\n");
    //printf("\n%f\n%f\n%f %d ",l.list[0],l.list[1],l.list[2],l.x);

    matb=mat_mul(b,a);
    printf("b*a\n");
    mat_print(matb);
    printf("\n");
    printf("a*a\n");
    matb=mat_mul(a,a);
    mat_print(matb);

    mat matni;
    printf("\n");
    float ni[16]={4,5,6,4,2,1,56,6,8,0,98,7,2,5,8,9};
    matni=list_mal(lsit_lod(ni,16),4,4);
    mat_print(matni);
    printf("\n");
    hls=mat_determinant(matni);
    printf("determinant_mat\n");
    mat_print(hls.mat);

    printf("determinant%f\n",hls.determinant);
}
