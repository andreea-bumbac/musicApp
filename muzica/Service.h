#pragma once
#include "Repo.h"
#include <algorithm>
#include <vector>

class Service
{
private:
	Repo repo;

public:
	Service(Repo repo_dat) :repo{ repo_dat } {}

	//functie pentru modificare melodie
	void modificare(int id, string titlu, int rank);

	//functie pentru stergere melodie dupa id
	void stergere(int id);

	//functie ce returneaza vectorul de melodii sortat dupa rank
	vector<Melodie> get_all();

	//functie ce returneaza numarul de melodii ale artistului
	int filtrare(string artist);

	//functie ce returneaza numarul de melodii cu acelasi rank
	int filtrare2(int rank);
};
