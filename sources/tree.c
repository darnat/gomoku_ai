/*
** tree.c for Gomoku in /home/hirt_r/rendu/gomoku_ai
**
** Made by hirt_r
** Login   <hirt_r@epitech.net>
**
** Started on  Wed Jan 20 17:47:44 2016 hirt_r
** Last update Thu Jan 21 22:19:01 2016 hirt_r
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

  i = -1;
  while (++i < 19)
    {
      j = -1;
      while (++j < 19)
	{
	  if (getPawnAt(board, i, j))
	    write(1, "O", 1);
	  else
	    write(1, ".", 1);
	}
      write(1, "\n", 1);
    }
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

  if (tree->level >= DEPTH || setPawn(tree->board, i, j, 1))
    return;
  if ((newtree = malloc(sizeof(t_tree))) == NULL)
    return;
  affBoard(tree->board);
  newtree->x = i;
  newtree->y = j;
  newtree->pawn = NULL;
  newtree->nextd = NULL;
  newtree->nextp = NULL;
  newtree->board = tree->board;
  newtree->prev = tree;
  if (newtree->prev)
    newtree->level = tree->level + 1;
  else
    newtree->level = 0;
  if (tree->nextd)
    {
      tmp = tree->nextd;
      while (tmp->nextp)
	tmp = tmp->nextp;
      tmp->nextp = newtree;
    }
  else
    tree->nextp = newtree;
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

t_tree		*newTree(t_tree *prev)
{
  t_tree	*tree;

  if ((tree = malloc(sizeof(t_tree))) == NULL)
    return (NULL);
  if (prev == NULL)
    tree->board = newBoard();
  setPawn(tree->board, 10, 10, 2);
  tree->prev = prev;
  if (tree->level < DEPTH)
    addBranch(tree);
  return (tree);
}
