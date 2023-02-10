#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

// Fonction qui permet de convertir les caractères avec accent/majuscule en caractère simple
char Conversion_Char(char c) {

    char caracter = tolower(c);
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
    else if (caracter == -76 || caracter == -108 || caracter == -77) {
        caracter = 111;
    }

    // u
    else if (caracter == -101 || caracter == -103 || caracter == -69 || caracter == -71 || caracter == -70) {
        caracter = 117;
    }

    // c
    else if (caracter == -121 || caracter == -89) {
        caracter = 99;
    }

    //n
    else if (caracter == -79) {
        caracter = 110;
    }

  return caracter;

}

// Fonction qui permet de compter le nombre d'occurrences de chaque lettre de l'alphabet d'un fichier texte puis l'écrit dans le fichier correspondant
int * Occurrences_Lettres(string urlFile) {

  ifstream monFlux(urlFile);
  ofstream monFluxWrite(urlFile, ios::app);
  char letter, letter2;
  int static tabOccurrences[26] = {};
  char tabLetter[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  string tabSave = "[";

  if (monFlux && monFluxWrite) {
    while (monFlux.get(letter)) {

      letter2 = Conversion_Char(letter);
      for (int i = 0; i < 26; i++) {

        if (tabLetter[i] == letter2) {

          tabOccurrences[i] += 1;
        }

      }

    }

    monFluxWrite << "Occurrences du texte à analyser : ";

    for (int i = 0; i < 26; i++) {

      tabSave += to_string(tabOccurrences[i]);
      monFluxWrite << tabLetter[i] << ":" << tabOccurrences[i] << " ; ";

      if (i == 25) {} else {
        tabSave += ",";
      }
    }

    tabSave += "]";

    cout << "" << endl;

    monFluxWrite << " " << endl;

    monFluxWrite << "Tableau d'occurrences : " << tabSave << endl;

    cout << "" << endl;

    return tabOccurrences;

  } else {

    return 0;

  }

  cout << "Une erreur s’est produite" << endl;

  cout << "Nous vous prions de nous excuser pour la gêne occasionnée" << endl;

  exit(0);

}

// Fonction qui contient les tableaux par défaut des 5 textes des fichiers langues

int * ReturnTabFiles(string urlFile) {

  if (urlFile == "francais.txt") {

    int static tab[26] = {396,47,122,165,800,50,37,35,295,27,0,249,132,330,238,122,30,304,353,280,270,67,0,19,15,0};
    return tab;

  } else if (urlFile == "allemand.txt") {

    int static tab[26] = {311,78,141,239,926,53,126,237,455,4,49,141,135,560,121,30,1,440,344,344,201,38,52,0,1,50};
    return tab;

  } else if (urlFile == "italien.txt") {

    int static tab[26] = {570,44,216,153,544,39,108,41,540,0,1,279,172,346,489,122,11,273,209,287,130,81,1,0,1,29};
    return tab;

  } else if (urlFile == "espagnol.txt") {

    int static tab[26] = {448,60,168,168,495,28,35,33,257,14,1,195,149,279,339,110,33,237,269,158,161,45,0,2,64,10};
    return tab;

  } else if (urlFile == "anglais.txt") {

    int static tab[26] = {283,43,96,102,378,62,72,127,222,5,16,154,94,259,244,54,0,198,208,267,68,36,43,4,70,1};
    return tab;

  }

  else {

    return 0;

  }

}

// Fonction qui permet de calculer l'écart
double Calcule_Ecart(int * texteTabAnalyse, string urlLangue) {

  int * tabLangue = ReturnTabFiles(urlLangue + ".txt");
  double sommeTexteAnalyser = 0;
  double sommeTabLangue = 0;
  int nbElementTabTexte = 26;
  double resultatTabLangue = 0;
  double calculTabLangue = 0;

  for (int i = 0; i < nbElementTabTexte; i++) {
    sommeTexteAnalyser += texteTabAnalyse[i];
    sommeTabLangue += tabLangue[i];
  }

  for (int i = 0; i < nbElementTabTexte; i++) {
    calculTabLangue += pow((texteTabAnalyse[i] / sommeTexteAnalyser) - (tabLangue[i] / sommeTabLangue), 2.0);
  }

  resultatTabLangue = sqrt(calculTabLangue);

  cout << "Ecart " << urlLangue << " " << fixed << setprecision(2) << resultatTabLangue << endl;
  return resultatTabLangue;
};



// Fonction qui permet de retourner la langue du texte
void Trouve_Langue(int * adresseTab, string urlFile) {

  string urlLangue[5] = {"allemand","espagnol","francais","italien","anglais"};
  double resultatLangue[5];

  for (int i = 0; i < 5; i++) {
    resultatLangue[i] = Calcule_Ecart(adresseTab, urlLangue[i]);
  };

  int positionLangue;
  double resultatPetit = resultatLangue[0];
  int i;

  for (i = 0; i < 5; i++) {
    if (resultatLangue[i] < resultatPetit) {
      resultatPetit = resultatLangue[i];
      positionLangue = i;
    }
  }

  cout << "Langue trouvée : " << urlLangue[positionLangue] << endl;
  ofstream monFluxWrite(urlFile, ios::app);

  if (monFluxWrite) {

    monFluxWrite << "Langue trouvée : " << urlLangue[positionLangue] << endl;

    monFluxWrite << urlLangue[0] << "; écart : " <<  fixed << setprecision(2) << resultatLangue[0] << endl;

    monFluxWrite << urlLangue[1] << "; écart : " <<  fixed << setprecision(2) << resultatLangue[1] << endl;

    monFluxWrite << urlLangue[2] << "; écart : " <<  fixed << setprecision(2) << resultatLangue[2] << endl;

    monFluxWrite << urlLangue[3] << "; écart : " <<  fixed << setprecision(2) << resultatLangue[3] << endl;

   monFluxWrite << urlLangue[4] << "; écart : " <<  fixed << setprecision(2) << resultatLangue[4] << endl;

  } else {

    cout << "Une erreur s’est produite" << endl;
    cout << "Nous vous prions de nous excuser pour la gêne occasionnée" << endl;
    exit(0);

  }

}


int main() {

  int choixUtilisateur;
  string nomFile;
  string cheminAcces;
  string urlFile;

  do {

    cout << "Que souhaitez-vous générer ?" << endl;
    cout << "• Les occurrences des lettres d'un texte : Option (1)" << endl;
    cout << "• Trouver la langue d'un texte: Option (2)" << endl;
    cout << "• Quitter : Option (3)" << endl;

    cin >> choixUtilisateur;
    cout << "• Choix selectionner : " << choixUtilisateur << endl;
    cout <<""<<endl;

  }

  while ((choixUtilisateur != 1) && (choixUtilisateur != 2) && (choixUtilisateur != 3) && isdigit(choixUtilisateur) != 0);

  int *adresseTab;
  if (choixUtilisateur == 1) {

    do {

      cout << "• Veuillez me renseigner le chemin d'accès du fichier !" << endl;
      cin >> cheminAcces;
      cout <<""<<endl;
      cout << "• Veuillez me renseigner le nom du fichier à générer et son extension !" << endl;
      cin >> nomFile;

    }

    while (cheminAcces.empty() == true && urlFile.empty() == true);

    urlFile = cheminAcces+nomFile;
    adresseTab = Occurrences_Lettres(urlFile);

    if (adresseTab == 0) {

      cout << "Impossible d'ouvrir le ficher !!" << endl;
      cout << "Veuillez vérifier le chemin ou accès du fichier saisie !!!" << endl;
      cout << "Vous avez saisie : "<< urlFile<< endl;

    } else {

      cout << "• Ficher généré avec succès !" << endl;

    }

  } else if (choixUtilisateur == 2) {

    do {
      cout << "• Veuillez me renseigner le chemin d'accès du ficher !" << endl;
      cin >> cheminAcces;
      cout <<""<<endl;
      cout << "• Veuillez me renseigner le nom du fichier à analyser et son extension !" << endl;
      cin >> nomFile;

    }

    while (cheminAcces.empty() == true && urlFile.empty() == true);

    urlFile = cheminAcces+nomFile;
    adresseTab = Occurrences_Lettres(urlFile);


    if (adresseTab == 0) {

      cout << "Impossible d'ouvrir le fichier !!" << endl;
      cout << "Veuillez vérifier le chemin ou accès du fichier saisie !!!" << endl;
      cout << "Vous avez saisie : "<< urlFile<< endl;

    } else {

      Trouve_Langue(adresseTab, urlFile);

    }

  } else if (choixUtilisateur == 3) {
    cout << "Au revoir" << endl;

  } else {

    cout << "Une erreur s’est produite" << endl;

    cout << "Nous vous prions de nous excuser pour la gêne occasionnée" << endl;

    exit(0);

  }

}

