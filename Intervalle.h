#pragma once
#include "string.h"
#include <iostream>
using namespace std;

template<class T>
class Intervalle
{
private:
    T debut;
    T fin;
public:
    Intervalle(T a, T b);
    void afficher() const;
    bool appartient(T x) const;
    static T MAX(const T& a, const T& b);
    static T MIN(const T& a, const T& b);
    Intervalle<T> intersection(const Intervalle<T>& I) const;
    Intervalle<T> Union(const Intervalle<T>& I) const;
    T longueur() const;
    bool estInclus(const Intervalle<T>& I) const;
    ~Intervalle();
};

template<class T>
inline Intervalle<T>::Intervalle(T a, T b)
{
    if (a > b)
    {
        throw "le debut est superieur a la fin : intervalle invalide";
    }
    this->debut = a;
    this->fin = b;
}

template<class T>
inline void Intervalle<T>::afficher() const
{
    cout << "[" << this->debut << " - " << this->fin << "]" << endl;
}

template<class T>
inline bool Intervalle<T>::appartient(T x) const
{
    return (x >= debut && x <= fin);
}

template<class T>
inline T Intervalle<T>::MAX(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

template<class T>
inline T Intervalle<T>::MIN(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

template<class T>
inline Intervalle<T> Intervalle<T>::intersection(const Intervalle<T>& I) const
{
    T nouveauDebut = max(this->debut, I.debut);
    T nouvelleFin = min(this->fin, I.fin);
    if (nouveauDebut > nouvelleFin)
    {
        throw  "les intervalles sont dijoints !";
    }
    return Intervalle<T>(nouveauDebut, nouvelleFin);
}

template<class T>
inline Intervalle<T> Intervalle<T>::Union(const Intervalle<T>& I) const
{
    if (this->fin < I.debut - 1 && I.fin < this->debut - 1)
    {
        throw "les intervalles ne sont pas contigus !";
    }
    T nouveauDebut = MIN(this->debut, I.debut);
    T nouvelleFin = MAX(this->fin, I.fin);
    return Intervalle<T>(nouveauDebut, nouvelleFin);
}

template<class T>
inline T Intervalle<T>::longueur() const
{  
    return (this->fin - this->debut + 1);
}

template<class T>
inline bool Intervalle<T>::estInclus(const Intervalle<T>& I) const
{
    return (I.debut >= this->debut && I.fin <= this->fin);
}

template<class T>
inline Intervalle<T>::~Intervalle()
{
    // Destruction de l'objet intervalle
}

