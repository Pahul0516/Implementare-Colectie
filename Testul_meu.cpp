#include "Testul_meu.h"
#include <assert.h>
#include "Colectie.h"
#include "IteratorColectie.h"


void test()
{
	Colectie c;
	assert(c.vida() == true);
	assert(c.dim() == 0); 
	c.adauga(5);
	c.adauga(1);
	c.adauga(10);
	c.adauga(7);
	c.adauga(1);
	c.adauga(1);
	c.adauga(1);
	c.adauga(1);
	assert(c.dim() == 8);
	assert(c.stergere_n_ori(1, 2) == 2);
	assert(c.stergere_n_ori(5, 2) == 1);
	assert(c.stergere_n_ori(100, 2) == -1);
	assert(c.dim() == 5);
}