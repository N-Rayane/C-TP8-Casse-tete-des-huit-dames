#include "../include/Graphique.h"
#include "../include/Moteur.h"

int main() {
    Position test = 0;
    placer_dame_position(&test, C1);
    placer_dame_position(&test, F2);
    placer_dame_position(&test, B3);
    placer_dame_position(&test, E4);
    placer_dame_position(&test, H5);
    placer_dame_position(&test, A6);
    placer_dame_position(&test, D8);

    remplir_tab_cases_attaquees();

    printf("\n%d\n", est_sans_attaque_mutuelle(test));

    afficher_position(test);

    return 0;
}
