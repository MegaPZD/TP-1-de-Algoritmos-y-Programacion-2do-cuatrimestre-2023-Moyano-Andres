#include <stdio.h>
#include "calculo_enanito.h"

/*
pre: -Recibe por referencia la variable "inicial_enanito" desde el main.
post: -Dependiendo del valor de "inicial_enanito" mostrará 1 de los 4 mensajes que
corresponden a los 4 enanitos.
*/

void resultado_de_preguntar(char inicial_enanito){

    if (inicial_enanito == GRUNION){

        printf("Segun tus respuestas a las preguntas el enanito que sera tu alma gemela será:\n -GRUÑÓN- \nEl tiene 5 propiedades y tambien 60 inversiones que le generan pasivos diarios, solo no le arruines el día.\n");

    } else if (inicial_enanito == DORMILON){

        printf("Segun tus respuestas a las preguntas el enanito que sera tu alma gemela será:\n -DORMILÓN- \nSe dice que con estar cerca de el se te contagia el sueño,\nideal para los que no pueden dormir.\n");

    } else if (inicial_enanito == SABIO){

        printf("Segun tus respuestas a las preguntas el enanito que sera tu alma gemela será:\n -SABIO- \nNo te da un pez sino que te enseña a pescar\nSi tu examen quieres aprobar a sabio tienen que consultar.\n");

    } else {

        printf("Segun tus respuestas a las preguntas el enanito que sera tu alma gemela será:\n -FELIZ- \nTiene 6 deudas registradas y vive en un monoambiente pero es feliz si estas con él.\n");

    }

}

int main(){

    char inicial_enanito;

    printf("\nEn este test usted encontrará a su alma gemela\nrespondiendo unas simples preguntas sabrá cual de los 7 enanitos\nes el más compatible con usted (si... todos nos hemos preguntado eso una vez):\n\n");

    calcular_enanito(&inicial_enanito);

    resultado_de_preguntar(inicial_enanito);

    return 0;
}