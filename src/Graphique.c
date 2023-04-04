/**
 * @file Graphique.c
 * Fichier contenant
 * l'interface graphique
 * du jeu des huit dames
 * @author Claire SALLE
 * @author Rayane NASSIB
 * @date 05-04-2023
 */

#include "../include/Graphique.h"

void initialiser_ncurses() {
    initscr();
    noecho();
    // nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(FALSE);
    start_color();
    init_pair(BLANC, COLOR_WHITE, COLOR_WHITE);
    init_pair(DAME_BLANCHE, COLOR_BLACK, COLOR_WHITE);
    init_pair(DAME_NOIRE, COLOR_WHITE, COLOR_BLACK);
    init_pair(VIOLET, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(DAME_VIOLET, COLOR_BLACK, COLOR_MAGENTA);
}

int recuperer_touche(int touche) {
    switch (touche) {
    case KEY_UP:
        return HAUT;
    case KEY_DOWN:
        return BAS;
    case KEY_LEFT:
        return GAUCHE;
    case KEY_RIGHT:
        return DROITE;
    case KEY_BACKSPACE:
        return SUPPRIMER;
    case '\n':
        return VALIDER;
    default:
        return -1;
    }
}

void afficher_carre(char lettre, int x, int y, int couleur_fond,
                    int couleur_texte) {
    attron(COLOR_PAIR(couleur_fond));
    for (int j = 0; j < NB_LIGNES_CASE; j++) {
        move(y+j, x);
        for (int i = 0; i < NB_COLONNES_CASE; i++) {
            if(((NB_LIGNES_CASE % 2 == 0 && j - 1 == NB_LIGNES_CASE / 2) || (NB_LIGNES_CASE % 2 == 1 && j == NB_LIGNES_CASE / 2)) && ((NB_COLONNES_CASE % 2 == 1 && i == NB_COLONNES_CASE / 2) || (NB_COLONNES_CASE % 2 == 0 && i - 1 == NB_COLONNES_CASE / 2))) {
                attroff(COLOR_PAIR(couleur_fond));
                attron(COLOR_PAIR(couleur_texte));
                addch(lettre);
                attroff(COLOR_PAIR(couleur_texte));
                attron(COLOR_PAIR(couleur_fond));
            } else addch(' ');
        }
    }
    attroff(COLOR_PAIR(couleur_fond));
}

void afficher_texte(const char* texte) {
    mvprintw(2, (COLS - strlen(texte))/2, texte);
}

int affiche_pos(Position pos, Case actu) {
    int nb_cases_x, nb_cases_y, debut_x, debut_y, x, y;
    
    debut_x = (COLS/2) - ((NB_COLONNES*NB_COLONNES_CASE)/2);
    debut_y = (LINES/2) - ((NB_LIGNES*NB_LIGNES_CASE)/2);
    if (debut_x < 0 || debut_y < 0) return 0;

    x = debut_x;
    y = debut_y;

    for (int j = 7; j >= 0; j--) {
        //move(j, 0);
        for (int i = 0; i < 8; i++) {
            
            if ((pos >> (i + 8 * j)) & 1) {
                if ((i + 8 * j) == actu) {
                    afficher_carre('d', x, y, VIOLET, DAME_VIOLET);
                }
                else if((i + j) % 2 == 0) {
                    afficher_carre('d', x, y, BLANC, DAME_BLANCHE);
                } else {
                    afficher_carre('d', x, y, NOIR, DAME_NOIRE);
                }
            }
                
            else {
                if ((i + 8 * j) == actu) {
                    afficher_carre(' ', x, y, VIOLET, VIOLET);
                } else if ((i + j) % 2 == 0) {
                    afficher_carre(' ', x, y, BLANC, BLANC);
                } else {
                    afficher_carre(' ', x, y, NOIR, NOIR);
                }
            }
            
            x += NB_COLONNES_CASE;    
        }
        x = debut_x;
        y += NB_LIGNES_CASE;
    }
    refresh();
    return 1;
}

void sortir() {
    nodelay(stdscr, FALSE);
    curs_set(TRUE);
    endwin();
}
