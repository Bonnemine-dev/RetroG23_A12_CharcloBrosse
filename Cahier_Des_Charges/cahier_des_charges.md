# _Charclo Brosse_
___
# Introduction

Ce cahier des charges est destiné à la conception du jeu _Charclo Brosse_. Il est conçu par le groupe A12, _"Va falloir Brosser"_ : 
- Melvin Warnet
- Erwan Godelle
- Arthur Ancien
- Tom Bonneau
- Kevin Simon

>[!warning] 
>Dans ce document des mots à forte connotation discriminante, comme _"clochard"_ seront régulièrement employé, **nous n'avons pour but de dénigrer quelconque classe sociale** ceux-ci sont utilisés car ils font partis même de l'esprit du jeu.

>[!warning] 
>Dans ce document figure **des valeurs numériques** vouées à de potentiels **modifications** lors de la phase de conception du jeu pour **améliorer l'experience utilisateur**.

# Livrables

1. Le texte sans couleur : Constitue **la version 1 du jeu**, doit être livré le **09/06/23**. C'est **une version jouable**, sans graphisme, se déplacer, un type d'ennemi, vies, points. _(voir annexe)_

3. <font color="green">Le texte en vert</font> + sans couleur : Constitue **la version 2 du jeu**, doit être livré le **16/06/23**. C'est **la version visée**, avec graphismes, animations, plusieurs niveaux, argent, multiplicateurs de points, temps imparti, highscores, bloc POW, 3 types d'ennemis, obstacles, règles du jeu, pause. _(voir annexe)_

4. <font color="blue">Le texte en bleu</font> + <font color="green">vert</font> + sans couleur : Constitue **la version 3 du jeu**, ne doit **pas obligatoirement être livré**. C'est **une version additionnelle**, plus de niveaux, plusieurs thèmes, multijoueur, accélération, combos, 5 types d'ennemis, sound effect. _(voir annexe)_

# Présentation générale

## Inspiration

Charclo Brosse est un jeu **inspiré** du jeu _Mario Bros_ sorti sur arcade et conçu par _Nintendo_ en 1983. Il sagit d'un jeu dans lequel **le joueur fait évoluer un personnage** nommé JumpMan dans des niveaux constitués **de plateformes, formées par des blocs, sur plusieurs hauteurs** sur lesquelles le personnage peut se déplacer. Il doit vaincre **tout les ennemis d'un niveau** pour passer au suivant. Pour vaincre un ennemi il doit **l'immobiliser** en frappant avec sa tête le bloc en dessous de l'ennemi, puis il **le toucher** avant que l'ennemi ne se **remette à bouger**. Le but est d'obtenir **le plus de points** en tuant des ennemis, en ramassant des pièces et en terminant des niveaux. _(voir annexes)_


## Présentation du jeu

 L'écran du jeu est fixe. Charclo est le personnage principal du jeu, le joueur peut **le controler** et le faire évoluer dans des niveaux. Ces niveaux sont constitués **de plateformes, composés de blocs**. L'objectif du joueur est de déplacer Charclo <font color="green">et de gagner le plus de points possible en terminant des niveaux le plus rapidement possible</font> en tuant tous les ennemis. <font color="green">Il a la possibilité de ramasser des pièces et des billets qui lui permettent de débloquer automatiquement des multiplicateurs de points</font><font color="blue">, ces multiplicateurs s'accompagnent de changement de thème (environnement), plus il récupère d'argent plus le thème sera luxueux/extravagant. Il existe un mode coopération dans lequel deux joueurs peuvent déplacer deux Charclo en même temps dans le même niveau, leur objectif reste d'obtenir le meilleur score.</font><font color="green"> Un tableau des highscores enregistre les 10 meilleurs scores <font color="blue">de chaque mode de jeu</font> et le nom des joueurs les aillant réalisés.</font>
 

# Régles du jeu

## La partie

