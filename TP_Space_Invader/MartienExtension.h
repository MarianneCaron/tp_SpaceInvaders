#pragma once

#include "ExtraTerrestre.h"
#include "Martien.h"


class MartienExtension : public Martien {
public:

	MartienExtension(int, int);

	virtual void putMartien() const=0;
	virtual void resetMartien() = 0;
	virtual void bougerMartien() =0;
	virtual void removeMartien() const = 0;
	bool collision(const MartienExtension& martien) const;
};