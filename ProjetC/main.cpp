#include <iostream>
#include <fstream>

using namespace std;

char conversionChar(char s) {
    // Majuscule en minuscule
    s = tolower(s);

    //A, Â, À, Ä, â, à, ä
    if (s == 'â' || s == 'à' || s == 'ä') {
        s = 'a';
    }
    //É, È, Ê, Ë, é, è, ê, ë
    if (s == 'é' || s == 'è' || s == 'ê' || s == 'ë') {
        s = 'e';
    }

    //Ï, Î, ï, î
    if (s == 'ï' || s == 'î' ) {
        s == 'i';
    }

    //Ô, ô
    if (s == 'ô') {
        s == 'o';
    }

    //Û, Ù, û, ù
    if (s == 'û' || s == 'ù') {
        s == 'u';
    }

    //Ç, ç
    if (s == 'ç') {
        s == 'c';
    }

    cout<<s<<endl;
    return s;

}

void Occurrences_Lettres(){
    cout << "Hello world!" << endl;

    //Déclaration d'un flux permettant de lire dans le fichier
    ifstream monFlux("fileTest.txt");
    ofstream monFluxWrite("fileTest.txt",ios::app);

    /*
    3 facons de lire un file :

    Ligne par ligne, en utilisant getline().
    Mot par mot, en utilisant les chevrons >>  .
    Caractère par caractère, en utilisant get()
    */

    char letter,letter2;
    int tab[5] = {0,0,0,0,0};
     char tabLetter[5] ={'a','b','c','d','e'};
    int a =0;


    if(monFlux && monFluxWrite){
        while(monFlux.get(letter)){
                if(letter=='â'){cout << "ok"<< endl;}

        letter2 = conversionChar(letter);
            for(int i =0;i <5;i++){
                if(tabLetter[i]== letter2){

                tab[i] +=1;

                cout << "rentre"<< endl;
                cout << letter<< endl;
                }
            }
        }

        for(int i = 0;i < 5;i++){
        cout << "Occurences du texte à analyser : "<< tabLetter[i]<<" " << tab[i]<< endl;

        monFluxWrite << "Occurences du texte à analyser : "<< tabLetter[i]<<" "<< tab[i]<< endl;

        }
                cout << "Tableau d'occurences : "<< tab;
                monFluxWrite << "Tableau d'occurences : "<< tab;
    }
    else{
        cout << "Erreur Impossible d'ouvrir le ficher" << endl;
    }




}
int main()
{


    return 0;
}
