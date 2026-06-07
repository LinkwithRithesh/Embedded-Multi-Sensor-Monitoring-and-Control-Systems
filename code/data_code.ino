int ir = 2;
int gas = 3;
int led = 4;

int m1 = 5;
int m2 = 13;

float temperature;
int tempSensor = A0;
float thres_temp = 20.0;

int trig = 7;
int echo = 8;

int a = 9;
int b = 10;
int c = 11;
int d = 12;

void setup()
{
    pinMode(ir, INPUT);
    pinMode(gas, INPUT);
    pinMode(led, OUTPUT);

    pinMode(m1, OUTPUT);
    pinMode(m2, OUTPUT);

    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    Serial.println("===== SYSTEM STATUS =====");

    // =================================================
    // 1. IR SENSOR
    // =================================================

    int ir_value = digitalRead(ir);

    if (ir_value == HIGH)
    {
        Serial.println("Object Detected");
    }
    else
    {
        Serial.println("No Object Detected");
    }

    Serial.println("-------------------");
    delay(500);

    // =================================================
    // 2. GAS SENSOR + EMERGENCY LED
    // =================================================

    int gas_value = digitalRead(gas);

    if (gas_value == HIGH)
    {
        Serial.println("GAS LEAKAGE DETECTED !!!");

        for (int i = 0; i < 5; i++)
        {
            digitalWrite(led, HIGH);
            delay(50);

            digitalWrite(led, LOW);
            delay(50);
        }
    }
    else
    {
        Serial.println("No Gas Detected");
        digitalWrite(led, LOW);
    }

    Serial.println("-------------------");
    delay(500);

    // =================================================
    // 3. TEMPERATURE + DC MOTOR
    // =================================================

    int temp_value = analogRead(tempSensor);

    temperature = (temp_value * 5.0 * 100.0) / 1023.0;

    Serial.print("Temperature : ");
    Serial.print(temperature);
    Serial.println(" C");

    if (temperature >= thres_temp)
    {
        Serial.println("DC Motor ON");

        digitalWrite(m1, HIGH);
        digitalWrite(m2, LOW);
    }
    else
    {
        Serial.println("DC Motor OFF");

        digitalWrite(m1, LOW);
        digitalWrite(m2, LOW);
    }

    Serial.println("-------------------");
    delay(500);

    // =================================================
    // 4. ULTRASONIC + STEPPER MOTOR
    // =================================================

    digitalWrite(trig, LOW);
    delayMicroseconds(2);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);

    digitalWrite(trig, LOW);

    long duration = pulseIn(echo, HIGH);

    float distance = duration * 0.034 / 2;

    Serial.print("Distance : ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance >= 15)
    {
        Serial.println("Object Far");

        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
    }
    else
    {
        Serial.println("Object Close");

        // Clockwise Rotation
        for (int i = 0; i < 13; i++)
        {
            digitalWrite(a, HIGH);
            delay(100);
            digitalWrite(a, LOW);

            digitalWrite(b, HIGH);
            delay(100);
            digitalWrite(b, LOW);

            digitalWrite(c, HIGH);
            delay(100);
            digitalWrite(c, LOW);

            digitalWrite(d, HIGH);
            delay(100);
            digitalWrite(d, LOW);
        }

        // Anti-Clockwise Rotation
        for (int i = 0; i < 13; i++)
        {
            digitalWrite(d, HIGH);
            delay(100);
            digitalWrite(d, LOW);

            digitalWrite(c, HIGH);
            delay(100);
            digitalWrite(c, LOW);

            digitalWrite(b, HIGH);
            delay(100);
            digitalWrite(b, LOW);

            digitalWrite(a, HIGH);
            delay(100);
            digitalWrite(a, LOW);
        }
    }

    Serial.println("-------------------");
    delay(1000);
}
