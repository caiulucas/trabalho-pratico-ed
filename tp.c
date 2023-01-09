#include <stdio.h>
#include "automato.h"

int main(int argc, char **argv) 
{
  if (argc != 2)
  {
    printf("Numero de argumentos inválidos! Sao 2.\n");
    printf("Linha de execução: ./exe 'nome_do_arquivo' \n");
    printf("\tExemplo de execução: ./exe teste.txt\n");
    return 0;
  }

  char *filename = argv[1];

  CelularAutomaton automaton;

  readReticulated(filename, &automaton);
  CelularAutomaton nextGenAutomaton = evolveReticulated(automaton);

  printReticulated(nextGenAutomaton);

  deallocateReticulated(&automaton);
  deallocateReticulated(&nextGenAutomaton);
  
  return 0;
}