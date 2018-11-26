Lecture AST: http://www.gaudry.be/programmer-arbres.html

1) lecture/edition de ligne => chaine de caractères
2) lexer => liste chainée avec un type pour chaque maillon
3) parser, erreurs, inhibiteurs, expansion, etc => liste réduite
4) arbre syntaxique => arbre
5) Executeur de commande => ben rien c'est fini. :smile:
6) repeat

# TODO GROUPE (voir onglet PROJECTS - "Valider 21/42sh")
- OBLIGATOIRE (21sh a 100%)
  - BUILTINS POSIX: (Hélène)
    - cd
    - cd path/to/dir
    - exit
    - echo
    - env
    - setenv
    - unsetenv
  - GESTION DU PATH + VIM .c + MESSAGES ERREUR SHELL + PROMPT (Hélène)
  - GESTION DES SIGNAUX (Pauline)
  - LEXEUR PARSEUR (Heidy)
  - PIPES ET REDIRECTIONS (> < >> << | ; &> &<)
  - EDITION DE LIGNES (deplacement gauche droite, fin debut, historique fleches; copier coller; edition sur plusieurs lignes) (Pauline)
  - GESTION DES PARENTHESES: si non fermées, le shell attend
- BONUS (+5% pour chaque)
  - Droits dans le path (notre programme ne doit pas chercher a executer des fichier qui ne sont pas des binaires)
  - Completion
  - Table de hashage pour les binaires
  - Recherche dans l'historique avec ctrl + R
  - +9 bonus que je suggère (qui nous valident 42sh directement):
    - opérateurs logiques
    - multi commandes avec ;
    - Inhibiteurs "" '' \
    - Gestion des backquotes
    - Variables locales + builtins unset et export
    - Agregation des fd de sortie (2>&- par exemple)
    - Globing (* [] {})
    - Mode bindings Emacs et/ou Vim activable et désactivable à loisir
    - Coloration syntaxique du shell activable et désactivable à loisir
  
  - Pour info, les points du corrigé de 42sh:
    - opérateurs logiques
    - multi commandes avec ;
    - [OPTIONNEL 42SH]
    - Inhibiteurs "" '' \
    - Heredoc
    - Agregation des fd de sortie (2>&- par exemple)
    - Gestion des backquotes
    - Globing (* [] {})
    - Variables locales + builtins unset et export
    - Sous shell ()
    - Builtin read avec toutes ses options
    - Job control (20 points sur le 42sh)
    - [BONUS 42sh]
    - scripts shell (20 points sur le 42sh)
    + autres (inutile pour les points)


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

# Last minute to-do avant push (voir PROJECT "Check last minute")
- Norminette?
- Auteur?
- Leaks?
- Makefile? (relink)
- Nom de l'executable?
- Git push?
