#pragma once
#include <time.h>

class Timer {
public:

	// Les attributs
	int timerValue;
	int delai;

	// Les construteurs
	// Sans param�tre
	Timer();

	// Avec param�tre
	Timer(int delai);

	// Les m�thodes sp�cifiques

	void setDelai(int delai);
	int getDelai() const;
	bool estPret();
};
