#include <stdio.h>
#include "calculo_enanito.h"

const char LECHUGA = 'A';
const char BROCOLI = 'B';
const char ZANAHORIA = 'C';
const char TOMATE = 'D';
const char INVIERNO = 'I';
const char VERANO = 'V';
const int MIN_CALIFICA = 0;
const int MAX_CALIFICA = 5;
const int MIN_MINUTO = 40;
const int MAX_MINUTO = 120;
const int MAXGRUNION_MINDORMI = 10;
const int MAXDORMI_MINSABIO = 20;
const int MAXSABIO_MINFELIZ = 30;

/*
pre: -Recibe las letras seleccionadas correctamente en las preguntas 1 y 2.
post: -Suma los puntos acumulados de las preguntas 1 y 2 y los devuelve por referencia.
*/

void sumar_puntos(char respuesta, float* puntos){

    if(respuesta == LECHUGA || respuesta == INVIERNO){
        *puntos += 0; 
    } else if(respuesta == BROCOLI){
        *puntos += 5; 
    } else if(respuesta == ZANAHORIA){
        *puntos += 10; 
    } else if(respuesta == TOMATE){
        *puntos += 15; 
    } else if(respuesta == VERANO){
        *puntos += 10;
    }

}

/*
pre: -Recibe un numero entre el 0 y 5 de la pregunta 3.
post: -Devuelve por referencia el puntaje acumulado.
Dependiendo del numero se restara mas o menos puntos.
*/

void restar_puntos(float respuesta, float* puntos){

    *puntos -= respuesta;

}

/*
pre: -Recibe el tiempo que se selecciono en la pregunta 4.
post: -Dado el tiempo se lo divide y se suma con el puntaje acumulado.
*/

void operacion_cultivos(float* tiempo, float* puntos){

    float suma_a_puntos = 0;
    suma_a_puntos = *tiempo/8;
    *puntos += suma_a_puntos;

}

/*
pre: -Recibe la respuesta de la pregunta 1, correctamente seleccionada o no.
post: -Verifica si la respuesta fue seleccionada correctamente hasta
que se elija una en el rango de respuestas indicadas por las constantes de las verduras 
y lo devuelve por referencia. Si la respuesta estaba correctamente seleccionada
el procedimiento no hara cambios en ella.
*/

void validar_p1(char* respuesta_p1){
    
    while(!(*respuesta_p1 == LECHUGA || *respuesta_p1 == BROCOLI || *respuesta_p1 == ZANAHORIA || *respuesta_p1 == TOMATE)){
        printf("\nERROR: Valor incresado no valido\nVuelva a elegir por favor:\nA ('A') para lechuga\nB ('B') para brócoli\nC ('C') para zanahoria\n D ('D') para Tomate\n\nEliges: ");
        scanf(" %c", respuesta_p1);
        fflush(stdin);
    }
}


/*
pre: -Recibe la respuesta de la pregunta 2, correctamente seleccionada o no.
post: -Verifica si la respuesta fue seleccionada correctamente hasta
 que se elija una en el rango de respuestas indicadas por las constantes de las 2 estaciones y
 lo devuelve por referencia. Si la respuesta estaba correctamente seleccionada
 el procedimiento no hara cambios en ella.
*/

void validar_p2(char* respuesta_p2){

    while(!(*respuesta_p2 == INVIERNO || *respuesta_p2 == VERANO)){
        
        printf("\nERROR: Valor incresado no valido\n\nVuelva a seleccionar:\nI ('I') para invierno\nV ('V') para verano\n\nEliges: ");
        scanf(" %c", respuesta_p2);
        fflush(stdin);
    }

}

/*
pre: -Recibe el rango de numeros de la pregunta 3, correctamente seleccionada o no.
post: -Verifica si la respuesta fue seleccionada correctamente hasta
 que se elija una en el rango de respuestas y lo devuelve por referencia. Si la respuesta estaba correctamente seleccionada
 el procedimiento no hara cambios en la respuesta.
*/

void validar_rango_p3(float* rango){

    while(!(*rango >= 0 && *rango <= 5)){

        printf("ERROR: el rango debe ser del 0 al 5.\n\nVuelve a intentarlo: ");
        scanf("%f", rango);

    }

}

/*
pre: -Recibe el tiempo (entre 40 y 120, indicados en las constantes) de la pregunta 4,
correctamente seleccionada o no.
post: -Verifica si la respuesta fue seleccionada correctamente hasta
que se elija una en el rango de respuestas y lo devuelve por referencia.
Si la respuesta estaba correctamente seleccionada el procedimiento no hara cambios
en la respuesta.
*/

void validar_tiempo_p4(float* tiempo){

    while(!(*tiempo >= MIN_MINUTO && *tiempo <= MAX_MINUTO)){

        printf("ERROR: el tiempo debe ser del 40 al 120.\n\nVuelve a intentarlo: ");
        scanf("%f", tiempo);

    }

}

