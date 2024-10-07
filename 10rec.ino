const int pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10}; // Пины выходов
uint8_t receivedCommand[9]; // Буфер для приема данных

void setup() {
  for (int i = 0; i < 9; i++) {
    pinMode(pins[i], OUTPUT); // Настраиваем пины как выходы
  }
  Serial.begin(9600); // Инициализация UART
}

void loop() {
  // Проверяем, есть ли данные в UART
  if (Serial.available() >= 9) { // Ждем, пока будут доступны 9 байт
    for (int i = 0; i < 9; i++) {
      receivedCommand[i] = Serial.read(); // Читаем по одному байту
    }

    // Проходим по каждому элементу массива и управляем соответствующими пинами
    for (int i = 0; i < 9; i++) {
      if (receivedCommand[i] == 1) {
        digitalWrite(pins[i * 2], HIGH); // Устанавливаем HIGH для нечетного элемента
      } else if (receivedCommand[i] == 2) {
        digitalWrite(pins[i * 2 + 1], HIGH); // Устанавливаем HIGH для четного элемента
      }
    }
  }
}
