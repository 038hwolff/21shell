# BONUS OK 21SH
- option -dev
- operateurs logiques && ||
- backquotes
- subshells
- variable locale
- auto completion
- gestion des sorties
- expansions des inhibiteurs
- Gestion des erreurs
- Execution en entree standard

# 21sh - Points-clés pedago
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
- http://www.gaudry.be/programmer-arbres.html
- https://ruslanspivak.com/lsbasi-part7/

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
- tgetnam

# Last minute to-do avant push (voir PROJECT "Check last minute")
- Norminette?
- Auteur?
- Leaks?
- Makefile? (relink)
- Nom de l'executable?
- Git push?
