#include <iostream>
#include <fstream> // lire ecrir file
#include <string>
#include <sstream>
#include <math.h>  //
#include <algorithm>





using namespace std;

char conversionChar(char s) {
    // Majuscule en minuscule
    s = tolower(s);

    //A, Â, À, Ä, â, à, ä
    if (s == 'â' || s == 'à' || s == 'ä') {
        s = 'a';
        cout << "ok";
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

    return s;

}

int* Occurrences_Lettres(string urlFile){

    //Déclaration d'un flux permettant de lire dans le fichier
    ifstream monFlux(urlFile);
    ofstream monFluxWrite(urlFile,ios::app);

    /*
    3 facons de lire un file :

    Ligne par ligne, en utilisant getline().
    Mot par mot, en utilisant les chevrons >>  .
    Caractère par caractère, en utilisant get()
    */

    char letter,letter2;
    int static tab[26] = {};
     char tabLetter[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    string tableau = "";


    if(monFlux && monFluxWrite){
        while(monFlux.get(letter)){

        letter2 = conversionChar(letter);
            for(int i =0;i < 26;i++){
                if(tabLetter[i]== letter2){
                tab[i] +=1;
               // cout << tab[i] << endl;
                }
            }
        }
        monFluxWrite << "Occurences du texte à analyser : ";
        for(int i = 0;i < 26;i++){
      //  cout << "Occurences du texte à analyser : "<< tabLetter[i]<<" " << tab[i]<< endl;

        tableau += std::to_string(tab[i]);


        monFluxWrite << tabLetter[i] << " : " << tab[i] << " " ;


        if(i == 4){}else{tableau+=",";}

        }
        tableau+="";
                monFluxWrite << " " << endl;
                monFluxWrite << "Tableau d'occurences : "<< tableau << endl;
                cout << tab << endl;
                 return tab;
    }
    else{
        cout << "Erreur Impossible d'ouvrir le ficher" << endl;
    }


};

int * recupTabFile(string urlFile){
    int static tab[26];

  ifstream monFlux(urlFile); // ouvre le file en mode lecture
   if(monFlux){

    std::string str;
    while(monFlux >> str); // recup le dernier mot

    int i =0;
    std::string word ="";
    std::istringstream isstream;
    isstream.str(str);
    while(getline(isstream, word, ',')){//split le dernier mot quand il y a une virgule
       int num = stoi(word); //convertir le nb en string en int
        tab[i] = num; // j'insere le nb de type dans le tableau
        i++;
    }
    return tab;

   }
    else{
        cout << "Erreur Impossible d'ouvrir le ficher" << endl;
    }
return 0;

}


double Calcule_ecart(int *textTabAnalyse,string urlLangue){

    int *tabLangue = recupTabFile(urlLangue+".txt");

    double sommeTextAnalyser = 0;

    double sommeTabLangue= 0;

    int nbElementTabText = 26;

    double resultatTabLangue =0;
    double  calculTabLangue =0;


    for(int i = 0;i< nbElementTabText;i++){
        sommeTextAnalyser += textTabAnalyse[i];
        sommeTabLangue += tabLangue[i];

    }


    for(int i = 0;i < nbElementTabText;i++){

    calculTabLangue += pow((textTabAnalyse[i]/sommeTextAnalyser) - (tabLangue[i]/sommeTabLangue),2.0);

    }

   resultatTabLangue = sqrt(calculTabLangue);

    cout << "Ecart " << urlLangue << " "<< resultatTabLangue<< endl;

return resultatTabLangue;





};


void prog(int *p,string urlFile)
{
    string urlLangue[5] = {"allemand","espagnol","francais","italien","anglais"};
    double resultatLangue[5];



   // p = Occurrences_Lettres(urlFile);
    for(int i = 0;i < 5;i++){
     resultatLangue[i] = Calcule_ecart(p,urlLangue[i]);
     };
   int positionLangue;

    double mini = resultatLangue[0];

    int i;

    for(i = 0; i < 5; i++)
    {
        if(resultatLangue[i] < mini)
        {
            mini =  resultatLangue[i];
            positionLangue = i;
        }
    }



   cout <<"Langue trouvée : " << urlLangue[positionLangue] << endl;
  ofstream monFluxWrite(urlFile,ios::app);
  if(monFluxWrite){

        monFluxWrite <<"Langue trouvée : " << urlLangue[positionLangue] << endl;
        monFluxWrite << urlLangue[0] <<"; écart : "  << resultatLangue[0] << endl;
        monFluxWrite << urlLangue[1] <<"; écart : "  << resultatLangue[1] << endl;
        monFluxWrite << urlLangue[2] <<"; écart : "  << resultatLangue[2] << endl;
        monFluxWrite << urlLangue[3] <<"; écart : "  << resultatLangue[3] << endl;
        monFluxWrite << urlLangue[4] <<"; écart : "  << resultatLangue[4] << endl;




   }
   else{
        cout << "Erreur Impossible d'ouvrir le ficher" << endl;
    }


}
int main()
{
    string urlFile ="test.txt";
 int *p = Occurrences_Lettres(urlFile);
 prog(p,urlFile);

   //Calcule_ecart(p);




    return 0;
}
