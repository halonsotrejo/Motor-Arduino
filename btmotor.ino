
int output2 = 2; 
int output3 = 3;
int output4 = 4;
int output5 = 5;

void setup(){

  Serial.begin(9600);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);
  pinMode(output5, OUTPUT);

  Serial.println("Conectado...");
}

void loop(){
  
  while (Serial.available() == 0);                                                                       
  char dato = Serial.read();
  Serial.println(dato);
   
  if (dato == 'a') {
    moverAdelante();
      Serial.println("Adelante");
  }
  else if (dato == 's'){
    detener();
      Serial.println("Detener");
  }
  else if (dato == 'r'){
    moverAtras();
      Serial.println("Atras");
  }
  else if (dato == 'd'){
    girarDerecha();
      Serial.println("Derecha");
  }
  else if (dato == 'i'){
    girarIzquierda();
      Serial.println("Izquierda");
  }
  else {
    Serial.println("Comando Invalido");
  }
 // Serial.flush(); 
}

void moverAdelante(){
  digitalWrite(output2, LOW);
  digitalWrite(output3, HIGH); //adelante para motor derecho
  digitalWrite(output4, HIGH);
  digitalWrite(output5, LOW); //adelante para motor izquierdo
}

void moverAtras(){
  digitalWrite(output2, HIGH);
  digitalWrite(output3, LOW); //atras para motor derecho
  digitalWrite(output4, LOW);
  digitalWrite(output5, HIGH); //atras para motor izquierdo
}

void girarIzquierda(){
   digitalWrite(output2, LOW);
   digitalWrite(output3, HIGH); //adelante para motor derecho
   digitalWrite(output4, LOW);
   digitalWrite(output5, HIGH); //atras para motor izquierdo
}

void girarDerecha(){
  digitalWrite(output4, HIGH);
  digitalWrite(output5, LOW); //adelante para motor izquierdo
  digitalWrite(output2, HIGH);
  digitalWrite(output3, LOW); //atras para motor derecho
}

void detener(){
  digitalWrite(output2, LOW);
  digitalWrite(output3, LOW);
  digitalWrite(output4, LOW);
  digitalWrite(output5, LOW);
}


