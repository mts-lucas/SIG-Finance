typedef struct morador Morador;

struct morador
{
    char nome[51];
    char cpf[15];
    char idade[4];
    char ocupacao[20];
    float renda;
    char status;
};

void preenche_morador(void);
void mostrarMorador(Morador* mor);
void gravarMorador(Morador* mor);
void visualizar_morador(void);
void interacao_menu_cad_morador(void);
char menu_cad_moradores(void);
char ler(void);
void sobre_m1(void);
void deletar_morador(void);
void altera_morador(void);
void buscarUm(void);
