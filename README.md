# Projet_Cpp

LE BRAZIDEC Lucas - MENDES Laura

Projet étudiant qui gère le fonctionnement d'une carte ESP8266 entourée de capteurs/actionneurs. Le projet est tourné autour du fonctionnement d'un laser-game et gère les fonctionnalités : 
- détection d'un laser
- comptage de points
- gestion de différentes phases de jeu

Liste des composants 3v3 : 
- capteur optique laser x8
- diode laser (classe 2) x2
- capteur de mouvement x2
- bouton poussoir x4
- LED x2

Le principe est le suivant : 
- le joueur entre : son nom, le nombre de fois où il doit atteindre la cible et le nombre de tentatives qu'il a,
- la partie se lance : le joueur appuie sur un bouton pour tenter de toucher la cible,
- si il touche la cible : son nombre de succès augmente et une Led verte s'allume,
- sinon : son nombre d'échecs augmente et une Led rouge s'allume, 
- une fois le nombre de succès max est atteint : la partie se termine et une nouvelle tentative commance,
- une fois les tentatives achevées : les scores des différentes tentatives s'affichent.

Lancement du projet : 
- l'étape 6 contient la dernière version du projet et est exécutable en lançant le fichier .ino
- le haut du fichier contient les constantes à remplir par le joueur pour lancer la partie 
- pour recommencer une partie : il faut remodifier ces infos et téléverser à nouveau sur le ESP8266 
