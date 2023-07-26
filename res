


Je suis en train de debugger mon programme(ecrire un simple shell).
J'aimerais que tu m'aides a debugger chaque partie, et notamment les pertes de memoires.:




Il semble que les modifications apportées n'ont pas résolu complètement les blocs "still reachable". Cependant, ces blocs "still reachable" ne sont pas des fuites de mémoire réelles, mais plutôt des allocations qui restent accessibles jusqu'à la fin de l'exécution du programme.

Dans ce cas, vous pouvez ignorer ces avertissements de valgrind car ils ne représentent pas une fuite de mémoire significative. Les allocations en question sont toujours accessibles et seront libérées à la fin de l'exécution du programme.

Cependant, si vous souhaitez éliminer complètement ces avertissements, vous pouvez ajouter des appels supplémentaires à free pour libérer ces allocations avant la fin du programme. Par exemple, vous pouvez ajouter les appels suivants avant la fin du programme :



