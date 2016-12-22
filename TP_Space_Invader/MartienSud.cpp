#include "MartienSud.h"
#include <string>
#include <iostream>
using namespace std;

MartienSud::MartienSud(int type, int valeur) :MartienExtension(type, valeur) {
	ET2 = "\\¥/";
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
	cout << ET2;
}

void MartienSud::bougerMartien() {
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

void MartienSud::removeMartien() const {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << ' ' << ' ' << ' ';
}