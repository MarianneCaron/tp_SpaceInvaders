#pragma once
#include "ExtraTerrestre.h"
#include "Martien.h"
#include "MartienExtension.h"
#include <string>
using namespace std;
class MartienSud: public MartienExtension {

private:
	string ET2;
public:
	MartienSud(int type, int valeur);

	void putMartien() const override;
	void nouvelleCoordMartien()  override;
	void resetMartien() override;
	void removeMartien() const override;
};
