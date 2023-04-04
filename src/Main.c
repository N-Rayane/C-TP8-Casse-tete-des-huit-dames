#include "../include/Graphique.h"
#include "../include/Moteur.h"

int main() {
    Position pos = 0;
    Case actu = A1;
    int touche;

    initialiser_ncurses();
    remplir_tab_cases_attaquees();
    affiche_pos(pos, actu);
    while ((touche = getch()) != 'q') {
        if (gerer_controles(recuperer_touche(touche), pos, &actu) == 1) {
            placer_dame_position(&pos, actu);
        }
        affiche_pos(pos, actu);
        if (!est_sans_attaque_mutuelle(pos)) {
            afficher_texte("Deux dames se mangent.");
        } else if (nombre_dames(pos) == 8) {
            afficher_texte("Bravo ! Vous avez réussi !!");
        } else {
            afficher_texte("                           ");
        }
    }
    
    sortir();

    return 0;
}
