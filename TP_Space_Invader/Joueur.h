#pragma once

#include "VaisseauDefender.h"
#include "Saisie.h"


class Joueur {
	VaisseauDefender vaisseau;
	


public:
	Joueur();
	VaisseauDefender &getVaisseau();
	bool operationVaisseau();
	
};
