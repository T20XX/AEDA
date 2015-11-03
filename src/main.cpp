#include <iostream>
using namespace std;

void selecao1()
{

}
void selecao2()
{

}
void selecao3()
{

}



int main() {
	int selecao=-1;
	while (selecao !=0)
	{
		cout << "Menu" << endl;
		cout << "1. Registar Utilizador" << endl;
		cout << "2. Gerir Utilizadores" << endl;
		cout << "3. Gerir Anúncios" << endl;
		cout << "0. Sair" << endl;
		while (selecao < 0 || selecao > 3)
			cin >> selecao;
	if (selecao == 0)
		break;
	else if (selecao == 1)
		selecao1();
	else if (selecao == 2)
		selecao2();
	else if (selecao == 3)
		selecao3();
	selecao = -1;
	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
