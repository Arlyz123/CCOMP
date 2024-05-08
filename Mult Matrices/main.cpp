#include <iostream>

int MultiplicacionMatriz(int (*M)[3][3]){

    int *resultado=**(M + 2);

    for (int *ptrMatriz=**M ; ptrMatriz < **(M + 1);){

        for (int *ptrMatriz2 = **((M + 1)), (*control) [3] = *(M + 1) ; ptrMatriz2 < **(M + 2) ; ptrMatriz2++ , resultado++) {

            if (*(control+1) == ptrMatriz2 ){
                resultado-=3;
                control++;
                ptrMatriz++;
            }
            *resultado = *resultado + *ptrMatriz * *ptrMatriz2;
        }
        ptrMatriz++;
    }
    return 0;
}

int main() {
    int a[3][3][3]={{{1,2,3},{4,5,6},{7,8,9}}, {{10,11,12},{13,14,15},{16,17,18}},
                    {{0,0,0},{0,0,0},{0,0,0}}};

    MultiplicacionMatriz(a);
    std::cout << "Matriz A[3] :"<< std::endl;

    for (int j{0}; j < 3; j++){
        for (int i{0}; i < 3; i++){
        std::cout << a[2][j][i] << "\t";
        }
        std::cout << std::endl;
    }

}