- Le joueur a **trois vie en démarrant le jeu**, il peut en perdre mais **pas en gagner**.
- <font color="green">Un niveau se termine quand le joueur à vaincu tous les ennemis de ce niveau.</font>
- La partie **s'arrète** quand le joueur perd ces trois vies <font color="green">ou quand le joueur ne fini pas un niveau dans le temps imparti.</font>
- Lorsque la partie s'arrète, un écran de GameOver s'affiche<font color="green">, il s'accompagne d'un espace pour entrer un pseudonyme si le score atteint fait partie des 10 meilleurs scores, du nombre d'ennemi battus par type, du score, du numéro du niveau atteint, du multiplicateur atteint</font><font color="blue">, du nombre de combos.</font>
- <font color="green">Le joueur à la possibilité de mettre sa partie en pause.</font>

## Charclo

- Au début d'un niveau, Charclo apparait **au millieu, au plus bas du niveau**.
- Quand Charclo perd une vie, il réapparait **au millieu, au plus haut du niveau**, sur une plateforme temporaire.
- Le joueur à la possibilité de **déplacer** Charclo de gauche à droite et de droite à gauche, de sauter et de se laisser tomber d'une plateforme supérieur à une plateforme inférieur. 
- L'accélération de Charclo est **instantané**. 
- <font color="blue">L'accélération de Charclo n'est pas instantanée, elle suit une courbe de progression exponentielle.</font>
- Quand Charclo franchit **une bordure de l'écran de jeu**, il apparait de l'autre coté de l'écran en concervant sa vitesse de déplacement.
- Quand Charclo saute en se trouvant en dessous d'une plateforme, lorsque sa tête touche les blocs se trouvant au dessus de lui, **ces blocs se soulèvent**. La phase montante de son saut est alors **stoppé** mais il concerve sa vitesse.
- <font color="green">Quand Charclo rentre en colision avec un obstacle, il perd une vie et disparait.</font>
- Quand Charclo rentre en **colision** avec un ennemi dans un état invulnérable, il **perd une vie et disparait**.
- Quand Charclo rentre en **colision** avec un ennemi dans un état vulnérable, l'ennemi **est vaincu et disparait**.
- <font color="green">Lorsque Charclo rentre en colision par le dessous avec un bloc POW, tous les ennemis affichés changent d'état, les invulnérables passent en vulnérable et les vulnérables passent en invulnérable.</font>

## Les ennemis

- Il y a 1, <font color="green">3</font> ou <font color="blue">5</font> **types** d'ennemi.
- Il y a **un nombre défini** d'ennemis <font color="green">par niveaux</font><font color="blue">, sauf dans le dernier niveau où les ennemis apparaissent à l'infini.</font>
- Les ennemis **apparaisent à intervalles régulier** aux deux extrémités hautes d'un niveau via des "spawner".
- Un ennemi se déplace constamment **horizontalement dans la même direction**.
- Quand deux ennemis rentrent en **colision**, peu importe leurs états, les deux partent dans **la direction opposée**.
- Lorsqu'un ennemi arrive au bout d'une plateforme, il **tombe naturellement** sur celle du dessous.
- Lorsqu'un ennemi franchit **une bordure de l'écran de jeu**, il apparait de l'autre coté de l'écran en concervant sa vitesse de déplacement et sa direction.
- Lorsqu'un ennemi arrive **tout en bas à une extremité de l'écran de jeu** au niveau d'un "dispawner", il **disparait et réaparrait** en haut au niveau du "spawner" du même côté.
- Quand un ennemi se trouve sur **un bloc soulevé** par un joueur, il est **immobilisé** et passe dans un état vulnérable pendant un certain temps (10s) avant de se remettre à bouger.

## Les niveaux

- Il existe **un nombre défini** de niveau.
- <font color="green">Chaque niveau est différent.</font>
- **Aux deux extrémités hautes** d'un niveau se trouvent des "spawner", ce sont de ces spawners qu'**apparaissent les ennemis**.
- **Aux deux extrémités basses** d'un niveau se trouvent des "dispawner", ce sont dans ces dispawners que **disparaissent les ennemis**.
- <font color="green">Certains niveaux possèdent un bloc POW, celui-ci se trouve sur au millieu, à la hauteur de la première plateforme.</font>
- <font color="green">Certains niveaux possèdent des obstables, ceux-ci sont placé à des endroits définis.</font>

