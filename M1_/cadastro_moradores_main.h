void interacao_menu_cad_morador(void);
char menu_cad_moradores(void);
char ler(void);
void cad_morador(void);
void visualizar_morador(void);
void sobre_moradores(void);
void deletar_morador(void);
void altera_morador(void);

typedef struct morador Morador;

struct morador
{
    char nome[51];
    char cpf[12];
    char idade[4];
    char ocupacao[12];
    char renda[7];
};

void preenche_morador(Morador* mor);
// void exibe_morador(Morador *mor);