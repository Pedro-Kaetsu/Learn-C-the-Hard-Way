/* usuario.h */

#ifndef _USUARIO_H
#define _USUARIO_H
#include <stdbool.h>

/* nome do arquivo aonde os usuários são cadastrados */
#define ARQ_USUARIO "usuario.dat"

/* estrutura que representa um usurio */
typedef struct {
    int id; // id do usuário
    char login[21]; // login do usuário
    char nome[51]; // nome do usuário
} usuario;

/* função que cadastra um novo usuário no arquivo e direciona-o
 * para a tela inicial de sua agenda, caso o cadastro tenha sido
 * bem-sucedido */
void cadastrar_usuario(void);

/* função que solicita o login do usuário e caso ele seja válido,
 * direciona-o para a tela inicial de sua agenda */
void autenticar_usuario(void);

/* função que devolve verdadeiro caso um usuário com o login
 * fornecido como primeiro argumento da função já esteja cadastrado
 * e armazena os dados desse usuário na estrutura cujo endereço
 * é passado como segundo argumento da função. Se o usuário não
 * estiver cadastrado, a função devolve falso.
 * Esta função deve ser usada pelas funções cadastrar_usuario()
 * e autenticar_usuario() */
bool usuario_existe(const char *, usuario *);

#endif
