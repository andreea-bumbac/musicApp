#pragma once
#include "Song.h"
#include <iostream>
#include <fstream>
#include <vector>

class Repo
{
private:
	vector<Melodie>vector_melodii;

	//functie care citeste melodiile din fisier
	void citire_fisier();

	//functie care scrie melodii in fisier
	void scriere_fisier();

	string nume_fisier;

public:
	Repo(string nume_fisier_asignare) :nume_fisier{ nume_fisier_asignare } {

		citire_fisier();

	}

	//functie care modifica titlul si rankul melodiei
	void modifica(Melodie melodie_noua);

	//functie care sterge o melosie din vector
	void sterge(Melodie melodie_noua);

	//functie ce returneaza vectorul de melodii
	vector<Melodie> ObtineLista();
};


