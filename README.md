# 21sh - Points-clés
- Lecture et édition de ligne avancée avec Termcaps
- Analyse lexicale ("Lexing")
- Analyse syntaxique ("Parsing")
- Analyse sémantique
- Génération d'un Arbre de Syntaxe Abstraite (Abstract Syntax Tree, AST)
- Evaluation d'un AST 
- Job control

# Sources et recherches
- https://fr.wikipedia.org/wiki/Arbre_de_la_syntaxe_abstraite
- http://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html

# Fonctions autorisées
- malloc, free
- access
- open, close, read, write
- opendir, readdir, closedir
- getcwd, chdir
- stat, lstat, fstat
- fork, execve
- wait, waitpid, wait3, wait4
- signal, kill
- exit
- pipe
- dup, dup2
- isatty, ttyname, ttyslot
- ioctl
- getenv
- tcsetattr, tcgetattr
- tgetent
- tgetflag
- tgetnum
- tgetstr
- tgoto
- tputs

# To-do (partie obligatoire)
- Edition de ligne avec termcaps
  - Editer la ligne a l'endroit ou se trouve le curseur
  - Deplacer le curseur a droite et gauche pour editer
  - utiliser fleches haut et bas pour naviguer dans l'historique
- Gestion de CTRLD et CTRLC
- Separateur de commande ";"
- Pipes
- Les 4 redirections <, >, <<, >>
- Les agregateurs de descripteurs de fichiers (ex: 2>&-)
- Couper, copier et/ou coller tout ou partie d’une ligne avec la séquence de touches choisie
- Se déplacer par "mot" vers la gauche et vers la droite avec ctrl+LEFT et ctrl+RIGHT ou toute autre combinaison de touche raisonnable
- Aller directement au début et à la fin d’une ligne avec home et end
- Ecrire ET éditer une commande sur plusieurs lignes. Dans ce cas, on apprecierait que ctrl+UP et ctrl+DOWN permettent de passer d’une ligne à l’autre de la commande en restant sur la même colonne ou la colonne la plus appropriée sinon
- Gérer complètement les quotes et doubles quotes, même sur plusieurs lignes (hors expansions)


# Bonus
- Edition de l'historique
  - (Avance sur 42:)
    - Rendre les builtins POSIX
    - Operateurs logiques && et ||
    - Auto-completion (dynamique?)
  - (Recommandé sujet 21:)
    - Rechercher dans l’historique avec ctrl+R
    - Implémentation d’une table de hash pour les binaires
    - La complétion simple ou avancée avec tab
    - Mode bindings Emacs et/ou Vim activable et désactivable à loisir
    - Coloration syntaxique du shell activable et désactivable à loisir

# Last minute to-do
- Norminette?
- Auteur?
- Leaks?
- Makefile? (relink)
- Nom de l'executable?
- Git push?
