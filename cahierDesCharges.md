# Charclo Brosse
___
# Introduction

Ce cahier des charges est destiné à la conception du jeu Charclo Brosse . Il est conçu par le groupe "Va falloir Brosser" : 
- Melvin Warnet
- Erwan Godelle
- Arthur Ancien
- Tom Bonneau
- Kevin Simon

>[!warning] 
>Dans ce document le mot _"clochard"_ sera régulièrement utilisé, nous n'avons pas pour but de dénigrer quelconque classe sociale.

# Livrables
1. Version 1 : version jouable, (texte blanc), un niveau fonctionnel avec un type d'enemi. __09/06/23 (1er jalon)__
2. Version 2 : version visée, (<font color="green">texte en vert</font> et blanc)  __16/06/23 (2ème jalon)__
3. version 3 : version additionnelle, (<font color="blue">texte en bleu</font>,<font color="green"> vert </font>et blanc)

# Présentation générale

## Inspiration

Charclo Brosse sera un jeu inspiré du jeu Mario Bros. sorti sur arcade et conçu par Nintendo en 1983. Il sagit d'un jeu dans lequel le joueur fait évoluer un personnage nommé JumpMan dans des niveaux constitués de plateformes sur lesquelles le personnage peut se déplacer et il doit vaincres tout les enemis d'un niveau pour passer au suivant, pour ce faire il doit les immobiliser en frappant avec sa tête la platforme en dessous de l'énemi puis le touche avant qu'il ne se remette à bouger. Le but est de faire le plus de points possible en tuant des enemis, en ramassant des pièces et en terminant des niveaux.


## Présentation du jeu

 Charclo est le personnage principal du jeu, il sagit d'un clochard qui évolu dans des niveaux allant des égouts jusqu'à de beaux chateaux, ces niveaux sont constitués d'un écran comportant des plateformes et des énemis. Il se déplace également sur des plateformes et doit vaincre tous les énemis du niveau. Son objectif est aussi d'aquérir le plus de points <font color="green">et d'argent possible (pièces ou billets), plus il a d'argent, plus il sa tenue s'améliore changeant son environement (décor).</font> Au cours de sa progression le joueur gagne des points<font color="green">, les 10 meilleurs scores de tous les joueurs confondu seront sauvegardés, le but est donc d'obtenir le plus haut score.</font>
 <font color="blue">Deux joueurs peuvent aussi jouer en coopération.</font>
 

## Régles du jeu


Le joueur a trois vie en démarrant le jeu, il ne peut pas en gagner et si il n'en a plus la partie se termine.
Le niveau se termine quand le joueur a vaincu tous les monstres de celui-ci.
<font color="green">La partie s'arrête quand le joueur ne fini pas un niveau dans un temps imparti.</font>

Le joueur apparait au plus bas au milieu du niveau.
Le joueur a la possibilité de déplacer Charclo de gauche à droite et vice versa, de sauter et de se laisser tomber d'une plateforme à une plateforme plus basse. 
<font color="blue">La vitesse du joueur suit une acceleration, sa vitesse n'est pas instantanée.</font>
Si il franchit une bordure de l'écran il apparait de l'autre côté de l'écran en concervant sa vitesse de déplacement.
Si le joueur saute en dessous d'une plateforme, il soulève la partie de la plateforme touchée et la phase montante de son saut et stopée donc il retombe.
Si le joueur rentre en colision avec un enemi non vulnérable, il perd une vie, le personnage disparait avant de réapparaitre en haut au milieu du niveau si il lui reste des vie.
Si le joueur rentre en colision avec un enemi vulnérable, l'enemi est vaincu et disparait, <font color="green">le joueur gagne des points.</font>


Il y a un nombre défini d'enemis par niveaux, ceux-ci apparaissent au deux extrémités hautes du niveaux à intervalle régulier. 
Un enemi se déplace constament horizontalement dans la même direction, s'il il rentre en colision avec un autre enemi, il part dans la direction opposée.
Si un enemi arrive au bout d'une plateforme, il tombe sur celle du dessous.
Si un enemi arrive tout en bas a une extrémité, il disparait avant de réaparaitre en haut du même côté.
Quand le joueur soulève une plateforme, si un enemi est au dessus il devient immobile et vulnérable au joueur pendant 10 secondes

<font color="green">Le niveau comporte un nombre de pièces fixes que le joueur peut réccupérer en rentrant en colision avec.</font>
<font color="blue">Le thème du jeu et la tenue du personnage évolue en foncton de palliers de quantité pièces ammassées.</font><font color="green">
Le pallier etteint correspond à un multiplicateur de points.</font>

Tuer un énemi rapporte un certain nombre de points en fonction de celui-ci.
<font color="blue">Si il tue un enemi peu de temps après un autre un combo est apliqué, il agît en tant que multiplicateur de score.</font>
<font color="green">Le temps restant à la fin d'un niveau est convertie en points.</font>

<font color="green">Le niveau dispose d'un bloc spécial qui, quand il est frappé par le dessous, rends les énemis affichés vulnérable si il ne le sont pas et les rends invulnérable avant une attaque du joueur sinon .</font>


## Déroulement d'une partie

