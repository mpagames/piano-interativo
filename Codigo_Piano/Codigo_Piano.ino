// =====================================
// PIANO INTERATIVO - código do Arduino
//
// - Cada botão toca uma nota no buzzer (pino A1).
// - Ao apertar um botão, envia para o app um número de 1 a 12
//   (1 = Dó, 2 = Dó#, 3 = Ré ... 12 = Si), uma vez por toque.
// - O app também pode mandar um número de 1 a 12 para cá:
//   no jogo da memória, o Arduino toca a nota da sequência.
// =====================================

// Pinos dos botões, na ordem das notas:
//                         Dó  Dó# Ré  Ré# Mi  Fá  Fá# Sol Sol# Lá  Lá# Si
const int PINOS_BOTOES[12] = { 2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13 };

// Frequência de cada nota em Hz (mesma ordem)
const int FREQUENCIAS[12]  = { 523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988 };

const int SOM = A1;  // pino do buzzer

// Tempo para ignorar o "tremido" do botão ao apertar e soltar (ms)
const unsigned long TEMPO_DEBOUNCE = 50;

// Quanto tempo dura uma nota pedida pelo app (ms)
const unsigned long DURACAO_NOTA_APP = 400;

int teclaAtual = -1;                 // botão apertado agora (-1 = nenhum)
unsigned long tempoUltimaMudanca = 0;
int numeroRecebido = 0;              // número que está chegando do app


void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 12; i++) {
    pinMode(PINOS_BOTOES[i], INPUT);
  }
}


// Devolve qual botão está apertado (0 a 11), ou -1 se nenhum
int lerTecla() {
  for (int i = 0; i < 12; i++) {
    if (digitalRead(PINOS_BOTOES[i]) == HIGH) {
      return i;
    }
  }
  return -1;
}


void loop() {
  unsigned long agora = millis();

  // ---------- BOTÕES DO PIANO ----------
  int tecla = lerTecla();

  // Só faz algo quando o botão MUDA (apertou, soltou ou trocou de botão).
  // Assim, segurar um botão envia a nota uma vez só.
  if (tecla != teclaAtual && agora - tempoUltimaMudanca >= TEMPO_DEBOUNCE) {
    teclaAtual = tecla;
    tempoUltimaMudanca = agora;

    if (tecla >= 0) {
      tone(SOM, FREQUENCIAS[tecla]);
      Serial.println(tecla + 1);
    } else {
      noTone(SOM);
    }
  }

  // ---------- NOTAS PEDIDAS PELO APP ----------
  // O app envia um número de 1 a 12 seguido de uma quebra de linha.
  while (Serial.available() > 0) {
    char c = Serial.read();

    if (c >= '0' && c <= '9') {
      numeroRecebido = numeroRecebido * 10 + (c - '0');
    }
    else if (c == '\n') {
      // Só toca se ninguém estiver apertando um botão
      if (numeroRecebido >= 1 && numeroRecebido <= 12 && teclaAtual < 0) {
        tone(SOM, FREQUENCIAS[numeroRecebido - 1], DURACAO_NOTA_APP);
      }
      numeroRecebido = 0;
    }
  }
}
