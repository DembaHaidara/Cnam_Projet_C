#include <iostream>
#include <fstream> // lire ecrir file
#include <string>
#include <sstream>// stream
#include <math.h>  //O
#include <algorithm>
#include <array>
#include <wchar.h>







using namespace std;

char conversionChar(wchar_t s) {
    // Majuscule en minuscule
    s = tolower(s);

    //A, Â, À, Ä, â, à, ä
    if (s == 'Ä' || s == 'à' || s == 'ä') {
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
void Securiter(string urlFile){
   //Verification du nom des ficher sinon a cause du ofstream meme si le nom di ficher est faux il va le cree puis ecrit dedans
    if(urlFile == "francais.txt"){}
    else if(urlFile == "allemand.txt"){}
    else if(urlFile == "italien.txt"){}
    else if(urlFile == "espagnol.txt"){}
    else if(urlFile == "test.txt"){}
    else{
        cout <<"URL saisie incorrecte"<< endl;
        exit(0);}
}

int* Occurrences_Lettres(string urlFile){


    //Déclaration d'un flux permettant de lire dans le fichier
    ifstream monFlux(urlFile); //pour lire le file
    ofstream monFluxWrite(urlFile,ios::app); //pour write avec 2 eme parametre qui signifie a la fin du ficher


    /*
    3 facons de lire un file :

    Ligne par ligne, en utilisant getline().
    Mot par mot, en utilisant les chevrons >>  .
    Caractère par caractère, en utilisant get()
    */

    char letter,letter2;
    wchar_t caract;
                cout << caract <<endl;


    int static tab[26] = {};//tableau quii contiendra le nb d occurence
     char tabLetter[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    string tableau = ""; // tableau quii contiendra le nb d occurence en mode string , va nous servie pour l enregistrer dans le file

    if(monFlux && monFluxWrite){// je verifie si l ouverture du ficher en ecriture et lecture est possible
        while(monFlux.get(letter)){// je recupere dans le ficher caractere par caractere
        caract = letter;
                        cout << " l "<< letter <<endl;

                        cout << "c"<< caract <<endl;
        letter2 = conversionChar(caract);// je convertir tout les caracter spacial
            for(int i =0;i < 26;i++){
                if(tabLetter[i]== letter2){ //des que je croisse la lettre je l enregistre dans le tab
                tab[i] +=1;
               // cout << tab[i] << endl;
                }
            }
        }
        monFluxWrite << "Occurences du texte à analyser : ";
        for(int i = 0;i < 26;i++){
      //  cout << "Occurences du texte à analyser : "<< tabLetter[i]<<" " << tab[i]<< endl;

        tableau += std::to_string(tab[i]);


        monFluxWrite << tabLetter[i] << " : " << tab[i] << ";" ;


        if(i == 25){}else{tableau+=",";}

        }
        tableau+="";
                monFluxWrite << " " << endl;
                monFluxWrite << "Tableau d'occurences : "<< tableau << endl;
                 return tab;
    }
    else{
        return 0;
    }
cout <<"Une erreur c'est produite"<< endl;
cout << "Nous vous prions de nous excuser pour la gêne occasionnée" << endl;
exit(0);

};
int * genereTabFileAuto(string urlFile){

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
        return 0;
    }
cout <<"Une erreur c'est produite"<< endl;
cout << "Nous vous prions de nous excuser pour la gêne occasionnée" << endl;
exit(0);

}
int * recupTabFile(string urlFile,int choix2){

    cout << urlFile << choix2 << endl;

    if(choix2 == 1){
     return genereTabFileAuto(urlFile);
    }
    else if(choix2 == 2){

            if(urlFile == "francais.txt"){
                   int tab[26] = {83,15,38,78,235,8,21,8,113,6,0,135,46,95,70,48,4,79,182,66,124,32,0,8,2,0};
                   return tab;
                    }
            else if(urlFile == "allemand.txt"){
                    int tab[26] = {123,50,49,74,259,49,47,77,150,0,26,54,24,223,37,13,0,98,91,89,88,9,11,2,5,37};
                    return tab;

                    }
            else if(urlFile == "italien.txt"){
                    int tab[26] = {203,10,94,71,20513,26,17,163,4,3,108,43,123,170,54,8,128,87,102,62,26,4,5,9,17};
                    return tab;
                    }
            else if(urlFile == "espagnol.txt"){
                     int tab[26] = {43,4,16,18,53,2,5,4,27,1,0,20,8,30,35,9,2,21,30,11,19,7,1,0,1,3};
                     return tab;
                    }
            else{
            cout <<"URL saisie incorrecte"<< endl;
            exit(0);}
            }

    else{
        cout <<"Une erreur c'est produite "<< endl;
        cout << "Nous vous prions de nous excuser pour la gêne occasionnée" << endl;
        exit(0);
    }
}


double Calcule_ecart(int *textTabAnalyse,string urlLangue,int choix2){

    int *tabLangue = recupTabFile(urlLangue+".txt",choix2);

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


void Trouve_langue(int *p,string urlFile,int choix2)
{
    string urlLangue[5] = {"allemand","espagnol","francais","italien","anglais"};
    double resultatLangue[5];



   // p = Occurrences_Lettres(urlFile);
    for(int i = 0;i < 5;i++){
     resultatLangue[i] = Calcule_ecart(p,urlLangue[i],choix2);
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
        cout <<"Une erreur c'est produite"<< endl;
        cout << "Nous vous prions de nous excuser pour la gêne occasionnée" << endl;
        exit(0);
    }


}
int main()
{

    int choix;
    string urlFile ="test.txt";



    do{
    cout <<"Que souhaitez -vous générer ?"<< endl;
    cout <<"• Les occurrences des lettres d'un texte : Option (1)"<< endl;
    cout <<"• Trouver la langue d'un texte: Option (2)"<< endl;
    cout <<"• Quitter : Option (3)"<< endl;


    cin >> choix;
    cout <<"• Choix selectionner : "<< choix << endl;



    }while( (choix != 1) && (choix != 2) & (choix != 3));



    if(choix == 1){
        string cheminAcces;
        string url;

        do{
        cout <<"• Veuillez me renseigne le chemin d'acces du ficher !"<< endl;
        cin >> cheminAcces;
        cout <<"• Veuillez me renseigne le nom du ficher à génere et son extension !"<< endl;
        cin >> urlFile;
        }while(cheminAcces.empty()==true && urlFile.empty()==true);
        Securiter(urlFile);

        int *p = Occurrences_Lettres(urlFile);
        if(p == 0){
                    cout <<"Impossible d'ouvrir le ficher !!"<< endl;
                    cout <<"Veuillez verifier le chemin ou acces du ficher saisie !!!"<< endl;
        }
        else{   cout <<"• Ficher Génere avec succes !"<< endl;}

    }
    else if(choix == 2){

        string cheminAcces;
        string url;

        do{
        cout <<"• Veuillez me renseigne le chemin d'acces du ficher !"<< endl;
        cin >> cheminAcces;
        cout <<"• Veuillez me renseigne le nom du ficher à analyser et son extension !"<< endl;
        cin >> urlFile;
        }while(cheminAcces.empty()==true && urlFile.empty()==true);

        Securiter(urlFile);


        int *p = Occurrences_Lettres(urlFile);
        if(p == 0){ cout <<"Impossible d'ouvrir le ficher !!"<< endl;
                    cout <<"Veuillez verifier le chemin ou acces du ficher saisie !!!"<< endl;}
        else{
        int choix2;
         do{
    cout <<"Que souhaitez-vous générer ?"<< endl;
    cout <<"• Genere les tableau a partir des ficher texte langue  : Option (1)"<< endl;
    cout <<"• Genere les tableau de langue par-defaut: Option (2)"<< endl;




    }while( (choix2 != 1) && (choix2 != 2));


        Trouve_langue(p,urlFile,choix2);}


    }
    else if(choix == 3){ cout <<"Aurevoir :)"<< endl;}
    else{
        cout <<"Une erreur c'est produite"<< endl;
        cout << "Nous vous prions de nous excuser pour la gêne occasionnée" << endl;
        exit(0);
        }


    return 0;
}
