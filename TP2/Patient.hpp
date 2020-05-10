// Fichier: Patient.hpp //
// Charles Bertrand et Jérémie Lacroix //
// Date de création: 23 octobre 2018 //

#ifndef Patient_hpp
#define Patient_hpp

#include <iostream>

using namespace std;

class Patient
{
public:
    // Constructeur //
    Patient(string nom, int priorite, int rang);
    
    // Mutateur //
    void SetNom(string nom) {mNom = nom; } // But: Permet d'assigner un nom au patient //
    void SetPriorite(int priorite) { mPriorite = priorite; } // But: Permet d'assigner la priorité au patient //
    void SetRang(int rang) {mRang = rang; } // Permet d'assigner le rang au patient //
    
    // Accesseur //
    string GetNom() const { return mNom; } // Retourne le nom du patient //
    int GetPriorite() const { return mPriorite; } // Retourne la priorite du patient //
    int GetRang() const { return mRang; } // Retourne le rang du patient //
    
private:
    string mNom;
    int mPriorite;
    int mRang;
};

#endif /* Patient_hpp */