## Les points

- Le joueur peut gagner des points en **tuant des ennemis**<font color="green">, chaque type d'ennemi correspond à un nombre de points.</font>
- <font color="green">Le joueur peut gagner des points en terminant des niveaux.</font>
- <font color="green">Le temps restant à la fin de chaque niveau est converti en points.</font>
- <font color="blue">Le joueur peut réaliser des combos en tuant des ennemis rapidement les un à la suite des autres, ces combos sont des multiplicateurs de points.</font>
- <font color="green">Le joueur peut obtenir des multiplicateurs de points en ramassant de l'argent.</font>

## L'argent

- <font color="green">Le joueur peut ramasser de l'argent en rentrant un colision avec.</font>
- <font color="green">Il y a un nombre de fini de pièces et de billets dans chaque niveau.</font>
- <font color="green">Les billets rapportent plus d'argent que les pièces.</font>
- <font color="green">Il y a des pallier d'argent qui quand ils sont atteints débloquent des multiplicateurs de points pour le joueur</font><font color="blue">, cela débloque aussi un nouveau thème, Charclo est donc dans un nouvel environnement avec de nouveaux vêtement.</font>

## Coopération

- <font color="blue">Lorsque les deux joueurs rentre en colision, leurs courses sont stoppées.</font>
- <font color="blue">Lorsque l'un des deux joueurs n'a plus de vie, son personnage ne réapparait pas mais l'autre joueur peut continuer de jouer.</font>


# Déroulement d'une partie

- Le joueur lance le jeu.
- Le menu est affiché<font color="green">, le joueur voit les highscores.</font>
- Le joueur peut appuyer sur **trois bouton** : lancer une partie<font color="green">, afficher les règles</font>, quitter le jeu.
- Si il appuie sur le bouton "quitter le jeu" **le jeu se ferme**.
- <font color="green">Si il appuie sur le bouton "afficher les règles", la page des règles du jeu est affichée ainsi qu'un bouton pour retourner au menu.</font>
- Si il appuie sur le bouton "lancer une partie"<font color="blue">, il choisi un ou deux joueurs, </font>**une partie se lance**.
- Le joueur apparait en bas au millieu du **premier niveau**.
- Il attend que **les ennemis apparaisent**.
- <font color="green">Il peut ramasser de l'argent afin de débloquer des multiplicateurs de points.</font>
- <font color="green">Il peut appuyer sur pause puis reprendre sa partie.</font>
- Il doit tuer **tous les ennemis** en suivant les règles du jeu.
- <font color="green">Si il tue tous les ennemis du niveau, il passe au niveau supplémentaire et apparait en bas au millieu de celui-ci.</font>
- <font color="green">Il peut ramasser de l'argent afin de débloquer des multiplicateurs de points.</font>
- Si il perd **toutes ses vies** <font color="green">ou qu'il ne termine pas un niveau dans le temps imparti,</font> il **perd la partie**.
- L'écran de GameOver est affiché, il peut retourner au menu.


# Spécifications techniques

## Interface utilisateur

Dans **le menu** <font color="green">et la section pause</font> _(voir annexe)_ le joueur peut utiliser les touches : 
   - Flèche du haut : passe au bouton **du dessus**.
   - Flèche du bas : passe au bouton **du dessous**.
   - Entrée : **appuie** sur le bouton.
   - Clic gauche : **appuie** sur le bouton.

**En partie** le joueur peut utiliser les touches :
   - Flèche de droite : Déplacement de Charclo (Joueur1) **vers la droite**.
   - Flèche de gauche : Déplacement de Charclo (Joueur1) **vers la gauche**.
   - Flèche du haut : **Saut** de Charclo (Joueur1).
   - <font color="green">Echap : Mettre la partie en pause.</font>
   - <font color="blue">D : Déplacement de Charclo (Joueur2) vers la droite.</font>
   - <font color="blue">Q: Déplacement de Charclo (Joueur2) vers la gauche.</font>
   - <font color="blue">Z : Saut de Charclo (Joueur2).</font>

