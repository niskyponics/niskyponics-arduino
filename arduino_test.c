void setup()
{
/* sets the arduino data rate in bits per second at 9600 */
    Serial.begin(9600);
}

void loop()
{
	
/* code to tell if arduino is working */
    Serial.print("Hello World! from Arduino");
    Serial.println(millis());
    
    delay(1000);
}
