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

5. Faire la vue externe puis écrire l'algorithme du sous-programme minmaxTemp() dont le but est de trouver la température minimale et la température maximale de la série de mesures.
Ce sous-programme doit recevoir le tableau de mesures et le nombre de ces mesures. Il doit renvoyer les deux valeurs correspondant au minimum et au maximum des valeurs du tableau de mesures.

    Voici l'algorithme du sous-programme minmaxTemp() :

    ```cpp
    minmaxTemp(tabMesures, nbMesures, min, max)
    {
        min ← tabMesures[1]
        max ← tabMesures[1]
        pour i allant de 2 à nbMesures
        {
            si tabMesures[i] < min
            {
                min ← tabMesures[i]
            }
            sinon si tabMesures[i] > max
            {
                max ← tabMesures[i]
            }
        }
    }
    ```

    ### <center> Explication </center>

    - La première ligne permet d'initialiser la variable min avec la première valeur du tableau de mesures.
    - La deuxième ligne permet d'initialiser la variable max avec la première valeur du tableau de mesures.
    - La troisième ligne permet de parcourir le tableau de mesures à partir de la deuxième valeur.
    - La quatrième ligne permet de comparer la valeur de la mesure n°i avec la valeur de la variable min.
    - La cinquième ligne permet de mettre à jour la valeur de la variable min si la valeur de la mesure n°i est inférieure à la valeur de la variable min.
    - La sixième ligne permet de comparer la valeur de la mesure n°i avec la valeur de la variable max.
    - La septième ligne permet de mettre à jour la valeur de la variable max si la valeur de la mesure n°i est supérieure à la valeur de la variable max.

6. Faire la vue externe puis écrire l'algorithme du sous-programmeTproche0() dont le but est de trouver la mesure de température la plus proche de 0°C.
Ce sous-programme doit recevoir le tableau de mesures et le nombre de ces mesures. Il doit renvoyer la valeur la plus proche de 0°C.
Si deux mesures de signes opposés ont la même valeur absolue, on retient la mesure positive. L'algorithme de ce sous-programme utilise la fonction fabs() de la bibliothèque standard sur les mathématiques qui renvoie la valeur absolue d'un nombre réel.

    Voici l'algorithme du sous-programme Tproche0() :

    ```cpp
    Tproche0(tabMesures, nbMesures, proche0)
    {
        proche0 ← tabMesures[1]
        pour i allant de 2 à nbMesures
        {
            si fabs(tabMesures[i]) < fabs(proche0)
            {
                proche0 ← tabMesures[i]
            }
        }
    }
    ```

    ### <center> Explication </center>

    - La première ligne permet d'initialiser la variable proche0 avec la première valeur du tableau de mesures.
    - La deuxième ligne permet de parcourir le tableau de mesures à partir de la deuxième valeur.
    - La troisième ligne permet de comparer la valeur absolue de la mesure n°i avec la valeur absolue de la variable proche0.
    - La quatrième ligne permet de mettre à jour la valeur de la variable proche0 si la valeur absolue de la mesure n°i est inférieure à la valeur absolue de la variable proche0.

    >POurquoi utiliser la fonction fabs() ?

    ```cpp
    fabs(-5.5) = 5.5
    fabs(5.5) = 5.5
    ```
    La fonction `fabs()` permet de renvoyer la valeur absolue d'un nombre réel.
