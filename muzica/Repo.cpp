#include "Repo.h"

void Repo::citire_fisier()
//functie care citeste melodiile din fisier
{
	ifstream fin(nume_fisier);
	int id, rank;
	string titlu, artist;
	while (fin >> id)
	{
		fin >> titlu >> artist >> rank;
		Melodie melodie(id, titlu, artist, rank);
		vector_melodii.push_back(melodie);
	}
	fin.close();
}

void Repo::scriere_fisier()
//functie care scrie melodii in fisier
{
	ofstream fout(nume_fisier);
	for (auto melodie : vector_melodii)
	{
		fout << melodie.get_ID() << '\n' << melodie.get_Titlu() << '\n' << melodie.get_Artist() << '\n' << melodie.get_Rank() << '\n';

	}
	fout.close();
}

void Repo::modifica(Melodie melodie_noua)
//functie care modifica titlul si rankul melodiei 
//date de intrare:    melodie_noua - Melodie
{
	for (auto& melodie : vector_melodii)
	{
		if (melodie.get_ID() == melodie_noua.get_ID())
		{
			melodie.modificaRank(melodie_noua.get_Rank());
			melodie.modificaTitlu(melodie_noua.get_Titlu());
			scriere_fisier();
		}
	}
}

void Repo::sterge(Melodie melodie_noua)
//functie care sterge o melodie din vector
//date de intrare:  melodie_noua - Melodie
{
	int i = 0;
	for (auto& melodie : vector_melodii)
	{
		if (melodie.get_ID() == melodie_noua.get_ID())
		{
			vector_melodii.erase(vector_melodii.begin() + i); scriere_fisier(); break;
		}
		i++;
	}



}

vector<Melodie> Repo::ObtineLista()
//functie ce returneaza vectorul de melodii
//date de iesire:  vector_melodii - vector<Melodie>
{
	return vector_melodii;
}