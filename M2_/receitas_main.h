typedef struct receita Receita;

struct receita
{
    char morador[51];
    char descricao[100];
    char valor[7];
    char tipo;
    char status;
};

void preenche_receita(void);
void mostrarReceita(Receita* newreceita);
void gravarReceita(Receita* newreceita);
// void exibe_receita(Receita* mor);

char menu_principal_re(void);
void gerencia_menu_principal(void);
char ler(void);
void cadastrar_re(void);
void editar_re(void);
void excluir_re(void);
void checar_re(void);
void sobre_re(void);
char tipos(void);

