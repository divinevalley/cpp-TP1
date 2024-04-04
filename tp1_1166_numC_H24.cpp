/* Fichier tp1_1166_numC_H24.cpp pour le numéro C du Tp1 IFT 1166
 
 Auteur: Deanna Wung
 IFT 1166, H 2024
 TP1. C.
 
 Numéro C du TP1 : 10 points
 
 Ajouter des fonctions et leurs appels afin de :
 1. afficher le contenu de ces 4 tableaux avant le tri;
 2. rechercher et afficher les résultats de la
 recherche des personnes ayant de numéros suivants :
 2233, 4177, 9876
 par la recherche séquentielle dans le tableau
 des numéros non triés
 
 3. déterminer et afficher toutes les informations
 a) d'une personne ayant la taille la plus grande
 b) d'une personne ayant le poids le plus lourd
 
 4. calculer et afficher
 a) la taille moyenne des femmes
 b) le poids moyen des hommes
 
 5. trier (avec le tri par sélection) les personnes selon leurs
 numéros et afficher le contenu de ces 4 tableaux
 aprés le tri;
 
 6. rechercher et afficher les résultats de la
 recherche des personnes ayant de numéros suivants :
 2233, 4177, 9876
 par la recherche séquentielle dans le tableau des numéros triés
 
 
 Critères de correction :
 6 x 1 point pour le bon fonctionnement
 4 points pour la qualité du code
 
 Total de 10 points
 */

#include <iostream>  // pour entrée-sortie  cin, cout
#include <iomanip>   // pour le formatage
#include <fstream>   // pour les fichiers
#include <float.h>  // pour FLT_MAX


using namespace std; // librairie standard

/* cette fonction est expliquée en classe :
 Elle permet de lire le fichier a partir de son nom,
 de remplir les 4 tableaux et de transmettre via
 pointeur le nombre de personnes lues.
 */
void lireRemplir(const char nomALire[], int numero[], char sexe[],
                 float taille[], float poids[], int * p)
{
    const float PIED_EN_METRE = 0.3048,
    LIVRE_EN_KG = 0.454;
    int nbPieds, nbPouces, nbLivres;
    
    ifstream  aLire (nomALire, ios::in); // localiser et ouvrir pour la lecture
    
    int n = 0; // initialiser le compteur
    
    while (aLire >> sexe[n] >> numero[n] >> nbPieds >> nbPouces >> nbLivres)
    {
        taille[n] = (nbPieds + nbPouces /12.0) * PIED_EN_METRE;
        poids[n]  = nbLivres * LIVRE_EN_KG ;
        n++;
    }
    aLire.close();
    *p = n ;
}

// afficher le contenu des tableaux
void afficher(int numero[], char sexe[], float taille[], float poids[], int nbPers) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    
    cout << "Contenu des tableaux :\n";
    cout << "indice      numero     sexe     taille      poids  " << endl ;
    
    for(int i = 0; i < nbPers; i++){
        cout << setw(3) << i << ") " << setw(12) << numero[i] << setw(8) << sexe[i] << setw(12) << setprecision(2) << taille[i] << setw(12)  << poids[i] << endl;
    }
    cout << endl;
}

/* afficher une "ligne" de données, càd un certain index de chaque tableau : numéro, sexe, etc.*/
void afficherCertainIndex(int numero[], char sexe[], float taille[], float poids[], int nbPers, int indexAAfficher){
    if (indexAAfficher == -1) {
        cout << "introuvé" << endl << endl;
        return;
    }
    
    for (int i = 0; i < nbPers; i++) {
        if (i == indexAAfficher) {
            cout << setw(3) << i << ") " << setw(12) << numero[i] << setw(8) << sexe[i] << setw(12) << setprecision(2) << taille[i] << setw(12)  << poids[i] << endl;
            cout << endl;
        }
    }
}

/* rechercher et la personne ayant un certain numero (id) 
 pointeur pour retenir index du resultat de recherche */
void rechercherCertainId(int id, int numero[], int nbPers, int * pIndex){
    *pIndex = -1; // initialiser
    for (int i = 0; i < nbPers; i++) {
        
        if (numero[i] == id) { // si on trouve les id recherchés,
            *pIndex = i;
            return;
        } // index va donner -1 si introuvé
    }
}

/*rechercher valeur maximale, par exemple taille, poids, etc ...
 pointeur pour retenir index du resultat de recherche */
