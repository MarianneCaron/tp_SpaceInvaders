#include "Timer.h"

Timer::Timer() {}

Timer::Timer(int delai) {
	this->delai = delai;
	timerValue = clock();
}

void Timer::setDelai(int delai) {
	this->delai = delai;
}

int Timer::getDelai() const {
	return delai;
}

bool Timer::estPret() {
	bool retour = false;

	if (clock() >= timerValue + delai) {
		retour = true;
		timerValue = clock();
	}

	return retour;
}

