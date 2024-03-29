#include <iostream> //  écrire file
#include <fstream> //lire file
#include <string>
#include <math.h>  // fonction maths (racine carré sqrt)
#include <wchar.h> // Caractère large

using namespace std;

//Fonction qui permet de convertir les caractère avec accent en caractère simple
char conversionChar(char c) {
    char caracter = c;

    // a
    if (caracter == -126 || caracter == -128 || caracter == -124 || caracter == -94 || caracter == -96 || caracter == -92) {
        caracter = 97;
    }

    // e
    else if (caracter == -119 || caracter == -120 || caracter == -118 || caracter == -117 || caracter == -87 || caracter == -88 || caracter == -86 || caracter == -85) {
        caracter = 101;
    }

    // i
    else if (caracter == -113 || caracter == -114 || caracter == -81 || caracter == -82) {
        caracter = 105;
    }

    // o
    else if (caracter == -76 || caracter == -108 ) {
        caracter = 111;
    }

    // u
    else if (caracter == -101 || caracter == -103 || caracter == -69 || caracter == -71) {
        caracter = 117;
    }

    // c
    else if (caracter == -121 || caracter == -89) {
        caracter = 99;
    }

  return caracter;

}
//Fonction qui permet de compter le nb d'occurence de chaque lettre de l'alphabet d un ficher txt puis
// l ecrit dans le ficher correspondant
int * Occurrences_Lettres(string urlFile) {
  //Déclaration d'un flux permettant de lire dans le fichier
  ifstream monFlux(urlFile); //pour lire le file
  ofstream monFluxWrite(urlFile, ios::app); //pour write avec 2 eme parametre qui signifie a la fin du ficher

  /*
  3 facons de lire un file :

  Ligne par ligne, en utilisant getline().
  Mot par mot, en utilisant les chevrons >>  .
  Caractère par caractère, en utilisant get()
  */

  char letter, letter2;


  int static tabOccurence[26] = {}; //tableau quii contiendra le nb d occurence
  char tabLetter[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  string tableau = "["; // tableau quii contiendra le nb d occurence en mode string , va nous servie pour l enregistrer dans le file

  if (monFlux && monFluxWrite) { // je verifie si l ouverture du ficher en ecriture et lecture est possible
    while (monFlux.get(letter)) { // je recupere dans le ficher caractere par caractere

      letter2 = conversionChar(letter); // je convertir tout les caracter spacial et me retourne la valeur sans accent
      for (int i = 0; i < 26; i++) {
        if (tabLetter[i] == letter2) { //des que je croisse la lettre je l enregistre dans le tab
          tabOccurence[i] += 1;
        }
      }
    }
    monFluxWrite << "Occurences du texte à analyser : ";
    for (int i = 0; i < 26; i++) {

      tableau += to_string(tabOccurence[i]); // me convertie mon tableau de int en string

      monFluxWrite << tabLetter[i] << ":" << tabOccurence[i] << " ; "; //permet d'ecricre les occurence dans le ficher txt  write << data

      // Si j arrive a l indice 25 , ne me concatene pas la virgule
      if (i == 25) {} else {
        tableau += ",";
      }

    }
    tableau += "]";
    monFluxWrite << " " << endl;
    monFluxWrite << "Tableau d'occurences : " << tableau << endl;// ecrir dans le file write << data
    return tabOccurence; // je retounre le tableu d occurence(int) au main
  } else {// si il ne peut pas lire et ecrir dans le file return 0
    return 0;
  }
  cout << "Une erreur c'est produite" << endl;
  cout << "Nous vous prions de nous excuser pour la gêne occasionnée" << endl;
  exit(0);

}

//Fonction qui contient les tableau par defaux des 5 text langue
int * recupTabFile(string urlFile) {

  if (urlFile == "francais.txt") {
    int static tab[26] = {83,15,38,78,235,8,21,8,113,6,0,135,46,95,70,48,4,79,182,66,124,32,0,8,2,0};
    return tab;
  } else if (urlFile == "allemand.txt") {
    int static tab[26] = {123,50,49,74,259,49,47,77,150,0,26,54,24,223,37,13,0,98,91,89,88,9,11,2,5,37};
    return tab;
  } else if (urlFile == "italien.txt") {
    int static tab[26] = {203,10,94,71,20513,26,17,163,4,3,108,43,123,170,54,8,128,87,102,62,26,4,5,9,17};
    return tab;
  } else if (urlFile == "espagnol.txt") {
    int static tab[26] = {43,4,16,18,53,2,5,4,27,1,0,20,8,30,35,9,2,21,30,11,19,7,1,0,1,3};
    return tab;
  } else if (urlFile == "anglais.txt") {
    int static tab[26] = {116,27,48,67,219,35,36,66,129,7,19,57,33,111,91,23,0,93,135,145,59,19,24,4,32,0};
    return tab;
  }
  else {
    return 0;
  }
}

// Permet de calculer l'ecart
double Calcule_ecart(int * textTabAnalyse, string urlLangue) {

  int * tabLangue = recupTabFile(urlLangue + ".txt"); //recup la langue du tableau par défaut qui a été généré

  double sommeTextAnalyser = 0;

  double sommeTabLangue = 0;

  int nbElementTabText = 26;

  double resultatTabLangue = 0;
  double calculTabLangue = 0;

  for (int i = 0; i < nbElementTabText; i++) {
    sommeTextAnalyser += textTabAnalyse[i]; // additionner toutes les occurences a=3 , b=6 , c=0 ça nous fera 3+6+0 du texte à analyser

    sommeTabLangue += tabLangue[i]; // additionner toutes les occurences a=3 , b=6 , c=0 ça nous fera 3+6+0 de la langue

  }

  for (int i = 0; i < nbElementTabText; i++) {

    calculTabLangue += pow((textTabAnalyse[i] / sommeTextAnalyser) - (tabLangue[i] / sommeTabLangue), 2.0); // 2.0 = au carré

  }

  resultatTabLangue = sqrt(calculTabLangue); // racine carré

  cout << "Ecart " << urlLangue << " " << resultatTabLangue << endl;

  return resultatTabLangue;

};

void Trouve_langue(int * p, string urlFile) {

  string urlLangue[5] = {"allemand","espagnol","francais","italien","anglais"};
  double resultatLangue[5]; //définit la taille du tab vide, et contiendra le stockage de tous les calculs ecart de chaque langue

  // p = Occurrences_Lettres(urlFile);
  for (int i = 0; i < 5; i++) {
    resultatLangue[i] = Calcule_ecart(p, urlLangue[i]); //return le resultat de calcul ecart par rapport a la langue de l'indice du tab

  };

  int positionLangue; //indice du tableau resultat langue

  double mini = resultatLangue[0]; // valeur plus petite est à l'indice 0

  int i;
 // ce for ci dessous me permet de recupere la plus petit valeur
  for (i = 0; i < 5; i++) {
    if (resultatLangue[i] < mini) {// si la valeur de l'indice actuelle est plus petit que l indice par defaux alors rentre dans le if
      mini = resultatLangue[i]; //save la valeur la plus petit
      positionLangue = i; // retenir l'indice du plus petit

    }

  }

  cout << "Langue trouvée : " << urlLangue[positionLangue] << endl;

  ofstream monFluxWrite(urlFile, ios::app);// (ecrit dans le fil , a la fin du ficher)
  if (monFluxWrite) {

    monFluxWrite << "Langue trouvée : " << urlLangue[positionLangue] << endl;
    monFluxWrite << urlLangue[0] << "; écart : " << resultatLangue[0] << endl;
    monFluxWrite << urlLangue[1] << "; écart : " << resultatLangue[1] << endl;
    monFluxWrite << urlLangue[2] << "; écart : " << resultatLangue[2] << endl;
    monFluxWrite << urlLangue[3] << "; écart : " << resultatLangue[3] << endl;
    monFluxWrite << urlLangue[4] << "; écart : " << resultatLangue[4] << endl;

  } else {
    cout << "Une erreur c'est produite" << endl;
    cout << "Nous vous prions de nous excuser pour la gêne occasionnée" << endl;
    exit(0);
  }

}

int main() {
  int choix; // choix selon les options 1,2,3
  string nomFile;
  string cheminAcces;
  string urlFile;

  do { //tant que c'est pas bon il va re-executer, recommence cette partie
    cout << "Que souhaitez -vous générer ?" << endl;
    cout << "• Les occurrences des lettres d'un texte : Option (1)" << endl;
    cout << "• Trouver la langue d'un texte: Option (2)" << endl;
    cout << "• Quitter : Option (3)" << endl;

    cin >> choix;
    cout << "• Choix selectionné : " << choix << endl;
  }

  while ((choix != 1) && (choix != 2) && (choix != 3) && isdigit(choix) != 0); // tant que c pas 1,2,3 on va re executer le do

   int *p;
  if (choix == 1) {


    do {
      cout << "• Veuillez me renseigne le chemin d'accès du ficher !" << endl;
      cin >> cheminAcces;
      cout << "• Veuillez me renseigne le nom du ficher à généré et son extension !" << endl;
      cin >> nomFile;
    }

    while (cheminAcces.empty() == true && urlFile.empty() == true); // empty = vide
    urlFile = cheminAcces+nomFile;

    p = Occurrences_Lettres(urlFile);
    if (p == 0) { // dans la fonction occurence_lettre, si arrive pas a ouvrir ou a écrire le fichier : return 0
      cout << "Impossible d'ouvrir le ficher !!" << endl;
      cout << "Veuillez vérifier le chemin ou accès du ficher saisie !!!" << endl;
            cout << "Vous avez saisie : "<< urlFile<< endl;

    } else {
      cout << "• Ficher généré avec succès !" << endl;
    }

  } else if (choix == 2) {



    do {
      cout << "• Veuillez me renseigne le chemin d'accès du ficher !" << endl;
      cin >> cheminAcces;
      cout << "• Veuillez me renseigner le nom du ficher à analyser et son extension !" << endl;
      cin >> nomFile;
    }

    while (cheminAcces.empty() == true && urlFile.empty() == true);

    urlFile = cheminAcces+nomFile;

      p = Occurrences_Lettres(urlFile);


    if (p == 0) {
      cout << "Impossible d'ouvrir le ficher !!" << endl;
      cout << "Veuillez vérifier le chemin ou accès du ficher saisie !!!" << endl;
      cout << "Vous avez saisie : "<< urlFile<< endl;

    } else {

      Trouve_langue(p, urlFile);
    }
  } else if (choix == 3) {
    cout << "Aurevoir :)" << endl;
  } else {
    cout << "Une erreur c'est produite" << endl;
    cout << "Nous vous prions de nous excuser pour la gêne occasionnée" << endl;
    exit(0);
  }
}
