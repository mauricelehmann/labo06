/*
 -----------------------------------------------------------------------------------
 Laboratoire : 06
 Fichier     : saisie.cpp
 Auteur(s)   : Maurice Lehmann et Alexandre Marques
 Date        : 20.11.2017

 But         : Contient les fonctions relative aux saisies utilisateur
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
//TEST

#include "saisie.h"
#include "calendrier.h"

bool saisieUtilisateur( int& jour, int& mois, int& annee, const string& message, int jourMin, int moisMin, int anneeMin)
{
   string date  ;
   int jourUser, moisUser, anneeUser;
   
   //Corresond aux séparateurs entre jour, mois et année
   char caract1, caract2;
   bool saisieCorrect = false ;
   do
   {      
      cout << message;
      cin >> jourUser >> caract1 >> moisUser >> caract2 >> anneeUser  ;
      
      //Contrôle de la validité des séparateurs
      if(caract1 == '-' && caract2 == '-')
      {
         //Contrôle des bornes de contrôle
         //Si l'année est différente, on ne controle pas les mois et les jours
         if(anneeUser != anneeMin)
         {
            moisMin = MIN_MOIS;
            jourMin = MIN_JOUR;
         }
         //Sinon on contrôle si le mois et le jour
         else
         {
            if(moisUser != moisMin)
            {
               jourMin = MIN_JOUR;
            }
         }
        
         //Controle des outputs
         if(controleSaisie( anneeUser , anneeMin , MAX_ANNEE , "Annee incorrect ! ") 
         and controleSaisie( moisUser , moisMin , MAX_MOIS , "Mois incorrect ! ")
         and controleSaisie( jourUser , jourMin , nombreJourMois(moisUser, anneeUser) , "Jour incorrect !"))
         {
            saisieCorrect = true ;
            jour = jourUser;
            mois = moisUser;
            annee = anneeUser;
         }
      }
      else
      {
         cout << "Le format de date n'est pas correct. " << endl;
      }
      
      VIDER_BUFFER ;
      
   }while(!saisieCorrect) ;
}

bool controleSaisie( int valeur , unsigned int limiteInf , unsigned limiteSup , string message){
   
   //Controle d'une valeur entre deux bornes
   if( valeur < limiteInf or valeur > limiteSup ){
      cout << message << endl ;
      return false ;
   }
   return true ;
}

bool recommencerProgramme()
{
   char reponseUtilisateur ; 
   bool saisieOK;
   bool recommencerProgramme = false ; 
   
   // Demande de recommencer le programme
   do 
   {
      cout << "Voulez-vous recommencer le programme ? " << endl
           << "(si non, le programme se terminera) [O/N] : ";

      cin >> reponseUtilisateur;
      
      saisieOK = ( (reponseUtilisateur == 'O') || (reponseUtilisateur == 'N') || (reponseUtilisateur == 'o') || (reponseUtilisateur == 'n') );

      if (!saisieOK){
         cin.clear();
         cout << "Votre saisie n'est pas valide." << endl << endl;
      }
      // Si la saisie est valide, on va initialiser le flag qui détermine si le
      // programme doit recommencer.
      else{
         recommencerProgramme = (reponseUtilisateur == 'O') || (reponseUtilisateur == 'o');
      }
      VIDER_BUFFER;
      
   }while (!saisieOK);
   
   return recommencerProgramme ;
}