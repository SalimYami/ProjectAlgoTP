#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int chaine_vers_entier(const char* chaine) {
    int resultat = 0;
    int i = 0;
    int signe = 1;

    // Gérer le signe (+ ou -)
    if (chaine[i] == '-') {
        signe = -1;
        i++;
    } else if (chaine[i] == '+') {
        i++;
    }

    // Convertir chaque caractère en entier jusqu'à rencontrer un non-chiffre
    while (chaine[i] != '\0' && isdigit(chaine[i])) {
        resultat = resultat * 10 + (chaine[i] - '0');
        i++;
    }

    return resultat * signe;
}

int main() {

    const char* texte3 = "42 est la reponse.";

    int resultat3 = chaine_vers_entier(texte3);

    printf("La chaine '%s' convertie en entier est : %d\n", texte3, resultat3);

    return 0;
}
