/*
** struct_pawn.h for GOmoku in /home/hirt_r/rendu/gomoku_ai
**
** Made by hirt_r
** Login   <hirt_r@epitech.net>
**
** Started on  Sat Jan 16 15:54:18 2016 hirt_r
** Last update Fri Jan 22 19:18:56 2016 hirt_r
*/

#ifndef STRUCT_TREE_H_
# define STRUCT_TREE_H_

#define DEPTH 2

typedef struct	s_tree
{
  int		x;
  int		y;
  t_pawn	*pawn;
  struct s_tree	*nextd;
  struct s_tree	*nextp;
  struct s_tree	*prev;
  t_board	*board;
  int		level;
  int		value;
}		t_tree;

#endif /* !STRUCT_PAWN_H_ */
