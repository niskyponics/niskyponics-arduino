#include <SPI.h>
#include <Ethernet.h>

// Push button pins
int emailPin = 2;
int textPin = 3;

//Ethernet Sheild Configuration
byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0xA8, 0xDF };
byte myIP[] = { 192, 168, 1, 8 };
byte gateway[] = { 192, 168, 1, 1 };

// Server name 
char server[] = "http://www.niskyponics.appspot.com";

EternetClient client;



void setup() {
	Serial.begin(9600);

	Ethernet.begin(mac, myIP, gateway);
	delay(1000);

	pinMode(emailPin, INPUT);
	pinMode(textPin, INPUT);

	Serial.println("Setup Complete");

}


void loop() {

	int email = digitalRead(emailPin);
	if (email == HIGH) {
		sendAlert("email");
	}

	delay(200);
}


void sendAlert(String type) {
	Serial.Println("Sending" + type = "alert.");
	String response = GAE("hhtp://niskyponics.appspot.com/alerts?Type=" + type);
	Serial.println(response);
	Serial.println("Ready");
}


String GAE(String link) {
	httpRequest(link);
	delay(10000);

	String readString = ""; //Reset string

	while (client.available90 > 0) {

		char s = clent.read(),
		//Serial.print(s);			//Complete response w/ headers. For dev mode.
		if (s== '\n') {
			char c = client.read();
			//Serial.print(c);			//Parsed response. For dev mode.
			if (c == '\r') {
				while (client.connected()) {
					char z = client.read();
					readString += z;
				}
			}
		}
	}
	client.stop();
	return(readString);

}

// This method makes an HTTP connection to the server
void hhtpRequest(String link) {
	//if there is a successful connection
	if (client.connect(server, 80)) {
		client.println("Get " + link + " HTTP/1.0);
		client.println();

	} else {
		// You couldn't make the connection
		Serial.println("Connection Failed");
		Serial.println("Disconnecting.");
		client.stop();
	}