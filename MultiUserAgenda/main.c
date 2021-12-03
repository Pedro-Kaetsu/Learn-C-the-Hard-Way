#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <usuario.h>
#include <agenda.h>

int option;

int main ()
{
    while (option != 3)
    {
        printf ("----------Menu Principal----------\n\n");
        printf ("1 - Primeiro Acesso\n");
        printf ("2 - Acessar Agenda\n");
        printf ("3 - Sair\n");
        scanf ("%d", &option);

        switch (option)
	    {
	        case 1:
                cadastrar_usuario();
	            break;

	        case 2:
                autenticar_usuario();
	            break;
            
	    }
    }
    
    return 0;
}