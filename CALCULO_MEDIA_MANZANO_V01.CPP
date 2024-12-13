//PROGRAMA PARA CALCULAR A NOTA DO MANZANO 2�SEMESTRE 2024 - 2� PER�ODO

#include<iostream>
#include<iomanip>

//Fun��o para C�lculo de N1 usado pelo professor para calcular a nota do aluno
float CalculaN1(float trab_aplicados, float trab_entregues, float av_aplicadas, float av_entregues, float assiduidade)
{
    //Declara��o de vari�veis locais
    float quant_trabalhos;   //quantidade de trabalhos entregues * 10/trabalhos aplicados
    float quant_avaliacoes;  //quantidade de avalia��es entregues * 10/avalia��es aplicadas

    //calculo do peso dos trabalhos e avalia��es
    quant_trabalhos  = (10.0 / trab_aplicados) * trab_entregues;
    quant_avaliacoes = (10.0 / av_aplicadas) * av_entregues;

    //calculo (com retorno de fun��o) do primeiro par�metro usado pelo professor (n1) no calculo da m�dia
    return (assiduidade + quant_trabalhos + quant_avaliacoes) / 3;
}

//Fun��o para C�lculo de N2 usado pelo professor para calcular a nota do aluno
float calculaN2(float trab_aplicados, float trab_entregues, float av_aplicadas, float *NotasAvaliacoes)
{
    //Declara��o de vari�veis locais
    int   soma_trabalhos;    //soma dos resultados dos trabalhos de acordo com o calculo do professor
    int   soma_avaliacoes;   //soma dos resiltados das avalia��es de acordo com o calculo do professor
    float med_trabalhos;     //media dos trabalhos do aluno de acordo com os calculos do professor
    float med_avaliacoes;    //media das avalia��es de acordo com os calculos do professor

    //soma dos trabalhos e avalia��es de acordo com o calculo usado pelo professor
    soma_trabalhos  = 0;
    for (int i = 1; i <= trab_entregues; ++i)
        soma_trabalhos += 10.0;
    med_trabalhos = soma_trabalhos / trab_aplicados;

    soma_avaliacoes = 0;
    for (int i = 1; i <= av_aplicadas; ++i)
        soma_avaliacoes += NotasAvaliacoes[i];
    med_avaliacoes = soma_avaliacoes / av_aplicadas;

    //calculo do segundo par�metro usado pelo professor (n2) no calculo da m�dia
    return (med_trabalhos + 0.0) * 0.2 + (med_avaliacoes + 0.0) * 0.8;
}

//fun��o para controle de integridade em paradas de SIM ou N�O
char validaSeN(char resp)
{
    std::cout << "Resposta invalida, entre [S] para sim ou [N] para nao." << std::endl;
    std::cin.get(resp);
    std::cin.ignore();
    //retorna a entrada do usuario em mai�sculo
    return (toupper(resp));
}

