#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <usuario.h>
#include <agenda.h>

int opt, id1, id2, i;
contato contcad, contcons;
FILE * agenda_arq;

void menu_agenda(usuario usuario)
{
    printf("\n--------Agenda de %s--------\n\n", usuario.nome);
    while (opt != 5)
    {
        printf ("1 - Novo Contato\n");
        printf ("2 - Alterar Contato\n");
        printf ("3 - Listar Contatos\n");
        printf ("4 - Consultar Contatos\n");
        printf ("5 - Sair\n\n");
        scanf ("%d", &opt);

        switch (opt)
	    {
	        case 1:
                cadastrar_contato(usuario.id);
	            break;

	        case 2:
                printf("\n\nDigite o ID do contato a ser alterado:\n");
                scanf("%d",&id1);
                alterar_contato(id1);
	            break;
            
            case 3:
                listar_contatos(usuario.id);
                break;
            
            case 4:
                consultar_contatos(usuario.id);
                break;
            
	    }
    }
}
void cadastrar_contato(int idusr)
{
    printf("\n\nVamos cadastrar um novo Contato:\n");
    printf("Informe o nome do contato:\n");
    scanf("%s", contcad.nome);
    printf("Informe o telefone do contato:\n");
    scanf("%s", contcad.telefone);
    printf("Informe o e-mail do contato:\n");
    scanf("%s", contcad.email);

    agenda_arq = fopen(ARQ_AGENDA, "r+b");
    fseek(agenda_arq,0,SEEK_SET);
    id2 = fgetc(agenda_arq);
    id2++;
    fseek(agenda_arq,0,SEEK_SET);
    fputc(id2, agenda_arq);
    fclose(agenda_arq);
    agenda_arq = fopen(ARQ_AGENDA, "ab");
    contcad.id_contato = id2;
    contcad.id_usuario = idusr;
    fwrite(&contcad,sizeof(usuario),1, agenda_arq);
    fclose(agenda_arq);
    printf("\nContato Cadastrado:\nID: %d\nNome: %s\nTelefone: %s\nE-mail: %s\n\n", contcad.id_contato,contcad.nome,contcad.telefone,contcad.email);

}

void alterar_contato(int id)
{

}

void listar_contatos(int id)
{
    agenda_arq = fopen(ARQ_AGENDA, "rb");
    fseek(agenda_arq,1,SEEK_SET);
    printf("\nID\tNome\tTelefone\tE-mail\n\n");
    while (( i = feof(agenda_arq)) != 1 )
    {
        fread(&contcons,sizeof(usuario),1, agenda_arq);
        if (contcons.id_usuario == id)
        {
            printf("%d\t%s\t%s\t%s\n", contcons.id_contato, contcons.nome, contcons.telefone, contcons.email);
        }
    }
    printf("\n");
    fclose(agenda_arq);
}

void consultar_contatos(int id)
{
    char pesquisa[20];
    printf("Pesquisar por nome:\n");
    scanf("%s",&pesquisa);
    agenda_arq = fopen(ARQ_AGENDA, "rb");
    fseek(agenda_arq,1,SEEK_SET);
    printf("\nID\tNome\tTelefone\tE-mail\n\n");
    while (( i = feof(agenda_arq)) != 1 )
    {
        fread(&contcons,sizeof(usuario),1, agenda_arq);
        if (contcons.id_usuario == id && (strchr(contcons.nome, *pesquisa) != NULL))
        {
            printf("%d\t%s\t%s\t%s\n", contcons.id_contato, contcons.nome, contcons.telefone, contcons.email);
        }
    }
    printf("\n");
    fclose(agenda_arq);

}