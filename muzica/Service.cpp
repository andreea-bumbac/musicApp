#include "Service.h"

void Service::modificare(int id, string titlu, int rank)
//functie pentru modificare melodie
//date de intrare:   id,rank - intreg,  titlu - string
{
	Melodie melodie(id, titlu, "", rank);
	repo.modifica(melodie);

}

void Service::stergere(int id)
//functie pentru stergere melodie dupa id
//date de intrare:    id - intreg
{
	Melodie melodie(id, "", "", 0);
	repo.sterge(melodie);
}
 
vector<Melodie> Service::get_all()
//functie ce returneaza vectorul de piese sortat dupa rank
//date de iesire:  piese - vector<Melodie>
{

	vector<Melodie> piese = repo.ObtineLista();
	sort(piese.begin(), piese.end(), [&](Melodie melodia1, Melodie melodia2) {
		return melodia1.get_Rank() < melodia2.get_Rank(); });
	return piese;
}

int Service::filtrare(string artist)
//functie ce returneaza numarul de melodii ale artistului
//date de intrare:   artist - string
//date de iesire:   numar - intreg
{
	int numar = 0;
	vector<Melodie> melodii = repo.ObtineLista();
	for (auto melodie : melodii)
	{
		if (melodie.get_Artist() == artist)
			numar++;
	}
	return numar;
}

int Service::filtrare2(int rank)
//functie ce returneaza numarul de melodii cu acelasi rank
//date de intrare:   rank - intreg
//date de iesire:   numar - intreg
{
	int numar = 0;
	vector<Melodie> melodii = repo.ObtineLista();
	for (auto melodie : melodii)
	{
		if (melodie.get_Rank() == rank)
			numar++;
	}
	return numar;
}
