#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

int countLiveNeighbors(CelularAutomaton automaton, int row, int col) // Função para verifica as células vivas vizinhas
{
  int count = 0;

  // Checa a célula a esquerda
  if (col > 0 && automaton.reticulated[row][col - 1] == 1)
  {
    count++;
  }

  // Checa a célula a direita
  if (col < automaton.dimension - 1 && automaton.reticulated[row][col + 1] == 1)
  {
    count++;
  }

  // Checa a célula de cima
  if (row > 0 && automaton.reticulated[row - 1][col] == 1)
  {
    count++;
  }

  // Checa a célula de baixo
  if (row < automaton.dimension - 1 && automaton.reticulated[row + 1][col] == 1)
  {
    count++;
  }

  // Checa o a diagonal superior esquerda
  if (row > 0 && col > 0 && automaton.reticulated[row - 1][col - 1] == 1)
  {
    count++;
  }

  // Checa o a diagonal superior direita
  if (row > 0 && col < automaton.dimension - 1 && automaton.reticulated[row - 1][col + 1] == 1)
  {
    count++;
  }

  // Checa o a diagonal inferior esquerda
  if (row < automaton.dimension - 1 && col > 0 && automaton.reticulated[row + 1][col - 1] == 1)
  {
    count++;
  }

  // Checa o a diagonal inferior direita
  if (row < automaton.dimension - 1 && col < automaton.dimension - 1 && automaton.reticulated[row + 1][col + 1] == 1)
  {
    count++;
  }

  return count;
}

int **allocateReticulated(int dimension) // Função para alocar dinamicamente a matriz
{
  int **reticulated = malloc(dimension * sizeof(int *));

  for (int i = 0; i < dimension; i++)
  {
    reticulated[i] = malloc(dimension * sizeof(int));
  }

  return reticulated;
}

void deallocateReticulated(CelularAutomaton *automaton) // Função para desalocar dinamicamente a matriz
{
  for (int i = 0; i < automaton->dimension; i++)
  {
    free(automaton->reticulated[i]);
  }

  free(automaton->reticulated);
}

void readReticulated(CelularAutomaton *automaton) // Função para ler o arquivo
{
  fscanf(stdin, "%d", &automaton->dimension);

  // Aloca a matrix de acordo com a dimensão lida na primeira linha do arquivo
  automaton->reticulated = allocateReticulated(automaton->dimension);

  // Preenche a matrix com os dados do arquivo
  for (int i = 0; i < automaton->dimension; i++)
  {
    for (int j = 0; j < automaton->dimension; j++)
    {
      fscanf(stdin, "%d", &automaton->reticulated[i][j]);
    }
  }
}

CelularAutomaton evolveReticulated(CelularAutomaton automaton) // Função para evoluir as células
{
  int nextGen[automaton.dimension][automaton.dimension];
  for (int i = 0; i < automaton.dimension; i++)
  {
    for (int j = 0; j < automaton.dimension; j++)
    {
      int liveNeighborsCount = countLiveNeighbors(automaton, i, j);

      // Validação das regras de vivo ou morto de acordo com o número de vizinhos
      if (automaton.reticulated[i][j] == 1)
      {
        if (liveNeighborsCount < 2 || liveNeighborsCount > 3)
        {
          nextGen[i][j] = 0;
        }
        else
        {
          nextGen[i][j] = 1;
        }
      }

      else
      {
        if (liveNeighborsCount == 3)
        {
          nextGen[i][j] = 1;
        }
        else
        {
          nextGen[i][j] = 0;
        }
      }
    }
  }

  CelularAutomaton nextGenAutomaton;
  nextGenAutomaton.dimension = automaton.dimension;
  nextGenAutomaton.reticulated = allocateReticulated(nextGenAutomaton.dimension);

  for (int i = 0; i < nextGenAutomaton.dimension; i++)
  {
    for (int j = 0; j < nextGenAutomaton.dimension; j++)
    {
      nextGenAutomaton.reticulated[i][j] = nextGen[i][j];
    }
  }

  return nextGenAutomaton;
}

void printReticulated(CelularAutomaton automaton) // Função para imprimir a matriz das células
{
  for (int i = 0; i < automaton.dimension; i++)
  {
    for (int j = 0; j < automaton.dimension; j++)
    {
      printf("%d ", automaton.reticulated[i][j]);
    }

    printf("\n");
  }
}