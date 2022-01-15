#ifndef _MAIN_FUNCTIONS_H
#define _MAIN_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "input.h"
#include "print.h"
#include "../constants/consts.h"

void removePerson(Person *list, int *listSize) {
	char op, op2;
	int i, index;

	system("cls");

	do {
		printf("Insira o indice da pessoa a ter seu registro removido: ");
		scanf("%d", &index);
		clearBuffer();

		if ((index < 0) || (index > (*listSize - 1))) {
      system("cls");
      printf("Indice invalido! Tente novamente.\n");
    }
		
	} while ((index < 0) || (index > (*listSize - 1)));

	printf("Informacao da pessoa que deseja remover: \n");
	printPerson(list[index]);

  do {
	  printf("Tem certeza que deseja remover este registro? [s/n] ");
	  scanf("%c", &op);
    clearBuffer();
    if ((toupper(op) != 'S') && (toupper(op) != 'N')) {
      system("cls");
      printf("Opcao invalida, tente novamente!\n");
    }
  } while ((toupper(op) != 'S') && (toupper(op) != 'N'));

  if (toupper(op) == 'S') {

		for (i = index; i < *listSize - 1; i++)
			list[i] = list[i + 1];
		printf("\nRegistro removido com sucesso.\n\n");
    *listSize -= 1;
    system("pause");

  } else if (toupper(op) == 'N') {

    do {
      system("cls");
      printf("Deseja voltar ao menu inicial? [s/n] ");
      scanf("%c", &op2);
      clearBuffer();
      if ((toupper(op2) != 'S') && (toupper(op2) != 'N')) {
        printf("Opcao invalida, tente novamente!\n");
        system("pause");
      }
    } while ((toupper(op2) != 'S') && (toupper(op2) != 'N'));

    if (toupper(op2) == 'N') {
      removePerson(list, listSize);
    }
  }
}

#endif