/*
Cocktail Sort: Son bubble hacia arriba y hacia abajo _ Hacerlo con aritmetica de punteros

void cocktail (int * ini, int * fin)
El programa para cuando no hay swap o ini>fin
*/

#include <iostream>

void cocktail (int * ini, int * fin){
    int temp;

    while (true) {

        int verif_swap = 0;

        if (ini <= fin) { // 3 < 97
            // arriba
            for (int *p{ini}; p < fin; p++) { // 

                if (*p > *(p + 1)) { // 65 > 2
                    temp = *(p + 1);//  temp = 2 
                    *(p + 1) = *p;  // p+1 = 65
                    *p = temp;      // p = 2
                    verif_swap++;   // 1
                } 
                // p++ = 65
            }
            fin--;

            /* 
            verifica que si variable sigue 0 no pase al siguiente for 
            porque seria innecesario hacer cambios ya que la lista ya esta ordenada 
            */
            if (verif_swap == 0)
            break;

            // abajo
            for (int *p=fin ; p > ini ; p--) {

                if (*p < *(p - 1)) {
                    temp = *(p - 1);
                    *(p - 1) = *p;
                    *p = temp;
                    verif_swap++;
                }
            }
            ini++;
        }
        else break;
    }
}

int main(){
    int array [] = {3, 65, 2, 99, 12, 10, 44, 78, 95, 97};
    
    cocktail(array, array + std::size(array) - 1);

/*     std:: cout << std::size(array) << std::endl;
    std:: cout << std::size(array) -1 << std::endl;
    std:: cout << array << std::endl;
    std:: cout << array+1 << std::endl;
    std:: cout << array+2 << std::endl;
    std:: cout << array+3 << std::endl;
    std:: cout << array+4 << std::endl;
    std:: cout << array+5 << std::endl;
    std:: cout << array+6 << std::endl;
    std:: cout << array+7 << std::endl;
    std:: cout << array+8 << std::endl;
    std:: cout << array+9 << std::endl;
    std:: cout << array + std::size(array) -1 << std::endl; */


    for (int i : array){
        std::cout << i << " ";
    }
}