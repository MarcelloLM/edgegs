const int sensorNivel = A0;
const int ledVerde = 2;
const int ledAmarelo = 3;
const int ledVermelho = 4;
const int buzzer = 5;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leituraSensor = analogRead(sensorNivel);
  Serial.println(leituraSensor);  // Para ver no monitor serial o valor do nível de água simulado

  // Lógica de alarme por faixa de nível
  if (leituraSensor < 350) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
  } else if (leituraSensor < 700) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    tone(buzzer, 1000, 200);  // beep curto
    delay(500);
    noTone(buzzer);
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 1000);  // buzzer contínuo
  }

  delay(1000);  // Espera de 1 segundo antes de nova leitura
}