- Le joueur allume le jeu
- Il arrive sur le menu, <font color="green">il voit les highscore</font>
- il peut choisir entre jouer, <font color="green">afficher les règles</font> et quiter le jeu
- <font color="green">si il choisi d'afficher les règles, il est amené sur une nouvelle page où elles sont affiché et où il peut revenir au menu</font>
- s'il choisi de jouer, la partie démare
- Le joueur apparait en bas au milieu du premier niveau
- il attend que le premier énemi apparaisse,
- il doit tuer tout les énemis du niveau apparaissant au fur et à mesure en suivant les règles du jeu.
- <font color="green">il peut rammesser des pièces afin de débloquer des multiplicateurs de score</font>
- <font color="green">s'il parvient à tuer tous les énemis, il passe au niveau suivant, en aapraissant en bas au milieu de celui-ci, son score est mis à jour et ainsi de suite</font>
- dans le cas où il perd ses trois vie <font color="green">ou que le timer arrive à 0</font>, l'écran de game over apparait
- <font color="green">avec le score obtenue, le nombre d'énemis par type, le numéro du niveau atteint, le multiplicateur de fin, le nombre de combo et où il peut  entrer son pseudo si il est dans les 10 premiers high scores</font>
- il peut appuyer sur un bouton pour revenir au menu


# Spécification technique
## Interface utilisateur
croquis à faire

## Déplacement joueurs

vitesse du joueur : 4 blocs/s
<font color="blue">courbe d'accélération :  à spécifier</font>
saut : 6 blocs de hauteur 
touches directionnelle joueur 1:  droite : flèche droite, gauche : flèche gauche, saut : flèche du haut .
<font color="blue">touches directionnelle joueur 2:  droite : d, gauche : q, saut : z .</font>

## Collison

chaque objet  (enemis, joueurs, pièces, plateformes) est représenté par une hitbox (rectangle minimal autour de l'objet)
un objet est en colision avec un autre quand deux hitbox se touchent ou se chevauches
liste dess colisions :
- Charclo ou monstre et plateforme par le dessus : il marche sur la plateforme
- Charclo et plateforme par le dessous : il soulève le bloc au dessus (au milieu de sa hitbox) de lui en entrenant les deux autres à côté et entre en phase descendante de son saut
- Charclo et la platforme sur le coté : sa viesse en axe x est mise à 0
- Charclo et monstre : si l'enemi est en état invulnérable, Charclo perd une vie, si il est à l'état vunérable, il élimine l'énemi 
- monstre et monstre : les monstres repartent dans des sens opposés
- <font color="green">Charclo et Pièce : la pièce disparait, le compteur de pièce augmente de 1</font>
- <font color="green">Charclo et obstacle : charclo perd une vie</font>

## Système de points

## Enemis
Il y 1 <font color="green">3</font> ou <font color="blue">5</font> types d'énemis qui ont chacun leurs spécialité.

|                            | basique   | <font color="green">progressif</font>              | <font color="blue">sautant</font> | <font color="green">géant</font> | <font color="blue">freezer</font>                                  |
| -------------------------- | --------- | -------------------------------------------------- | --------------------------------- | -------------------------------- | ---------------------------------------- |
| vitesse**                  | 2 blocs/s | 2 ou 3 ou 4 blocs/s                                | 3 blocs/s                         | 2 blocs/s                        | 6 blocs/s                                |
| hauteur en bloc            | 1         | 1                                                  | 1                                 | 3                                | 1                                        |
| spécificité                | rien      | vitesse augmentée à chaque immobilisation (2x max) | saute tout les 3 blocs            |                                  | étourdi Charclo si colision et disparait |
| nombre de points rapportés | 100       | 200                                                | 300                               | 400                              | 500                                      |



## Niveaux
les niveaux sont composés de blocs (40 blocs de large et 22 de haut), chaque bloc fait 32 par 32px disposés différement selon le niveau.
Chaque bloc peut être une plateforme ou un obstacle.
Chaque niveau est défini par un fichier json contenant un dictionnaire avec :
-   le numéro du niveau (servant de vérification à l'ouverture du fichier)
-   le contenu du niveau sous forme d'un tableau à deux dimensions (40 par 22) d'entier où chaque entier correspond à un bloc (0 pour pas de bloc, 1 pour du sol, 2 pour une plateforme, ...)
-   la position du tuyau haut gauche sous forme d'un tableau (`[x,y]`)
-   la position du tuyau haut droite sous forme d'un tableau (`[x,y]`)
-   la position du tuyau bas gauche sous forme d'un tableau (`[x,y]`)
-   la position du tuyau bas droite sous forme d'un tableau (`[x,y]`)
-   les ennemis du niveau sous forme de dictionnaire (`{type : nombre, type :nombre, ...}`)

# Direction artistique
## Graphismes

<font color ="blue">Chaque thème du</font>  jeu est représenter dans un tileset (grande image) dans lequel seront représentés les éléments du jeux sous forme de pixel-art en blocs de 32px (plateforme, enemis, Charclo <font color="green">(avec animation), bloc spécial</font>, spawner).
Les plateformes seront constitués de blocs;
Les fonds est une image png appliquée en fond.

<font color="green">Les personnages seront animés : ils disposeront de plusieurs images dans le tileset mises à la suite.</font>

## Audio 
<font color="blue">Des bruitages seront associés avec certains évenements.</font>


