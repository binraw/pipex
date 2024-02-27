#pipex



1 - creation des deux childs avec fork >

2 - waitpid des deux process 

3 - creation des deux process 

4 - possibiliter de gestion erreur des creations des childs

5 - process creaton en changant bien les fd 

6 - recup des commandes dans /bin ensuite a voir 




7 -  gestion erreurs quand les fichiers ne s'ouvre pas 

commande pas bonne 
si jarrive a trouver le path ou pas 
le fichier in n'existe pas ou j'ai pas les droits
return les bon messages d'erreur et code  