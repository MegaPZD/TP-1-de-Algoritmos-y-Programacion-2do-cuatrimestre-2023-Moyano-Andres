#ifndef __calculo__enanito__H__
#define __calculo__enanito__H__

#define GRUNION 'G'
#define DORMILON 'D'
#define SABIO 'S'
#define FELIZ 'F'

/*
Pre: -
Post: Se le harán preguntas al usuario y en base a sus respuestas se le asignará un enanito. El
enanito asignado será devuelto por referencia en el parámetro inicial_enanito que va a contenr
su inicial.
- G: Gruñón
- D: Dormilón
- S: Sabio
- F: Feliz
*/

void calcular_enanito(char* inicial_enanito);

#endif /* __calculo__enanito__H__ */