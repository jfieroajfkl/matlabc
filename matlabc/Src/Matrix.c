//
// Created by hanqi on 2025/1/15.
//

#include "Matrix.h"
#include "stdio.h"
list sublist(list list_a,list list_b){
    int i;
    list list_out;
    if (list_a.x<list_b.x){
        i=list_a.x;
    }else{
        i=list_b.x;
    }
    list_out.x=i;
    for(int ii=0;ii<i;ii++){
        list_out.list[ii]=list_a.list[ii]-list_b.list[ii];
    }
    return list_out;
}

list lsit_lod(float lsit[],int len){
    //printf("%f",lsit[1]);
    list out;
    out.x=len;
    for(int i=0;i<len;i++){
        out.list[i]=lsit[i];
    }
    return  out;
}


determinant mat_determinant(mat matx){
    list numl;
    determinant outdeter;
    float out;
    list Line[matx.y];
    mat out_mat;
    numl.x=matx.x;
    out_mat.x=matx.x;
    out_mat.y=matx.y;
    float num0=0;//存储变1的倍（初等变换）
    float num1=0;//与被除行的除数变量
    for(int yi=0;yi<matx.x;yi++){
        Line[yi]=mat_daql(matx,yi);
    }
    for(int yi=0;yi<matx.x;yi++) {
        num0 = Line[yi].list[yi];
        for (int i = yi; i < Line[yi].x; i++) {
            Line[yi].list[i] = Line[yi].list[i] / num0;
        }
        for (int i=yi;i<matx.y-1;i++){
            num1=Line[i+1].list[yi]/Line[yi].list[yi];
            //下面准备高斯消元2025/1/24
            for(int ii=0;ii<Line[yi].x;ii++){
                Line[yi].list[ii]=Line[yi].list[ii]*num1;
            }
            Line[i+1] = sublist(Line[i+1],Line[yi]);
            for(int ii=0;ii<Line[yi].x;ii++){
                Line[yi].list[ii]=Line[yi].list[ii]/num1;
            }
        }
        for (int i = yi; i < Line[yi].x; i++) {
            Line[yi].list[i] = Line[yi].list[i] * num0;
        }
    }//结束下面进行组合成矩阵
    for(int y=0;y<matx.y;y++){
        for(int x=0;x<matx.x;x++){
            out_mat.mat[y][x]=Line[y].list[x];
        }
    }
    //mat_print(out_mat);
    for(int i=0;i<matx.x;i++){
        numl.list[i]=out_mat.mat[i][i];
    }
    out=mullist(numl);
    outdeter.determinant=out;
    outdeter.mat=out_mat;
    return outdeter;
}


mat list_mal(list listx,int x,int y){
    mat outmat;
    int ix=0;
    int iy=0;
    for(int i=0;i<listx.x;i++){
        outmat.mat[iy][ix]=listx.list[i];
        if(ix<x){
            ix++;
        }else{
            ix=0;
            iy++;
            i--;
        }
    }
    outmat.x=x;
    outmat.y=y;
    return outmat;
}


float mullist(list listx){
    float num=1;
    for(int i=0;i<listx.x;i++){
        num=listx.list[i]*num;
    }
    return num;
}

float sumlist(list listx){
    float num=0;
    for(int i=0;i<listx.x;i++){
        num=listx.list[i]+num;
    }
    return num;
}

void mat_print(mat mat_p){ //输出矩阵

    for(int yi=0;yi<mat_p.y;yi++){
        for(int xi=0;xi<mat_p.x;xi++){
            printf("%f ",mat_p.mat[yi][xi]);
        }
        printf("\n");
    }

}

list mat_daql(mat mat, int x){ //行采集
    //float mat_lout[mat.x];
    list mat_lout;
    int i=0;
    for(int xi=0;xi<mat.x;xi++){
        mat_lout.list[xi]=mat.mat[x][xi];
        i++;
    }
    mat_lout.x=i;
    return mat_lout;
}

list mat_daqh(mat mat,int x){ //列采集
    list mat_lout;
    int i=0;
    for(int yi=0;yi<mat.y;yi++){
        mat_lout.list[yi]=mat.mat[yi][x];
        i++;
    }
    mat_lout.x=i;
    return mat_lout;
}

mat mat_mul(mat mat_a,mat mat_b){
    mat mat_out;//输出矩阵
    mat_out.x=mat_b.x;
    mat_out.y=mat_a.y;
    list sumlistnum;
    sumlistnum.x=mat_a.x;
    list mat_al;//A矩阵的行列表
    list mat_bl;//B矩阵的列列表
    for(int yi=0;yi<mat_a.y;yi++){
        for(int xi=0;xi<mat_b.x;xi++){
            mat_al= mat_daql(mat_a,yi);
            mat_bl= mat_daqh(mat_b,xi);
            for(int c=0;c<mat_al.x;c++){
                sumlistnum.list[c]=mat_al.list[c]*mat_bl.list[c];
            }
            mat_out.mat[yi][xi]=sumlist(sumlistnum);
        }
    }
    return mat_out;
}
