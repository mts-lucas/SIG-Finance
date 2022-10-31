char menu_principal_dp(void);
void gerencia_menu_principal_dp(void);
char ler_dp(void);
void cadastrar_dp(void);
void editar_dp(void);
void excluir_dp(void);
void checar_dp(void);
void sobre_dp(void);
void pagar_dp(void);
char tipos_d(void);

typedef struct despesa Despesa;

struct despesa
{
    char morador[51];
    char descricao[100];
    char valor[7];
    char tipo;
};

void preenche_despesa(Despesa *desp);
// void exibe_receita(Despesa* desp);
