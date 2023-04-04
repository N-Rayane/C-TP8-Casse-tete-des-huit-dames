#include "../include/Graphique.h"
#include "../include/Moteur.h"
#include <curses.h>

int main() {
    Position test = 0;
    Case actu = A1;
    int touche;
    initialiser_ncurses();
    remplir_tab_cases_attaquees();
    while ((touche = getch()) != 'q') {
        gerer_controles(recuperer_touche(touche), test, &actu);
        affiche_pos(test, actu);
    }

    placer_dame_position(&test, C1);
    placer_dame_position(&test, F2);
    placer_dame_position(&test, B3);
    placer_dame_position(&test, E4);
    placer_dame_position(&test, H5);
    placer_dame_position(&test, A6);
    placer_dame_position(&test, D8);

    

    printf("\n%d\n", est_sans_attaque_mutuelle(test));
    getch();
    
    
    sortir();

    return 0;
}
