#include "Song.h"

int Melodie::get_ID()
//functie ce returneaza id.ul
//date de iesire:   id - intreg
{
	return id;
}

int Melodie::get_Rank()
//functie ce returneaza rankul
//date de iesire:  rank - intreg
{
	return rank;
}

string Melodie::get_Titlu()
//functie ce returneaza titlul
//date de iesire:   titlu - string
{
	return titlu;

}

string Melodie::get_Artist()
//functie ce returneaza artistul
//date de iesire:   artist - string
{
	return artist;
}

void Melodie::modificaRank(int rank_nou)
//functie de modificare rank
//date de intrare:  rank_nou - string
{
	rank = rank_nou;
}

void Melodie::modificaTitlu(string titlu_nou)
//functie pentru modificare titlu
//date de intrare:  titul_nou - string
{
	titlu = titlu_nou;
}

