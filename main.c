#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ** tab = malloc(3 * sizeof(*tab ));
	tab[2] = NULL;
	tuto();
	emplacement();
	return 0;
}