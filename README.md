Shell simple, en C, basé sur les features proposées par bash. Projet réalisé en binôme avec une liste limitée de fonctions autorisées de la libc.

# 21sh - Points-clés pedagogiques
- Lecture et édition de ligne avancée avec Termcaps
- Analyse lexicale ("Lexing")
- Analyse syntaxique ("Parsing")
- Analyse sémantique
- Génération d'un Arbre de Syntaxe Abstraite (Abstract Syntax Tree, AST)
- Evaluation d'un AST 

# FEATURES
- Edition de ligne à l'aide de la bibliothèque Termcaps
- Fonctionnalités de `ctrl+D` et `ctrl+C`
 dans l'édition de ligne et l'éxécuton de processus
 - Séparateur de commande `;`
 - Pipes `|`
 - Les quatre redirections `<` `>` `<<` `>>`
 - Aggrégation de descripteurs de fichiers, par exemple `2>&-`
 - Editer la ligne à l'endroit ou se trouve le curseur
 - Déplacer le curseur vers la gauche et la droite et éditer la ligne à un endroit précis
 - Utiliser les flèches du haut et du bas pour naviguer dans l'historique
 - Copier/couper/coller
 - Se déplacer par mot vers la gauche, la droite
 - Aller directement à la fin et en début de ligne avec `HOME` et `END`
 - Ecrire et éditer une commande sur plusieurs lignes, avec passage d'une ligne à l'autre sur la même colonne
 - Gestion complète des quotes et double quotes
 
# BONUS
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

# Sources et recherches
- https://fr.wikipedia.org/wiki/Arbre_de_la_syntaxe_abstraite
- http://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html
- http://www.gaudry.be/programmer-arbres.html
- https://ruslanspivak.com/lsbasi-part7/
