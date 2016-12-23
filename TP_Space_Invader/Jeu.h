#pragma once
#include "Joueur.h"
#include "Laser.h"
#include "Timer.h"
#include "MartienExtension.h"
#include "LaserMartien.h"

//Déclaration des constantes
#define MAX_LASERS 200
#define MAX_ET 200
#define MAX_TIR_ET 200

class Jeu {
private:
	int niveau;
	int score;
	int nbVies;
	bool premierTour;
	// Création du joueur
	Joueur leJoueur;

	// Tableau de laser
	Laser * lesLasers[MAX_LASERS];
	int nbLasers;
	Timer lasersTimer[MAX_LASERS];

	// Tableau de Martien
	MartienExtension * lesET[MAX_ET];
	Timer ETTimer[MAX_ET];

	//Timer pour l'apparition des ET
	Timer nouveauET;

	//Tableau de tir de Martien
	LaserMartien * lesTirET[MAX_TIR_ET];
	int nbTirET;
	Timer TirETTimer[MAX_TIR_ET];

	// Timer pour un nouveau tir d'alien
	Timer nouveauTirET;

	// Les méthodes privées de jeu
	bool collisionEntreMartiens(const MartienExtension & martien);
	bool champLibreTirer(const MartienExtension & martien);
	void bougerLasers();
	void collisionLaserEt();
	void collisionLaserVaisseau();
	void actionJoueur();
	void tirMartien();
	void bougerMartien();
	void apparitionMartien();
public:
	// Le constructeur
	Jeu(int niveau);
	// Le destructeur
	~Jeu();
	// Les méthodes
	void boucleJeu();


	
};