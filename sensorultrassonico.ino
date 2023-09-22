// baixar biblioteca ‘Ultrassonic’

#include "Ultrasonic.h" //inclusão da biblioteca necessária

const int echoPin = 13; //pino digital utilizado pelo echo(recebe)
const int trigPin = 12; //pino digital utilizado pelo trig(envia)

Ultrasonic ultrasonic(trigPin,echoPin); //inicializando os pinos do arduino

int distancia; //variável inteira
String result; //variável string

void setup(){
pinMode(echoPin, INPUT); //define o echoPin como entrada
pinMode(trigPin, OUTPUT); //define o trigPin como saida
Serial.begin(9600); //inicia a transmissao para monitor serial
}

void loop(){

hcsr04(); // faz a chamada do método "hcsr04()"

//imprime a distancia no monitor serial
Serial.print("Distancia= ");
Serial.print(result);
Serial.println("cm");
}

//método responsável por calcular a distância
void hcsr04(){
digitalWrite(trigPin, LOW); //seta o pino 12 com um pulso baixo "low"
delayMicroseconds(2); //intervalo de 2 microssegundos
digitalWrite(trigPin, HIGH); //seta o pino 12 com pulso alto "high"
delayMicroseconds(10); //intervalo de 10 microssegundos
digitalWrite(trigPin, LOW); //seta o pino 12 com pulso baixo "low" novamente

distancia = (ultrasonic.distanceRead(CM)); //função ranging, faz a conversão para centimetros, e armazena na variavel "distancia"

result = String(distancia); //variável result recebe a distância convertido de inteiro para string
delay(500); //intervalo de 500 milissegundos
}