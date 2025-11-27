#include <iostream>
#include <iomanip>
#include "Operacoes.h"
using namespace std;

void INSS(float salario) {
	float inss, deducao;
	cout << "--------------- INSS ---------------\n";
	cout << fixed << setprecision(2);
	if (salario > 0 && salario < 1518) {
		deducao = 0;
		cout << "> Faixa: 1\n"
			"> Alíquota: 7.5%\n"
			"> Quantia a deduzir: R$ " << deducao << endl;
		inss = (salario * 0.075);
		cout << "> \033[36mContribuição mensal do trabalhador: \033[91mR$ " << inss << "\033[0m" << endl;
		cout << "> \033[36mContribuição anual do trabalhador: \033[91mR$ " << inss * 12 << "\033[0m" << endl;
	}
	else if (salario > 1518 && salario < 2793) {
		deducao = 22.77;
		cout << "> Faixa 2.\n"
			"> Alíquota: 9%\n"
			"> Quantia a deduzir: R$ " << deducao << endl;
		inss = (salario * 0.09) - deducao;
		cout << "> \033[36mContribuição mensal do trabalhador: \033[91mR$ " << inss << "\033[0m" << endl;
		cout << "> \033[36mContribuição anual do trabalhador: \033[91mR$ " << inss * 12 << "\033[0m" << endl;
	}
	else if (salario > 2793 && salario < 4190.83) {
		deducao = 106.60;
		cout << "> Faixa 3.\n"
			"> Alíquota: 12%\n"
			"> Quantia a deduzir: R$ " << deducao << endl;
		inss = (salario * 0.12) - deducao;
		cout << "> \033[36mContribuição mensal do trabalhador: \033[91mR$ " << inss << "\033[0m" << endl;
		cout << "> \033[36mContribuição anual do trabalhador: \033[91mR$ " << inss * 12 << "\033[0m" << endl;
	}
	else if (salario > 4190.83 && salario < 8157.41) {
		deducao = 190.42;
		cout << "> Faixa 4.\n"
			"> Alíquota: 14%\n"
			"> Quantia a deduzir: R$ " << deducao << endl;
		inss = (salario * 0.14) - deducao;
		cout << "> \033[36mContribuição mensal do trabalhador: \033[91mR$ " << inss << "\033[0m" << endl;
		cout << "> \033[36mContribuição anual do trabalhador: \033[91mR$ " << inss * 12 << "\033[0m" << endl;
	}
	else if (salario > 8157.41) {
		salario = 8157.41;
		deducao = 190.42;
		cout << "> Teto máximo do INSS.\n"
			"> Alíquota: 14%\n"
			"> Quantia a deduzir: R$ " << deducao << endl;
		inss = (salario * 0.14) - deducao;
		cout << "> \033[36mContribuição mensal do trabalhador: \033[91mR$ " << inss << "\033[0m" << endl;
		cout << "> \033[36mContribuição anual do trabalhador: \033[91mR$ " << inss * 12 << "\033[0m" << endl;
	}
	else {
		cout << "> Esse salário não é válido.\n";
	}
	cout << "------------------------------------\n\n";

}

void FGTS_normal(float salario) {
	float fgts_normal = salario * 0.08;
	cout << "> Trabalhador CLT.\n"
		"> Alíquota padrão: 8%\n"
		"> \033[36mFGTS deduzido: \033[92mR$ " << fgts_normal << "\033[0m" << endl;
}

void FGTS_aprendiz(float salario) {
	float fgts_aprendiz = salario * 0.02;
	cout << "> Trabalhador Jovem Aprendiz.\n"
		"> Alíquota padrão: 2%\n"
		"> \033[36mFGTS deduzido: \033[92mR$ " << fgts_aprendiz << "\033[0m" << endl;
}

void FGTS_domestico(float salario) {
	float domestico_base = salario * 0.08;
	float domestico_rescisorio = salario * 0.032;
	cout << "> Trabalhador Doméstico.\n"
		"> Alíquota padrão (8%): " << domestico_base << "\n> Antecipação rescisória (3.2%): " << domestico_rescisorio <<
		"\n> \033[36mFGTS deduzido: \033[92mR$ " << (domestico_base + domestico_rescisorio) << "\033[0m" << endl;
}

void FGTS(float salario) {
	char tipo;
	cout << "--------------- FGTS ---------------\n";
	cout << "> Qual tipo de FGTS você deseja calcular?\n"
		"> [1] Trabalhador CLT\n"
		"> [2] Jovem Aprendiz\n"
		"> [3] Trabalhador Doméstico\n"
		"> Digite o número correspondente: "; cin >> tipo; cout << "\n\n";

	if (cin.fail()) {
		cout << "Entrada inválida! Programa encerrado." << endl;
		exit(EXIT_FAILURE);
	}
	else if (tipo == '1') {
		FGTS_normal(salario);
	}
	else if (tipo == '2') {
		FGTS_aprendiz(salario);
	}
	else if (tipo == '3') {
		FGTS_domestico(salario);
	}
	else {
		cout << "Valor inválido. Pulando FGTS...\n";
	}
	cout << "------------------------------------\n\n";

}

void Decimo_Terceiro(float salario) {
	short meses, dias;
	cout << "---------- DÉCIMO TERCEIRO ----------\n";
	cout << "> Insira a quantidade de meses completos que você trabalhou: "; cin >> meses;
	if (cin.fail() || meses < 1 || meses > 12) {
		cout << "Entrada inválida! Programa encerrado." << endl;
		exit(EXIT_FAILURE);
	}
	cout << "> Insira a quantidade de dias restantes que você trabalhou \n> [Se não tiver trabalhado dias a mais além dos meses inseridos, digite 0 (zero)]\n> Dias: "; cin >> dias;
	if (cin.fail()) {
		cout << "Entrada inválida! Programa encerrado." << endl;
		exit(EXIT_FAILURE);
	}
	float DT = (salario / 12) * meses + (dias/22);
	cout << ">\033[36m Décimo terceiro a receber: \033[92mR$ " << DT << "\033[0m" << "\n";
	cout << "------------------------------------\n\n";
}