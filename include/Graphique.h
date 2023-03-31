#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

#include "Moteur.h"
#include <ncurses.h>

/**
 * Les numéros des paires de couleurs
 * pour init_pair()
 */
enum couleurs {
    CYAN = 1,
    LETTRE_CYAN,
    BLEU,
    LETTRE_BLEUE,
    VIOLET,
    LETTRE_VIOLET,
    CYAN_LETTRE_ROUGE,
    VIOLET_LETTRE_ROUGE,
    CYAN_LETTRE_VIOLET,
    NOIR,
    TEXTE_FIN
};

/**
 * @brief Crée une fenêtre ncurses et
 * la paramètre. Initialise toutes les
 * couleurs qui seront utilisées.
 */
void initialiser_ncurses();

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

void affiche_pos(Position pos);

#endif
