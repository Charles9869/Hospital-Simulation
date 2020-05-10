// Fichier: Simulation.cpp //
// Charles Bertrand et Jérémie Lacroix //
// Date de création: 23 octobre 2018 //

#include "Simulation.hpp"

using namespace std;
// Prototype: Simulation::Simulation() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Constructeur //
Simulation::Simulation()
{

}

// Prototype: void DemanderNom(string phrase) //
// Intrants: Phrase //
// Extrants: Aucun //
// Type: Procédure //
// But: Permet de demander le nom du patient //
void Simulation::DemanderNom(string phrase)
{
	string Nom;
	cout << phrase;
	cin.ignore();
	getline(cin, Nom);
	SetNom(Nom);
}

// Prototype: void DemanderPriorite(string phrase) //
// Intrants: Phrase //
// Extrants: Aucun //
// Type: Procédure //
// But: Permet de demander la priorité au patient //
void Simulation::DemanderPriorite(string phrase)
{
	int PrioriteNumber;
	cout << phrase;
	do
	{
		while (!(cin >> PrioriteNumber))
		{
			cin.clear(); // clear failbit from character
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore bad input
			cout << "\nError! Nombre entre 0 et 3 uniquement!" << endl;
			cout << phrase;
		}
		if (PrioriteNumber < 0 || PrioriteNumber > 3) { cout << "\nError! Nombre entre 0 et 3 uniquement!\n" << phrase; }
	} while (PrioriteNumber < 0 || PrioriteNumber > 3);
	SetPriorite(PrioriteNumber);
	cout << endl;
}

// Prototype: void Run() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Procédure //
// But: Responsable du programme //
void Simulation::Run()
{
	bool Quitter = false;
	while (!Quitter)
	{
		Menu();
		switch (GetChoix())
		{
		case 0:
			Quitter = true;
			break;
		case 1:
			VerificationChoixUn();
			break;
		case 2:
			VerificationChoixDeux();
			break;
		case 3:
			VerificationChoixTrois();
			break;
		case 4:
			VerificationChoixQuatre();
			break;
		case 5:
			VerificationChoixCinq();
			break;
		}
	}
}

// Prototype: void Menu() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Procédure //
// But: Affichage du menu //
void Simulation::Menu()
{
	const string LIGNE_TIRET = string(50, '-');
	const string Menu = "1. Une personne arrive a l'urgence\n"
		"2. Un medecin est pret a traiter un patient\n"
		"3. On change la priorite d'une personne en attente\n"
		"4. Une personne quitte l'urgence\n"
		"5. Afficher les files d'attente\n"
		"0. Quitter\n" + LIGNE_TIRET + "\nVotre Choix: ";

	int Choix;
	cout << Menu;
	do
	{
		while (!(cin >> Choix))
		{
			cin.clear(); // clear failbit from character
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore bad input
			cout << "\nError! Nombre entre 0 et 5 uniquement!" << endl;
			cout << Menu;
		}
		if (Choix < 0 || Choix > 5) { cout << "\nError! Nombre entre 0 et 5 uniquement!\n" << Menu; }
	} while (Choix < 0 || Choix > 5);
	
	SetChoix(Choix);
	cout << endl;
}

// Prototype: void EntrerInformationPatient() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Procédure //
// But: S'occupe des informations du patient //
void Simulation::EntrerInformationPatient()
{
	DemanderNom("Entrez votre nom: ");
	DemanderPriorite("Entrez votre priorite: ");
	cout << endl;
}

// Prototype: void QuitterUrgence() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Procédure //
// But: Permet à un patient de quitter l'urgence //
void Simulation::QuitterUrgence()
{
	if (mFile.GetSize() > 0) {
		DemanderNom("Entrez votre nom: ");
		size_t Index = mFile.GetIndexFromName(GetNom());

		if (Index != -1) {
			mFile.Afficher(Index);

			string Confirmation;
			cout << "Voulez-vous vraiment quitter? (o/n): \n";
			cin >> Confirmation;

			if (Confirmation == "o") { mFile.RemoveByIndex(Index); }
			else { cout << "Operation annulee! " << endl; }
		}
		else { cout << "Le patient n'existe pas! \n" << endl; }
	}
	else { cout << "Il n'y a personne dans la file d'attente! \n" << endl; }
}

// Prototype: void VerificationChoixUn() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Procédure //
// But: Responsable du choix 1 si l'usager le sélectionne //
void Simulation::VerificationChoixUn()
{
	DemanderNom("Entrez le nom du patient: ");
	DemanderPriorite("Entrez la priorite du patient: ");

	DistributeurDeRang Rang;
	Patient patient(GetNom(), GetPriorite(), Rang.GetRang());

	mFile.AjouterPatient(patient);
}

// Prototype: void VerificationChoixDeux() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Procédure //
// But: Responsable du choix 2 si l'usager le sélectionne //
void Simulation::VerificationChoixDeux()
{
	static const int PATIENT_UN = 0;

	if (mFile.GetSize() > 0)
	{
		mFile.Sort();
		cout << "Ce patient sera traite par le medecin et retire de la file d'attente!" << endl;
		mFile.Afficher(PATIENT_UN);
		mFile.RemoveByIndex(PATIENT_UN);
	}
	else { cout << "Il n'y a personne dans la file d'attente! \n" << endl; }
}
// Prototype: void VerificationChoixTrois() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Procédure //
// But: Responsable du choix 3 si l'usager le sélectionne //
void Simulation::VerificationChoixTrois()
{
	size_t Index;
	if (mFile.GetSize() > 0)
	{
		string NomPatient;
		cout << "Entrez votre nom: ";
		cin.ignore();
		getline(cin, NomPatient);

		Index = mFile.GetIndexFromName(NomPatient);
		if (Index == -1) { cout << "Le patient n'existe pas! \n" << endl; }
		else
		{
			DemanderPriorite("Entrez la nouvelle priorite: ");
			cout << endl;
			mFile.SetPrioriteByIndex(Index, GetPriorite());
		}
	}
	else { cout << "Il n'y a personne dans la file d'attente! \n" << endl; }
}

// Prototype: VerificationChoixQuatre() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Procédure //
// But: Responsable du choix 4 si l'usager le sélectionne //
void Simulation::VerificationChoixQuatre()
{
	QuitterUrgence();
}

// Prototype: void VerificationChoixCinq() //
// Intrants: Aucun //
// Extrants: Aucun //
// Type: Procédure //
// But: Responsable du choix 5 si l'usager le sélectionne //
void Simulation::VerificationChoixCinq()
{
	if (mFile.GetSize() > 0)
	{
		// Tri la file d'attente //
		mFile.Sort();

		// Affecte les rang selon la priorité //
		mFile.AfficherFile();
	}
	else { cout << "Il n'y a personne dans la file d'attente! \n" << endl; }
}
