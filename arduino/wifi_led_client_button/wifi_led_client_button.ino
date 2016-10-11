/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */
#include <ESP8266WiFi.h>

const char* ssid     = "Chuan6";
const char* password = "12341234";

//const char* host = "192.168.1.94";
const char* host = "172.20.10.2";

const int buttonPin = 5;     // the number of the pushbutton pin
const int ledPin =  14;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
    Serial.begin(115200);
    delay(10);

    // turn on the built-in LED
    pinMode(2, OUTPUT);
    digitalWrite(ledPin, LOW);
    
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
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    // initialize the LED pin as an output:
    pinMode(ledPin, OUTPUT);
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);
}

//Change status when button is pressed
int ledStatus = -1;
int btnStatus = -1;

void loop()
{
    //delay(10);
    
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
    
    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:
    if (buttonState == HIGH)
    {
        // turn LED on:
        digitalWrite(ledPin, HIGH);
        
        // first time or just press
        if(btnStatus == -1 || btnStatus == 0)
        {
            btnStatus = 1;

            // send request to switch the LED
            sendData("SWT");
            
            /*
            // send data using http request
            if(ledStatus == 0)
            {
              sendData("ON");
              ledStatus = 1;
            }
            else
            {
              sendData("OFF");
              ledStatus = 0;              
            }
            */
        }
    }
    else
    {
        btnStatus = 0;
        
        // turn LED off:
        digitalWrite(ledPin, LOW);
        //sendData("OFF");
    }
}

// Send data using http request to the server
void sendData(String status)
{
    Serial.print("connecting to ");
    Serial.println(host);
    
    // Use WiFiClient class to create TCP connections
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort))
    {
        Serial.println("connection failed");
        return;
    }
    
    // We now create a URI for the request
    String url = "/LED=" + status;
    
    Serial.print("Requesting URL: ");
    Serial.println(url);
    
    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0)
    {
        if (millis() - timeout > 5000)
        {
            Serial.println(">>> Client Timeout !");
            client.stop();
            return;
        }
    }
    
    // Read all the lines of the reply from server and print them to Serial
    while(client.available())
    {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }
    
    Serial.println();
    Serial.println("closing connection");
}

