#include "Laser.h"
#include "LaserMartien.h"

#include <iostream>
using namespace std;

void LaserMartien::startLaserMartien(int x, int y) {
	coord.setPositionX(x);
	coord.setPositionY(y+1);
	putLaser();
	isAlive = true;
}

void LaserMartien::moveLaser() {
	removeLaser();
	coord.setPositionY(coord.getPositionY() + 1);
	putLaser();
}

void LaserMartien::putLaserMartien() {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << char(46);
}