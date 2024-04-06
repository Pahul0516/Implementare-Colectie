#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c): col(c){
	/* de adaugat */
	prim();
}

void IteratorColectie::prim() {
	/* de adaugat */
	index = 0;
	
}

// complexitate teta de 1
void IteratorColectie::urmator() {
	/* de adaugat */
	if (valid())
	{
		if (col.vector[index].de_scazut > 1)
		{
			col.vector[index].de_scazut--;
		}
		else
		{
			col.vector[index].de_scazut = col.vector[index].fr;
			index++;
		}

	}

}

// complexitate teta de 1
bool IteratorColectie::valid() const {
	/* de adaugat */
	if (index > col.nr_elemente - 1)
		return false;
	else
		return true;
}


// complexitate teta de 1
TElem IteratorColectie::element() const {
	/* de adaugat */
	if (valid() == false)
	{
		throw ("Nu-i bun iteratorul");
	}
	else

		return col.vector[index];
}