template <class T>
void rechercherMax(T tabARechercher[], int nbPers, int * pIndex){
    T max = FLT_MIN;
    for (int i=0; i < nbPers; i++) {
        if (tabARechercher[i] > max){
            max = tabARechercher[i];
            *pIndex = i;
        }
    }
}

/* calculer moyen de taille ou poids pour F ou M */
template <class T>
void moyenneFOuM(T tabARechercher[], int nbPers, char fOuM, char sexe[], float * pMoyen) {
    float somme = 0.0;
    int compteurTotal = 0;
    for (int i=0; i < nbPers; i++) {
        if (sexe[i] == fOuM){
            somme += tabARechercher[i];
            compteurTotal++;
        }
    }
    *pMoyen = somme / compteurTotal;
}

/* switcher les deux valeurs dans tableaux. 
 fonction utilisée pour trier() */
template <class T>
void permuter(T &x, T &y) {
    T tempo = x;
    x = y ;
    y = tempo;
}

/* trier les tableaux par taille. modifie les tableaux */
void trier(int numero[], float taille[], float poids[], char sexe[], int nbPers) {
    for (int i = 0; i < nbPers-1; i++) {
        int indMin = i;
      for (int j = i+1; j < nbPers; j++)
          if (numero[j] < numero[indMin]){
              indMin = j;
          }
    if (indMin != i){ // on permute les éléments des 3 tableaux
        permuter(numero[i], numero[indMin]);
        permuter(taille[i], taille[indMin]);
        permuter(poids[i], poids[indMin]);
        permuter(sexe[i], sexe[indMin]);
      }
    }
}

int main() {
    
    /* déclaration de 4 tableaux et du nombre de personnes lues
     qui est aussi le nombre d'éléments de ces 4 tableaux */
    
    const int MAX_PERS = 25;
    int numero[MAX_PERS];
    char sexe[MAX_PERS];
    float taille[MAX_PERS], poids[MAX_PERS];
    int nbPers;

    lireRemplir("imp_h24.txt", numero, sexe, taille, poids, &nbPers);
    cout << "On vient de lire les informations de " << nbPers << " personnes\n\n" ;
    
    // 1. afficher le contenu de ces 4 tableaux avant le tri;
    afficher(numero, sexe, taille, poids, nbPers);
    
    /* 2. rechercher et afficher les résultats de la
    recherche des personnes ayant de numéros suivants :
    2233, 4177, 9876
    par la recherche séquentielle dans le tableau
    des numéros non triés */
    
    cout << "2. rechercher et afficher les personnes ayant numéros: " << endl;
    cout << "=> numero 2233:" << endl;
    int indexAAfficher;
    rechercherCertainId(2233, numero, nbPers, &indexAAfficher);
    afficherCertainIndex(numero, sexe, taille, poids, nbPers, indexAAfficher);
    
    cout << "=> numero 4177:" << endl;
    rechercherCertainId(4177, numero, nbPers, &indexAAfficher);
    afficherCertainIndex(numero, sexe, taille, poids, nbPers, indexAAfficher);
    
    cout << "=> numero 9876:" << endl;
    rechercherCertainId(9876, numero, nbPers, &indexAAfficher);
    afficherCertainIndex(numero, sexe, taille, poids, nbPers, indexAAfficher);
    
    /*
     3. déterminer et afficher toutes les informations
     a) d'une personne ayant la taille la plus grande
     b) d'une personne ayant le poids le plus lourd
     */
    cout << "3. Rechercher et afficher les max : " << endl;
    cout << "Résultat taille max : " << endl;
    rechercherMax(taille, nbPers, &indexAAfficher);
    afficherCertainIndex(numero, sexe, taille, poids, nbPers, indexAAfficher);
    
    cout << "Résultat poids max : " << endl;
    rechercherMax(poids, nbPers, &indexAAfficher);
    afficherCertainIndex(numero, sexe, taille, poids, nbPers, indexAAfficher);
    
    /* 4. calculer et afficher
     a) la taille moyenne des femmes
     b) le poids moyen des hommes
     */
    cout << "4. Calculer et afficher les moyennes : " << endl;
    float moyenne;
    // femmes taille moyenne
    moyenneFOuM(taille, nbPers, 'F', sexe, &moyenne);
    cout << "=> taille moyenne des femmes : " << moyenne << endl;
    
    // hommes poids moyen
    moyenneFOuM(poids, nbPers, 'M', sexe, &moyenne);
    cout << "=> poids moyen des hommes : " << moyenne << endl;
    cout << endl;
    
    /*
    5. trier (avec le tri par sélection) les personnes selon leurs
    numéros et afficher le contenu de ces 4 tableaux
    aprés le tri;
    */
    
    cout << "5. trier les personnes selon numéros : " << endl;
    trier(numero, taille, poids, sexe, nbPers);
    afficher(numero, sexe, taille, poids, nbPers);
    
    /*
     6. rechercher et afficher les résultats de la
     recherche des personnes ayant de numéros suivants :
     2233, 4177, 9876
     par la recherche séquentielle dans le tableau des numéros triés
     */
    cout << "6. (après le tri) rechercher et afficher résultats : " << endl;
    
    cout << "=> numero 2233:" << endl;
    rechercherCertainId(2233, numero, nbPers, &indexAAfficher);
    afficherCertainIndex(numero, sexe, taille, poids, nbPers, indexAAfficher);
    
    cout << "=> numero 4177:" << endl;
    rechercherCertainId(4177, numero, nbPers, &indexAAfficher);
    afficherCertainIndex(numero, sexe, taille, poids, nbPers, indexAAfficher);
    
    cout << "=> numero 9876:" << endl;
    rechercherCertainId(9876, numero, nbPers, &indexAAfficher);
    afficherCertainIndex(numero, sexe, taille, poids, nbPers, indexAAfficher);


    return 0;
    
}


