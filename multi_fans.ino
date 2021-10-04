// pinout: https://media.digikey.com/Photos/RDL/ESP32-DEVKITC-32D%20-%20Pinout.jpg

const int fans[] = {25, 26, 27, 13,  // A B C D
                    23, 22, 32, 33}; // E F G H

void setup() {
  Serial.begin(115200);
  delay(100); // wait till serial port is ready

  // print instructions
  Serial.println("\n * Fans IDs:");
  Serial.println("A B C D");
  Serial.println("E F G H");

  Serial.println("\n * Command examples:");
  Serial.println("A => turn fan #0 ON");
  Serial.println("h => turn fan #7 off");

  Serial.println("\n => your turn! \n");

  for (int i = 0; i < 8; i++)
    pinMode(fans[i], OUTPUT);
}


void loop() {
  if (Serial.available()) {
    char inChar = (char)Serial.read();

    // convert letter to number:
    unsigned id = toLowerCase(inChar) - 'a';

    if (id < 8) {
      // if uppercase then turn on, otherwise off:
      bool state = (inChar >= 'A' && inChar <= 'H');
      digitalWrite(fans[id], state);

      Serial.print(id);
      Serial.print(" => ");
      Serial.println(state);
    }
  }
}
