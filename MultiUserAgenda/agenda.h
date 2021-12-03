/* agenda.h */

#ifndef _AGENDA_H
#define _AGENDA_H
#include <stdbool.h>
#include "usuario.h"

/* nome do arquivo aonde os contados da agenda são cadastrados */
#define ARQ_AGENDA "agenda.dat"

/* estrutura que representa um contato da agenda */
typedef struct {
    int id_usuario; // id do usuário da agenda
    int id_contato; // id do contato
    char nome[51]; // nome do contato
    char telefone[16]; // telefone do contato
    char email[31]; // e-mail do contato
} contato;

/* função que recebe o um usuário como argumento e
 * exibe a tela inicial de sua agenda */
void menu_agenda(usuario);

/* função que cadastra um novo contato para o usuário
 * cujo id é fornecido como argumento da função */
void cadastrar_contato(int);

/* função que recebe como argumento o id de um contato
 * e permite alterar os dados desses contato, caso seu
 * id seja válido */
void alterar_contato(int);

/* função que lista todos os contatos de um usuário cujo
 * id é fornecido como argumento */
void listar_contatos(int);

/* função que permite consultar por nome os contatos de
 * um usuário cujo id é fornecido como argumento */
void consultar_contatos(int);

#endif