#include "Jeu.h"
#include "Affichage.h"
#include "MartienNord.h"
#include "MartienSud.h"
#include <Windows.h>
#include <time.h>	// pour time(int)
#include <stdlib.h>	// pour srand(int) et rand()

Jeu::Jeu(int niveau) :
	niveau(niveau), score(0), nbVies(5), premierTour(true), nbLasers(0), nbTirET(0)
{
	nouveauET.setDelai(5000 - ((niveau - 1) * 1500));
	nouveauTirET.setDelai(1000 - ((niveau - 1) * 200));
}

Jeu::~Jeu() {
	//Pour le tableau de Martiens
	for (int i = 0; i < ExtraTerrestre::getNombreExtraTerrestre(); i++) {
		delete lesET[i];
	}
	ExtraTerrestre::resetNombreExtraTerrestre();
	//Pour le tableau de Lasers
	for (int i = 0; i < nbLasers; i++) {
		delete lesLasers[i];
	}
	//Pour le tableau de tir de Martiens
	for (int i = 0; i < nbTirET; i++) {
		delete lesTirET[i];
	}
}

void Jeu::boucleJeu() {
	bool partieTermine = false;

	// **********************************************Boucle de la partie*************************************************** //
	while (!partieTermine) {
		// Affichage des scores
		Affichage::afficherScore(niveau, score, nbVies);

		bougerLasers();
		collisionLaserEt();
		collisionLaserVaisseau();
		actionJoueur();
		tirMartien();
		bougerMartien();
		apparitionMartien();

		// ****** Condition de fin de partie ************ //
		if ((ExtraTerrestre::getNombreExtraTerrestre() == 15) ||
			(ExtraTerrestre::getNombreExtraTerrestre() == 0) ||
			nbVies == 0)
		{
			partieTermine = true;
		}
	}	//************************** Fin de la boucle de la partie ********************************************//
}

bool Jeu::collisionEntreMartiens(const MartienExtension & martien) {
	bool collision = false;
	for (int i = 0; i < ExtraTerrestre::getNombreExtraTerrestre(); i++) {
		if (martien.collision(*lesET[i])) {
			collision = true;
		}
	}
	return collision;
}

bool Jeu::champLibreTirer(const MartienExtension & martien) {
	bool champLibre = true;
	for (int i = 0; i < ExtraTerrestre::getNombreExtraTerrestre(); i++) {
		if (martien.estDerriere(*lesET[i])) {
			champLibre = false;
		}
	}
	return champLibre;
}

void Jeu::bougerLasers() {

	// Faire bouger les lasers
	for (int i = 0; i < nbLasers; i++) {
		if ((lesLasers[i]->coord.getPositionY()) - 1 == 0) {
			lesLasers[i]->removeLaser();
			lesLasers[i] = lesLasers[nbLasers - 1];
			nbLasers--;
		}
		if (lesLasers[i]->isAlive && lasersTimer[i].estPret()) {
			lesLasers[i]->moveLaser();
		}
	}
}

void Jeu::collisionLaserEt() {
	// Test de collision entre les lasers et les ET
	for (int i = 0; i < nbLasers; i++) {
		for (int j = 0; j < ExtraTerrestre::getNombreExtraTerrestre(); j++) {
			if ((lesLasers[i]->coord.getPositionX() == lesET[j]->coord.getPositionX() ||
				lesLasers[i]->coord.getPositionX() == lesET[j]->coord.getPositionX() + 1 ||
				lesLasers[i]->coord.getPositionX() == lesET[j]->coord.getPositionX() + 2)
				&& lesLasers[i]->coord.getPositionY() == lesET[j]->coord.getPositionY()) {

				// Traitement du laser
				lesLasers[i]->removeLaser();
				lesLasers[i] = lesLasers[nbLasers - 1];
				nbLasers--;

				//Traitement des ET
				lesET[j]->removeMartien();
				score += lesET[j]->ajouterPoints();
				lesET[j] = lesET[ExtraTerrestre::getNombreExtraTerrestre() - 1];
				ExtraTerrestre::reduireNombreExtraTerrestre();
			}
		}
	}
}

