#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>
#include <malloc.h>


using namespace std;


Colectie::Colectie() {
	/* de adaugat */
	this->capacitate = 2;
	this->nr_elemente = 0;
	this->vector = new TElem[this->capacitate];
}

// complexitate este teta de n unde n este numarul de elemente a colectiei
void Colectie::adauga(int elem) {
	/* de adaugat */
	if (cauta(elem) == true)
	{
		for (int i = 0; i < nr_elemente; i++)
		{
			if (this->vector[i].val == elem)
			{
				this->vector[i].fr++;
				this->vector[i].de_scazut++;
			}
		}
	}
	else
	{
		if (nr_elemente != capacitate)
		{
			this->vector[nr_elemente].val = elem;
			this->vector[nr_elemente].fr = 1;
			this->vector[nr_elemente].de_scazut = 1;
			this->nr_elemente += 1;
		}
		else
		{
			while (nr_elemente==capacitate)
			{
				resize();
			}
			this->vector[nr_elemente].val = elem;
			this->vector[nr_elemente].fr = 1;
			this->vector[nr_elemente].de_scazut = 1;
			this->nr_elemente += 1;
		}

	}

}

// complexitate este O de n unde n este numarul de elemente a colectiei
bool Colectie::sterge(int elem) {
	/* de adaugat */
	if (this->cauta(elem) == true)
	{
		int poz = 0;
		for (int i = 0; i < this->nr_elemente; i++)
		{
			if (this->vector[i].val == elem)
			{
				poz = i;
				break;
			}
		}
		if (this->vector[poz].fr == 1)
		{
			for (int i = poz; i < this->nr_elemente; i++)
			{
				this->vector[i] = this->vector[i + 1];
			}
			this->nr_elemente--;
		}
		else
		{
			this->vector[poz].fr--;
		}
		return true;
	}
	else
		return false;
}

// complexitate este O de n unde n este numarul de elemente a colectiei
bool Colectie::cauta(int elem) const {
	/* de adaugat */
	for (int i = 0; i < this->nr_elemente; i++)
	{
		if (this->vector[i].val == elem)
			return true;
	}
	return false;
}

// complexitate este O de n unde n este numarul de elemente a colectiei
int Colectie::nrAparitii(int elem) const {
	/* de adaugat */
	int contor = 0;
	for (int i = 0; i < this->nr_elemente; i++)
	{
		if (this->vector[i].val == elem)
			return this->vector[i].fr;
	}
	return 0;
}

// complexitate este teta de n*fre unde n este numarul de elemente a colectiei iar fre este frecventa unui element
int Colectie::dim() const {
	/* de adaugat */
	int dimensiune = 0;
	for (int i = 0; i < nr_elemente; i++)
	{
		int fre = this->vector[i].fr;
		while (fre!=0) {
			dimensiune++;
			fre--;
		}
	}
	return dimensiune;
}

// complexitate este teta de 1
bool Colectie::vida() const {
	/* de adaugat */
	if (this->nr_elemente == 0)
		return true;
	else
		return false;
}


// complexitate este teta de n unde n este numarul de elemente a colectiei daca exista elementul in colectie sau teta de 1 daca nu exista
int Colectie::stergere_n_ori(int elem, int n)
{
	if (this->cauta(elem) == true)
	{
		int poz = 0;
		for (int i = 0; i < this->nr_elemente; i++)
		{
			if (this->vector[i].val == elem)
			{
				poz = i;
				break;
			}
		}
		if (this->vector[poz].fr - n > 0)
		{
			this->vector[poz].fr -= n;
			return n;
		}
		else
		{
			int frecventa = this->vector[poz].fr;
			for (int i = poz; i < this->nr_elemente; i++)
			{
				this->vector[i] = this->vector[i + 1];
			}
			this->nr_elemente--;
			return frecventa;
		}
	}
	else
	{
		return - 1;
	}
}

// complexitate este teta de n unde n este numarul de elemente al colectiei (complexitate amortizata)
void Colectie::resize() {
	TElem* vector_nou = new TElem[2 * this->capacitate];
	for (int i = 0; i < this->nr_elemente; i++)
	{
		vector_nou[i] = this->vector[i];
	}
	delete[]this->vector;
	this->vector = vector_nou;
	this->capacitate = this->capacitate * 2;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* de adaugat */
	this->capacitate = 0;
	this->nr_elemente = 0;
	delete[] this->vector;
}


