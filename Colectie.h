#pragma once

#define NULL_TELEM -1z

struct TElem
{
	int val;
	int fr;
	int de_scazut;
};

class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:

	TElem* vector;
	int nr_elemente;
	int capacitate;
	/* aici e reprezentarea */
public:
		//constructorul implicit
		Colectie();	

		//adauga un element in colectie
		void adauga(int e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(int e);

		//verifica daca un element se afla in colectie
		bool cauta(int elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(int elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		void resize();

		int stergere_n_ori(int elem, int n);

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();

};

