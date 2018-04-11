#include "Matrix.h"
using namespace std;

void Matrix::square(int *a, int *b, int *c, int m, int n) {
        int result[m][m];
    int arr[m][n];
    int i,j;

    for(i=0;i<n;i++){
        arr[0][i]=a[i];
        arr[1][i]=b[i];
        arr[2][i]=c[i];
    }

    int k; int num=0;
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            for(k=0;k<n;k++){
                num+=arr[i][k]*arr[j][k];
            }
            result[i][j]=num;
            num=0;
        }
    }

    int i2,j2;
    for(i2=0;i2<3;i2++) {
        for (j2 = 0; j2 < 3; j2++) {
            cout << result[i2][j2] << '\t';
        }
    }
        cout<<endl;
}