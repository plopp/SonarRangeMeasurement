/*
 * Copyright 2013 Marcus Kempe
 *
 */

/*
 * Define the pins you want to use as trigger and echo.
 */

#define ECHOPIN 3        // Pin to receive echo pulse
#define TRIGPIN 2        // Pin to send trigger pulse

/*
 * setup function
 * Initialize the serial line (D0 & D1) at 115200.
 * Then set the pin defined to receive echo in INPUT 
 * and the pin to trigger to OUTPUT.
 */

void setup()
{
  Serial.begin(115200);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

/*
 * loop function.
 * 
 */
void loop()
{
  // Start Ranging
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  // Compute distance
  float distance = pulseIn(ECHOPIN, HIGH);
  distance= distance/58;
  Serial.println(distance);
  delay(50);
}
