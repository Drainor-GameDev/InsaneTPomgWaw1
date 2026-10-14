D.1 Le additem prend un const Item& car & prend l'objet tel quel sans faire une copie innutile et const car c'est une contraine du cpp qui force à ne pas faire de modif sur un objet temporaire
D.2 Error: passing 'const Item' as 'this' argument discards qualifiers [-fpermissive]
   17 |     if (maxWeight < GetTotalWeight() + item.GetWeight())
   Le premier const assure que la valeur de retour ne doit pas être modifiée et le 2e assure que la fct ne modifiera pas l'objet qui l'appelle
D.3 Le programme alloue bien de la mémoire dynamiquement (le std::vector et les std::string), mais jamais manuellement avec new. Ces objets suivent le principe RAII : ils libèrent eux-mêmes leur mémoire dans leur destructeur. À la fin de main, inventory sort de portée, son destructeur est appelé, ce qui détruit le vecteur, qui détruit à son tour chaque Item et leurs chaînes. Toute la mémoire est donc libérée automatiquement.
D.4 Non il peut ne plus être valide car le vector peut se déplacer en cas de besoin de place donc le pointeur pourraît être une tout autre chose ce qui est assez problématique

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
