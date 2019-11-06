const int  pushbutton = 7;    
int estado = 0;            // Estado actual del boton
int ultimo_estado = 0;     // Ultimo estado del boton

void setup() {
  // initialize the button pin as a input:
  pinMode(pushbutton, INPUT_PULLUP);
  // initialize serial communication:
  Serial.begin(9600);  
  // El usuario hace cualquier cosa e inicia con el 
  // pushButton presionado
  if(digitalRead(pushbutton)== LOW){
    Serial.println("on");   
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
    } else {
      // Si el estado es LOW el pushbutton esta presionado
      Serial.println("on");
    }
    // Evitar rebote
    delay(50);
  }
  // Actualizamos ultimo estado
  ultimo_estado = estado;
}
