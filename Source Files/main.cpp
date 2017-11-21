/*
 -----------------------------------------------------------------------------------
 Laboratoire : 06
 Fichier     : main.cpp
 Auteur(s)   : Maurice Lehmann et Alexandre Marques
 Date        : 21.11.2017

 But         : Ce programme affiche le nombre de jours séparant deux dates entrée par l'utilisateur.

 Remarque(s) : Les années bissextiles sont gérées.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "calendrier.h" //Utilisé pour le calcule du nombre de jours entre les deux dates
#include "saisie.h" //Utilisé pour les entrées utilisateurs et fonction "recommencerProgramme" 

using namespace std;

int main() 
{
   //Initialisation du jour, mois , année de début et de fin
   int debutJour, debutMois, debutAnnee, finJour, finMois, finAnnee, nbJour;
   
   //Le programme recommence ou s'arrête selon le choix de l'utilisateur après son execution.
   do
   {
      //L'utilisateur entre la date de début complète "jj-mm-aaaa" , les paramètres de la fonctions sont par référence
      saisieUtilisateur(debutJour,debutMois,debutAnnee, "Entrez la date de debut (JJ-MM-AAAA) : "); 
      
      ////L'utilisateur entre la date de fin complète "jj-mm-aaaa", 
      // les 3 derniers paramètres sont utilisé pour le controle de validité entre les deux dates
      saisieUtilisateur(finJour,finMois,finAnnee, "Entrez la date de fin (JJ-MM-AAAA) : ", debutJour, debutMois, debutAnnee) ; 
      
      //Calcule du nombre de jour entre les deux dates
      nbJour = calculerNbJour(debutJour, debutMois, debutAnnee, finJour, finMois, finAnnee);
      
      cout << "le nombre de jour separant les deux dates est de " << nbJour << " jours." << endl << endl;
      
   } while(recommencerProgramme());
   
   return EXIT_SUCCESS;
}