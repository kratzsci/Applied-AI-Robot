 #include <WiFi.h>  

 // Create the objects for server and client  
 WiFiServer server(80);  
 WiFiClient client;  
   
 const char* ssid   = "AI-ASL-BOT";// This is the SSID that ESP32 will broadcast  
 const char* password = "JohPhi";     // password should be atleast 8 characters to make it work  
   
 // Create the global variable  
 String http;  
 String bluLedState = "off";  
 String grnLedState = "off";  
 String redLedState = "off";
 String drivingState = "STOP";
  
  // Motor A
  int motor1Pin1 = 15; 
  int motor1Pin2 = 2;
  int motor2Pin1 = 4;
  int motor2Pin2 = 5;  
  
 void setup() {  
  Serial.begin(115200);  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
   
  WiFi.softAP(ssid, password);  
   
  Serial.println( "" );  
  Serial.println( "WiFi AP is now running" );  
  Serial.println( "IP address: " );  
  Serial.println( WiFi.softAPIP() );  


  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT); 
   
  // Start our ESP32 server  
  server.begin();  
 }  
   
 void loop(){  
    
  if ( client = server.available() ) {  // Checks if a new client tries to connect to our server  
   Serial.println("New Client.");  
   String clientData = "";  
   while ( client.connected() ) {    // Wait until the client finish sending HTTP request  
    if ( client.available() ) {     // If there is a data,  
     char c = client.read();      //  read one character  
     http += c;            //  then parse it  
     Serial.write(c);    
     if (c == '\n') {         // If the character is carriage return,   
                      //  it means end of http request from client  
      if (clientData.length() == 0) { //  Now that the clientData is cleared,  
       sendResponse();        //    perform the necessary action  
       updateLED();  
       updateWebpage();
       DriveMotors();  
       break;  
      } else {  
       clientData = "";       //  First, clear the clientData  
      }  
     } else if (c != '\r') {      // Or if the character is NOT new line  
      clientData += c;        //  store the character to the clientData variable  
     }  
    }  
   }   
   http = "";  
   client.stop();            // Disconnect the client.  
   Serial.println("Client disconnected.");  
   Serial.println("");  
  }  
 }  
   
 void sendResponse() {  
  // Send the HTTP response headers  
  client.println("HTTP/1.1 200 OK");  
  client.println("Content-type:text/html");  
  client.println("Connection: close");  
  client.println();   
 }  
   
 void updateWebpage() {  
  // In here we will display / update the webpage by sending the HTML   
  //  to the connected client  
  // In order for us to use the HTTP GET functionality,  
  //  the HTML hyperlinks or href is use in the buttons.   
  //  So that, when you press the buttons, it will send a request to the   
  //  web server with the href links by which our ESP32 web server will  
  //  be check using HTTP GET and execute the equivalent action  
    
  // Send the whole HTML  
  client.println("<!DOCTYPE html><html>");  
  client.println("<head>");  
  client.println("<title>ASL AI</title>");  
  client.println("</head>");  
    
  // Web Page Heading  
  client.println("<body><h1>ASL AI Robot Control</h1>");  
   
  // Display buttons for Blue LED  
  client.println("<p>Robot satus: " + drivingState + "</p>");    

   
  client.print("<hr>");  
  
  client.println("<p><a href=\"/DRIVE/STOP\"><button id=\"DRIVE\">STOP</button></a></p>");
  client.println("<p><a href=\"/DRIVE/FORWARD\"><button id=\"STOP\">FORWARD</button></a></p>");
  client.println("<p><a href=\"/TURN/LEFT\"><button id=\"LEFT\">LEFT</button></a></p>");
  client.println("<p><a href=\"/TURN/RIGHT\"><button id=\"RIGHT\">RIGHT</button></a></p>");
  
  client.println("</body></html>");  
  client.println();  
 }  
   
 void updateLED() {  
  // In here we will check the HTTP request of the connected client  
  //  using the HTTP GET function,  
  //  Then turns the LED on / off according to the HTTP request  
  if (http.indexOf("GET /DRIVE/FORWARD") >= 0) {
    drivingState = "FORWARD";  
  } else if (http.indexOf("GET /DRIVE/STOP") >= 0) {
    drivingState = "STOP";  
  } else if (http.indexOf("GET /TURN/LEFT") >= 0) {
    drivingState = "LEFT";  
  } else if (http.indexOf("GET /TURN/RIGHT") >= 0) {
    drivingState = "RIGHT";  
  } else if (http.indexOf("GET /TURN/STRAIGHT") >= 0) {
    drivingState = "STRAIGHT";  
  }
 }  

 void DriveMotors() {
    if(drivingState == "FORWARD"){
      //Forward
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
    }
    else if(drivingState == "STOP"){
      //Stop
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
    }
 }
