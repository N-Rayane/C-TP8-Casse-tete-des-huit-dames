/**
 * @file Moteur.c
 * Fichier contenant le
 * moteur du jeu des huit
 * dames
 * @author Claire SALLE
 * @author Rayane NASSIB
 * @date 05-04-2023
 */

#include "../include/Moteur.h"
#include <stdio.h>

Position tab_cases_attaquees[64];

int est_case_occupee(Position pos, Case c) {
    return pos >> c;
}

int placer_dame_position(Position *pos, Case c) {
    (*pos) |= ((unsigned long long)1 << c);
    return 0;
}

int afficher_position(Position pos) {
    for (int j = 7; j >= 0; j--) {
        for (int i = 0; i < 8; i++) {
            if ((pos >> (i + 8 * j)) & 1)
                printf("+ ");
            else
                printf(". ");
        }
        printf("\n");
    }
    return 0;
}

/*exemple : D5 = 35 */
int calculer_cases_attaquees(Position *pos, Case c) {
    *pos = 0;
    int n = (c / 8) - (c % 8);
    int n2 = (c / 8) + (c % 8);
    for (int j = 7; j >= 0; j--) {
        for (int i = 0; i < 8; i++) {
            if ((i + 8 * j != c) &&
                ((i + 8 * j) / 8 == c / 8 || (i + 8 * j) % 8 == c % 8 ||
                 (j - i) == n || (i + j) == n2)) {
                *pos |= ((unsigned long long)1 << (i + 8 * j));
            }
        }
    }

    /* (c % 8) + 1 = nombre de colonne, cad 3e pour l'exemple */
    /* c / 8 = nombre de ligne, cad 4e pour l'exemple */
    return 1;
}

void gerer_controles(int touche, Position pos, Case *actu) {
    switch (touche) {
        case HAUT:
            if (*actu >= A8) return;
            *actu += 8;
            break;
        case BAS:
            if (*actu <= H1) return;
            *actu -= 8;
            break;
        case GAUCHE:
            if (*actu <= A1) return;
            *actu -= 1;
            break;
        case DROITE:
            if (*actu >= H8) return;
            *actu += 1;
            break;
        case VALIDER:
            break;
    }
}

int remplir_tab_cases_attaquees() {
    Position pos;
    for (int i = A1; i < H8; i++) {
        calculer_cases_attaquees(&pos, i);
        tab_cases_attaquees[i] = pos;
    }
    return 0;
}

int est_sans_attaque_mutuelle(Position pos) {
    Position attaque = 0;
    for (int i = 0; i < 64; i++) {
        if (pos >> i & 1) {
            attaque |= tab_cases_attaquees[i];
        }
    }

    return !((attaque & pos) || 0);
}
