#pragma once
#include "Vaisseau.h"

#include <iostream>
#include <string>
using namespace std;

class VaisseauDefender:public Vaisseau {
private:

	string dessinVaisseau;

public:

	VaisseauDefender();
	void removeVaisseauDefender() const;
	void putVaisseauDefender() const;
	void modifierPositionDefender(char key);
	

};