int main(void)
{
    // Declara��o de vari�veis
	char  SeN;               //verific�o em paradas de SIM e N�O durante o programa
	char  continua;			 //usado para manter o programa aberto ou fechar ao fim da execu��o principal

    int   trab_aplicados;    //quantidade de trabalhos (OU V�DEOS) aplicados no semestre
	int   trab_entregues;    //quantidade de trabalhos/ v�deos entregues pelo aluno

	int   av_aplicadas;      //quantidade de avalia��es aplicadas no semestre
	int   av_entregues;      //quantidade de avalia��es entregues pelo aluno

	float *NotasAvaliacoes;  //notas de cada avalia��o aplicada                           -- isto � uma matriz, como preferir chamar e como � din�mica, usa ponteiro
    float assiduidade;       //assiduidade do aluno, 10 = 100% e 4,8 = 48% de presen�a

    float n1;                //(assiduidade + quant_trabalhos + quant_avaliacoes) / 3     -- 1� vari�vel usada no calculo do professor
	float n2;                //(med_trabalhos + 0.0) * 0.2 + (med_avaliacoes + 0.0) * 0.8 -- 2� vari�vel usada no calculo do professor
	float n3;                //Nota semestral do aluno (Nota da prova final)              -- 3� vari�vel usada no calculo do professor

	float n3Ifa;			 //Nota necess�ria na prova final para fazer Ifa

    float mf;                //(n2 + n3) / 2.0 * 0.85 + n1 * 0.15                         -- calculo da m�dia final do aluno usado pelo professor

	//configurando a precis�o para 1 casa depois da v�rgula
    std::cout << std::setprecision(1) << std::fixed << std::right;

	//texto de apresenta��o do programa
    std::cout << "--------Voce esta usando um programa para calcular a sua nota na materia de:----"    << std::endl;
    std::cout << "---------- LINGUAGEM DE PROGRAMA��O COM J. A. MANZANO 2024 2  SEMETRE ----------"    << std::endl;
    std::cout << "----- Esse programa pode ser ineficiente caso o calculo do professor mude ------"    << std::endl;
	std::cout << "caso realmente tenha mudado, certifique-se de fazer seu proprio programa -------"    << std::endl;
    std::cout << std::endl;
    std::cout << "--------------    Esteja atento ao que o programa pede!!!  ---------------------"    << std::endl;
    std::cout << "--------------  Recomenda-se fazer a conta mais de uma vez ---------------------"    << std::endl;
    std::cout << "------- Os resultados s�o menos precisos com menos dados, considere isso.-------"    << std::endl;
    std::cout << std::endl;
    std::cout << "----- para testar o codigo, os dados do exemplo do manzano no doc. do SUAP -----"    << std::endl;
    std::cout << "------- 'LIPA-Notas avaliacoes e provas de 27 de Julho de 2024 as 08:17' -------"    << std::endl;
    std::cout << std::endl;
    std::cout << "- *  * O PROGRAMA PODE APRESENTAR ERROS EXECUTE O CALCULO MAIS DE UMA VEZ *  * -"  << std::endl;

	//permire o inicio do programa
	continua = 'S';

	//la�o que mantem o programa em execu��o
	while(toupper(continua) == 'S'){
        // Aluno pode informar os dados de Pontualidade e Aproveitamento fornecidos pelo professor
		std::cout << std::endl;
		std::cout << "Voce ja tem as notas de Pontualidade e Aproveitamento?[S/N] "; std::cin.get(SeN);
		std::cin.ignore();
		//confirma��o de integridade do dado
		while((SeN != 'S') && (SeN != 'N')){
			SeN = validaSeN(SeN);    //chamada de fun��o
		}
		if(SeN == 'S'){
            std::cout << std::endl;
            std::cout << "Entre sua nota de pontualidade:"; std::cin >> n2;
            std::cin.ignore(80,'\n');
            std::cout << std::endl;
            std::cout << "Entre sua nota de Aproveitamento:"; std::cin >> n1;
            std::cin.ignore(80,'\n');
            std::cout << std::endl;

            n3 = (2.0 * ((6 - (n1 * 0.15))/0.85)) - n2;     //mf = 6
            //calcula a nota necess�ria para ficar de IFA
            n3Ifa = (2.0 * ((4 - (n1 * 0.15))/0.85)) - n2;  //mf = 4

            //sa�da das informa��es de acordo com o aluno
            std::cout << std::endl;
            std::cout << std::endl;

            if(n3 < 10){
                std::cout << "------------------------------------------------------------------------------" << std::endl;
                std::cout << std::endl;
                std::cout << "Para passar de semestre voce deve tirar no minimo......: " << n3 << "." << std::endl;
                std::cout << std::endl;
                std::cout << "------------------------------------------------------------------------------" << std::endl;
            }
            std::cout << std::endl;
            std::cout << "------------------------------------------------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cout << "--------Para entrar em processo de IFA, e necessario tirar.....: " << n3Ifa << " ou mais." << std::endl;
            std::cout << std::endl;
            std::cout << "------------------------------------------------------------------------------" << std::endl;
            std::cout << std::endl;
		}else{
            //entrada dos dados pelo usu�rio
            //coleta informa��o sobre trabalhos e v�deos passados
            std::cout << std::endl;
            std::cout << "Informe a quantidade de trabalhos aplicados ou videos passados para assistir....:"; std::cin >> trab_aplicados;
            std::cin.ignore (80, '\n');
            std::cout << "Quantos deles voce entregou/ assistiu?..........................................:"; std::cin >> trab_entregues;
            std::cin.ignore (80, '\n');
            std::cout << std::endl;

            //coleta informa��o sobre avalia��es aplicadas
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Informe a quantas avaliacoes foram aplicadas..............:"; std::cin >> av_aplicadas;
            std::cin.ignore(80, '\n');
            //confirma��o de integridade do dado (acredito que de para melhorar)
            if(av_aplicadas == 0){
                std::cout << "Este valor nao e valido, entre um valor positivo" << std::endl;
                while(av_aplicadas == 0){
                    std::cin >> av_aplicadas;
                    std::cin.ignore(80, '\n');
                }
            }

            //coleta informa��es sobre avalia��es entregues
            std::cout << "Quantas delas voce entregou?..............................:"; std::cin >> av_entregues;
            std::cin.ignore(80, '\n');
            //confirma��o de integridade do dado (acredito que de para melhorar)
            if((av_entregues > av_aplicadas) || (av_entregues<0)){
                std::cout << "Este valor nao e valido, voce pode ter entregue entre 0 e " << av_aplicadas << " avalia��es." << std::endl;
                while((av_entregues > av_aplicadas) || (av_entregues<0)){
                    std::cin >> av_entregues;
                    std::cin.ignore(80, '\n');
                }
            }
            std::cout << std::endl;

            //cria-se uma matriz com base na quantidade de provas que o usu�rio informou fazer
            NotasAvaliacoes = new float[av_aplicadas];

            //se o aluno nao entregou nenhuma avalia��o, todas tem nota zero
            if(av_entregues != 0){
                //coleta as notas de cada avalia��o individualmente
                std::cout << "Responda a seguir, com atencao (se necessario use VIRGULA)." << std::endl;
                for (int i = 1; i <= av_aplicadas; ++i)
                {
                    std::cout << "Informe sua nota na avaliacao " << i << ": "; std::cin >> NotasAvaliacoes[i];
                    std::cin.ignore(80, '\n');
                    //confirma��o de integridade do dado (acredito que de para melhorar)
                    if ((NotasAvaliacoes[i] < 0)||(NotasAvaliacoes[i] > 10)){
                        std::cout << "Entrada Invalida, entre um valor de 0 a 10." << std::endl;
                        std::cin >> NotasAvaliacoes[i];
                        std::cin.ignore();
                    }
                }
            }else{
                for (int i = 1; i <= av_aplicadas; ++i)
                    NotasAvaliacoes[i] = 0;
            }

            //coleta informa��es de frequencia do aluno
            std::cout << std::endl;
            std::cout << "Informe a sua frequencia nas aulas (ex: 100% = 10 e 48% = 4,8): "; std::cin >> assiduidade;
            std::cin.ignore(80, '\n');
            //confirma��o de integridade do dado (acredito que de para melhorar)
            if((assiduidade > 10)||(assiduidade<0)){
                std::cout << "Este valor nao e valido, voce pode ter entregue entre 0 e 10." << std::endl;
                std::cout << "Lembre-se que 100% = 10 e 48% = 4,8.........................:" << std::endl;
                while((assiduidade > 10) ||(assiduidade<0)){
                    std::cin >> assiduidade;
                    std::cin.ignore(80, '\n');
                }
            }

            //aluno informa se j� fez a prova final ou ainda n�o fez
            std::cout << std::endl;
            std::cout << "Voce ja fez a prova final do semestre?[S/N] "; std::cin.get(SeN);
            std::cin.ignore();
            //confirma��o de integridade do dado
            while((SeN != 'S') && (SeN != 'N')){
                SeN = validaSeN(SeN);    //chamada de fun��o
            }

            //Se 'N' o programa mostra as notas que o aluno prescisa alcan�ar para conseguir passar
            if(SeN == 'N'){
                n1 = CalculaN1(trab_aplicados, trab_entregues, av_aplicadas, av_entregues, assiduidade);  //chamada de fun��o
                n2 = calculaN2(trab_aplicados, trab_entregues, av_aplicadas, NotasAvaliacoes);            //chamada de fun��o

                //calculo da nota necess�ria na prova final para passar direto
                //equa��o de calculo de m�dia do professor no caminho reverso para entender a n3 necess�ria
                n3 = (2.0 * ((6 - (n1 * 0.15))/0.85)) - n2;     //mf = 6
                //calcula a nota necess�ria para ficar de IFA
                n3Ifa = (2.0 * ((4 - (n1 * 0.15))/0.85)) - n2;  //mf = 4

                //sa�da das informa��es de acordo com o aluno
                std::cout << std::endl;
                std::cout << std::endl;
                if((n3Ifa > 10)||(assiduidade < 7.5)){
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << std::endl;
                    std::cout << " * * * Impossivel passar, necessario tirar: " << n3Ifa << " na prova final. * * * " << std::endl;
                    std::cout << "nao e possivel nem pegar IFA, voce mandou mal mesmo dessa vez, meus pesames..." << std::endl;
                    std::cout << "----- mesmo que consiga fica te ifa, voc� reprovou pelo exesso de faltas -----" << std::endl;
                    std::cout << std::endl;
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << std::endl;
                }else{
                    if(n3Ifa < 0){
                        std::cout << "------------------------------------------------------------------------------" << std::endl;
                        std::cout << std::endl;
                        std::cout << "Para passar de semestre voc� deve tirar no minimo......: " << n3 << "." << std::endl;
                        std::cout << std::endl;
                        std::cout << "------------------------------------------------------------------------------" << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "------------------------------------------------------------------------------" << std::endl;
                        std::cout << std::endl;
                        std::cout << "--- De acordo com o programa voce vai pode de IFA mesmo tirando 0 na prova ---" << std::endl;
                        std::cout << std::endl;
                        std::cout << "------------------------------------------------------------------------------" << std::endl;
                        std::cout << std::endl;
                    }else{
                        if(n3 < 10){
                            std::cout << "------------------------------------------------------------------------------" << std::endl;
                            std::cout << std::endl;
                            std::cout << "Para passar de semestre voce deve tirar no minimo......: " << n3 << "." << std::endl;
                            std::cout << std::endl;
                            std::cout << "------------------------------------------------------------------------------" << std::endl;
                        }
                        std::cout << std::endl;
                        std::cout << "------------------------------------------------------------------------------" << std::endl;
                        std::cout << std::endl;
                        std::cout << "--------Para entrar em processo de IFA, e necessario tirar.....: " << n3Ifa << " ou mais." << std::endl;
                        std::cout << std::endl;
                        std::cout << "------------------------------------------------------------------------------" << std::endl;
                        std::cout << std::endl;
                    }
                }
                std::cout << "Sua Nota N1, Pontualidade e............................: " << n1 << std::endl;
                std::cout << "Sua Nota N2, Aproveitamento e..........................: " << n2 << std::endl;
                std::cout << std::endl;

            }else{ //caso o aluno ja tenha feito a prova final, ent�o � apresentado os dados assim como a condi��o final do aluno
                std::cout << "Informe a sua nota na prova semestral(Nota da Prova final)....: "; std::cin >> n3;
                std::cin.ignore(80, '\n');
                std::cout << std::endl;

                //Calculos de N1 e N2
                n1 = CalculaN1(trab_aplicados, trab_entregues, av_aplicadas, av_entregues, assiduidade);  //chamada de fun��o
                n2 = calculaN2(trab_aplicados, trab_entregues, av_aplicadas, NotasAvaliacoes);            //chamada de fun��o

                //calculo da m�dia do aluno usado pelo professor
                mf = ((n2 + n3) / 2.0) * 0.85 + n1 * 0.15;

                //sa�da das informa��es de acordo com o aluno
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Sua media final e......................................: " << mf << std::endl;
                std::cout << std::endl;
                std::cout << "Sua Nota N1, Pontualidade e............................: " << n1 << std::endl;
                std::cout << "Sua Nota N2, Aproveitamento e..........................: " << n2 << std::endl;
                std::cout << "Sua Nota N3, Prova Semestral e.........................: " << n3 << std::endl;
                std::cout << std::endl;
                std::cout << "=================   Media Final: " << mf << " ==============" << std::endl;
                std::cout << std::endl;

                //condi��o final do aluno
                if (mf >= 6.0)
                    std::cout << "---------------------  Aluno APROVADO --------------------" << std::endl;
                else
                {
                    if (mf < 4)
                        std::cout << "||||||||||||||||||||||| Aluno REPROVADO ||||||||||||||||||" << std::endl;
                    else
                        std::cout << "   *    *    *      * ficou de IFA *      *     *     *   " << std::endl;
                }
            }

		}
		//pergunta se o usu�rio deseja continuar no programa e fazer o calculo novamente
		std::cout << "Deseja fazer o calculo novamente? [S/N]" << std::endl;
		std::cin >> continua;
		std::cin.ignore(80, '\n');
	}

	//libera espa�o na memoria
    delete [] NotasAvaliacoes;

	//encerramento do programa
    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar o programa." << std::endl;
    std::cin.get();

    return 0;
}
