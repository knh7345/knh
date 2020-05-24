#include <SPI.h>
#include "WizFi250.h"
#include <Wire.h>

char ssid[] = "GSSH_Drone";    
char pass[] = "0123456789";          
int status = WL_IDLE_STATUS;      
double before = analogRead(A0);

char server[] = "192.168.12.101";

#define PinA 5
#define PinB 6
#define Addr 0x1E 
#define num 20

int sensorValues_x[num];
int sensorValues_y[num];
int sensorValues_z[num];

WiFiClient client;

void printWifiStatus();

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire.beginTransmission(Addr); 
  Wire.write(byte(0x02));
  Wire.write(byte(0x00));
  Wire.endTransmission();
  
  WiFi.init();
  
  pinMode(PinA, INPUT); 
  pinMode(PinB, INPUT); 
  
    if (WiFi.status() == WL_NO_SHIELD) {
      Serial.println("WiFi shield not present");
      while (true);
    }
     while ( status != WL_CONNECTED) {
      Serial.print("Attempting to connect to WPA SSID: ");
      Serial.println(ssid);
      status = WiFi.begin(ssid, pass);
      Serial.println(status);
    }

    Serial.println("You're connected to the network");

    printWifiStatus();

    Serial.println();
    Serial.println("Starting connection to server...");
     if (client.connect(server, 80)) {
      Serial.println("Connected to server");
      heart_check();
    }
}


void loop()
{
    while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

   if (!client.connected()) {
    Serial.println();
    Serial.println("Disconnecting from server...");
    client.stop();

     while (true);
  }
}

char heart_check() //심정지 확인
{
  int pos[3]={0,0,0};
  int ptimes=0;
  int otimes=0;
  double now=0;
  double t=0;
 
  while (true)
  {
    if((digitalRead(PinA) == 1)||(digitalRead(PinB) == 1)){
      continue;
    }
    else{
        Serial.println(analogRead(A0));
        now=analogRead(A0);
        t=(now-before);
        if (t<=0.05 and t>=-0.05)  {
          Serial.print("Pause ");
          ptimes+=1;
          Serial.println(ptimes);
        }
        else  {
          Serial.print("OK ");
          otimes+=1;
          Serial.println(otimes);
        }
        if (otimes>=300)  {
          ptimes=0;
          otimes=0;
        }
        else if (ptimes>=70)  {
          Serial.println("1");
          if (otimes<=100)  {
            client.println(pos[0]);
            client.println(pos[1]);
            client.println(pos[2]);
            client.println('a');
            client.println();
            break;
          }
        }
    }
    Wire.beginTransmission(Addr);
    Wire.write(byte(0x03));       // Send request to X MSB register
    Wire.endTransmission();
   
    Wire.requestFrom(Addr, 6);    // Request 6 bytes; 2 bytes per axis
    if(Wire.available() <=6) {    // If 6 bytes available
      pos[0] = Wire.read() << 8 | Wire.read();
      pos[1] = Wire.read() << 8 | Wire.read();
      pos[2] = Wire.read() << 8 | Wire.read();
    }
    before=now;
    filter(pos[0],pos[1],pos[2]);
    delay(300);
  }
}

void printWifiStatus()
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

void filter(float x, float y, float z)
{
  for(int i=0; i < num-1; i++) {
    sensorValues_x[i] = sensorValues_x[i+1];
    sensorValues_y[i] = sensorValues_y[i+1];
    sensorValues_z[i] = sensorValues_z[i+1];
  }
  
  sensorValues_x[num-1] = x;
  sensorValues_y[num-1] = y;
  sensorValues_z[num-1] = z;
  float filter_x, filter_y, filter_z;

  for(int i=0; i < num; i++) {
    filter_x += sensorValues_x[i];
    filter_y += sensorValues_y[i];
    filter_z += sensorValues_z[i];
  }
  
  filter_x /= num;
  filter_y /= num;
  filter_z /= num;
  
  x=filter_x;
  y=filter_y;
  z=filter_z;
}
