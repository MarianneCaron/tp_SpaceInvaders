#include "MartienExtension.h"

MartienExtension::MartienExtension(int type, int valeur) :Martien(type, valeur) {

}

bool MartienExtension::collision(const MartienExtension& martien) const{
	bool collision = false;
	if (this != &martien) {
		if (this->coord.getPositionY() == martien.coord.getPositionY() &&
			(this->coord.getPositionX() >= martien.coord.getPositionX()-2 &&
				this->coord.getPositionX()<= martien.coord.getPositionX()+2)) {
			collision = true;
		}
	}
	return collision;
}

bool MartienExtension::estDerriere(const MartienExtension& martien) const {
	bool derriere = false;
	if (this != &martien) {
		if (this->coord.getPositionY() < martien.coord.getPositionY() &&
			(this->coord.getPositionX() >= martien.coord.getPositionX() - 2 &&
				this->coord.getPositionX() <= martien.coord.getPositionX() + 2)) {
			derriere = true;
		}
	}
	return derriere;
}