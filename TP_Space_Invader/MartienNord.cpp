#include "MartienNord.h"
#include "ExtraTerrestre.h"
#include "UIKit.h"
#include <string>
#include <iostream>
using namespace std;

MartienNord::MartienNord(int type, int valeur) :MartienExtension(type, valeur) {
	removeExtraTerrestre();
	ET1 = "\\¤/";
}

void MartienNord::resetMartien() {
	coord.setPositionX(rand() % 105 + 1);
	coord.setPositionY(rand() % 18 + 1);
	isAlive = true;
	nombreExtraTerrestre++;
}

void MartienNord::putMartien() const {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	UIKit::color(FOREGROUND_RED + FOREGROUND_INTENSITY);
	cout << ET1;
	UIKit::color(FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);
}

void MartienNord::nouvelleCoordMartien() {

	int percent = (rand() % 100 + 1);

	if (percent < 40 && coord.getPositionY() < 35) {
		coord.setPositionY(coord.getPositionY() + 1);
	}
	else if (percent < 60 && coord.getPositionY() > 1) {
		coord.setPositionY(coord.getPositionY() -1 );
	}
	else if (percent < 80 && coord.getPositionX() > 3) {
		coord.setPositionX(coord.getPositionX() - 1);
	}
	else if (coord.getPositionX() < 107) {
		coord.setPositionX(coord.getPositionX() + 1);
	}

}

void MartienNord::removeMartien() const {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << ' ' << ' ' << ' ';
}