## Déplacement joueur

Le joueur peut **déplacer** Charclo vers la droite, la gauche ou le faire sauter en appuyant sur les touches correpsondantes :

   - Lorsque le joueur appuie sur la touche pour **aller** à droite ou celle pour aller à gauche la vitesse de Charclo passe **instantanément** à 4 blocs/s (128px/s) dans la **direction correspondante**.
   - <font color="blue">Lorsque le joueur appuie sur la touche pour aller à droite ou celle pour aller à gauche la vitesse de Charclo passe progressivement de 0 à 4 blocs/s (128px/s) dans la direction correspondante. (équation d'accélération à définir)</font>
   - Lorsque le joueur appuie sur la touche pour **sauter**, sa position en Y va augmenter à une vitesse **instantanée** de 10 blocs/s (320px/s). Si il rentre en **colision** avec le dessous d'une plateforme ou d'un bloc POW ou qu'il atteint la hauteur maximal qui est de 6 blocs de hauteur (192px) son saut **est stoppé** et il retombe, sa position en Y va diminuer à une vitesse **instantanée** de 10 blocs/s (320px/s) jusqu'a rentrer en **colision** avec le haut d'une plateforme.
   - <font color="blue">Lorsque le joueur appuie sur la touche pour sauter, sa position en Y va augmenter à une vitesse qui ira progressivement de 0 à 10 blocs/s (320px/s). Si il rentre en colision avec le dessous ou d'une plateforme ou d'un bloc POW ou qu'il atteint la hauteur maximal qui est de 6 blocs de hauteur (192px) son saut est stoppé et il retombe, sa position en Y va diminuer à une vitesse qui ira progressivement de 0 à 10 blocs/s (320px/s) jusqu'à rentrer en colision avec le haut d'une plateforme. (équation d'accélération à définir)</font>
   - Charclo, une fois une phase de **saut engagée**, ne peut plus changer **de vitesse** ou **de direction**. Donc dès l'instant où Charclo n'est plus en colision avec le sol, sa vitesse et sa direction **sont figées**.
   - Si dans son saut Charclo entre en **collision** avec le côté d'une plateforme, il concerve **sa vitesse** mais il ne peut pas avancé tant qu'il est en **colision** avec le côté de la plateforme.
   - Lorsque Charclo n'est plus en **colision** avec le dessus d'une plateforme, donc qu'**il tombe** d'une plateforme, sa position en Y va diminuer à une vitesse **instantanée** de 10 blocs/s (320px/s) jusqu'a rentrer en **colision** avec une plateforme inférieur.
   - <font color="blue">Lorsque Charclo n'est plus en colision avec le dessus d'une plateforme, donc qu'il tombe d'une plateforme, sa position en Y va diminuer à une vitesse instantanée de 10 blocs/s (320px/s) jusqu'à rentrer en colision avec une plateforme inférieur.</font>

## HitBox

**Chaque objet** du jeu (joueur, ennemi, bloc, argent, bloc POW, obtacle, spawer, dispawner, plateforme temporaire) sont représenté par **une image** (visible) et d'**une HitBox** (invisible). La HitBox est **la zone "physique"** de l'objet, tous ce qui est dans cette zone **est l'objet**, alors que l'image est seulement **la partie visuelle** de l'objet, la HitBox et l'image ne font donc pas forcément **la même taille** _(voir annexe)_. Ainsi chaque objet possède une taille de HitBox **définie** :

   - Charclo : 32x64 px
   - Ennemi standard : 32x32 px
   - <font color="green">Ennemi accélérateur : 32x32px</font>
   - <font color="green">Ennemi géant : 32x96px</font>
   - <font color="blue">Ennemi freezer : 32x32px</font>
   - <font color="blue">Ennemi sautant : 32x32px</font>
   - <font color="green">Piece : 32x32px</font>
   - <font color="green">Billet : 32x32px</font>
   - Bloc : 32x32px
   - <font color="green">Bloc POW : 32x32px</font>
   - <font color="green">Obstacle : 32x32px</font>
   - Spawer : 32x96px
   - Dispawner : 32x96px
   - Plateforme temporaire : 64x32px

