#include <stdio.h>
#include "automato.h"

int main(int argc, char **argv) 
{
  CelularAutomaton automaton;

  readReticulated(&automaton);
  CelularAutomaton nextGenAutomaton = evolveReticulated(automaton);

  printReticulated(nextGenAutomaton);

  deallocateReticulated(&automaton);
  deallocateReticulated(&nextGenAutomaton);
  
  return 0;
}