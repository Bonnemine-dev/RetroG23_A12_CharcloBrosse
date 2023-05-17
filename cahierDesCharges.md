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

# Présentation générale

## Inspiration

Charclo Brosse sera un jeu inspiré du jeu Mario Bros. sorti sur arcade et conçu par Nintendo en 1983. Il sagit d'un jeu dans lequel le joueur fait évoluer un personnage nommé JumpMan dans des niveaux constitués de plateformes sur lesquelles le personnage peut se déplacer et il doit vaincres tout les enemis d'un niveau pour passer au suivant, pour ce faire il doit les immobiliser en frappant avec sa tête la platforme en dessous de l'énemi puis le touche avant qu'il ne se remette à bouger. Le but est de faire le plus de points possible en tuant des enemis, en ramassant des pièces et en terminant des niveaux.

##  Présentation du jeu

 Charclo est le personnage principal du jeu, il sagit d'un clochard qui évolu dans des niveaux allant des égouts jusqu'à de beaux chateaux, ces niveaux sont constitués d'un écran comportant des plateformes et des énemis. Il se déplace également sur des plateformes et doit vaincre tous les énemis du niveau. Son objectif est aussi d'aquérir le plus d'argent possible (pièces ou billets), plus il a d'argent, plus il sa tenue s'améliore changeant son environement (décor). Au cours de sa progression le joueur gagne des points, les 10 meilleurs scores de tous les joueurs confondu seront sauvegardés, le but est donc d'obtenir le plus haut score.

## Régles du jeu


Le joueur a trois vie en démarrant le jeu, il ne peut pas en gagner et si il n'en a plus la partie se termine.
Le niveau se termine quand le joueur a vaincu tous les monstres de celui-ci.
La partie s'arrête quand le joueur ne fini pas un niveau dans un temps imparti.

Le joueur apparait au plus bas au milieu du niveau.
Le joueur a la possibilité de déplacer Charclo de gauche à droite et vice versa, de sauter et de se laisser tomber d'une plateforme à une plateforme plus basse. 
La vitesse du joueur suit une acceleration, sa vitesse n'est pas instantanée.
Si il franchit une bordure de l'écran il apparait de l'autre côté de l'écran en concervant sa vitesse de déplacement.
Si le joueur saute en dessous d'une plateforme, il soulève la partie de la plateforme touchée et la phase montante de son saut et stopée donc il retombe.
Si le joueur rentre en colision avec un enemi non vulnérable, il perd une vie, le personnage disparait avant de réapparaitre en haut au milieu du niveau.
Si le joueur rentre en colision avec un enemi vulnérable, l'enemi est vaincu et disparait, le joueur gagne des points.

Il y a un nombre défini d'enemis par niveaux, ceux-ci apparaissent au deux extrémités hautes du niveaux à intervalle régulier. 
Un enemi se déplace constament horizontalement dans la même direction, s'il il rentre en colision avec un autre enemi, il part dans la direction opposée.
Si un enemi arrive au bout d'une plateforme, il tombe sur celle du dessous.
Si un enemi arrive tout en bas a une extrémité, il disparait avant de réaparaitre en haut du même côté.
Quand le joueur soulève une plateforme, si un enemi est au dessus il devient immobile et vulnérable au joueur pendant $value secondes

La niveau comporte un nombre de pièces fixes que le joueur peut réccupérer en rentrant en colision avec.


## Déroulement d'une partie
# Spécification technique
## Interface utilisateur
## Déplacement mobs
## Déplacement joueurs
## Collison 
## Système de points
## Enemis
## Niveaux

# Direction artistique
## Graphismes
## Audio 

# Livrables
