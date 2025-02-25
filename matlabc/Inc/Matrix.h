#ifndef MATLABC_MATRIX_H
#define MATLABC_MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

extern int mat_num;

typedef struct mat_grop{
    float mat[20][20];
    int x;
    int y;
}mat;

typedef struct list_grop{
    float list[20];
    int x;
}list;

typedef struct determinant{
    mat mat;
    float determinant;
}determinant;

float mullist(list listx);
float sumlist(list listx);
void mat_print(mat mat_p);
list mat_daql(mat mat, int x);list mat_daqh(mat mat,int x);
list lsit_lod(float lsit[],int len);
mat mat_mul(mat mat_a,mat mat_b);
mat list_mal(list listx,int x,int y);
determinant mat_determinant(mat matx);
list array_list(float listx[]);

#ifdef __cplusplus
}
#endif
#endif //MATLABC_MATRIX_H