#include <iostream>
#include <fstream> // lire ecrir file
#include <string>
#include <sstream>// stream
#include <math.h>  //O
#include <algorithm>
#include <array>
#include <wchar.h>







using namespace std;


int main(){


    ifstream monFlux("/media/alm/Seagate Basic/00Documents/CNAM/C/Cnam_Projet_C/ProjetC/test.txt"); //pour lire le file



    char letter,letter2;
    wchar_t caract;
                cout << caract <<endl;




    if(monFlux){// je verifie si l ouverture du ficher en ecriture et lecture est possible

        while(monFlux.get(letter)){// je recupere dans le ficher caractere par caractere
        caract = letter;
        cout << letter<< " cha"<< (char) caract << " "<< (int) letter<<endl;

            if(caract== 61 || caract == -61 || caract == 69 || caract == 101){cout << "ok"<< endl;}
	     else{
	     	cout << letter<< endl;
            }

            if ((caract >= 131 && caract <= 134) || (caract >= 142 && caract <= 143) || caract==160 || (caract >= 181 && caract <= 183) || (caract >= 198 && caract <= 199) || (caract >= -125 && caract <= -122) || (caract >= -114 && caract <= -113) || caract==-96 || (caract >= -75 && caract <= -73) || (caract >= -58 && caract <= -57)){
                        caract=97; //a
                        cout << "ok"<< endl;
                    }
                    // Transforme les accents similaires a lettre "c" en "c"
                    else if(caract==128 || caract==135 || caract==-121){
                        caract=99;
                    }
                    // Transforme les accents similaires a lettre "d" en "d"
                    else if(caract == 209 || caract==-47){
                        caract=100;
                    }
                    // Transforme les accents similaires a lettre "e" en "e"
                    else if(caract==130 || (caract >= 136 && caract <= 138) || caract==144 || (caract >= 210 && caract <= 212) || caract==-126 || (caract >= -120 && caract <= -118) || caract==-112 ||(caract >= -46 && caract <= -44)){
                        caract=101;
                        cout << "ok"<< endl;
                    }
                    else{}

        }
       }
       else{	     	cout << "erreu" << endl;}





    return 0;
}

