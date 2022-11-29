#pragma once
#include <vector>
#include <string>
using namespace std;

class Melodie
{
private:
	int id, rank;

	string titlu, artist;

public:
	//constructor
	Melodie(int id, string titlu, string artist, int rank) :id{ id }, titlu{ titlu }, artist{ artist }, rank{ rank }{}

	//functie ce returneaza id.ul
	int get_ID();

	//functie ce returneaza rankul
	int get_Rank();

	//functie ce returneaza titlul
	string get_Titlu();

	//functie ce returneaza artistul
	string get_Artist();

	//functie pentru modificare rank
	void modificaRank(int rank_nou);

	//functie pentru modificare titlu
	void modificaTitlu(string titlu_nou);
};

