const int inputs[] = {2, 3, 4, 5, 6, 7, 8, 9, 10}; // Пины входов
uint8_t command[9] = {0}; // Массив состояний, изначально все нули
bool xgamer = true; // Флаг состояния игрока

void setup() {
  Serial.begin(9600); // Инициализация UART
  for (int i = 0; i < 9; i++) {
    pinMode(inputs[i], INPUT_PULLUP); // Настраиваем пины как входы
  }
  pinMode(12, OUTPUT); // Пин для индикации
  pinMode(13, OUTPUT); // Пин для индикации
}

void loop() {
  // Управление индикацией состояния xgamer
  digitalWrite(12, xgamer ? HIGH : LOW);
  digitalWrite(13, xgamer ? LOW : HIGH);

  // Проходим по каждому входу
  for (int i = 0; i < 9; i++) {
    if (digitalRead(inputs[i]) == LOW) { // Если пин активен (LOW)
      if (command[i] == 0) { // Если элемент массива еще не изменен
        command[i] = xgamer ? 1 : 2; // Устанавливаем 1 или 2 в зависимости от состояния xgamer
        xgamer = !xgamer; // Переключаем состояние игрока
      }
    }
  }

  // Отправляем обновленный массив
  Serial.write(command, sizeof(command));
  delay(500); // Задержка для предотвращения повторных срабатываний
}