## Collision

Certains de ces objets peuvent **se mouvoir** et donc rentrer **en collision** avec d'autre objet. Il y a une collision entre deux objet lorsque la HitBox d'un des objet **rencontre** celle de l'autre objet **(touché ou chevauché)**. Il n'y a **pas toujours** une collision lorsque les HitBox de deux objets se rencontrent, il faut donc répertorier **toutes les collisions** qui peuvent avoir lieu et auxquelles ont souhaite **associer un évenement** :
   - Charclo et dessus d'un bloc -> Charclo **se déplace** sur le bloc.
   - Le centre du haut de Charclo et le dessous d'un bloc -> Le saut **est stoppé** et le bloc et les un ou deux blocs qui l'entourent **se soulèvent** de 16px puis reprennent leur position au bout de 0.5s. 
   - Charclo et le côté d'un bloc -> Le déplacement horizontale de Charclo est **temporairement stoppé**.
   - Charclo et monstre dans l'état invulnérable -> Charclo **perd** une vie.
   - Charclo et monstre dans l'état vulnérable -> L'ennemi **est définitivement vaincu**.
   - Charclo et un spawner/dispawer -> Rien ne se passe mais Charclo est affiché au **premier plan**.
   - Charlo et le bord de l'écran -> Charclo **disparait et apparait** de l'autre coté.
   - Un ennemi et dessus d'un bloc -> L'ennemi **se déplace** sur le bloc.
   - Un ennemi et un bloc dans l'état soulevé -> L'ennemi est **immobilisé** et passe à l'**état vulnérable**.
   - Un ennemi et un dispawner -> L'ennemi **disparait**.
   - Un ennemi de côté et un ennemi de côté -> Les deux ennemis repartent dans **la direction opposée**.
   - Un ennemi et le bord de l'écran -> L'ennemi **disparait et apparait** de l'autre coté.
   - Un ennemi et le coté d'une plateforme -> L'ennemi repare dans **la direction opposé**.
   - <font color="green">Un ennemi et une pièce/billet -> Rien ne se passe mais l'ennemi est affiché au premier plan.</font>
   - <font color="green">Un ennemi et un obstacle -> Rien ne se passe mais l'ennemi est affiché en premier plan.</font>
   - <font color="green">Charclo et le dessous d'un bloc POW -> Le bloc POW est activé et disparait.</font>
   - <font color="green">Charclo et le côté d'un bloc POW -> Le déplacement horizontale de Charclo est temporairement stoppé.</font>
   - <font color="green">Charclo et le dessus d'un bloc POW -> Charclo se déplace sur le bloc.</font>
   - <font color="green">Charclo et une pièce/billet -> Charclo ramasse la pièce/billet.</font>
   - <font color="green">Charclo et un obstacle -> Charclo perd une vie.</font>
   - <font color="green">Un ennemi et le côté d'un bloc POW -> L'ennemi repare dans la direction opposé.</font>
   - <font color="green">Un ennemi et le dessus d'un bloc POW -> L'ennemi se déplace sur sur le bloc.</font>
   - <font color="blue">Charclo1 et Charclo2 -> Les deux sont stoppés.</font>
  
Il y a aussi des évenements qui doivent être mis en place lorsqu'**une collision n'est plus en cours** :
   - Charclo et le dessus d'un bloc (hors saut) -> Charclo **tombe naturellement**.
   - Un ennemi et le dessus d'un bloc -> L'ennemi **tombe naturellement**.

## Argent

<font color="green">L'argent est représenté sous la forme de pièces ou de billets, que le joueur peut ramasser dans les niveaux :</font>
   - <font color="green">Les pièces rouges rapportent 0,10.</font>
   - <font color="green">Les pièces jaunes rapportent 1.</font>
   - <font color="green">Les billets rapportent 5.</font>

