//PROGRAMA PARA CALCULAR A NOTA DO MANZANO 2ºSEMESTRE 2024 - 2º PERÍODO

#include<iostream>
#include<iomanip>

using namespace std;

int main(void)
{
    // Declaração de variáveis

    int   trab_aplicados;    //quantidade de trabalhos (OU VÍDEOS) aplicados no semestre
	int   trab_entregues;    //quantidade de trabalhos/ vídeos entregues pelo aluno
	int   soma_trabalhos;    //soma dos resultados dos trabalhos de acordo com o calculo do professor
	float quant_trabalhos;   //quantidade de trabalhos entregues * 10/trabalhos aplicados
	float med_trabalhos;     //media dos trabalhos do aluno de acordo com os calculos do professor
    
	int   av_aplicadas;      //quantidade de avaliações aplicadas no semestre
	int   av_entregues;      //quantidade de avaliações entregues pelo aluno
	int   soma_avaliacoes;   //soma dos resiltados das avaliações de acordo com o calculo do professor
	float quant_avaliacoes;  //quantidade de avaliações entregues * 10/avaliações aplicadas
	float *NotasAvaliacoes;  //notas de cada avaliação aplicada
	float med_avaliacoes;    //media das avaliações de acordo com os calculos do professor 
    
    float assiduidade;       //assiduidade do aluno, 10 = 100% e 4,8 = 48% de presença
    
    float n1;                //(assiduidade + quant_trabalhos + quant_avaliacoes) / 3     -- 1ª variável usada no calculo do professor
	float n2;                //(med_trabalhos + 0.0) * 0.2 + (med_avaliacoes + 0.0) * 0.8 -- 2ª variável usada no calculo do professor
	float n3;                //Nota semestral do aluno (Nota da prova final)              -- 3ª variável usada no calculo do professor
    
    float mf;                //(n2 + n3) / 2.0 * 0.85 + n1 * 0.15                         -- calculo da média final do aluno usado pelo professor

	//configurando a precisão para 1 casa depois da vírgula
    cout << setprecision(1) << fixed << right;

	//texto de apresentação do programa
    cout << "--------Voce esta usando um programa para calcular a sua nota na materia de:----"    << endl;
    cout << "---------- LINGUAGEM DE PROGRAMAÇÃO COM J. A. MANZANO 2024 2  SEMETRE ----------"    << endl;
    cout << "----- Esse programa pode ser ineficiente caso o calculo do professor mude ------"    << endl;
    cout << "caso realmente tenha mudado, certifique-se de fazer seu proprio programa -------"    << endl;
    cout << endl;
    cout << "--------------    Esteja atento ao que o programa pede!!!  ---------------------"    << endl;
    cout << "--------------  Recomenda-se fazer a conta mais de uma vez ---------------------"    << endl;
    cout << "------- Os resultados são menos precisos com menos dados, considere isso.-------"    << endl;
    cout << endl;
    cout << "----- para testar o codigo, os dados do exemplo do manzano no doc. do SUAP -----"    << endl;
    cout << "------- 'LIPA-Notas avaliacoes e provas de 27 de Julho de 2024 as 08:17' -------"    << endl;
    cout << endl;
    cout << "- TODOS OS DADOS DEVEM SER INFORMADOS, EM CASO DE \"0\" ENTRE 1, OU VAI FALHAR -"  << endl;

	//entrada dos dados pelo usuário
	//informação sobre trabalhos e vídeos
    cout << endl;
    cout << "Informe a quantidade de trabalhos aplicados ou videos passados para assistir....:"; cin >> trab_aplicados;
    cin.ignore (80, '\n');
    cout << "Quantos deles voce entregou/ assistiu?..........................................:"; cin >> trab_entregues;
    cin.ignore (80, '\n');
    cout << endl;

	//informação sobre avaliações aplicadas
    cout << endl;
	cout << endl;
    cout << "Informe a quantas avaliacoes foram aplicadas..............:"; cin >> av_aplicadas;
    cin.ignore(80, '\n');
	//confirmação de integridade do dado
	if(av_aplicadas == 0){
		cout << "Este valor nao e valido, entre um valor positivo" << endl;
		while(av_aplicadas == 0){
			cin.ignore(80, '\n');
		}
	}
    cout << "Quantas delas voce entregou?..............................:"; cin >> av_entregues;
    cin.ignore(80, '\n');
	//comfirmação de integridade do dado
	if((av_entregues > av_aplicadas) || (av_entregues<=0)){
		cout << "Este valor nao e valido, voce pode ter entregue entre 0 e " << av_aplicadas << " avaliações." << endl;
		while((av_entregues > av_aplicadas) || (av_entregues<=0)){
			cin.ignore(80, '\n');
		}
	}
    cout << endl;
	
	//cria-se uma matriz com base na quantidade de provas que o usuário informou fazer
    NotasAvaliacoes = new float[av_aplicadas];

	//coleta as notas de cada avaliação individualmente
    cout << "Responda a seguir, com atencao (se necessario use VIRGULA)." << endl;
    for (int i = 1; i <= av_aplicadas; ++i)
    {
        cout << "Informe sua nota na avaliacao " << i << ": "; cin >> NotasAvaliacoes[i];
        cin.ignore(80, '\n');
    }

	//informações de frequencia e nota da prova final do aluno
    cout << endl;
    cout << "Informe a sua frequencia nas aulas (ex: 100% = 10 e 48% = 4,8): "; cin >> assiduidade;
    cin.ignore(80, '\n');
	//confirmação de integridade do dado
	if((assiduidade > 10) ||(assiduidade<0)){
		cout << "Este valor nao e válido, você pode ter entregue entre 0 e 10." << endl;
		while((assiduidade > 10) ||(assiduidade<0)){
			cin.ignore(80, '\n');
		}
	}
    cout << endl;
    cout << "Informe a sua nota na prova semestral(Nota da Prova final)....: "; cin >> n3;
    cin.ignore(80, '\n');
    cout << endl;

	//calculo do peso dos trabalhos e avaliações
    quant_trabalhos  = (10.0 / trab_aplicados) * trab_entregues;
    quant_avaliacoes = (10.0 / av_aplicadas) * av_entregues;

	//calculo do primeiro parâmetro usado pelo professor no calculo da média
    n1 = (assiduidade + quant_trabalhos + quant_avaliacoes) / 3;

	//soma dos trabalhos e avaliações de acordo com o calculo usado pelo professor
    soma_trabalhos  = 0;
    for (int i = 1; i <= trab_entregues; ++i)
        soma_trabalhos += 10.0;
    med_trabalhos = soma_trabalhos / trab_aplicados;

	soma_avaliacoes = 0;
    for (int i = 1; i <= av_aplicadas; ++i)
        soma_avaliacoes += NotasAvaliacoes[i];
    med_avaliacoes = soma_avaliacoes / av_aplicadas;

	//calculo do segundo parâmetro usado pelo professor no calculo da média
    n2 = (med_trabalhos + 0.0) * 0.2 + (med_avaliacoes + 0.0) * 0.8;

	//calculo da média do aluno usado pelo professor
    mf = (n2 + n3) / 2.0 * 0.85 + n1 * 0.15;

	//saída das informações de acordo com o aluno
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
	
	//condição final do aluno
	if (mf >= 6.0)
		cout << "---------------------  Aluno APROVADO --------------------" << endl;
	else
	{
		if (mf < 4)
			cout << "||||||||||||||||||||||| Aluno REPROVADO ||||||||||||||||||" << endl;
		else
			cout << "   *    *    *      * ficou de IFA *      *     *     *   " << endl;
	}

	//libera espaço na memoria
    delete [] NotasAvaliacoes;

	//encerramento do programa
    cout << endl;
    cout << "Tecle <Enter> para encerrar o programa." << endl;
    cin.get();

    return 0;
}
