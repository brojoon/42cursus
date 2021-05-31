#include <iostream>

void upper(char *str)
{
	for (char *to_upper = str; *to_upper != 0; to_upper++)
		if (islower(*to_upper))
			*to_upper = *to_upper - 32;
	std::cout << str;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			upper(argv[i]);
		std::cout << std::endl;
	}
	return 0;
}