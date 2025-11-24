#pragma warning(disable: 4996)
#include <stdio.h>


int main()
{
	bool tf = true;
	int num1, num2;
	float risultato;
	char op;
	while (tf) {
		bool tf2 = true;
		printf("inserire i due numeri dell'operazione:\n ");
		printf("1: ");
		scanf("%d", &num1);
		printf("\n2: ");
		scanf("%d", &num2);
		while (tf2) {
			printf("inserire l'operazione:\n ");
			scanf(" %c", &op);
			if (op == '+') {
				risultato = num1 + num2;
				tf2 = false;
			}
			else if (op == '-') {
				risultato = (float)num1 - num2;
				tf2 = false;
			}
			else if (op == '/') {
				risultato = num1 / num2;
				tf2 = false;
			}
			else if (op == '*') {
				risultato = num1 * num2;
				tf2 = false;
			}
			else {
				printf("hai inserito una operaione non valida\n");
				tf2 = true;
			};
		}
			printf("\nil tuo risultato e: %.2f", risultato);
			printf("\ncontinuare con le operazioni? s/n\n");
			char scelta;
			scanf(" %c", &scelta);
			if (scelta == 'n') {
				tf = false;
			};
			

	}
}
