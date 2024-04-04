/**
 TP1 Numero B
 
 Auteur: Deanna Wung, IFT 1166 Hiver 2024
 
 TP1_1166_NumB_H24.cpp
 
 */


#include <iostream>
#include <iomanip>
#include <float.h>  // pour FLT_MAX (reel le plus grand)
using namespace std;

/** Cette méthode permet d'afficher le contenu  des 4 tableaux.   **/
void afficher(int age[], int nbCafe[], char sexe[], float taille[], int nbPers, const char message[]) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    
    cout << "Contenu des 4 tableaux " << message << " :\n";
    cout << "indice      age     cafe   sexe   taille  " << endl ;
    
    for(int i = 0; i < nbPers; i++)
        cout << setw(3) << i << ") " << setw(10) << age[i] << setw(8) << nbCafe[i]
        << setw(6) << sexe[i] << setw(10) << setprecision(2) << taille[i]
        << endl;
    cout << endl;
    
}

/* calculer la valeur moyenne depuis un tableau d'éléments */
template <class T>
float moyenne(T tab[], int nbElem) {
    float somme = 0.0 ;
    for(int i = 0; i < nbElem ; i++)
        somme += tab[i];
    
    return somme / nbElem ;
}

/* pour 1. compteur nb de femmes ou hommes */
int nbFemmesOuHommes(char tab[], char indiquerFOuM, int nbPers){
    int compteur = 0;
    for (int i=0; i<nbPers; i++) { // parcourir tableau
        if (tab[i] == indiquerFOuM) {
            compteur++; // si match, compter
        }
    }
    return compteur;
}

/* pour 2. A-C. compter nb personnes dont l'age/nbCafe/taille depasse x */
template <class T>
int nbPersDepassant(T tableau[], T x, int nbPers){
    int compteur = 0;
    for (int i=0; i<nbPers; i++) { // parcourir tableau
        if (tableau[i] > x) { // si depasse (strict)
            compteur++; // si match, compter
        }
    }
    return compteur;
}


/* 3. calculer la valeur minimale depuis un tableau d'éléments */
template <class T>
float valeurMinimale(T tab[], int nbElem) {
    float min = FLT_MAX;
    for(int i = 0; i < nbElem ; i++){
        if (tab[i] < min) {
            min = tab[i];
        }
    }
    return min;
}


int main() {
    int age[] = { 25, 19, 41, 37, 20, 37 },
    nbCafe[] = { 3, 4, 0, 6, 3, 2 } ;
    char sexe[] = { 'F', 'M', 'F', 'F', 'M', 'F' };
    float taille[] = { 1.72, 1.84, 1.65, 1.57, 1.93, 1.85 };
    
    int nbPers = sizeof(age) / sizeof(int);
    
    afficher(age, nbCafe, sexe, taille, nbPers, " au debut");
    
    cout << "Age moyen : " << setw(6)
    << setprecision(2) << moyenne(age, nbPers) << " an(s) " << endl ;
    cout << "Consommation moyenne de cafe : " << setw(6)
    << setprecision(2) << moyenne(nbCafe, nbPers)
    << " tasse(s) par jour" << endl ;
    
    cout << "Taille moyenne : " << setprecision(2)
    << moyenne(taille, nbPers) << " metre" << endl << endl;;
    
    
    // 1. compter et afficher le nombre de femmes, hommes
    cout << "1. compter et afficher le nombre de femmes, hommes : " << endl;
    cout << " Le nombre de femmes: " << nbFemmesOuHommes(sexe, 'F', nbPers) << endl;
    cout << " Le nombre d'hommes: " << nbFemmesOuHommes(sexe, 'M', nbPers) << endl << endl;
    
    // 2. compter et afficher le nombre de personnes
    // - dont l'age dépasse 20 ans,
    // - qui consomme plus de 2 tasses de café / jr
    // - dont la taille dépasse 1.73m
    cout << "2." << endl;
    cout << " A. " << nbPersDepassant(age, 20, nbPers) << " personnes ont plus de 20 ans (strict >)." << endl;
    cout << " B. " << nbPersDepassant(nbCafe, 2, nbPers) << " personnes boivent plus de 2 tasses de café par jour" << endl;
    cout << " C. " << nbPersDepassant(taille, 1.73F, nbPers) << " personnes font plus de 1.73m " << endl << endl;
    
    
    // 3. déterminer et afficher les valeurs :
    // - age minimal
    // - consomm. minimale de café
    // - taille plus petite
    cout << "3." << endl;
    cout << " A. age minimal : " << valeurMinimale(age, nbPers) << endl;
    cout << " B. consomm. minimale de café : " << valeurMinimale(nbCafe, nbPers) << endl;
    cout << " C. taille plus petite : " << valeurMinimale(taille, nbPers) << endl << endl;
    
    return 0;
}

/*
 Exécution :
 
 Contenu des 4 tableaux  au debut :
 indice      age     cafe   sexe   taille
   0)         25       3     F      1.72
   1)         19       4     M      1.84
   2)         41       0     F      1.65
   3)         37       6     F      1.57
   4)         20       3     M      1.93
   5)         37       2     F      1.85

 Age moyen :  29.83 an(s)
 Consommation moyenne de cafe :   3.00 tasse(s) par jour
 Taille moyenne : 1.76 metre

 1. compter et afficher le nombre de femmes, hommes :
  Le nombre de femmes: 4
  Le nombre d'hommes: 2

 2.
  A. 4 personnes ont plus de 20 ans (strict >).
  B. 4 personnes boivent plus de 2 tasses de café par jour
  C. 3 personnes font plus de 1.73m

 3.
  A. age minimal : 19.00
  B. consomm. minimale de café : 0.00
  C. taille plus petite : 1.57

 Program ended with exit code: 0
 */
