// Fichier: FileAttente.cpp //
// Charles Bertrand et Jérémie Lacroix //
// Date de création: 23 octobre 2018 //

#include "FileAttente.hpp"

// Prototype: FileAttente::FileAttente() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Constructeur //
FileAttente::FileAttente()
{

}

// Prototype: void AjouterPatient(const Patient& rPatient) //
// Intrants: référence constante sur un patient //
// Extrants: Aucun //
// Type: Procédure //
// But: Permet d'ajouter un patient dans la File d'attente //
void FileAttente::AjouterPatient(const Patient& rPatient)
{
	mFile.push_back(rPatient);
}

// Prototype: void AfficherFile() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Procédure //
// But: Permet d'afficher la file d'attente //
void FileAttente::AfficherFile()
{
	Priorite P0, P1, P2, P3, Moyenne2;
	pair<double, double> Moyenne, MoyenneArrondi;
	for (size_t i = 0; i < mFile.size(); ++i)
	{
		cout << "\nRang: " << mFile[i].GetRang() << "\nNom: " << mFile[i].GetNom() << "\nPriorite: " << mFile[i].GetPriorite() << endl;
		AffichagePrioriteZero(P0, P1, P2, P3, i, Moyenne);
		AffichagePrioriteUn(P1, P2, P3, i, Moyenne);
		AffichagePrioriteDeux(P2, P3, i, Moyenne);
		AffichagePrioriteTrois(P3, i, Moyenne);
	}

	MoyenneArrondi.first = llround(Moyenne.first / mFile.size());
	MoyenneArrondi.second = llround(Moyenne.second / mFile.size());
	AfficherTempsFirst("Temps moyen d'attente: ", MoyenneArrondi);
	cout << " a ";
	AfficherTempsSecond(MoyenneArrondi);
	cout << "\n";
}

// Prototype: void AffichagePrioriteZero(Priorite& rP0, Priorite& rP1, Priorite& rP2, Priorite& rP3, size_t index, pair<double, double>& rMoyenne) //
// Intrants: P0, P1, P2, P3, index, Moyenne //
// Extrants: Aucun //
// Type: Procédure //
// But: Responsable de l'affichage du temps de consultation pour les patients ayant la priorité 0 //
void FileAttente::AffichagePrioriteZero(Priorite& rP0, Priorite& rP1, Priorite& rP2, Priorite& rP3, size_t index, pair<double, double>& rMoyenne)
{
	if (mFile[index].GetPriorite() == 0)
	{
		if (mFile[index].GetRang() == 1)
		{
			rMoyenne.first += rP0.first; rMoyenne.second += rP0.second;
		}
		else if (index == 0 && mFile[index].GetRang() > 1 || mFile[index].GetRang() > 1)
		{
			rP0.first += PRIORITE_ZERO_MIN; rP0.second += PRIORITE_ZERO_MAX;
			rP1.first += rP0.first; rP1.second += rP0.second;
			rP2.first += rP0.first; rP2.second += rP0.second;
			rP3.first += rP0.first; rP3.second += rP0.second;
			rMoyenne.first += rP0.first; rMoyenne.second += rP0.second;
		}

		// Affichage du temps d'attente //
		AfficherTempsFirst("Temps prevu: ", rP0);
		cout << " a ";
		AfficherTempsSecond(rP0);
	}
}

// Prototype: void AffichagePrioriteUn(Priorite& rP1, Priorite& rP2, Priorite& rP3, size_t index, pair<double, double>& rMoyenne) //
// Intrants: P1, P2, P3, index, Moyenne //
// Extrants: Aucun //
// Type: Procédure //
// But: Responsable de l'affichage du temps de consultation pour les patients ayant la priorité 1 //
void FileAttente::AffichagePrioriteUn(Priorite& rP1, Priorite& rP2, Priorite& rP3, size_t index, pair<double, double>& rMoyenne)
{
	if (mFile[index].GetPriorite() == 1)
	{
		if (mFile[index].GetRang() == 1)
		{
			rP2.first += rP1.first; rP2.second += rP1.second;
			rP3.first += rP1.first; rP3.second += rP1.second;
			rMoyenne.first += rP1.first; rMoyenne.second += rP1.second;
		}
		else if (index == 0 && mFile[index].GetRang() > 1 || mFile[index].GetRang() > 1 || (index != 0 && mFile[index - 1].GetPriorite() != mFile[index].GetPriorite()))
		{
			rP1.first += PRIORITE_UN_MIN; rP1.second += PRIORITE_UN_MAX;
			rP2.first = rP1.first; rP2.second = rP1.second;
			rP3.first += rP1.first; rP3.second += rP1.second;
			rMoyenne.first += rP1.first; rMoyenne.second += rP1.second;
		}

		// Affichage du temps d'attente //
		AfficherTempsFirst("Temps prevu: ", rP1);
		cout << " a ";
		AfficherTempsSecond(rP1);
	}
}

