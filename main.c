#include "ft_printf.h"

int main()
{
	int a = 10;
	int b = -1000;
	int c = 3;
	char *str1 = "ALLER";
	char *str2 = "le statde";
	char z = '0';

	char *format = "%0*.*%, z = %c\n";

	setbuf(stdout, NULL);
	int retmoi = ft_printf(format, a, b, z);
	int retbibli = printf(format, a, b, z);
	printf("retour moi = %d\n", retmoi);
	printf("retour bibli = %d\n", retbibli);
//	printf("Bibli : %0*.*%, b = %d\n", a, b, c);
//	printf("Bibli : %0-10.s\n", str1);
	return(0);
}


// A FAIRE:
// - Ajouter espace debut si pas de 0 avec width
// - changer conditions de len_arg si str == NULL