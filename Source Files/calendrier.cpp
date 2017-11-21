/*
-----------------------------------------------------------------------------------
Laboratoire 	: Labo_06
Fichier         : calendrier.cpp
Auteur 		: Marques Alexandre, Maurice Lehmann
Date 		: 15.11.2017
But 		: Contient les fonctions relatives au calcule des jours
Commentaire(s) 	: -
Compilateur 	: MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#include "calendrier.h"

bool anneeBissextile(int annee) 
{ 
   // Une année est bissextile si les conditions suivantes sont respectées :
   // - année est divisible par 4 ou 100
   // - année n'est pas divisible par 400
   return (annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0));
}

int nombreJourMois(int mois, int annee) 
{
   switch((ListeMois)(mois)) 
   {
      case ListeMois::JANVIER 	: 
      case ListeMois::MARS 	: 
      case ListeMois::MAI 	: 
      case ListeMois::JUILLET 	: 
      case ListeMois::AOUT 	: 
      case ListeMois::OCTOBRE 	:
      case ListeMois::DECEMBRE 	: return 31;
      case ListeMois::AVRIL 	: 
      case ListeMois::JUIN 	: 
      case ListeMois::SEPTEMBRE : 
      case ListeMois::NOVEMBRE 	: return 30;
      case ListeMois::FEVRIER 	: return (28 + (int) anneeBissextile(annee));
   }
}

int calculerNbJour(const int& jourInitial, const int& moisInitial, const int& anneeInitiale, const int& jourFinal, const int& moisFinal, const int& anneeFinale)
{
   // on retire le nombre de jour du premier mois car on ajoutera le nombre de jour total du mois en-dessous
   // on ajoute le nombre de jour du dernier mois car on n'ajoutera pas le nombre de jour total du mois
   int nombreJours = 0 - jourInitial + jourFinal;
   
   // Il doit parcourir tous les mois de l'année sauf si l'année est égales à l'année final
   for(int mois = moisInitial, annee = anneeInitiale; mois < moisFinal || annee < anneeFinale; ++mois)
   {
      // on récupère le nombre de jour total du mois
      int nbJourMois = nombreJourMois(mois, annee);
      
      // on ajoute le nombre de jours totaux de chaque mois
      nombreJours += nbJourMois;
      
      // il y a un changement d'année si le prochain mois est janvier
      if(mois == (int)ListeMois::DECEMBRE && annee != anneeFinale)
      {
         mois = 0;
         annee++;
      }
   }
   
   return nombreJours;
}