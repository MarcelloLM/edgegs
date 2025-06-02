// KenzoSafety – Sistema Físico de Monitoramento de Enchentes
// Desenvolvido por Fernando Kenzo e  Marcello Lassalla - FIAP (Edge Computing & IoT - 2025)

const int sensorNivel = A0;     // Entrada analógica do sensor de nível (potenciômetro)
const int ledVerde = 2;         // LED Verde – Situação normal
const int ledAmarelo = 3;       // LED Amarelo – Alerta moderado
const int ledVermelho = 4;      // LED Vermelho – Alerta crítico
const int buzzer = 5;           // Buzzer para alarme sonoro

void setup() {
  // Configura os pinos dos LEDs e buzzer como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Inicializa a comunicação serial para visualização dos dados
  Serial.begin(9600);
}

void loop() {
  // Lê o valor analógico do sensor de nível (0 a 1023)
  int leituraSensor = analogRead(sensorNivel);

  // Exibe o valor no monitor serial (útil para calibração)
  Serial.println(leituraSensor);

  // Verifica o nível da água e aciona os atuadores conforme a faixa
  if (leituraSensor < 350) {
    // Nível baixo: tudo normal
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
  } else if (leituraSensor < 700) {
    // Nível intermediário: alerta moderado
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);

    // Alarme sonoro intermitente (bip curto)
    tone(buzzer, 1000, 200);
    delay(500);
    noTone(buzzer);
  } else {
    // Nível alto: alerta crítico
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);

    // Alarme sonoro contínuo
    tone(buzzer, 1000);
  }

  // Aguarda 1 segundo antes da próxima leitura
  delay(1000);
}
