#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	if(argc < 3)
	{
		fprintf(stderr, "Invalid number or arguments!\n");
		return 1;
	}

	char message[strlen(argv[1])];
	int shift = strtol(argv[2], NULL, 10);
	char ch;

	strcpy(message, argv[1]);
	
	for(int i = 0; message[i] != '\0'; i++)
	{
		ch = message[i];
		
		if(ch >= 'a' && ch <='z'){
			ch = ch + shift;
			
			if(ch > 'z')
			{
				ch = ch - 'z' + 'a' - 1;
			}

			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z')
		{
			ch = ch + shift;

			if(ch > 'Z')
			{
				ch = ch - 'Z' + 'A' -1;
			}

			message[i] = ch;
		}

	}

	printf("%s\n", message);

	return 0;
}
