#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <usuario.h>
#include <agenda.h>

usuario usercad, usercons, useraut;
int id;
FILE * user_arq;

void cadastrar_usuario(void)
{
    printf("\n\nVamos Realizar seu cadastro:\n");
    printf("Informe um Login para acessar sua agenda:\n");
    scanf("%s", usercad.login);
    printf("Informe Seu Nome:\n");
    scanf("%s", usercad.nome);
    if ((usuario_existe(usercad.login, &usercad)) == 1)
    {
        printf("\n\nJa existe um usuario com esse login, tente novamente.\n");
    }
    else 
    {
        user_arq = fopen(ARQ_USUARIO, "r+b");
        fseek(user_arq,0,SEEK_SET);
        id = fgetc(user_arq);
        id++;
        fseek(user_arq,0,SEEK_SET);
        fputc(id, user_arq);
        fclose(user_arq);
        user_arq = fopen(ARQ_USUARIO, "ab");
        usercad.id = id;
        fwrite(&usercad,sizeof(usuario),1, user_arq);
        fclose(user_arq);
        printf("\nDados Cadastrados:\nID: %d\nLogin: %s\nNome: %s", usercad.id,usercad.login,usercad.nome);
        autenticar_usuario();
    }
}

void autenticar_usuario(void)
{
    printf("\n\nEntre com seu login:\n");
    scanf("%s",&useraut.login);
    if ((usuario_existe(useraut.login, &useraut)) == 1)
    {
        printf("\nUsuario Autenticado com Sucesso!\n");
        menu_agenda(useraut);
    }
    else
    {
        printf("\nOpa, login errado\n");
    }
}

bool usuario_existe(const char * login, usuario *usr)
{
    int i;
    user_arq = fopen(ARQ_USUARIO, "rb");
    fseek(user_arq,1,SEEK_SET);
    while (( i = feof(user_arq)) != 1 )
    {
        fread(&usercons,sizeof(usuario),1, user_arq);
        if ((strcmp(usercons.login, login)) == 0)
        {
            strcpy(usr->login, usercons.login);
            usr->id = usercons.id;
            strcpy(usr->nome, usercons.nome);
            return 1;
        }
    }
    fclose(user_arq);  
    return 0;  
}