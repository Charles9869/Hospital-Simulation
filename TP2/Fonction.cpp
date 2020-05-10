// Fichier: Fonction.cpp //
// Charles Bertrand et Jérémie Lacroix //
// Date de création: 25 Octobre 2018 //

#include "Fonction.h"

// Prototype: int TransformToHours(int Minutes) //
// Intrants: Minutes //
// Extrants: Valeur en Hours //
// Type: Fonction //
// But: Permet de transformer des minutes en heures //
int TransformToHours(int Minutes)
{
	return Minutes / 60;
}

// Prorotype: int TransformerToMinutes(int Minutes) //
// Intrants: Minutes //
// Extrants: Valeur en minutes //
// Type: Fonction //
// But: Permet d'obtenir les minutes après les heures //
int TransformToMinutes(int Minutes)
{
	return Minutes % 60;
}