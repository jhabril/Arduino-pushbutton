const int  pushbutton = 7;    
const int  led = 13;
int estado = 0;            // Estado actual del boton
int ultimo_estado = 0;     // Ultimo estado del boton

void setup() {
  // initialize the button pin as a input:
  pinMode(pushbutton, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);  
  // El usuario hace cualquier cosa e inicia con el 
  // pushButton presionado
  if(digitalRead(pushbutton)== LOW){
    Serial.println("on");   
    digitalWrite(led,HIGH);
  }
}

void loop() {
  // Lee el estado del boton
  estado = digitalRead(pushbutton);

  // Compara el estado actual del boton con el ultimo estado
  if (estado != ultimo_estado) {
    if (estado == HIGH) {
      // Si el estado es HIGH el pushbutton no esta presinado    
      Serial.println("off");
      // La inversion del HIGH LOW saca de onda
      digitalWrite(led,LOW);   
    } else {
      // Si el estado es LOW el pushbutton esta presionado
      // La inversion del LOW HIGH saca de onda
      Serial.println("on");
      digitalWrite(led,HIGH);
    }
    // Evitar rebote
    delay(50);
  }
  // Actualizamos ultimo estado
  ultimo_estado = estado;
}
