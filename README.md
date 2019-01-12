TODO 42 JANVIER
- builtins POSIX (type, echo, exit (avec valeur de retour), cd) HELENE
- La création de variable d’environnement pour une commande unique, exemple : HOME=/tmp cd
- Gestion du job control, avec les built-ins jobs, fg, bg et l’opérateur &
(partie modulaire:)
- Les commandes groupées et sous-shell
- La substitution de commande (backquotes)
- Arithmetiques HELENE
- table de hashage HEIDY et builtins hash HELENE
(en plus si envie)
- La substitution de processus
- La gestion des alias via les built-ins alias et unalias

PARTIE MODULAIRE 42 OK
- Inhibiteurs
- Completion dynamique


# BONUS OK 21SH
- option -dev
- Heredoc
- operateurs logiques && ||
- backquotes
- subshells
- variable locale
- auto completion
- gestion des sorties
- expansions des inhibiteurs
- Gestion des erreurs
- Execution en entree standard


1) lecture/edition de ligne => chaine de caractères
2) lexer => liste chainée avec un type pour chaque maillon
3) parser, erreurs, inhibiteurs, expansion, etc => liste réduite
4) arbre syntaxique => arbre
5) Executeur de commande => ben rien c'est fini. :smile:
6) repeat


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
