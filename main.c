#include "ft_printf.h"

int main()
{
	int a = 0;
	int b = 10;
	int c = 101;
	char *str1 = "ALLER";
	char *str2 = "le stade";
	char z = '0';
	void *p;

	char *format = "%*.*x\n";

	setbuf(stdout, NULL);
	int retmoi = ft_printf(format, a, b, c);
	int retbibli = printf(format, a, b, c);
	printf("retour moi = %d\n", retmoi);
	printf("retour bibli = %d\n", retbibli);
	printf("Bibli : %-*p\n", -2, 10, p);
//	printf("Bibli : %0-10.s\n", str1);
	return(0);
}


// A FAIRE:
// - Ajouter espace debut si pas de 0 avec width
// - changer conditions de len_arg si str == NULL