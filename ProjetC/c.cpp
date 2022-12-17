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


    ifstream monFlux("test.txt"); //pour lire le file



    char letter,letter2;
    wchar_t caract;
                cout << caract <<endl;


 

    if(monFlux){// je verifie si l ouverture du ficher en ecriture et lecture est possible
    
        while(monFlux.get(letter)){// je recupere dans le ficher caractere par caractere
        caract = letter;
            if(letter=='Ä' || letter == 'U+E4'){cout << "ok"<< endl;}
	     else{
	     	cout << letter<< endl;
            }
        }
       }
       else{	     	cout << "erreu" << endl;}

  



    return 0;
}

