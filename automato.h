#pragma once

typedef struct {
  int dimension;
  int **reticulated;
} CelularAutomaton;

int **allocateReticulated(int dimension);

void deallocateReticulated(CelularAutomaton *automaton);

void readReticulated(CelularAutomaton *automaton);

CelularAutomaton evolveReticulated(CelularAutomaton automaton);

void printReticulated(CelularAutomaton automaton);