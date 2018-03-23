/*
** EPITECH PROJECT, 2017
** evalexpr
** File description:
** 
*/
#include <criterion/criterion.h>
#include <stdio.h>
/*
int my_strlen(char *str)
{
	int a = 0;

	while(str[a] != '\0'){
		a = a + 1;
	}
	return(a);
}




int my_strremake(int valeurdedepart, char *str, char* calculstr)
{
	int lenght; //valeur de fin de calcul str (partie à ajouter
	int u;
	char* returnstr;
	//returnstr = str
	returnstr = malloc(sizeof(char) * my_strlen(str));
	lenght = my_strlen(calculstr);
	for (u=valeurdedepart;u-valeurdedepart <= lenght; u++)
		str[u] = calculstr[u-valeurdedepart];
	return(str);
}
*/
char *recurv_int_to_str(int my_int, char *str    ,     int cpt)
{
	if (my_int > 9) 
	{
	str[cpt] = my_int % 10;
	cpt = cpt + 1;
	my_int_to_str(my_int / 10);		
	}
	return 0;
}
int my_int_to_str(int my_int)
{
	int modulo = 10;
	int div;
	char *str;
	int i;
	int cpt = 0;
	int nb;
	malloc(sizeof(char) * 10);
	recurv_int_to_str(my_int, str, cpt);


	/*
	while(modulo < 1000000000){		
		div = modulo / 10;
		i = my_int % modulo;
		str[cpt] = i / div;
		cpt = cpt + 1;
		modulo = modulo * 10;
	}
	*/
	printf("%s\n", str);
	return (0);
}

/*
int my_str_to_int(char* my_str)
{
	int u;
	int my_new_int = 0;
	for (int i = 0; i < my_strlen(my_str); ++i)
	{
		for (u = '0'; u <= '9'; u++)
			if (my_str[i] == u)
				my_new_int = my_new_int * 10 + u - 48;
	}
	return (my_new_int);
}
*/

int main ()
{
	my_int_to_str(12345);
	/*
	char* str;
	char* calculstr;
	str = malloc(sizeof(char) * my_strlen("bonjour"));
	calculstr = malloc(sizeof(char) * my_strlen("soir"));
	str = "bonjour";
	calculstr ="soir";
	printf("%s\n", str);
	printf("%s\n", calculstr);
	my_strremake(4, "bonjour", "soir");
	*/
	return(0);
}

/*
Test(sample, test1)
{
	cr_assert(my_str_to_int("1") == "1");
}

Test(sample, test12)
{
	cr_assert(my_str_to_int("12") == "12");
}
*/