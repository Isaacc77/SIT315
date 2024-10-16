// Pin definitions
const int pirPin = 2;   // PIR sensor on 2
const int ledPin = 13;  // led on 13

// Store motion status
volatile bool motionDetected = false;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set LED as output
  pinMode(ledPin, OUTPUT);
  
  // Attach an interrupt to pin 2, which triggers on RISING signal (motion detected)
  attachInterrupt(digitalPinToInterrupt(pirPin), detectMotion, RISING);
}

void loop() {
  // not in use due to interrupt
  if (motionDetected) {
  // Turn on the LED
  digitalWrite(ledPin, HIGH);
  Serial.println("Motion Detected");
  // Reset the flag after processing
  motionDetected = false;
  delay(500);
  } else {
  // Turn off the LED when no motion is detected
  digitalWrite(ledPin, LOW);
  Serial.println("No Motion");

  // Small delay to avoid flooding the serial monitor
  delay(500);
  }
}
  // Interrupt Service Routine (ISR) to handle PIR sensor
void detectMotion() {
  // Toggle the motion detected flag
  motionDetected = true;
  Serial.println("Interrupt");
  }
