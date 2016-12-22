#pragma once
#include "Joueur.h"
#include "Laser.h"
#include "Timer.h"
#include "MartienExtension.h"
#include "LaserMartien.h"

//Déclaration des constantes
#define MAX_LASERS 80
#define MAX_ET 80
#define MAX_TIR_ET 200

class Jeu {
private:
	int niveau;
	int score;
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

public:
	// Le constructeur
	Jeu(int niveau);

	// Les méthodes
	void boucleJeu();
	bool collisionEntreMartiens(const MartienExtension & martien);
};