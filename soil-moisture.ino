// Define the analog pin connected to the soil moisture sensor
const int sensorPin = A0;

// Define the digital pin connected to the buzzer
const int buzzerPin = 8;

// Variable to store raw sensor reading
int sensorValue = 0;

// Variable to store calculated soil moisture percentage
int moisturePercent = 0;

void setup() {
  // Start serial communication at 9600 bps (bits per second)
  // This allows us to print data to the Serial Monitor
  Serial.begin(9600);

  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the analog value from the soil moisture sensor
  sensorValue = analogRead(sensorPin);

  // Convert the raw sensor value (approx. range 300–800) to a percentage (0–100)
  // 800 = dry soil, 300 = wet soil (you may need to calibrate these values for your specific sensor)
  moisturePercent = map(sensorValue, 800, 300, 0, 100);

  // Ensure the moisture percentage stays within 0–100% bounds
  moisturePercent = constrain(moisturePercent, 0, 100);

  // Print the moisture percentage to the Serial Monitor
  Serial.print("Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // Check if the soil moisture is below 30%
  if (moisturePercent < 30) {
    // If the soil is too dry, alert using the buzzer
    Serial.println("Status: Soil is DRY");
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
  } else {
    // If the soil is adequately moist
    Serial.println("Status: Soil is OK");
    digitalWrite(buzzerPin, LOW);   // Turn off the buzzer
  }

  // Print a separator line for readability in Serial Monitor
  Serial.println("--------------------------");

  // Wait for 2 seconds before taking another reading
  delay(2000);
}
