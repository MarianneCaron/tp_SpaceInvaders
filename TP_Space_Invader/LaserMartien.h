#pragma once
#include "Laser.h"

class LaserMartien : public Laser {


public:
	void startLaserMartien(int x, int y);
	void moveLaser() override;
	void putLaserMartien();
};