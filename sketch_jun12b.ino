char bluetoothData = 0;  // Stores incoming data 

void setup() {
  Serial.begin(9600);    // For Serial Monitor (USB)
  Serial1.begin(9600);   // For HC-05 (TX1=18, RX1=19)
  pinMode(13, OUTPUT);   // Built-in LED
  
  Serial.println("Arduino Mega Ready!");
  Serial1.println("AT+NAMEHC05_BT");  // Optional: Rename HC-05 (if needed)
}

void loop() {
  if (Serial1.available() > 0) {       // Check if HC-05 sent data
    bluetoothData = Serial1.read();    // Read the byte
    
    // Print to Serial Monitor (for debugging)
    Serial.print("HC-05 Sent: ");
    Serial.println(bluetoothData);
    
    // Echo back to HC-05 (optional)
    Serial1.print("Arduino Received: ");
    Serial1.println(bluetoothData);
    
    // Control LED
    if (bluetoothData == '1') {
      digitalWrite(13, HIGH);
      Serial.println("LED ON");
      Serial1.println("LED ON");
    } 
    else if (bluetoothData == '0') {
      digitalWrite(13, LOW);
      Serial.println("LED OFF");
      Serial1.println("LED OFF");
    }
  }
}
