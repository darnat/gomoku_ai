/*
** board.h for Gomoku in /home/hirt_r/rendu/gomoku_ai
**
** Made by hirt_r
** Login   <hirt_r@epitech.net>
**
** Started on  Tue Jan 19 14:35:08 2016 hirt_r
** Last update Sat Jan 23 12:56:03 2016 hirt_r
*/

#ifndef board_h
#define board_h

t_board		*newBoard();
t_pawn		*checkEaten(t_board *);
t_pawn		*addPawn(t_pawn **, int, int);
int		checkWin(t_board *);
t_tree		*newTree(t_board *);
t_pawn		*getPawnAt(t_board *, int, int);
void		removePawnAt(t_board *, int, int);
void		addBranch(t_tree *);
int		calcValue(t_tree *);
t_pawn		*makeAI(t_tree *);
t_pawn		*setPawnAI(t_board *);

#endif /* board_h */