/* Exécution:
 
 On vient de lire les informations de 20 personnes

 Contenu des tableaux :
 indice      numero     sexe     taille      poids
   0)         2187       F        1.68       81.72
   1)         4148       M        1.80       83.99
   2)         2233       M        1.85       85.35
   3)         4433       M        1.47       57.66
   4)         2108       F        1.80       74.91
   5)         4100       F        1.65       54.03
   6)         2176       F        1.88       84.90
   7)         5423       M        1.75       66.74
   8)         4169       M        1.68       55.84
   9)         4177       F        1.75       62.65
  10)         2879       M        1.88       86.71
  11)         5477       F        1.80       66.74
  12)         4869       M        1.60       73.55
  13)         4354       M        1.68       76.73
  14)         2235       M        1.88       85.81
  15)         5444       M        1.78       68.55
  16)         4198       F        1.75       56.75
  17)         5678       M        2.01       86.26
  18)         1357       F        1.68       70.37
  19)         3498       F        1.50       61.29

 2. rechercher et afficher les personnes ayant numéros:
 => numero 2233:
   2)         2233       M        1.85       85.35

 => numero 4177:
   9)         4177       F        1.75       62.65

 => numero 9876:
 introuvé

 3. Rechercher et afficher les max :
 Résultat taille max :
  17)         5678       M        2.01       86.26

 Résultat poids max :
  10)         2879       M        1.88       86.71

 4. Calculer et afficher les moyennes :
 => taille moyenne des femmes : 1.72
 => poids moyen des hommes : 75.20

 5. trier les personnes selon numéros :
 Contenu des tableaux :
 indice      numero     sexe     taille      poids
   0)         1357       F        1.68       70.37
   1)         2108       F        1.80       74.91
   2)         2176       F        1.88       84.90
   3)         2187       F        1.68       81.72
   4)         2233       M        1.85       85.35
   5)         2235       M        1.88       85.81
   6)         2879       M        1.88       86.71
   7)         3498       F        1.50       61.29
   8)         4100       F        1.65       54.03
   9)         4148       M        1.80       83.99
  10)         4169       M        1.68       55.84
  11)         4177       F        1.75       62.65
  12)         4198       F        1.75       56.75
  13)         4354       M        1.68       76.73
  14)         4433       M        1.47       57.66
  15)         4869       M        1.60       73.55
  16)         5423       M        1.75       66.74
  17)         5444       M        1.78       68.55
  18)         5477       F        1.80       66.74
  19)         5678       M        2.01       86.26

 6. (après le tri) rechercher et afficher résultats :
 => numero 2233:
   4)         2233       M        1.85       85.35

 => numero 4177:
  11)         4177       F        1.75       62.65

 => numero 9876:
 introuvé

 Program ended with exit code: 0
 
 */
