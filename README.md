TP1

D.1 Le additem prend un const Item& car & prend l'objet tel quel sans faire une copie innutile et const car c'est une contraine du cpp qui force à ne pas faire de modif sur un objet temporaire
D.2 Error: passing 'const Item' as 'this' argument discards qualifiers [-fpermissive]
   17 |     if (maxWeight < GetTotalWeight() + item.GetWeight())
   Le premier const assure que la valeur de retour ne doit pas être modifiée et le 2e assure que la fct ne modifiera pas l'objet qui l'appelle
D.3 Le programme alloue bien de la mémoire dynamiquement (le std::vector et les std::string), mais jamais manuellement avec new. Ces objets suivent le principe RAII : ils libèrent eux-mêmes leur mémoire dans leur destructeur. À la fin de main, inventory sort de portée, son destructeur est appelé, ce qui détruit le vecteur, qui détruit à son tour chaque Item et leurs chaînes. Toute la mémoire est donc libérée automatiquement.
D.4 Non il peut ne plus être valide car le vector peut se déplacer en cas de besoin de place donc le pointeur pourraît être une tout autre chose ce qui est assez problématique

TP2

A.1 
Monster
-- Walking Monster
   --Goblin (marche, attaque au corps à corps)
   --SkeletonArcher (marche, tire à l'arc)
   --Necromancer (marche, lance un sort)
-- FlyingMonster
   --Bat (vole, attaque au corps à corps)
   --Wraith (vole, lance un sort)
   --gargoyle (vole, tire à l'arc)
-- TeleportingMonster
   --diablotin (teleporte, attaque au corps à corps)

Le code se dupplique sur les types d'attaques
A.2
Il faut 9 pour 3 attaques et 3 déplacement
12 pour 3 attaques 4 déplacement
A.3
La 4e devrait pouvoir hériter de Walking et flying pour fonctionner
A.4
Le problème serait qu'il y aurait des conflicts d'héritage car flying et walking héritent de Monster

C.3
Aucune tout est là !!!!

D.1
Il ne faut que 7 classes
D.2
Dans un MMO l'héritage reste primordial pour la gestion des entités, avec la logique réseau. Un ennemi est une entité, un joueur est une entitée etc...
D.3
Monsters -> GameObject
IMovement, IAttack -> interfaces de components
Fly, Walk... -> Component
D.4
Le fly est possédé par le unique ptr du monster qui est possédé par le verctor du Simulation manager
Le fly est immédiatement détruit quand le unique ptr reçoit un nouvel oject 

TP3

B.5 On gagne en rapidité d'implémentation on peut ajouter des bindings sans avoir à faire un énorme switch case de plus en plus illisible
Il aurait fallu ajouter des if dans les cases
Et on gagne en lisibilité et séparation des tâches

C.1 On as besoin de la commande de l'input
C.2 Car on ne peut pas garder une stack trace des actions
Il faudrait créer un pile d'action avec les Command en objets créés et non réutilisés 