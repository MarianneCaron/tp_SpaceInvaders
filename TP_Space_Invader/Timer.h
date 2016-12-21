#pragma once
#include <time.h>

class Timer {
public:

	// Les attributs
	int timerValue;
	int delai;

	// Les construteurs
	// Sans paramêtre
	Timer();

	// Avec paramètre
	Timer(int delai);

	// Les méthodes spécifiques

	void setDelai(int delai);
	int getDelai() const;
	bool estPret();
};