void Jeu::collisionLaserVaisseau() {
	// Test de collision entre les lasers des ET et le vaisseau
	for (int i = 0; i < nbTirET; i++) {
		if ((lesTirET[i]->coord.getPositionX() >= leJoueur.getVaisseau().coord.getPositionX() &&
			lesTirET[i]->coord.getPositionX() <= leJoueur.getVaisseau().coord.getPositionX() + 6)
			&& lesTirET[i]->coord.getPositionY() == leJoueur.getVaisseau().coord.getPositionY() - 1) {

			// Traitement du laser
			lesTirET[i]->removeLaser();
			lesTirET[i] = lesTirET[nbTirET - 1];
			nbTirET--;

			//Baisser nombre de vies
			nbVies--;
			Beep(300, 50);
		}
	}
}

void Jeu::actionJoueur() {
	// Action du joueur
	if (leJoueur.operationVaisseau()) {
		lesLasers[nbLasers] = new Laser;
		lesLasers[nbLasers]->startLaser(leJoueur.getVaisseau().coord.getPositionX() + 3);
		lasersTimer[nbLasers].setDelai(50);
		nbLasers++;
		Beep(500, 50);
	}
}

void Jeu::tirMartien() {
	// les tir des Martiens
	// Faire bouger les  tirs courants
	for (int i = 0; i < nbTirET; i++) {
		if ((lesTirET[i]->coord.getPositionY()) + 1 == 45) {
			lesTirET[i]->removeLaser();
			lesTirET[i] = lesTirET[nbTirET - 1];
			nbTirET--;
		}
		if (TirETTimer[i].estPret()) {
			lesTirET[i]->moveLaser();
		}
	}

	// Les nouveaux tir
	if (nouveauTirET.estPret()) {
		for (int i = 0; i < ExtraTerrestre::getNombreExtraTerrestre(); i++) {
			if ((lesET[i]->coord.getPositionX() - leJoueur.getVaisseau().coord.getPositionX() < 10)
				&& (lesET[i]->coord.getPositionX() - leJoueur.getVaisseau().coord.getPositionX() > -10)
				&& champLibreTirer(*lesET[i]))
			{
				lesTirET[nbTirET] = new LaserMartien;
				lesTirET[nbTirET]->startLaserMartien(lesET[i]->coord.getPositionX() + 1, lesET[i]->coord.getPositionY() + 1);
				TirETTimer[nbTirET].setDelai(100);
				nbTirET++;
			}
		}
	}
}

void Jeu::bougerMartien() {
	//Faire bouger les ET
	for (int i = 0; i < MAX_ET; i++) {
		if (i < ExtraTerrestre::getNombreExtraTerrestre() && ETTimer[i].estPret()) {
			int anciennePosX = lesET[i]->coord.getPositionX();
			int anciennePosY = lesET[i]->coord.getPositionY();
			lesET[i]->removeMartien();
			lesET[i]->nouvelleCoordMartien();
			if (collisionEntreMartiens(*lesET[i])) {
				lesET[i]->coord.setPositionX(anciennePosX);
				lesET[i]->coord.setPositionY(anciennePosY);
			}
			lesET[i]->putMartien();
		}
	}
}

void Jeu::apparitionMartien() {
	//Faire apparaitre les ET
	if (nouveauET.estPret() || premierTour) {

		int percent = (rand() % 100 + 1);
		if (percent < 70) {
			lesET[MartienExtension::getNombreExtraTerrestre()] = new MartienNord(1, 100);
			ETTimer[MartienExtension::getNombreExtraTerrestre()].setDelai(1000 - ((niveau - 1) * 200));
		}
		else {
			lesET[MartienExtension::getNombreExtraTerrestre()] = new MartienSud(2, 200);
			ETTimer[MartienExtension::getNombreExtraTerrestre()].setDelai(500 - ((niveau - 1) * 50));
		}
		lesET[MartienExtension::getNombreExtraTerrestre()]->resetMartien();
		// Boucle pour s'assurer que les aliens n'apparaissent pas sur un autre alien
		do {
			if (collisionEntreMartiens(*lesET[MartienExtension::getNombreExtraTerrestre() - 1]))
			{
				MartienExtension::reduireNombreExtraTerrestre();
				lesET[MartienExtension::getNombreExtraTerrestre()]->resetMartien();
			}
		} while (collisionEntreMartiens(*lesET[MartienExtension::getNombreExtraTerrestre() - 1]));
		lesET[MartienExtension::getNombreExtraTerrestre() - 1]->putMartien();
		premierTour = false;
	}
}