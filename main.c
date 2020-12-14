#include "ft_printf.h"

int main()
{
	int a = 6;
	int b = 4;
	int c = 3;
	char *str1 = "ALLER";
	char *str2 = "le statde";
	char z = '0';

	char *format = " %*.5s %*.5s \n";

	setbuf(stdout, NULL);
	int retmoi = ft_printf(format, -10, "123", -10, "4567");
	int retbibli = printf(format, -10, "123", -10, "4567");
	printf("retour moi = %d\n", retmoi);
	printf("retour bibli = %d\n", retbibli);
//	printf("Bibli : %0010.12d\n", a);
//	printf("Bibli : %0-10.s\n", str1);
	return(0);
}


// A FAIRE:
// - Ajouter espace debut si pas de 0 avec width
// - changer conditions de len_arg si str == NULL