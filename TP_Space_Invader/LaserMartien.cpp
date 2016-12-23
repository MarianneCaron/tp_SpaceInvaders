#include "Laser.h"
#include "LaserMartien.h"

#include <iostream>
using namespace std;

void LaserMartien::startLaserMartien(int x, int y) {
	removeLaser();
	coord.setPositionX(x);
	coord.setPositionY(y+1);
	putLaser();
	isAlive = true;
}

void LaserMartien::moveLaser() {
	removeLaser();
	coord.setPositionY(coord.getPositionY() + 1);
	putLaserMartien();
}

void LaserMartien::putLaserMartien() {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << "'";
}