#include <iostream>
using namespace std;


void lowercase(char (*i)[100], char (*F)[100]){
    for (char (*p)[100]=i ; p<=F ; p++){
        for (char *q=*p ; *q ; q++){
            if (*q>='A' && *q<='Z'){
                *q+=32;
            }
        }
    }


}

void upercase(char (*i)[100], char (*F)[100]){
    for (char (*p)[100]=i ; p<=F ; p++){
        for (char *q=*p ; *q ; q++){
            if (*q>='a' && *q<='z'){
                *q-=32;
            }
        }
    }
}



int main(){

    char c [3][100]={"Como Has Cambiado Pelona",
                    "Cisco de Carboneria",
                    "TE HAS VUELTO UNA NEGRA MONA"};
    lowercase(c,c+2);
    upercase(c,c+2);
    cout << *c <<endl;
    cout << *(c+1) <<endl;
    cout << *(c+2) <<endl;

}