#include "test.h"

void test_domain() 
//functie ce testeaza atributele clasei Melodie
{
	Melodie a(1, "a", "a", 2);
	assert(a.get_ID() == 1);
	assert(a.get_Titlu() == "a");
	assert(a.get_Artist() == "a");
	assert(a.get_Rank() == 2);
	a.modificaRank(3);
	assert(a.get_Rank() == 3);
	a.modificaTitlu("b");
	assert(a.get_Titlu() == "b");
}



void test_service()
//functie ce testeaza functionalitatile clasei Service
{
	Repo r{ "test.txt" };
	Service s{ r };
	vector<Melodie> v = s.get_all();
	assert(v.size() == 2);
	s.modificare(1, "a", 1);
	v = s.get_all();
	assert(v.at(0).get_Titlu() == "a");
	s.stergere(2);
	v = s.get_all();
	assert(v.size() == 1);
	int nr = s.filtrare("b");
	assert(nr == 1);
	ofstream fout("test.txt");
	fout << "1\na\nb\n1\n2\na\nb\n1\n";
	fout.close();
}

void test_all()
//functia ce apeleaza testele
{
	test_domain();
	test_service();
}