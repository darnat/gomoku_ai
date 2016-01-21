/*
** struct_pawn.h for GOmoku in /home/hirt_r/rendu/gomoku_ai
**
** Made by hirt_r
** Login   <hirt_r@epitech.net>
**
** Started on  Sat Jan 16 15:54:18 2016 hirt_r
** Last update Wed Jan 20 19:25:31 2016 hirt_r
*/

#ifndef STRUCT_TREE_H_
# define STRUCT_TREE_H_

#define DEPTH 3

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
}		t_tree;

#endif /* !STRUCT_PAWN_H_ */