<font color="green">Récuperer de l'argent permet d'atteindre des paliers et de débloquer des multiplicateurs de points et des thèmes :</font>
   - <font color="green">Le premier palier est débloqué à 10.</font>
   - <font color="green">Le deuxième palier est débloqué à 25.</font>
   - <font color="green">Le troisème palier est débloqué à 50.</font>
   - <font color="green">Le quatrième palier est débloqué à 100.</font>
   - <font color="green">...</font>

## Points

L'**objectif du joueur** est d'obtenir **le plus de points** possibles, il y a plusieurs choses qui rapportent des points :
   - **Vaincre des ennemis** rapporte 100, 200, 300, 400 ou 500 points.
   - <font color="green">Finir un niveau rapporte 100 fois le numéro du niveau.</font>
   - <font color="green">Le temps restant à la fin de chaque niveau est converti en points.</font>
   - Tous les points gagnées sont **multipliés** par le multiplicateur de point.
   - <font color="green">Chaque palier d'argent atteint multiplie par 3 le multiplicateur de point.</font>
   - <font color="blue">Quand il y a un combo le multiplicateur de point et multiplié temporairement par le nombre d'ennemi concernés par le combo.</font> 


## Ennemis

Il existe 1<font color="green">, 3</font><font color="blue">, ou 5</font> **types** d'ennemis différent et ils ont chacun **leurs spécificités** :
   - Ennemi standard : Il se déplace **horizontalement** dans la direction opposée à son point d'apparition à **une vitesse** de 2 blocs/s (64px/s).
   - <font color="green">Ennemi accélérateur : Il se déplace horizontalement dans la direction opposée à son point d'apparition à une vitesse de 2 blocs/s (64px/s). Lorsqu'il se relève après avoir été immobilisé, sa vitesse passe à 3 blocs/s (96px/s), puis si il se relève à nouveau après avoir été à nouveau immobilisé, sa vitesse passe à 4 blocs/s (128px/s).</font>
   - <font color="blue">Ennemi sautant : Il se déplace horizontalement dans la direction opposée à son point d'apparition à une vitesse de 3 blocs/s (96px/s). Il saute à 4 blocs de haut tous les 3 blocs parcourus.</font>
   - <font color="green">Ennemi géant : Il se déplace horizontalement dans la direction opposée à son point d'apparition à une vitesse de 2 blocs/s (64px/s). Mais il 3 fois plus grand que les autres ennemis, ainsi il est impossible de sauté au dessus.</font>
   - <font color="blue">Ennemi freezer : Il se déplace horizontalement dans la direction opposée à son point d'apparition à une vitesse de 6 blocs/s (192px/s). Il se déplace très rapidement et lorsqu'il rentre en collision avec Charclo, il disparait et Charclo est immobilisé pendant 2s.</font>

|                            | Standard   | <font color="green">Accélérateur</font> | <font color="blue">Sautant</font> | <font color="green">Géant</font> | <font color="blue">Freezer</font>                                  |
| -------------------------- | --------- | -------------------------------------------------- | --------------------------------- | -------------------------------- | ---------------------------------------- |
| Vitesse           | 2 blocs/s | <font color="green">2, 3 ou 4 blocs/s</font> |<font color="blue"> 3 blocs/s  </font>                       | <font color="green">2 blocs/s</font>                        | <font color="blue">6 blocs/s</font>                                |
| Taille            | 1 bloc | <font color="green">1 bloc</font> | <font color="blue">1 bloc</font>| <font color="green">3  blocs</font> | <font color="blue">1 bloc </font>  |
| Spécificité                | Aucune      | <font color="green">Vitesse augmentée à chaque immobilisation (2x max).</font> | <font color="blue">Saute tout les 3 blocs parcourus.</font>         | <font color="green">Bien plus grand que les autres.</font> | <font color="blue">Etourdi Charclo si colision et disparait.</font> |
| Points | 100       | <font color="green">200</font>                                                | <font color="blue">300</font>                               | <font color="green">400</font>                              | <font color="blue">500</font>                                      |


## Niveaux