/*
pre: -Recibe por referencia la variable "puntos" desde calcular_enanito.
post: -Muestra la pregunta 1 y pide una respuesta para posteriori llamar a 2 procesos
(validar_p1 y sumar_puntos) que validan la respuesta y tambien empezan a contabilizar los puntos.
Devuelve por referencia la variable "puntos".
*/

void realizar_pregunta_1(float* puntos1){

    char respuesta1;

    printf("¿Cuál es tu verdura favorita?\nSeleccione:\n\nA ('A') para lechuga\nB ('B') para brócoli\nC ('C') para zanahoria\nD ('D') para Tomate\n\nEliges: ");
    scanf(" %c", &respuesta1);
    fflush(stdin);

    validar_p1(&respuesta1);
    
    sumar_puntos(respuesta1, puntos1);

}

/*
pre: -Recibe por referencia las variables "puntos" y "verano_o_invierno"
desde calcular_enanito.
post: -Muestra la pregunta 2 y pide una respuesta al usuario para posteriori llamar a 2 procesos
(validar_p2 y sumar_puntos) que validan la respuesta y continuan con el conteo de los puntos.
Devuelve por referencia ambas variables.
*/

void realizar_pregunta_2(char* respuesta2, float* puntos2){


    printf("¿Sos team verano o team invierno?\nSeleccione:\n\nI ('I') para invierno\nV ('V') para verano\n\nEliges: ");
    scanf(" %c", respuesta2);
    fflush(stdin);

    validar_p2(respuesta2);

    sumar_puntos(*respuesta2, puntos2);

}

/*
pre: -Recibe por referencia las variables "puntos" y "verano_o_invierno"
desde calcular_enanito.
post: -Dependiedo del valor "verano_o_invierno" muestra por pantalla una de 2 pregunta 3
y pide una respuesta al usuario para posteriori llamar a 2 procesos, validar_rango_p3 y restar_puntos,
que validan la respuesta y continuan con el conteo de los puntos respectivamente.
Devuelve por referencia la variable "puntos".
*/

void realizar_pregunta_3(char opcion, float* puntos3){

    float rango = -1;

    if(opcion == INVIERNO){
        printf("\n¿Cuánto te enoja trabajar bajo la lluvia? Del 0 al 5, se sincero: ");
    } else if(opcion == VERANO){
        printf("\n¿Cuanto te enojan los mosquitos? Del 0 al 5, se sincero: ");
    }

    scanf("%f", &rango);

    validar_rango_p3(&rango);

    restar_puntos(rango, puntos3);

}

/*
pre: -Recibe por referencia la variable "puntos" desde calcular_enanito.
post: -Pide la respuesta de la pregunta 4 al usuario para posteriori llamar a 2 procesos
(validar_tiempo_p4 y operacion_cultivos) que validan la respuesta y continuan con el conteo de los puntos.
Devuelve por referencia la variable.
*/

void realizar_pregunta_4(float* puntos4){

    float tiempo = 0;
    

    printf("\n¿Cuánto tiempo te llevaría cosechar un cultivo de 10 metros cuadrados?\nEl tiempo debe estar en el rango de 40 a 120 minutos.\nPara los segundos se debera usar un formato decimal (MM.SS)\nIngrese el tiempo: ");
    scanf("%f", &tiempo);

    validar_tiempo_p4(&tiempo);

    operacion_cultivos(&tiempo, puntos4);

}

/*
pre: -Recibe por referencia las variables "inicial_enanito" y "puntos" desde calcular_enanito.
post: -Compara el puntaje acumulado de "puntos" con las constantes que definen el min y maximo
rango para obtener a cada enanito. Dependiendo de esto devuelve por referencia "inicial_enanito".
*/

void conteo_final (float puntos_finales, char* inicial_enanito){

    if (puntos_finales < MAXGRUNION_MINDORMI){

        *inicial_enanito = GRUNION;

    } else if (puntos_finales >= MAXGRUNION_MINDORMI && puntos_finales < MAXDORMI_MINSABIO){

        *inicial_enanito = DORMILON;

    } else if (puntos_finales >= MAXDORMI_MINSABIO && puntos_finales < MAXSABIO_MINFELIZ){

        *inicial_enanito = SABIO;

    } else {

        *inicial_enanito = FELIZ;

    }

}

void calcular_enanito(char* inicial_enanito){

    float puntos = 0;
    char verano_o_invierno;

    realizar_pregunta_1(&puntos);

    realizar_pregunta_2(&verano_o_invierno, &puntos);

    realizar_pregunta_3(verano_o_invierno, &puntos);

    realizar_pregunta_4(&puntos);

    conteo_final(puntos, inicial_enanito);


}