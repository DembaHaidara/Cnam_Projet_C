
    //Déclaration d'un flux permettant d'écrire dans le fichier
    ofstream monFlux("fileTest.txt",ios::app);
    //                url         ,ecrit a la fin du file
    
    if(monFlux){
     monFlux << "Bonjour, je suis une phrase écrite dans un fichier." << endl;
        monFlux << 42.1337 << endl;
        int age(36);
        monFlux << "J'ai " << age << " ans." << endl;
    }
    else{
        cout << "Erreur Impossible d'ouvrir le ficher" << endl;
    }

