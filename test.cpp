#include <iostream>
#include <assert.h>

using namespace std;

void testRLPN();

int main()
{
	testRLPN();

	return 0;
}

/*
	int64_t n = 4;
	fmpz_t t, q;
	fmpz_init_set_ui(t, 5);
	fmpz_init_set_ui(q, 7);
	
	fmpz_mod_poly_t finv, f, xn1;
	fmpz_mod_poly_init(finv, q);
	fmpz_mod_poly_init(f, q);
	fmpz_mod_poly_init(xn1, q);
	fmpz_mod_poly_set_coeff_ui(xn1, 0, 1);
	fmpz_mod_poly_set_coeff_ui(xn1, n, 1);
	fmpz_mod_poly_set_coeff_ui(f, 0, 3);
	fmpz_mod_poly_set_coeff_ui(f, 1, 2);
	fmpz_mod_poly_set_coeff_ui(f, 2, 1);
	fmpz_mod_poly_set_coeff_ui(f, 3, 3);
	
	cout << "invmod = " << fmpz_mod_poly_invmod(finv, f, xn1) << endl;
	fmpz_mod_poly_print(xn1); flint_printf("\n");
	fmpz_mod_poly_print(f); flint_printf("\n");
	fmpz_mod_poly_print(finv); flint_printf("\n");
	
	mod_poly g( (int_ll_t) 7);
	cout << "invmod = " << fmpz_mod_poly_invmod(g.X._data().inner, f, xn1) << endl;
	fmpz_mod_poly_print(xn1); flint_printf("\n");
	fmpz_mod_poly_print(f); flint_printf("\n");
	flint::print(g.X); flint_printf("\n");
*/

#include "fmpz_mod_polyxx.h"

void testRLPN()
{
	using namespace flint;
	frandxx state;

	int n = 32;
	fmpzxx t(2);

	fmpz_mod_polyxx f(t), g(t), h(t), h1(t), h2(t), xn1(t);

	xn1.set_randtest_monic_irreducible(state, n);
	xn1._poly;
	xn1.print();
	cout << endl;
	h1.set_coeff(0, 1);

	for (int i = 0; i < 100; i++)
	{
		f.set_randtest_not_zero(state, n);
		g = f.invmod(xn1);
		h = f * g;
		h = h % xn1;
		assert(h == h1);
	}
}

