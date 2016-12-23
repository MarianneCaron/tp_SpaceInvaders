#include "VaisseauDefender.h"
#include "Vaisseau.h"
#include "UIKit.h"
#include <iostream>
#include <string>
using namespace std;


VaisseauDefender::VaisseauDefender() {
	removeVaisseau();
	dessinVaisseau = "<|=^=|>";
	coord.setPositionX(51);
	coord.setPositionY(40);
	putVaisseauDefender();
}


void VaisseauDefender::removeVaisseauDefender() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << "       ";
}

void VaisseauDefender::putVaisseauDefender() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	UIKit::color(FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_RED);
	cout << dessinVaisseau;
	UIKit::color(FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);
}

void VaisseauDefender::modifierPositionDefender(char key)
{
	removeVaisseauDefender();
	switch (key)
	{
	case 'k':	coord.setPositionX(coord.getPositionX() - 1);	break;
	case 'l':	coord.setPositionX(coord.getPositionX() + 1);
	}
	putVaisseauDefender();
}