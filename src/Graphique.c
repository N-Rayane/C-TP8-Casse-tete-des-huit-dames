#include "../include/Graphique.h"

void initialiser_ncurses() {
    initscr();
    noecho();
    // nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(FALSE);
    start_color();
    init_pair(CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(LETTRE_CYAN, COLOR_BLACK, COLOR_CYAN);
    init_pair(BLEU, COLOR_BLUE, COLOR_BLUE);
    init_pair(LETTRE_BLEUE, COLOR_BLACK, COLOR_BLUE);
    init_pair(VIOLET, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(LETTRE_VIOLET, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(CYAN_LETTRE_ROUGE, COLOR_RED, COLOR_CYAN);
    init_pair(VIOLET_LETTRE_ROUGE, COLOR_RED, COLOR_MAGENTA);
    init_pair(CYAN_LETTRE_VIOLET, COLOR_MAGENTA, COLOR_CYAN);
    init_pair(TEXTE_FIN, COLOR_RED, COLOR_BLACK);
    init_pair(NOIR, COLOR_BLACK, COLOR_BLACK);
    init_color(9, 0, 0, 0);
}

void afficher_carre(char lettre, int x, int y, int couleur_fond,
                    int couleur_texte) {
    attron(COLOR_PAIR(couleur_fond));
    mvprintw(y, x, "     ");
    mvprintw(y + 2, x, "     ");
    mvprintw(y + 1, x, " ");
    attroff(COLOR_PAIR(couleur_fond));
    attron(COLOR_PAIR(couleur_texte));
    printw(" %c ", lettre);
    attroff(COLOR_PAIR(couleur_texte));
    attron(COLOR_PAIR(couleur_fond));
    printw(" ");
    attroff(COLOR_PAIR(couleur_fond));
}

void affiche_pos(Position pos) {
}
