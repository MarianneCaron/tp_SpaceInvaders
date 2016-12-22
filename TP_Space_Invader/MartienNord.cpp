#include "MartienNord.h"
#include <string>
#include <iostream>
using namespace std;

MartienNord::MartienNord(int type, int valeur) :MartienExtension(type, valeur) {
	ET1 = "\\0/";
}

void MartienNord::resetMartien() {
	coord.setPositionX(rand() % 105 + 1);
	coord.setPositionY(rand() % 18 + 1);
	isAlive = true;
	nombreExtraTerrestre++;
}

void MartienNord::putMartien() const {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << ET1;
}

void MartienNord::bougerMartien() {
	removeMartien();
	switch (rand() % 4) {
		if ((coord.getPositionX() + 1) != 35) {
	case 0: coord.setPositionX(coord.getPositionX() + 1);
		break;
		}
		if ((coord.getPositionX() - 1) != 0) {
	case 1: coord.setPositionX(coord.getPositionX() - 1);
		break;
		}
		if ((coord.getPositionY() + 1) != 107) {
	case 2: coord.setPositionY(coord.getPositionY() + 1);
		break;
		}
		if ((coord.getPositionY() - 1) != 0) {
	case 3: coord.setPositionY(coord.getPositionY() - 1);
		break;
		}
	}
	
}

void MartienNord::removeMartien() const {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << ' ' << ' ' << ' ';
}