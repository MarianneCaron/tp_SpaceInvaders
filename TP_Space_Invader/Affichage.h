#pragma once

class Affichage {
public:

	static void init();
	static int menu();
	static void dessinerCadre();
	static void afficherScore(int score);
	static bool affichageFinPartie(bool gagne, int & niveau);
	
};