# TP | TABLEAUX À UNE DIMENSION


Prénom : <em>Aymerick</em>

Nom : <em>LAURETTA-PERONNE</em>

---

# <center> Introduction </center>

Le but de ce TP est de se familiariser avec la notion de tableaux et de renforcer les notions sur les sous-programmes.

Les différentes parties du TP sont basées sur le même thème : l'analyse d'une série de mesures de température. Ces mesures constituent les éléments d'un tableau sur lequel les traitements seront réalisés à l'aide de sous-programmes tels que la saisie des valeurs du tableau, l'affichage de ces valeurs, la recherche des extremums, la recherche de la valeur la plus proche de zéro et enfin le calcul des effectifs de plusieurs classes de températures.

- Le nombre des mesures à analyser est compris entre 0 inclus et 100 exclu
- Chaque mesure est comprise entre -273,5°C (zéro absolu) et 5526,0°C (estimation de la
température à la surface du soleil).

---

# <center> Saisie et affichage d'une série de valeurs de température </center>

1. Préparer une série d'une quinzaine de mesures de température.

    Voici la série de mesures de température que j'ai préparé :

    | Mesure n° | Température (°C) |
    |:---------:|:----------------:|
    | 1 | 32,0 |
    | 2 | 12,5 |
    | 3 | 18,2 |
    | 4 | 25,0 |
    | 5 | 15,0 |
    | 6 | 20,5 |
    | 7 | 30,8 |
    | 8 | -50,0 |
    | 9 | 5000,0 |
    | 10 | 34,1 |

2. Préparer la déclaration des constantes correspondant au nombre maximum de
mesures N_MAX et aux valeurs extrêmes d'une mesure T_MIN et T_MAX.
Préparer la déclaration du type t_mes correspondant au tableau de N_MAX mesures.

    Voici la déclaration des constantes et du type t_mes :

    ```cpp
    #define N_MAX 100
    #define T_MIN -273.5
    #define T_MAX 5526.0

    typedef float t_mes[N_MAX];
    ```

    J'ai choisi de déclarer le tableau de mesures comme un tableau de flottants car les mesures de température sont des nombres décimaux.

3. Faire la vue externe puis écrire l'algorithme du sous-programme lireTemp() qui commence par demander à l'utilisateur le nombre de mesures à analyser puis les valeurs de chaque mesure. Ces valeurs sont enregistrées dans un tableau tabMesures de type t_mes et leur nombre dans une variable nbMesures.
Le sous-programme doit renvoyer le tableau des mesures saisies et le nombre de mesures au programme principal.

    Voici l'algorithme du sous-programme lireTemp() :

    ```cpp
    lireTemp(tabMesures, nbMesures)
    {
        afficher("Saisie des mesures de température")
        afficher("Nombre de mesures : ")
        saisir(nbMesures)
        pour i allant de 1 à nbMesures
        {
            afficher("Température n°", i, " : ")
            saisir(tabMesures[i])
        }
    }
    ```

    ### <center> Explication </center>

    - La première ligne affiche un message d'introduction pour la saisie des mesures de température.
    - La deuxième ligne affiche un message demandant à l'utilisateur de saisir le nombre de mesures à analyser.
    - La troisième ligne permet de saisir le nombre de mesures à analyser.
    - La boucle for permet de saisir les valeurs de chaque mesure.
    - La quatrième ligne affiche un message demandant à l'utilisateur de saisir la valeur de la mesure n°i.
    - La cinquième ligne permet de saisir la valeur de la mesure n°i.

4. Faire la vue externe puis écrire l'algorithme du sous-programme afficherTemp() qui affiche la série de mesures sous deux formes différentes : toutes les mesures sur une seule ligne ou une mesure par ligne.
Le sous-programme reçoit en entrée le tableau des mesures, le nombre des mesures à afficher et un booléen indiquant si l'affichage doit oui ou non se faire sur une ligne unique.

    Voici l'algorithme du sous-programme afficherTemp() :

    ```cpp
    afficherTemp(tabMesures, nbMesures, ligneUnique)
    {
        si ligneUnique
        {
            afficher("Série de mesures sur une ligne : ")
            pour i allant de 1 à nbMesures
            {
                afficher(tabMesures[i], " ")
            }
        }
        sinon
        {
            afficher("Série de mesures par ligne : ")
            pour i allant de 1 à nbMesures
            {
                afficher("Température n°", i, " : ", tabMesures[i])
            }
        }
    }
    ```

    ### <center> Explication </center>

    - La première ligne affiche un message d'introduction pour l'affichage des mesures de température.
    - La deuxième ligne affiche un message indiquant que les mesures seront affichées sur une ligne unique.
    - La troisième ligne permet d'afficher la première mesure de température.
    - La boucle for permet d'afficher les mesures de température suivantes.
    - La quatrième ligne permet d'afficher la mesure de température n°i.
    - La cinquième ligne permet d'afficher un message indiquant que les mesures seront affichées par ligne.
    - La sixième ligne permet d'afficher la première mesure de température.
    - La boucle for permet d'afficher les mesures de température suivantes.
    - La septième ligne permet d'afficher la mesure de température n°i.

---

