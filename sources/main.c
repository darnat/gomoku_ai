/*
** main.c for Gomoku in /home/hirt_r/rendu/gomoku_ai
**
** Made by hirt_r
** Login   <hirt_r@epitech.net>
**
** Started on  Sat Jan 16 15:50:53 2016 hirt_r
** Last update Sun Jan 17 21:10:06 2016 hirt_r
*/

#include "struct_team.h"
#include "struct_pawn.h"
#include "struct_board.h"
#include <stdio.h>

t_pawn *checkEaten(t_board *);

int		main()
{
  t_board	*board;

  board = getBoard(0);
  setPawn(board, 2, 2, 1);
  setPawn(board, 2, 3, 2);
  setPawn(board, 2, 4, 2);
  setPawn(board, 2, 5, 1);
  checkEaten(board);
  return (0);
}