Un niveau occupe **tout l'écran de jeu**, il est quadrillé comme un tableau de **40 colonnes et 22 lignes** de blocs de 32x32px. Ces blocs sont disposé d'une manière **différente** dans chaque niveau, ils constituent **des plateformes** sur lesquelles Charclo et les ennemis peuvent **se déplacer**. _(voir annexe)_

Le nombre d'ennemi par type<font color="green">, le nombre et la position des pièces/billets</font>, le temps limite et la position des blocs sont propres à chaque niveau et enregistré dans un **fichier .json** sous la forme d'**un dictionnaire** contenant :
   - Le numéro du niveau (servant de vérification à l'ouverture du fichier).
   - Le contenu du niveau sous forme d'un tableau à deux dimensions (40x22) d'entier où chaque entier correspond à un bloc (0 pour pas de bloc, 1 pour du sol, 2 pour une plateforme, 3 pour un obstacle, ...).
   - Les ennemis du niveau sous forme de dictionnaire (`{type : nombre, type :nombre, ...}`).
   - Une liste de liste des pièces et billets (`[[type, x, y], [type, x, y], ...]` où type est un  entier correspondant à pièce ou billet) 


# Graphismes

## Direction artistique

Le jeu est dans le style **rétro/arcade**. Le personnage principal Charclo est **un clochard** qui ne possède qu'**une brosse** pour frapper les ennemis qui l'attaque. Il vit dans **les égouts** au millieu **des rats et des pigeons**. Il est poursuivi par **des policiers** car il dort dans des endroits interdits. Il récupère de **l'argent** qu'il trouve dans les niveaux et qui lui permet de **s'habiller et de voyager**.

## Thèmes

<font color="blue">Lorsque l'on atteint un palier d'argent le thème change, ce qui signifie que Charclo, les blocs, les ennemis, les spawners/dispawner, l'image de fond changent d'apparence. Si le palier est atteint au millieu d'un niveau, le thème changera au niveau suivant. Les thèmes restent à définir.</font>

## Animation 

<font color="blue">Certains objets se déplacent, pour rendre ce déplacement plus esthétique il est accompagné d'une animation. L'animation est constitué de quelques images (pas plus de 5) qui donne l'impression de mouvement. Les objets suivant doivent être animés :</font>
   - <font color="blue">Charclo qui saute et se déplace.</font>
   - <font color="blue">Les ennemis qui sont immobilisé.</font>
   - <font color="blue">Les ennemis qui se déplace.</font>
   - <font color="blue">Charclo quand il élimine un ennemi, coup de brosse.</font>
   - <font color="blue">Les pièces et billets (surbrillance)</font>

## Stockage 

Tous **les assets graphiques** d'un thème sont stockés dans **un tileset**. C'est une grande image au **format .png** qui est constitué de **toutes les images** du thème correspondant, lorsque l'on a besoin d'un des assets on ne prend **que la partie du tileset qui nous interesse**. _(voir annexe)_

## Audio 

<font color="blue">Une musique de fond et des bruitages seront associés avec certains évenements.</font>

# Annexes

## Inspirations

Vidéo d'un GamePlay de _Mario Bros_
[Gameplay _Mario Bros_](https://www.youtube.com/watch?v=JHlUEJXaxfY)

Un niveau du jeu _Mario Bros_.
![Image d'un niveau dans _Mario Bros_](../img_cahierDesCharges/inspiration_1.png)

## Versions

Maquette de la V1.

Maquette de la V2.

Maquette de la V3.


## Menu et pause

Croquis du menu du jeu.
![Image d'un croquis du menu](../img_cahierDesCharges/croquis_menu.png)

Croquis de la section pause du jeu.
![Image du croquis de la section pause](../img_cahierDesCharges/croquis_pause.png)


## Une HitBox

Un exemple de HitBox, ici la zone en vert.
![Image d'une HitBox](../img_cahierDesCharges/hitbox.png)



## Composition d'un niveau

Les différents objets présents dans un niveau
![Image des objets dans un niveau](../img_cahierDesCharges/objets.png)
## Un tileset

Un exemple de tileset.
![Image d'un tileset](../img_cahierDesCharges/tileset.png)






