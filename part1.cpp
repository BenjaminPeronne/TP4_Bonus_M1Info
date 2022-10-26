/**
 * @author Benjamin Peronne
 * @email contact@benjaminperonne.fr
 * @create date 2022-10-26 08:48:29
 * @modify date 2022-10-26 08:48:29
 * @desc [TP-Bonus - Part1]
 */

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

// ============================================================== //
// ====================== Fonction principale =================== //
// ============================================================== //
int main() {
    // Déclaration des variables
    t_mes tabMesures;
    int nbMesures;
    int choix;
    bool ligneUnique;

    // Traitement du choix
    while (choix != 3) {
        switch (choix) {
        case 1:
            lireTemp(tabMesures, nbMesures);
            break;
        case 2:
            cout << "Voulez-vous afficher les températures sur une seule ligne ? (1: oui, 0: non) ";
            cin >> ligneUnique;
            afficherTemp(tabMesures, nbMesures, ligneUnique);
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
        cout << "(3) Quitter?" << endl;
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
