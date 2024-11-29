// exam1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "string.h"
#include <iostream>
#include "Intervalle.h"
using namespace std;


int main()
{
    cout << "Test des intervalles avec des entiers :" << endl;
    try
    {
        Intervalle<int> I1(1, 5);
        cout << "Intervalle I1 : ";
        I1.afficher();
        cout << "La longueur de I1 " << "est : " << I1.longueur() << endl;
        cout << "8 appartient ? " << (I1.appartient(8) ? "Oui" : "Non") << endl;
        cout << "4 appartient ? " << (I1.appartient(4) ? "Oui" : "Non") << endl;
        cout << endl;
    }
    catch (const char* e)
    {
        cout << e << endl;
    }

    try {
        Intervalle<int> I2(1, 5);
        Intervalle<int> I3(6, 10);
        cout << "Intervalle I2 : ";
        I2.afficher();
        cout << "Intervalle I3 : ";
        I3.afficher();

        std::cout << "I2 est inclus dans I3 ? " << (I3.estInclus(I2) ? "Oui" : "Non") << std::endl;

        try
        {
            Intervalle<int> intersec = I2.intersection(I3);
            cout << "Intersection de I2 et I3 : ";
            intersec.afficher();
            cout << endl;
        }
        catch (const char* e)
        {
            cout << "Erreur d'intersection : " << e << endl;
        }

        try
        {
            Intervalle<int> un = I2.Union(I3);
            cout << "Union de I2 et I3 : ";
            un.afficher();
            cout << endl;
        }
        catch (const char* e)
        {
            cout << "Erreur d'union : " << e << endl;
        }
    }
    catch (const char* e)
    {
        cout << "Erreur générale : " << e << endl;
    }

    
 
    try
    {
        cout << "Test des intervalles avec des caracteres :" << endl;
        Intervalle<char> I4('A', 'E');
        cout << "Intervalle I4 : ";
        I4.afficher();
        cout << "C appartient ? " << (I4.appartient('C') ? "Oui" : "Non") << endl;
        cout << "H appartient ? " << (I4.appartient('H') ? "Oui" : "Non") << endl;

        cout << endl;

        Intervalle<char> I5('C', 'D');
        cout << "Intervalle I5 : ";
        I5.afficher();
        std::cout << "I5 est inclus dans I4 ? " << (I4.estInclus(I5) ? "Oui" : "Non") << std::endl;
    }
    catch (const char* e)
    {
        cout << "Erreur : " << e << endl;
    }



    cout << endl;

    return 0;
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
