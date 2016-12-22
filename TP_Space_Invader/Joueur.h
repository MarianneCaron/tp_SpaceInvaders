#pragma once

#include "Vaisseau.h"
#include "Saisie.h"


class Joueur {
	Vaisseau vaisseau;
	


public:
	Joueur();
	Vaisseau &getVaisseau();
	bool operationVaisseau();
	
};
