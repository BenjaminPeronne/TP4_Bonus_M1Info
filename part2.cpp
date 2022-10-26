/**
 * @author Benjamin Peronne
 * @email contact@benjaminperonne.fr
 * @create date 2022-10-26 09:19:10
 * @modify date 2022-10-26 09:19:10
 * @desc [TP-Bonus - Part2]
 */

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// Déclaration des constantes
#define N_MAX 100
#define T_MIN -273.5
#define T_MAX 5526.0

// Déclaration du type t_mes
typedef float t_mes[N_MAX];

// ============================================================== //
// =========== Déclaration des fonctions (prototypes) =========== //
// ============================================================== //
void lireTemp(t_mes tabMesures, int &nbMesures);
void afficherTemp(t_mes tabMesures, int nbMesures, bool ligneUnique);
void minmaxTemp(t_mes tabMesures, int nbMesures, float &min, float &max);
void Tproche0(t_mes tabMesures, int nbMesures, float &T0);
void calculEffectif(t_mes tabMesures, int nbMesures, float borneInf, float borneSup, int &effectif);
void afficherExtremums(float min, float max, float T0);  // fonction d'affichage
void afficherEffectifs(t_mes tabMesures, int nbMesures); // fonction d'affichage

// ============================================================== //
// ====================== Fonction principale =================== //
// ============================================================== //
int main() {
    // Déclaration des variables
    t_mes tabMesures;
    int nbMesures;
    int choix;
    bool ligneUnique;
    float min, max, T0;
    int effectif;
    float borneInf, borneSup;

    // Traitement du choix
    while (choix != 7) {

        switch (choix) {
        case 1:
            lireTemp(tabMesures, nbMesures);
            break;
        case 2:
            cout << "Voulez-vous afficher les températures sur une seule ligne ? (1: oui, 0: non) ";
            cin >> ligneUnique;
            afficherTemp(tabMesures, nbMesures, ligneUnique);
            break;
        case 3:
            Tproche0(tabMesures, nbMesures, T0);
            cout << "La température la plus proche de 0°C est " << T0 << "°C" << endl;
            break;
        case 4:
            minmaxTemp(tabMesures, nbMesures, min, max);
            afficherExtremums(min, max, T0);
            break;
        case 5:
            afficherEffectifs(tabMesures, nbMesures);
            break;
        case 6:
            cout << "Veuillez saisir la borne inférieure de la classe de températures : ";
            cin >> borneInf;
            cout << "Veuillez saisir la borne supérieure de la classe de températures : ";
            cin >> borneSup;
            calculEffectif(tabMesures, nbMesures, borneInf, borneSup, effectif);
            cout << "Il y a " << effectif << " mesures de températures comprises entre " << borneInf << " et " << borneSup << endl;
            break;

        default:
            cout << "Choix incorrect" << endl;
            break;
        }

        // Affichage du menu
        cout << endl;
        cout << "Voulez-vous :" << endl;
        cout << "(1) Entrer des températures" << endl;
        cout << "(2) Afficher la liste des températures" << endl;
        cout << "(3) Afficher la température la plus proche de 0" << endl;
        cout << "(4) Afficher les extremuns" << endl;
        cout << "(5) Afficher les effectifs des 4 classes" << endl;
        cout << "    ]-10, -5] ]-5, 0] ]0, 5] ]5, 10]" << endl;
        cout << "(6) Afficher l'effectif d'une classe" << endl;
        cout << "(7) Quitter?" << endl;
        cout << endl;
        cout << "Votre choix ? ";
        cin >> choix;
    }

    return 0;
}

// ============================================================== //
// ==============  Définition des sous-programmes =============== //
// ============================================================== //
void lireTemp(t_mes tabMesures, int &nbMesures) {
    cout << "Entrez le nombre de mesures à analyser : ";
    cin >> nbMesures;
    cout << endl;

    for (int i = 0; i < nbMesures; i++) {
        cout << "Entrez la mesure " << i + 1 << " : ";
        cin >> tabMesures[i];
        cout << endl;
    }
}

void afficherTemp(t_mes tabMesures, int nbMesures, bool ligneUnique) {
    if (ligneUnique == true) {
        for (int i = 0; i < nbMesures; i++) {
            cout << tabMesures[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < nbMesures; i++) {
            cout << tabMesures[i] << endl;
        }
    }
}

void minmaxTemp(t_mes tabMesures, int nbMesures, float &min, float &max) {
    // Initialisation des variables min et max
    min = tabMesures[0];
    max = tabMesures[0];

    for (int i = 0; i < nbMesures; i++) { // On parcourt le tableau de mesures
        if (tabMesures[i] < min) {        // Si la valeur est plus petite que la valeur minimale
            min = tabMesures[i];          // On la stocke dans la variable min
        }
        if (tabMesures[i] > max) { // Si la valeur est plus grande que la valeur maximale
            max = tabMesures[i];   // On la stocke dans la variable max
        }
    }
}

void Tproche0(t_mes tabMesures, int nbMesures, float &T0) {
    // Initialisation de la variable T0
    T0 = tabMesures[0];

    for (int i = 0; i < nbMesures; i++) {     // On parcourt le tableau de mesures
        if (fabs(tabMesures[i]) < fabs(T0)) { // Si la valeur absolue de la mesure est plus petite que la valeur absolue de la température la plus proche de 0
            T0 = tabMesures[i];               // On la stocke dans la variable T0
        }
    }
}

void calculEffectif(t_mes tabMesures, int nbMesures, float borneInf, float borneSup, int &effectif) {
    for (int i = 0; i < nbMesures; i++) {                            // On parcourt le tableau de mesures
        if (tabMesures[i] > borneInf && tabMesures[i] <= borneSup) { // Si la valeur est comprise entre les bornes
            effectif++;                                              // On incrémente l'effectif
        }
    }
}

// ============================================================== //
// ====================  Fonction d'affichage =================== //
// ============================================================== //
void afficherExtremums(float min, float max, float T0) {
    cout << "La température minimale est " << min << "°C" << endl;
    cout << "La température maximale est " << max << "°C" << endl;
    cout << "La température la plus proche de 0°C est " << T0 << "°C" << endl;
}

void afficherEffectifs(t_mes tabMesures, int nbMesures) {
    int nbMesuresInf0 = 0;
    int nbMesuresSup0 = 0;

    for (int i = 0; i < nbMesures; i++) {
        if (tabMesures[i] < 0) {
            nbMesuresInf0++;
        } else {
            nbMesuresSup0++;
        }
    }

    cout << "Il y a " << nbMesuresInf0 << " mesures inférieures à 0°C" << endl;
    cout << "Il y a " << nbMesuresSup0 << " mesures supérieures à 0°C" << endl;
}
