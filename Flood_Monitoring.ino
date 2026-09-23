#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD I2C Address (Use 0x27 or 0x3F based on I2C scanner result)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin Definitions
#define TRIG_PIN 9
#define ECHO_PIN 10
#define FLOAT_SENSOR_PIN 7
#define BUZZER_PIN 6

// Tank and Alert Levels
const float tankHeight = 10.5; // Tank height in cm
const float alertLevel = 7.0;  // Flood Alert Trigger Level

void setup()
{
    Serial.begin(9600);

    // Initialize LCD
    lcd.begin(16, 2);
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("System Ready...");

    // Set pin modes
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(FLOAT_SENSOR_PIN, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);

    delay(2000);
    lcd.clear();
}

// Function to measure water level using ultrasonic sensor
float getWaterLevel()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout
    float distance = duration * 0.0343 / 2;         // Convert to cm
    float waterLevel = tankHeight - distance;       // Calculate actual water level

    // Ensure valid readings
    if (waterLevel < 0)
        waterLevel = 0;
    if (waterLevel > tankHeight)
        waterLevel = tankHeight;

    return waterLevel;
}

void loop()
{
    float waterLevel = getWaterLevel();
    int floatSensorState = digitalRead(FLOAT_SENSOR_PIN);

    // Print values to Serial Monitor for Debugging
    Serial.print("Water Level: ");
    Serial.print(waterLevel);
    Serial.println(" cm");

    Serial.print("Float Sensor State: ");
    Serial.println(floatSensorState == HIGH ? "Water Detected" : "No Water");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Water Level: ");
    lcd.print(waterLevel);
    lcd.print(" cm");

    // *Buzzer & LCD Alert System*
    if (waterLevel >= alertLevel)
    {
        Serial.println("🚨 FLOOD ALERT! Water Level at 7cm or above!");

        // Activate Buzzer
        digitalWrite(BUZZER_PIN, HIGH);
        delay(1000);
        digitalWrite(BUZZER_PIN, LOW);

        // Display FLOOD ALERT along with water level
        lcd.setCursor(0, 1);
        lcd.print("🚨 FLOOD ALERT!");
    }
    else
    {
        digitalWrite(BUZZER_PIN, LOW); // Ensure buzzer is OFF when below threshold
    }

    delay(2000); // Update every 2 seconds
}
So this is code.You just add that we like we have used blink and then from that when threshold level goes up, then we get email message and alarm.