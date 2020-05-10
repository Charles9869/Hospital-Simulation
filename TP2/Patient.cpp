// Fichier: Patient.cpp //
// Charles Bertrand et Jérémie Lacroix //
// Date de création: 23 octobre 2018 //

#include "Patient.hpp"

// Prototype: Patient::Patient(string nom, int priorite, int rang) //
// Intrants: Nom, Priorite, Rang //
// Extrants: Aucun //
// Type: Constructeur //
Patient::Patient(string nom, int priorite, int rang)
{
    SetNom(nom);
    SetPriorite(priorite);
    SetRang(rang);
}
