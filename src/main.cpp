#include "../head/Vector.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Test de l'implémentation de Vector" << endl;
    Vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push(i);
        cout << "Après push(" << i << "): ";
        v.print();
    }

    cout << "Pas d'erreur lors des push, donc la capacité dynamique fonctionne (et les push aussi pour le coup)." << endl;
    cout << "Taille actuelle du Vector: " << v.size() << endl;
    cout << "La taille doit être 10." << endl;
    cout << "Test de la méthode pop(): " << v.pop() << endl;
    cout << "La valeur ressortie doit être 9." << endl;
    cout << "Contenu du Vector après un pop: ";
    v.print();
    cout << "Taille actuelle du Vector: " << v.size() << endl;
    cout << "La taille doit être 9." << endl;

    Vector<string> vs;

    cout << "Test de Vector avec des strings" << endl;
    cout << "Test fonction isEmpty() sur un Vector vide: " << (vs.isEmpty() ? "Vrai" : "Faux") << endl;
    cout << "Ajout de quelques strings." << endl;
    vs.push("Bonjour");
    vs.push("le");
    vs.push("monde");
    cout << "Contenu du Vector de strings: ";
    vs.print();
    cout << "Test fonction isEmpty() sur un Vector non vide: " << (vs.isEmpty() ? "Vrai" : "Faux") << endl;
    cout << "Test de la méthode pop(): " << vs.pop() << endl;
    cout << "La valeur ressortie doit être 'monde'." << endl;
    cout << "Contenu du Vector après un pop: ";
    vs.print();
    cout << "Test opérateur []: vs[0] = " << vs[0] << endl;
    cout << "La valeur ressortie doit être 'Bonjour'." << endl;
    cout << "Test de la méthode find(): index de 'le' = " << vs.find("le") << endl;
    cout << "La valeur ressortie doit être 1." << endl;

    cout << "Test de la méthode find() pour un élément non présent: index de 'C++' = " << vs.find("C++") << endl;
    cout << "La valeur ressortie doit être -1." << endl;

    cout << "Test de la méthode Contains(): 'Bonjour' est-il dans le Vector? " << (vs.contains("Bonjour") ? "Oui" : "Non") << endl;
    cout << "La valeur ressortie doit être 'Oui'." << endl;
    cout << "'C++' est-il dans le Vector? " << (vs.contains("C++") ? "Oui" : "Non") << endl;
    cout << "La valeur ressortie doit être 'Non'." << endl;

    cout << "Test de la copie du Vector." << endl;
    Vector<string> vs2 = vs;
    cout << "Contenu du Vector copié: ";
    vs2.print();
    vs.push("C++");
    cout << "Après ajout de 'C++' au Vector initial, on print le Vector copié: ";
    vs2.print();
    cout << "Le Vector copié ne doit pas contenir 'C++'." << endl;
    cout << "Contenu du Vector initial modifié: ";
    vs.print();
    cout << "Le Vector initial doit contenir 'C++'." << endl;
    cout << "taille du Vector initial: " << vs.size() << endl;
    cout << "La taille doit être 3." << endl;
    
    cout << "Test des exceptions pour les accès hors limites." << endl;
    try
    {
        cout << vs.get_i(10) << endl;
    }
    catch (const std::out_of_range& e)
    {
        cout << "Exception attrapée pour get_i(10): " << e.what() << endl;
    }

    cout << "Fin des tests." << endl;


    return 0;
}