// Prototype: void AffichagePrioriteDeux(Priorite& rP2, Priorite& rP3, size_t index, pair<double, double>& rMoyenne) //
// Intrants: P2, P3, Index, Moyenne //
// Extrants: Aucun //
// Type: Procédure //
// But: Responsable de l'affichage du temps de consultation pour les patients ayant la priorité 2 //
void FileAttente::AffichagePrioriteDeux(Priorite& rP2, Priorite& rP3, size_t index, pair<double, double>& rMoyenne)
{
	if (mFile[index].GetPriorite() == 2)
	{
		if (mFile[index].GetRang() == 1)
		{
			rP3.first += rP2.first; rP3.second += rP2.second;
			rMoyenne.first += rP2.first; rMoyenne.second += rP2.second;
		}
		if (index == 0 || mFile[index].GetRang() > 1 || (mFile[index - 1].GetPriorite() != mFile[index].GetPriorite() && mFile[index].GetRang() > 1))
		{
			rP2.first += PRIORITE_DEUX_MIN; rP2.second += PRIORITE_DEUX_MAX;
			rP3.first = rP2.first; rP3.second = rP2.second;
			rMoyenne.first += rP2.first; rMoyenne.second += rP2.second;
		}

		// Affichage du temps d'attente //
		AfficherTempsFirst("Temps attente: ", rP2);
		cout << " a ";
		AfficherTempsSecond(rP2);
	}
}

// Prototype: void AffichagePrioriteTrois(Priorite& rP3, size_t index, pair<double, double>& rMoyenne) //
// Intrants: Priorite P3, index, Moyenne //
// Extrants: Aucun //
// Type: Procédure //
// But: Responsable de l'affichage du temps de consultation pour les patients ayant la priorité 3 //
void FileAttente::AffichagePrioriteTrois(Priorite& rP3, size_t index, pair<double, double>& rMoyenne)
{
	if (mFile[index].GetPriorite() == 3)
	{
		if (mFile[index].GetRang() == 1)
		{
			rP3.first += PRIORITE_TROIS_MIN; rP3.second += PRIORITE_TROIS_MAX;
			rMoyenne.first += rP3.first; rMoyenne.second += rP3.second;
		}
		else if (index == 0 && mFile[index].GetRang() > 1 || mFile[index].GetRang() > 1 || (index != 0 && mFile[index - 1].GetPriorite() != mFile[index].GetPriorite()))
		{
			rP3.first += PRIORITE_TROIS_MIN; rP3.second += PRIORITE_TROIS_MAX;
			rMoyenne.first += rP3.first; rMoyenne.second += rP3.second;
		}

		// Affichage du temps d'attente //
		AfficherTempsFirst("Temps attente: ", rP3);
		cout << " a ";
		AfficherTempsSecond(rP3);
	}
}

// Prototype: void Afficher(int index) //
// Intrants: Index //
// Extrants: Aucun //
// Type: Procédure //
// But: Afficher les informations du patient //
void FileAttente::Afficher(size_t index) const
{
	cout << "Rang: " << mFile[index].GetRang() << "\nNom: " << mFile[index].GetNom() << "\nPriorite: " << mFile[index].GetPriorite() << "\n" << endl;
}

// Prototype: int GetIndexFromName(string nom) //t
// Intrants: Nom //
// Extrants: L'index //
// Type: Fonction //
// But: Retourne l'index d'un patient selon leur nom //
size_t FileAttente::GetIndexFromName(string nom)
{
	size_t Index = 0;
	for (size_t i = 0; i < mFile.size(); ++i)
	{
		if (mFile[i].GetNom() == nom) { Index = i; break; }
		else { Index = -1; }
	}
	return Index;
}

// Prototype: void Sort() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Procédure //
// But: Permet le triage de la file d'attente selon les rangs et les priorités //
void FileAttente::Sort()
{
	std::sort(mFile.begin(),
		mFile.end(),
		[](const Patient& rP1, const Patient& rP2)
	{
		return rP1.GetRang() < rP2.GetRang();
	});

	std::sort(mFile.begin(),
		mFile.end(),
		[](const Patient& rP1, const Patient& rP2)
	{
		return rP1.GetPriorite() < rP2.GetPriorite();
	});
}

// Prototype: void AfficherTempsFirst(Priorite P) //
// Intrants: typedef d'un pair //
// Extrants: Aucun //
// Type: Procédure //
// But: Affiche le temps minimal de la bonne façon //
void FileAttente::AfficherTempsFirst(string phrase, Priorite P)
{
	if (P.first < 60) { cout << phrase << P.first << " min"; }
	else 
	{
		cout << phrase << TransformToHours(P.first);
		if (TransformToMinutes(P.first) < 10) { cout << "h0" << TransformToMinutes(P.first); }
		else { cout << "h" << TransformToMinutes(P.first) << " min"; }
	}
}

// Prototype: void AfficherTempsSecond(Priorite P) //
// Intrants: typedef d'un pair //
// Extrants: Aucun //
// Type: Procédure //
// But: Affiche le temps maximal de la bonne façon //
void FileAttente::AfficherTempsSecond(Priorite P)
{
	if (P.second < 60) { cout << P.second << " min\n"; }
	else
	{
		cout << TransformToHours(P.second);
		if (TransformToMinutes(P.second) < 10) { cout << "h0" << TransformToMinutes(P.second) << " min\n"; }
		else { cout << "h" << TransformToMinutes(P.second) << " min\n"; }
	}
}