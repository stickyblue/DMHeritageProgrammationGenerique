# Partie 1
## Q0

Le mot clé const est l'abréviation de constant. Comme son nom le suggère, il permet de dire au code que ces valeurs ne peuvent être changées. Cela est utile pour prévenir d'une mauvaise manipulation qui changerait la valeur de ces paramètres ou l'output d'une méthode par exemple.

## Q1

Le mot clé virtual est utilisé dans une classe abstraite pour que C++ sache quelle fonction appeler quand on utilise un pointeur vers la classe de base. Cela sert notament à déterminer le vrai type de l'objet que l'on utilise (dynamic dispatch).

Le destructeur doit également être virtuel, sous peine de créer des fuites mémoires. Imaginons que l'on utilise une classe mère et une fille dérivée de mère. Si l'on delete un objet de classe mère, le destructeur de la fille ne sera pas appelé. (tiré du cours: "Si une classe propose une liaison dynamique, son destructeur doit obligatoirement être virtuel")
)

## Q3

Un unique pointer ici permet de la certitude que l'on accèdera pas aux données du tableau précédent après changement de taille. En effet, sans celui-ci, deux pointers pourraient pointer vers l'ancien tableau, qui une fois désalloué en mémoire, donnerai accès à des emplacements mémoire normalement non alloués (car on ne supprimerai qu'un pointer vers ce tableau).

## Q6

Utiliser le passage d’un paramètre de type T par référence constante est préférable dans la méthode push(), plutôt que par copie car la copie nécessite un coût, de passer par une valeur intermédiaire pour copier/coller la valeur, puis de la détruire. Passer une référence ne passe que l'adresse sans déplacer l'objet, et le const rend la valeur identique, pas de risque de modifications non voulues.

## Q8

On définit l'opérateur [] car de cette manière, on garde la syntaxe "liste" déjà présente (on pourrait rajouter que cela est plus ergonomique)
L'utilité de const reste la même que la Q6, cela évite une quelconque modification, et la référence évite de devoir copier l'objet.

## Q10

Sans constructeur de copie, les copies traditionnelles ne copieraient alors que le pointer, on aurait alors deux pointer qui pointent vers un même tableau, ce qui crasherai à la compilation, car on utilise des unique pointers.

# Partie 2

## Q11

La problème d'utiliser des unique pointers est que ceux-ci garantissent un accès unique à la ressource demandée, ce qui rend la copie de la priority queue impossible directement. A moins d'implémenter notre propre structure de copie profonde, impossible de copier notre queue. Accéder aux valeurs pour la copie devra également être gérée de manière minucieuse pour éviter des fuites de mémoire (normalement non car on travaille avec des unique pointers, mais l'opérateur de copie et d'affectations n'étant pas gardé pour une classe contenant des unique pointers, il faudrait passer par des shared pointers [Source à laquelle je me suis référé pour la réponse](https://stackoverflow.com/questions/16030081/copy-constructor-for-a-class-with-unique-ptr)).

## Q12

Une contraite est que les types d'éléments utilisés doivent avoir une relation de priorité, les strings par exemple ne peuvent pas être évalués directement (Bien sûr, on peu les traduire en entier et comparer leur équivalents en entier, on pourrait comparer la longueur des strings également, on pourrait les hacher, ne récupérer que les chiffres du hash et les additionner, ect.) Il faut donc réussir à définir une relation de comparaison (de priorité) pour les types n'en ayant pas de défini par défaut.


## Q13

L'utilisation d'un vector permet une allocation dynamique de la mémoire (car la taille du vector est modifiée automatiquement au besoin). Cela peret également de gérer les copies, car l'implémentation de la copie a été implémentée dans la classe Vector. Un unique pointer réimplémenterai les problèmes énonés en question 11.

## Q18

La fonction push() commence par push un élément dans un Vector. Dans le pire des cas (le vector double de taille), on aurait le nombre d'éléments de l'arbre qui seraient déplacés, soit `(2^n) - 1` éléments (n étant le nombre d'**étages** de l'arbre). On considérera la taille de l'ancien vector, car seul l'élemant rajouté appartient au nouvel étage.
On obtient donc une complexité algorithmique de `O(2^n)`.

La réorganisation via shiftUp n'utilise qu'une opération swap entre deux étages, soit dans le pire des cas n opérations correspondant à chacun des étages. On a donc une complexité algorithmique de `O(n)`.

La complexité totale de push() serait alors `O(2^n + n)`.

De même pour la fonction pop().
D'une part on a le déplacement du dernier élément au premier, qui dans le pire des cas réduit la taille du Vector de moitié soit `O(2^(n-1))` (n étant ici le nombre d'étage avant d'avoir retiré le dernier éléments de l'étage précédent).
D'autre part, le shiftDown swap deux éléments entre deux étages, soit une opération par étage `O(n)`.
La complexité totale de pop() est donc `O(2^n + n)`.
