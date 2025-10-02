#include <Arduino.h>
#include <OneButton.h>

// Định nghĩa chân LED
#define LED1 2        // LED tích hợp sẵn trên board ESP32 (GPIO2)
#define LED2 25       // LED ngoài nối vào GPIO25

// Định nghĩa chân nút nhấn
#define BUTTON_PIN 26

// Tạo đối tượng OneButton
OneButton button(BUTTON_PIN, true, true);

bool controlLED1 = true;   // Đang điều khiển LED1 hay LED2
bool blinking = false;     // Trạng thái nhấp nháy
bool ledState = false;     // Trạng thái LED hiện tại
unsigned long lastToggle = 0;

void handleClick() {
  blinking = false;  // single click thì tắt chế độ nhấp nháy
  ledState = !ledState;

  if (controlLED1) {
    digitalWrite(LED1, ledState ? HIGH : LOW);
    digitalWrite(LED2, LOW);
  } else {
    digitalWrite(LED2, ledState ? HIGH : LOW);
    digitalWrite(LED1, LOW);
  }
}

void handleDoubleClick() {
  blinking = false;
  ledState = false;
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);

  controlLED1 = !controlLED1;  // Chuyển LED điều khiển
  Serial.print("Switched control to: ");
  Serial.println(controlLED1 ? "LED1" : "LED2");
}

void handleLongPress() {
  blinking = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);

  button.attachClick(handleClick);
  button.attachDoubleClick(handleDoubleClick);
  button.attachLongPressStart(handleLongPress);

  Serial.println("System ready. Single click = toggle LED, Double click = switch LED, Long press = blink");
}

void loop() {
  button.tick();

  if (blinking) {
    if (millis() - lastToggle >= 200) { // Blink mỗi 200ms
      lastToggle = millis();
      ledState = !ledState;

      if (controlLED1) {
        digitalWrite(LED1, ledState ? HIGH : LOW);
      } else {
        digitalWrite(LED2, ledState ? HIGH : LOW);
      }
    }
  }
}
