typedef struct receita Receita;



struct receita
{
    char cpf[15];
    char descricao[100];
    char valor[11];
    char tipo;
    char status;
    int id;
};

void preenche_receita(void);
void mostrarReceita(Receita* newreceita);
void gravarReceita(Receita* newreceita);
// void exibe_receita(Receita* mor);

char menu_principal_re(void);
void gerencia_menu_principal(void);
char ler(void);
void editar_re(void);
void excluir_re(void);
void checar_re(void);
void sobre_re(void);
int idCadastro();
