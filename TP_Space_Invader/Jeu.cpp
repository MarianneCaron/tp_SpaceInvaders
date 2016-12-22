#include "Jeu.h"
#include "Affichage.h"
#include "MartienNord.h"
#include "MartienSud.h"

#include <time.h>	// pour time(int)
#include <stdlib.h>	// pour srand(int) et rand()

Jeu::Jeu(int niveau):
niveau(niveau), score(0), premierTour(true), nbLasers(0),  nbTirET(0)
{
	nouveauET.setDelai(3000);
	nouveauTirET.setDelai(1000);
}

void Jeu::boucleJeu() {
	bool partieTermine = false;

	
	// **********************************************Boucle de la partie*************************************************** //
	while (!partieTermine) {
		// Affichage des scores
		Affichage::afficherScore(score);

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

		// Test de collision

		for (int i = 0; i < nbLasers; i++) {
			//for (int i = 0; i < nbLasers; i++) {  // lit des lasers pas encore initialisé
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


		// Action du joueur

		if (leJoueur.operationVaisseau()) {
			lesLasers[nbLasers] = new Laser;
			lesLasers[nbLasers]->startLaser(leJoueur.getVaisseau().coord.getPositionX());
			lasersTimer[nbLasers].setDelai(50);
			nbLasers++;
		}


		/*//Faire bouger les ET
		for (int i = 0; i < MAX_ET; i++) {
		if (i < ExtraTerrestre::getNombreExtraTerrestre() && ETTimer[i].estPret()) {
		lesET[i]->bougerMartien();
		lesET[i]->putMartien();
		}
		}*/

		//Faire apparaitre les ET
		if (nouveauET.estPret() || premierTour) {

			int percent = (rand() % 100 + 1);
			if (percent < 70) {
				lesET[MartienExtension::getNombreExtraTerrestre()] = new MartienNord(1, 10);
				ETTimer[MartienExtension::getNombreExtraTerrestre()].setDelai(1000);
			}
			else {
				lesET[MartienExtension::getNombreExtraTerrestre()] = new MartienSud(1, 20);
				ETTimer[MartienExtension::getNombreExtraTerrestre()].setDelai(500);
			}
			lesET[MartienExtension::getNombreExtraTerrestre()]->resetMartien();
			lesET[MartienExtension::getNombreExtraTerrestre() - 1]->putMartien();
			premierTour = false;
		}



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
				if ((lesET[i]->coord.getPositionX() - leJoueur.getVaisseau().coord.getPositionX() < 5)
					&& (lesET[i]->coord.getPositionX() - leJoueur.getVaisseau().coord.getPositionX() > -5))
				{
					lesTirET[nbTirET] = new LaserMartien;
					lesTirET[nbTirET]->startLaserMartien(lesET[i]->coord.getPositionX(), lesET[i]->coord.getPositionX());
					TirETTimer[nbTirET].setDelai(100);
					nbTirET++;
				}
			}
		}

		// ****** Condition de fin de partie ************ //
		if ((ExtraTerrestre::getNombreExtraTerrestre() == 15) || 
			(ExtraTerrestre::getNombreExtraTerrestre() == 0)) {
			partieTermine = true;
		}

	}	//************************** Fin de la boucle de la partie ********************************************//

}

bool Jeu::collisionEntreMartiens(const MartienExtension & martien ) {
	for (int i = 0; i < ExtraTerrestre::getNombreExtraTerrestre(); i++) {
		if (martien.collision(*lesET[i])) {
			return true;
		}
	}
	return false;
}