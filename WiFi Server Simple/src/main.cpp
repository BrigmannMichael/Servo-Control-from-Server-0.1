#include <WiFi.h>
#include <Arduino.h>
#include <ESP32Servo.h>


const int buttonPin = 25;
const int servoPin = 18;
Servo servo;
int pos = 0;
const char* ssid     = "brigmann";
const char* password = "Anm3ldun9";

String header;
const int LEDPIN = 5;
String LEDSTATE = "off";

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);
    pinMode(LEDPIN, OUTPUT);      // set the LED pin mode
    servo.attach(servoPin);
    pinMode(buttonPin, INPUT);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();
    

}

void loop(){
  int buttonState = digitalRead(buttonPin);

 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");

            client.println("<style>html { font-family: monospace; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: yellowgreen; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 32px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: gray;}</style></head>");

            client.println("<body><h1>Servo Motor Control</h1>");
            client.println("<p>Brigmann Engineering</p>");

            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");
            client.print("Servo 45 <a href=\"/A\">here</a> to activate the servo motor.<br>");
            client.print("Servo 90 <a href=\"/B\">here</a> to activate the servo motor.<br>");
            client.print("Servo 135 <a href=\"/C\">here</a> to activate the servo motor.<br>");
            client.print("Servo 315 <a href=\"/A\">here</a> to activate the servo motor.<br>");
            client.print("Servo 270 <a href=\"/B\">here</a> to activate the servo motor.<br>");
            client.print("Servo 225 <a href=\"/C\">here</a> to activate the servo motor.<br>");

            
            if (LEDSTATE == "off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");

            if (header.indexOf("GET /5/on") >= 0) {
              LEDSTATE = "on";
              digitalWrite(LEDPIN, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /5/off") >= 0) {
              LEDSTATE = "off";
              digitalWrite(LEDPIN, LOW);  }

          
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(5, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /5/on")) {
          digitalWrite(5, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(5, LOW);                // GET /L turns the LED off
        }
        if (currentLine.endsWith("GET /A")) {
          digitalWrite(25, LOW);   
          if (buttonState == LOW){
          	for (pos = 0; pos <= 45; pos += 1) { 
		      		servo.write(pos);   
            		delay(15); }
          	for (pos = 45; pos >= 0; pos -= 1) { 
	          	servo.write(pos);    
	            	delay(15);             
	}}}
   if (currentLine.endsWith("GET /B")) {
          digitalWrite(25, LOW);   
          if (buttonState == LOW){
          	for (pos = 0; pos <= 90; pos += 1) { 
		      		servo.write(pos);   
            		delay(15); }
          	for (pos = 90; pos >= 0; pos -= 1) { 
	          	servo.write(pos);    
	            	delay(15);             
	}}}
   if (currentLine.endsWith("GET /C")) {
          digitalWrite(25, LOW);   
          if (buttonState == LOW){
          	for (pos = 0; pos <= 135; pos += 1) { 
		      		servo.write(pos);   
            		delay(15); }
          	for (pos = 135; pos >= 0; pos -= 1) { 
	          	servo.write(pos);    
	            	delay(15);             
	}}}
  if (currentLine.endsWith("GET /D")) {
          digitalWrite(25, LOW);   
          if (buttonState == LOW){
          	for (pos = 0; pos <= 315; pos += 1) { 
		      		servo.write(pos);   
            		delay(15); }
          	for (pos = 315; pos >= 0; pos -= 1) { 
	          	servo.write(pos);    
	            	delay(15);             
	}}}
   if (currentLine.endsWith("GET /E")) {
          digitalWrite(25, LOW);   
          if (buttonState == LOW){
          	for (pos = 0; pos <= 270; pos += 1) { 
		      		servo.write(pos);   
            		delay(15); }
          	for (pos = 270; pos >= 0; pos -= 1) { 
	          	servo.write(pos);    
	            	delay(15);             
	}}}
   if (currentLine.endsWith("GET /F")){ 
          digitalWrite(25, LOW);   
          if (buttonState == LOW){
          	for (pos = 0; pos <= 225; pos += 1) { 
		      		servo.write(pos);   
            		delay(15); }
          	for (pos = 225; pos >= 0; pos -= 1) { 
	          	servo.write(pos);    
	            	delay(15);             
	}}}
      }}
      
         // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
      }}
