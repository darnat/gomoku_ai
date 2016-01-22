/*
** tree.c for Gomoku in /home/hirt_r/rendu/gomoku_ai
**
** Made by hirt_r
** Login   <hirt_r@epitech.net>
**
** Started on  Wed Jan 20 17:47:44 2016 hirt_r
** Last update Fri Jan 22 20:58:08 2016 hirt_r
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "struct_team.h"
#include "struct_pawn.h"
#include "struct_board.h"
#include "struct_tree.h"
#include "board.h"

void		affBoard(t_board *board)
{
  int		i;
  int		j;
  t_pawn	*pawn;

  i = -1;
  while (++i < 19)
    {
      j = -1;
      while (++j < 19)
	{
	  pawn = getPawnAt(board, i, j);
	  if (!pawn)
	    write(1, ".", 1);
	  else if (pawn->team->id == 1)
	    write(1, "X", 1);
	  else
	    write(1, "O", 1);
	}
      write(1, "\n", 1);
    }
  calcValue(board);
  write(1, "-------------------\n\n", 21);
}

int		checkValid(t_board *board, int i, int j)
{
  int		x;
  int		y;
  t_pawn	*pawn;

  x = -3;
  while (++x < 3)
    {
      y = -3;
      while (++y < 3)
	{
	  pawn = getPawnAt(board, i + x, j + y);
	  if (pawn)
	    return (1);
	}
    }
  return (0);
}

void		addItemBranch(t_tree *tree, int i, int j)
{
  t_tree	*tmp;
  t_tree	*newtree;

  if (tree->level >= DEPTH || setPawn(tree->board, i, j, tree->level % 2 + 1))
    return;
  if ((newtree = malloc(sizeof(t_tree))) == NULL)
    return;
  /* affBoard(tree->board); */
  newtree->x = i;
  newtree->y = j;
  newtree->pawn = NULL;
  newtree->nextd = NULL;
  newtree->nextp = NULL;
  newtree->board = tree->board;
  newtree->prev = tree;
  newtree->level = tree->level + 1;
  newtree->value = calcValue(tree->board);
  if (tree->nextd)
    {
      tmp = tree->nextd;
      while (tmp->nextp)
	tmp = tmp->nextp;
      tmp->nextp = newtree;
    }
  else
    tree->nextd = newtree;
  if (newtree->level < DEPTH)
    {
      addBranch(newtree);
    }
  removePawnAt(tree->board, i, j);
}

void		addBranch(t_tree *tree)
{
  int		i;
  int		j;

  i = -1;
  while (++i < tree->board->width)
    {
      j = -1;
      while (++j < tree->board->height)
	{
	  if (checkValid(tree->board, i, j))
	    addItemBranch(tree, i, j);
	}
    }
}

t_tree		*newTree(t_board *board)
{
  t_tree	*tree;

  if ((tree = malloc(sizeof(t_tree))) == NULL)
    return (NULL);
  tree->board = board;
  tree->prev = NULL;
  tree->nextd = NULL;
  tree->level = 0;
  addBranch(tree);
  return (tree);
}

int		calcValRec(t_tree *tree)
{
  t_tree	*tmp;
  int		max;
  int		val;

  tmp = tree->nextd;
  if (!tmp)
    return (tree->value);
  if (tree->level % 2)
    max = 100;
  else
    max = 0;
  while (tmp)
    {
      val = calcValRec(tmp);
      /* printf("WESH = %d\n", val); */
      if (tree->level % 2 && val < max)
	max = val;
      else if (tree->level % 2 == 0 && val > max)
	max = val;
      tmp = tmp->nextp;
    }
  /* printf("MIX : %2d | %2d\n", max, tree->value); */
  max = (tree->value + max) / 2;
  return (max);
}

void		makeAI(t_tree *tree)
{
  t_tree	*tmp;
  t_tree	*best;
  int		val;
  int		max;

  max = 0;
  tmp = tree->nextd;
  affBoard(tmp->board);
  while (tmp)
    {
      val = calcValRec(tmp);
      /* printf("X = %2d | Y = %2d | VAL = %d\n", tmp->x, tmp->y, val); */
      if (val >= max)
	{
	  max = val;
	  best = tmp;
	}
      tmp = tmp->nextp;
    }
  /* best = best; */
  printf("X = %2d | Y = %2d\n", best->x, best->y);
}
