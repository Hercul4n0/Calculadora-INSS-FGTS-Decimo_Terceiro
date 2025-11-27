#include <iostream>
#include <iomanip>
#include "Operacoes.h"
using namespace std;

int main() {
	
	cout << "\033[36m" R"(
  /$$$$$$ /$$   /$$$$$$$$        /$$$$$$          /$$         
 /$$__  $| $$  |__  $$__/       /$$__  $$        | $$              
| $$  \__| $$     | $$         | $$  \__/ /$$$$$$| $$ /$$$$$$$    
| $$     | $$     | $$         | $$      |____  $| $$/$$_____/
| $$     | $$     | $$         | $$       /$$$$$$| $| $$      
| $$    $| $$     | $$         | $$    $$/$$__  $| $| $$      
|  $$$$$$| $$$$$$$| $$         |  $$$$$$|  $$$$$$| $|  $$$$$$$
 \______/|________|__/          \______/ \_______|__/\_______/  
)" "\033[0m";
	cout << "\n\033[33mProgramado por: Hellano Lucas | Programmed by: Hellano lucas\033[0m\n" 
		"------------------------------------------------------------";
	float salario;
	cout << "\n\n";
	cout << "> Insira seu salário bruto atual (Sem os auxílios): "; cin >> salario; cout << endl;
	if (cin.fail() || salario == 0) {
		cout << "Entrada inválida! Programa encerrado." << endl;
		exit(EXIT_FAILURE);
	}

	INSS(salario);
	system("pause");
	cout << endl;
	FGTS(salario);
	system("pause");
	cout << endl;
	Decimo_Terceiro(salario);

	system("pause");
	return 0;
}