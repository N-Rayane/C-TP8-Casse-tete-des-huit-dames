/**
 * @file Graphique.h
 * Fichier d'en-tête de Graphique.c
 * présentant la définition de
 * ses fonctions et structures,
 * ainsi que leur documentation
 * @author Claire SALLE
 * @author Rayane NASSIB
 * @date 05-04-2023
 */

#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

#include "Moteur.h"
#include <ncurses.h>

#define NB_COLONNES 8
#define NB_LIGNES 8
#define NB_COLONNES_CASE 9
#define NB_LIGNES_CASE 5

/**
 * Les numéros des paires de couleurs
 * pour init_pair()
 */
enum couleurs {
    NOIR,
    BLANC,
    DAME_NOIRE,
    DAME_BLANCHE,
    VIOLET,
    LETTRE_VIOLET,
    CYAN_LETTRE_ROUGE,
    VIOLET_LETTRE_ROUGE,
    CYAN_LETTRE_VIOLET,
    CYAN,
    TEXTE_FIN
};

/**
 * @brief Crée une fenêtre ncurses et
 * la paramètre. Initialise toutes les
 * couleurs qui seront utilisées.
 */
void initialiser_ncurses();

int recuperer_touche(int touche);

/**
 * @brief affiche une case
 * contenant la lettre passée en
 * argument à la position (x, y)
 * @param lettre
 * @param x
 * @param y
 */
void afficher_carre(char lettre, int x, int y, int couleur_fond,
                    int couleur_texte);

/**
 * @brief affiche l'échéquier
 * avec les dames présentes dessus
 * @param pos la position des dames
 * @return int
 * @retval 1 si l'affichage a pu
 * être fait
 * @retval 0 si l'affage n'a pas
 * pu être fait
 */
int affiche_pos(Position pos, Case actu);

/**
 * @brief ferme la fenêtre
 * ncurses
 */
void sortir();

#endif
