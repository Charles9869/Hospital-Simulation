// Fichier: FileAttente.hpp //
// Charles Bertrand et Jérémie Lacroix //
// Date de création: 23 octobre 2018 //

#ifndef FileAttente_hpp
#define FileAttente_hpp

#include "Patient.hpp"
#include "Fonction.h"

// Typedef de pair //
typedef pair<int, int> Priorite;

class FileAttente
{
public:

	// Constructeur //
	FileAttente();

	// Méthodes //
	void AjouterPatient(const Patient& rPatient); // But: Permet d'ajouter un patient dans la File d'attente //
	void AfficherFile(); // But: Permet d'afficher la file d'attente //
	void SetPrioriteByIndex(size_t index, int valeur) { mFile[index].SetPriorite(valeur); } // But: Permet d'assigner la priorité selon l'index passé en paramètre //
	void RemoveByIndex(size_t index) { mFile.erase(mFile.begin() + index); } // But: Permet de retirer un patient selon l'index passé en paramètre //
	void Sort(); // But: Permet le triage de la file d'attente selon les rangs et les priorités //
	void AffichagePrioriteZero(Priorite& rP0, Priorite& rP1, Priorite& rP2, Priorite& rP3, size_t index, pair<double, double>& rMoyenne); // But: Responsable de l'affichage du temps d'attente pour les patients ayant la priorité 0 //
	void AffichagePrioriteUn(Priorite& rP1, Priorite& rP2, Priorite& rP3, size_t index, pair<double, double>& rMoyenne); // But: Responsable de l'affichage du temps d'attente pour les patients ayant la priorité 1 //
	void AffichagePrioriteDeux(Priorite& rP2, Priorite& rP3, size_t index, pair<double, double>& rMoyenne); // But: Responsable de l'affichage du temps d'attente pour les patients ayant la priorité 2 //
	void AffichagePrioriteTrois(Priorite& rP3, size_t index, pair<double, double>& rMoyenne); // But: Responsable de l'affichage du temps d'attente pour les patients ayant la priorité 3 //
	void Afficher(size_t index) const; // But: Afficher les informations du patient //
	void AfficherTempsFirst(string phrase, Priorite P); // But: Affiche le temps minimal de la bonne façon //
	void AfficherTempsSecond(Priorite P); // But: Affiche le temps maximal de la bonne façon //

	// Accesseurs //
	size_t GetSize() const { return mFile.size(); } // Return le size de la file //
	size_t GetIndexFromName(string nom); // Permet d'obtenir l'index à partir du nom d'un patient //
	int GetPrioriteByIndex(size_t index) { return mFile[index].GetPriorite(); } // Permet d'obtenir la priorité d'un patient selon l'index dans la file d'attente //


private:
	vector<Patient> mFile;
	const int HOURS_ADD = 22;
	const int MINUTES_ADD = 28;
	const int PRIORITE_ZERO_MIN = 30;
	const int PRIORITE_ZERO_MAX = 40;
	const int PRIORITE_UN_MIN = 22;
	const int PRIORITE_UN_MAX = 28;
	const int PRIORITE_DEUX_MIN = 18;
	const int PRIORITE_DEUX_MAX = 24;
	const int PRIORITE_TROIS_MIN = 15;
	const int PRIORITE_TROIS_MAX = 20;
};

#endif /* FileAttente_hpp */
