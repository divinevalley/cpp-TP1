/* TP1
 
 Auteur : Deanna Wung,  IFT 1166, Hiver 24
 TP1. Numéro A.
 Traiter et afficher les diviseurs de input
 Permet de prendre un numéro saisi par l'utilisateur
 et donner une liste de diviseurs de ce numéro.
 
*/

#include <iostream>
#include <iomanip> // permet d'appeler setw()

using namespace std;

int compterNbDiviseurs(int reponse){
    int compteur = 0;
    for (int i=1; i<=reponse; i++) {
        if (reponse % i == 0) { // est un diviseur
            compteur++; // incrementer compteur diviseurs
        }
    }
    return compteur;
}

void afficher(int intATester) {
    int k = 0;
    for(int i = 1; i <= intATester; i++)
       if (intATester % i == 0) { // si i est un diviseur,
           // commencer a afficher
           cout << setw(3) << ++k << ") " << setw(5) << i << endl;
       }
     cout << endl << endl;
}
  
int main() {
    int reponse;
  
    cout << "Saisir un nombre :  ";
    cin >> reponse;
       
    cout << "Les " << compterNbDiviseurs(reponse) << " diviseurs de " << reponse << " :" << endl;
    afficher(reponse);
    
    return 0;
}

/*
 Exécution :
 
 
 Saisir un nombre :  55
 Les 4 diviseurs de 55 :
   1)     1
   2)     5
   3)    11
   4)    55


 Program ended with exit code: 0
 */
