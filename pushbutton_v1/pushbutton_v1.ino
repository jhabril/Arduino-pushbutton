/*
 * Sketch para leer e imprimir el estado de un push button en el 
 * Serial Monitor no optimizado
 */
int pin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(pin));
}
