// Fichier: Fonction.cpp //
// Charles Bertrand et J�r�mie Lacroix //
// Date de cr�ation: 25 Octobre 2018 //

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
// But: Permet d'obtenir les minutes apr�s les heures //
int TransformToMinutes(int Minutes)
{
	return Minutes % 60;
}