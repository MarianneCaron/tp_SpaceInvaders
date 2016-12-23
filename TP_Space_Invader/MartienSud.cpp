#include "MartienSud.h"
#include "UIKit.h"
#include <string>
#include <iostream>
using namespace std;

MartienSud::MartienSud(int type, int valeur) :MartienExtension(type, valeur) {
	removeExtraTerrestre();
	ET2 = "\\±/";
}

void MartienSud::resetMartien() {
	bool collision=false;
	do {
		coord.setPositionX(rand() % 105 + 1);
		coord.setPositionY(rand() % 8 + 1);
		
	} while (collision);

	isAlive = true;
	nombreExtraTerrestre++;
}

void MartienSud::putMartien() const {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	UIKit::color(FOREGROUND_GREEN + FOREGROUND_INTENSITY);
	cout << ET2;
	UIKit::color(FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);
}

void MartienSud::nouvelleCoordMartien() {
	
	int percent = (rand() % 100 + 1);

	if (percent < 40 && coord.getPositionY() < 35) {
		coord.setPositionY(coord.getPositionY() + 1);
	}
	else if (percent < 60 && coord.getPositionY() > 1) {
		coord.setPositionY(coord.getPositionY() - 1);
	}
	else if (percent < 80 && coord.getPositionX() > 3) {
		coord.setPositionX(coord.getPositionX() - 1);
	}
	else if (coord.getPositionX() < 107) {
		coord.setPositionX(coord.getPositionX() + 1);
	}
	
}

void MartienSud::removeMartien() const {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << ' ' << ' ' << ' ';
}