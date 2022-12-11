typedef struct saldo Saldo;

struct saldo
{
    float valor_atual;
    float valor_despesas;
};

int dia_do_ano(int, int, int);
int bissexto(int);
int dataValida(int, int, int);
// char data_atual(void);
int validar_formato_data(char data[11], int tam);
int validar_letras(char nome[], int tam);
int validar_dinheiro(char dinheiro[], int tam);
char verificarcpf(char *cpf, int tam);
int validar_idade(char idade[], int tam);

void ler_nome(char *name);
void ler_cpf(char *cpf);
void ler_cpf_cad(char *cpf);
void ler_idade(char *idade);
void ler_ocupacao(char *ocupacao);
void ler_renda(char *renda);
void ler_descricaor(char *descricaor);
void ler_valordepositado(char *deposito);
char tipos_rec(void);
char tipos_despesa(void);
int idReceita();
int idDespesa();
int validar_id(char *id, int tam);
void ler_id(char *id);
int transform_to_integer(char *vetorchar, int tam);
float transform_to_float(char *vetorchar, int tam);
int checarCPF(char *cpf);
void ler_data(char *data);
void gravarSaldo(Saldo *newsaldo);
float ultimoSaldo(void);
void mostrarSaldo(Saldo *newsaldo);
float ultimaDespesa(void);
int compararDatas(char* datainicial, char* datafinal, char* dataarch);
int convertDataToInt(char* data, int func);