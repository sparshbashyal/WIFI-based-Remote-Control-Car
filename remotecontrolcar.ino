#include<ESP8266WiFi.h>

#define rl1 D1 
#define rl2 D2 
#define ll1 D5 
#define ll2 D6 
#define enableright D7 
#define enableleft D8 

#define motorspeed 180
unsigned long lastMsg = 0;
WiFiClient client;
WiFiServer server(80);


void setup() {
   Serial.begin(74880);
  Serial.println("Connecting to WiFi...");
  
  WiFi.begin("impress@vianet","#Impress2628");
  
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");  
    delay(500);         
  }
  
  Serial.println("");
  Serial.println("WiFi successfully connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  
  server.begin();
  pinMode(rl1,OUTPUT);
  pinMode(rl2,OUTPUT);
  pinMode(ll1,OUTPUT);
  pinMode(ll2,OUTPUT);
  pinMode(enableright,OUTPUT);
  pinMode(enableleft,OUTPUT);
}

void loop() {
  client = server.available();
  if(client == 1){
    String request = client.readStringUntil('\n');
    request.trim();
    if (request.indexOf("/front") != -1){
      rotatemotor(motorspeed,motorspeed);
    }
    else if(request.indexOf("/left") != -1){
      rotatemotor(motorspeed,-motorspeed);
    }
    else if (request.indexOf("/right") != -1){
      rotatemotor(-motorspeed,motorspeed);
    }
    else if(request.indexOf("/back") != -1){
      rotatemotor(-motorspeed,-motorspeed);
    }
    else if(request.indexOf("/stop") != -1){
      rotatemotor(0,0);
    }
  }  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("<meta charset='utf-8'>"); 
  client.println("<meta name='viewport' content='width=device-width, initial-scale=1, maximum-scale=1, user-scalable=0'>");
  client.println(""); 
  client.println("<!DOCTYPE HTML><html><head>");
  client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0'>");
  
  // CSS Styling for the D-Pad
  client.println("<style>");
  client.println("body { background-color: #222; color: white; font-family: sans-serif; text-align: center; }");
  client.println(".dpad { display: grid; grid-template-columns: 100px 100px 100px; grid-template-rows: 100px 100px 100px; gap: 10px; justify-content: center; margin-top: 50px; }");
  client.println(".btn { width: 100%; height: 100%; font-size: 20px; font-weight: bold; border-radius: 15px; border: none; background: #444; color: white; touch-action: manipulation; }");
  client.println(".btn:active { background: #00ff00; color: black; }"); 
  client.println(".up { grid-column: 2; }");
  client.println(".left { grid-column: 1; grid-row: 2; }");
  client.println(".right { grid-column: 3; grid-row: 2; }");
  client.println(".down { grid-column: 2; grid-row: 3; }");
  client.println("</style>");

  // JavaScript for background requests
client.println("<script>");
client.println("function sendCmd(event, cmd){");
client.println("  if(event) event.preventDefault();");
client.println("  var xhttp = new XMLHttpRequest();");
client.println("  xhttp.open('GET', '/' + cmd, true);");
client.println("  xhttp.send();");
client.println("}");
client.println("</script>");

  client.println("<h2>RC COMMAND CENTER</h2>");
  
  client.println("<div class='dpad'>");
  
  
  client.println("<button class='btn up' onmousedown='sendCmd(event,\"front\")' onmouseup='sendCmd(event,\"stop\")' ontouchstart='sendCmd(event,\"front\")' ontouchend='sendCmd(event,\"stop\")' ontouchcancel='sendCmd(event,\"stop\")'>&#9650</button>");
  
  
  client.println("<button class='btn left' onmousedown='sendCmd(event,\"left\")' onmouseup='sendCmd(event,\"stop\")' ontouchstart='sendCmd(event,\"left\")' ontouchend='sendCmd(event,\"stop\")' ontouchcancel='sendCmd(event,\"stop\")'>&#9664</button>");
  
  
  client.println("<button class='btn right' onmousedown='sendCmd(event,\"right\")' onmouseup='sendCmd(event,\"stop\")' ontouchstart='sendCmd(event,\"right\")' ontouchend='sendCmd(event,\"stop\")' ontouchcancel='sendCmd(event,\"stop\")'>&#9654</button>");

  
  client.println("<button class='btn down' onmousedown='sendCmd(event,\"back\")' onmouseup='sendCmd(event,\"stop\")' ontouchstart='sendCmd(event,\"back\")' ontouchend='sendCmd(event,\"stop\")' ontouchcancel='sendCmd(event,\"stop\")'>&#9660</button>");
  
  client.println("</div>");
  client.println("</body></html>");
  
  delay(1);
}

void rotatemotor(int rightmotor,int leftmotor){
  // right motor 
  if(rightmotor>0){
    digitalWrite(rl1,LOW);
    digitalWrite(rl2,HIGH);
  }
  else if(rightmotor<0){
    digitalWrite(rl1,HIGH);
    digitalWrite(rl2,LOW);
  }
  else if(rightmotor==0){
    digitalWrite(rl1,LOW);
    digitalWrite(rl2,LOW);
  }
  //left motor
  if(leftmotor>0){
    digitalWrite(ll1,LOW);
    digitalWrite(ll2,HIGH);
  }
  else if(leftmotor<0){
    digitalWrite(ll1,HIGH);
    digitalWrite(ll2,LOW);
  }
    else if(leftmotor==0){
    digitalWrite(ll1,LOW);
    digitalWrite(ll2,LOW);
  }
analogWrite(enableright,abs(rightmotor));
analogWrite(enableleft,abs(leftmotor));
}

