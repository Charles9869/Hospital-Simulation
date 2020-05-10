// Fichier: Simulation.hpp //
// Charles Bertrand et Jérémie Lacroix //
// Date de création: 23 octobre 2018 //

#ifndef Simulation_hpp
#define Simulation_hpp

#include "FileAttente.hpp"
#include "DistributeurDeRang.hpp"
#include <string>

class Simulation
{
public:
    
    // Constructeur //
    Simulation();
    
    // Mutateurs //
    void SetNom(string nom) {mNom = nom; } // But: Permet d'assigner le nom au patient //
    void SetPriorite(int priorite) { mPriorite = priorite; } // Permet d'assigner un priorite au patient //
    void SetChoix(int choix) { mChoix = choix; } // Permet d'assigner le choix de l'usager //
    
    // Accesseurs //
    string GetNom() const { return mNom; } // Retourne le nom du patient //
    int GetPriorite() const { return mPriorite; } // Retourne la priorite du patient //
    int GetChoix() const { return mChoix;} // Retourne le choix de l'usager //
    
    // Méthodes //
	void Run(); // Responsable du programme //
    void DemanderNom(string phrase); // But: Permet de demander le nom du patient //
    void DemanderPriorite(string phrase); // But: Permet de demander la priorité au patient //
    void Menu(); // But: Affichage du menu //
    void EntrerInformationPatient(); // But: S'occupe des informations du patient //
    void QuitterUrgence(); // But: Permet à un patient de quitter l'urgence //
	void VerificationChoixUn(); // But: Responsable du choix 1 si l'usager le sélectionne //
	void VerificationChoixDeux(); // But: Responsable du choix 2 si l'usager le sélectionne //
	void VerificationChoixTrois(); // But: Responsable du choix 3 si l'usager le sélectionne //
	void VerificationChoixQuatre(); // But: Responsable du choix 4 si l'usager le sélectionne //
	void VerificationChoixCinq(); // But: Responsable du choix 5 si l'usager le sélectionne //

private:
    FileAttente mFile;
    string mNom;
    int mPriorite;
    int mChoix;
};
#endif /* Simulation_hpp */
