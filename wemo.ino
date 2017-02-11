
#define ON "1"
#define OFF "0"

TCPClient client;
char wemoIP[ ] = "10.0.1.10";
int wemoPort = 49153;

void setup() {
    Serial.begin(9600);
}

void switchSet(String state) {
  TCPClient client;
  String data1;
  data1 += "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:SetBinaryState xmlns:u=\"urn:Belkin:service:basicevent:1\"><BinaryState>";
  data1 += state;
  data1 += "%d</BinaryState></u:SetBinaryState></s:Body></s:Envelope>";

  Serial.println("switchState");
  if (client.connect(wemoIP,wemoPort)) {
        client.println("POST /upnp/control/basicevent1 HTTP/1.1");
        client.println("Content-Type: text/xml; charset=utf-8");
        client.println("SOAPACTION: \"urn:Belkin:service:basicevent:1#SetBinaryState\"");
        client.println("Connection: keep-alive");
        client.print("Content-Length: ");
        client.println(data1.length());
        client.println();
        client.print(data1);
        client.println();
    }

  if (client.connected()) {
     client.stop();
  }
}

void switchOn() {
  switchSet(ON);
}

void switchOff() {
  switchSet(OFF);
}

void loop() {
  switchOn();
  delay(1000);
  switchOff();
  delay(1000);
}

