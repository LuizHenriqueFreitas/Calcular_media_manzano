//PROGRAMA PARA CALCULAR A NOTA DO MANZANO 2ºSEMESTRE 2024 - 2º PERÍODO

#include<iostream>
#include<iomanip>

using namespace std;

int main(void)
{
    // Declaração de variáveis

    int   trab_aplicados;
    int   av_aplicadas;
    float *na;
    float assiduidade;
    float n3;
    float quant_trabalhos;
    float quant_avaliacoes;
    float n1;
    int   soma_trabalhos;
    int   soma_avaliacoes;
    float n2;
    float mf;
    int   i;
    float med_trabalhos;
    float med_avaliacoes;
    int   trab_entregues;
    int   av_entregues;

    cout << setprecision(1) << fixed << right;

    cout << "----Voce esta usando um programa para calcular a sua nota na materia de:"    << endl;
    cout << "------ LINGUAGEM DE PROGRAMAÇÃO COM J. A. MANZANO 2024 2  SEMETRE ------"    << endl;
    cout << "- Esse programa pode ser ineficiente caso o calculo do professor mude --"    << endl;
    cout << "caso realmente tenha mudado, certifique-se de fazer seu proprio programa"    << endl;
    cout << endl;
    cout << "----------    Esteja atento ao que o programa pede!!!  -----------------"    << endl;
    cout << "----------  Recomenda-se fazer a conta mais de uma vez -----------------"    << endl;
    cout << "--- Os resultados são menos precisos com menos dados, considere isso.---"    << endl;
    cout << endl;
    cout << "- para testar o codigo, os dados do exemplo do manzano no doc. do SUAP -"    << endl;
    cout << "    'LIPA-Notas avaliacoes e provas de 27 de Julho de 2024 as 08:17'    "    << endl;
    cout << endl;
    cout << "TODOS OS DADOS DEVEM SER INFORMADOS, EM CASO DE \"0\" ENTRE 1, OU VAI FALHAR"  << endl;

    cout << endl;
    cout << "Informe a quantidade de trabalhos aplicados...............:"; cin >> trab_aplicados;
    cin.ignore (80, '\n');

    cout << "Quantos deles voce entregou?..............................:"; cin >> trab_entregues;
    cin.ignore (80, '\n');
    cout << endl;

    cout << endl;
    cout << "Informe a quantas avaliacoes foram aplicadas..............:"; cin >> av_aplicadas;
    cin.ignore(80, '\n');

    cout << "Quantas delas voce entregou?..............................:"; cin >> av_entregues;
    cin.ignore (80, '\n');
    cout << endl;

    na = new float[av_aplicadas];

    cout << "Responda a seguir, com atencao (se necessario use VIRGULA)." << endl;
    for (i = 1; i <= av_aplicadas; ++i)
    {
        cout << "Informe sua nota na avaliacao " << i << ": "; cin >> na[i];
        cin.ignore(80, '\n');
    }

    cout << endl;
    cout << "Informe a sua frequencia nas aulas (ex: 100% = 10 e 48% = 4,8):"; cin >> assiduidade;
    cin.ignore(80, '\n');
    cout << endl;
    cout << "Informe a sua nota na prova semestral.........................:"; cin >> n3;
    cin.ignore(80, '\n');
    cout << endl;

    quant_trabalhos  = (10.0 / trab_aplicados) * trab_entregues;
    quant_avaliacoes = (10.0 / av_aplicadas) * av_entregues;

    n1 = (assiduidade + quant_trabalhos + quant_avaliacoes) / 3;

    soma_trabalhos  = 0;
    for (i = 1; i <= trab_entregues; ++i)
        soma_trabalhos = soma_trabalhos + 10.0;
    med_trabalhos = soma_trabalhos / trab_aplicados;

    soma_avaliacoes = 0;
    for (i = 1; i <= av_aplicadas; ++i)
        soma_avaliacoes = soma_avaliacoes + na[i];
    med_avaliacoes = soma_avaliacoes / av_aplicadas;

    n2 = (med_trabalhos + 0.0) * 0.2 + (med_avaliacoes + 0.0) * 0.8;

    mf = (n2 + n3) / 2.0 * 0.85 + n1 * 0.15;

    if (mf >= 6.0)
        cout << "---------------------  Aluno APROVADO --------------------" << endl;
    else
    {
        if (mf < 4)
            cout << "------------------------ Aluno REPROVADO -----------------" << endl;
        else
            cout << "   *    *    *      * ficou de IFA *      *     *     *   " << endl;
    }

    cout << endl;
    cout << endl;
    cout << "Sua media final e......................................: " << mf << endl;
    cout << endl;
    cout << "Sua Nota N1, Pontualidade e............................: " << n1 << endl;
    cout << "Sua Nota N2, Aproveitamento e..........................: " << n2 << endl;
    cout << "Sua Nota N3, Prova Semestral e.........................: " << n3 << endl;
    cout << endl;
    cout << "=================   Media Final: " << mf << " ==============" << endl;
    cout << endl;

    delete [] na;

    cout << endl;
    cout << "Tecle <Enter> para encerrar o programa." << endl;
    cin.get();

    return 0;
}
