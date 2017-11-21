/*
-----------------------------------------------------------------------------------
Laboratoire 	: Labo_06
Fichier         : calendrier.h
Auteur 		: Marques Alexandre, Maurice Lehmann
Date 		: 15.11.2017
But 		: Met à disposition des fonctions en relation avec le calendrier
 *                Ex: calcule du nombre de jour entre 2 dates, verification année 
 *                   est bissextile ou nombre de jour dans un mois
Commentaire(s) 	: -
Compilateur 	: MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/

#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <cstdlib>  // Pour exit_success
#include <iostream> // Pour les entrées et sorties

using namespace std ;

// enumération de tous les mois de l'année
enum class ListeMois {JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE };

/**
 * fonction permettant de savoir si une année est bissextile
 * @param annee : l'année voulu pour le test
 * @return true : si l'année est bissextile
 */
bool anneeBissextile(int annee);

/**
 * Permet de savoir combien de jour contient un mois
 * @param mois : le mois voulu pour recuperer son nombre de jour
 * @param annee: permet de savoir si le mois de fevrier a 28 ou 29 jours
 * @return nombre de jour du mois
 */
int nombreJourMois(int mois, int annee);

/**
 * permet de savoir le nombre de jour séparant deux dates
 * @param jourInitial   : jour de la première date
 * @param moisInitial   : mois de la première date
 * @param anneeInitiale : annee de la première date
 * @param jourFinal     : jour de la seconde date
 * @param moisFinal     : mois de la seconde date
 * @param anneeFinale   : annee de la seconde date
 * @return le nombre de jour separant les deux dates
 */
int calculerNbJour(const int& jourInitial, const int& moisInitial, const int& anneeInitiale, const int& jourFinal, const int& moisFinal, const int& anneeFinale);

#endif /* CALENDRIER_H */

