# Ajouts

## Throw et try/catch

Tout comme en Java, le C++ permet l'utilisation de try/catch. Je me suis donc permis de mettre des throws là où certaines vérifications de taille étaient nécessaire. Ces throws sont testé dans le fichier main par l'intermédiaire d'un try/catch pour la fonction get_i, devant recevoir un out_of_range.

## Rétrécissement du vector dans la méthode adjust

Bien que non précisé dans l'énoncé, j'ai rajouter la possibilité de diviser par deux la taille d'un vector lorsque cela était possible, ce qui réduit la quantité de mémoire allouée.

## Supression de la valeur pop

L'énoncé demande que la méthode pop renvoie la valeur en fin de vecteur, mais ne précise pas de la supprimer par la suite, je me suis donc permis de le faire, ce qui aurait plus de sens vu que la fonction get_i ferait dejà la travail sinon.

## Fonction des diagrammes UML

Bien que non demandées dans l'énoncé, j'ai implémenté les méthodes non demandées dans l'énoncé, mais présentes dans le diagramme UML. Je ne les ai cependant pas utilisées vu que je ne les ai implémentées qu'à la fin du projet.


# Modifications

## Type renvoyé par pop

La fonction pop devait renvoyer des références à nos valeurs, ce qui me parrait étrange, car une fois supprimée, la valeur n'est normalement plus utilisable (surtout dans le cas où un vecteur voit sa taille divisée par 2). De même, une copie dans une variable temporaire de la valeur du noeud ne peut être réalisée, car la référence sera remplacée par la nouvelle valeur, et renvoyer une référence vers une variable temporaire n'est pas acceptable.

