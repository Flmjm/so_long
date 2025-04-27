Notes :

# **Tableau des événements d'écoute avec mlx_hook()**

*Code d'événement	Type d'événement	Code mlx_hook	Description*

2	KeyPress (touche pressée)	mlx_hook(win, 2, ...)	Lorsque l'utilisateur appuie sur une touche.

3	KeyRelease (touche relâchée)	mlx_hook(win, 3, ...)	Lorsque l'utilisateur relâche une touche.

4	ButtonPress (clic souris)	mlx_hook(win, 4, ...)	Lorsque l'utilisateur appuie sur un bouton de la souris.

5	ButtonRelease (clic relâché)	mlx_hook(win, 5, ...)	Lorsque l'utilisateur relâche un bouton de la souris.

6	MotionNotify (mouvement souris)	mlx_hook(win, 6, ...)	Lorsque la souris se déplace sur la fenêtre.

12	Expose (rafraîchissement fenêtre)	mlx_hook(win, 12, ...)	Lorsque la fenêtre nécessite un rafraîchissement (par exemple après un redimensionnement).

17	DestroyNotify (fermeture fenêtre)	mlx_hook(win, 17, ...)	Lorsque l'utilisateur ferme la fenêtre.

22	FocusIn/FocusOut (perte/gain de focus)	mlx_hook(win, 22, ...)	Lorsque la fenêtre gagne ou perd le focus.

# **Tableau des keycodes (codes de touches) dans MiniLibX**

### *Keycode		Touche / Action*

	65307	Échap (Escape)
	65400	Entrée (Enter)
	65361	Flèche gauche
	65362	Flèche haut
	65363	Flèche droite
	65364	Flèche bas
	32		Barre d'espace
	9		Tabulation (Tab)
	48		Touche numérique 0
	49		Touche numérique 1
	50		Touche numérique 2
	51		Touche numérique 3
	52		Touche numérique 4
	53		Touche numérique 5
	54		Touche numérique 6
	55		Touche numérique 7
	56		Touche numérique 8
	57		Touche numérique 9
	65				A
	66				B
	67				C
	68				D
	69				E
	70				F
	71				G
	72				H
	73				I
	74				J
	75				K
	76				L
	77				M
	78				N
	79				O
	80				P
	81				Q
	82				R
	83				S
	84				T
	85				U
	86				V
	87				W
	88				X
	89				Y
	90				Z
