#include "DHT.h"
#define DHTPIN 23    
#define DHTTYPE DHT11  
#include <WiFi.h>
#include <PubSubClient.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>

// Replace the next variables with your SSID/Password combination
const char* ssid = "Moto";
const char* password = "12345678";

// Insert Firebase project API Key
#define API_KEY "AIzaSyDLyu1qVzjpg8E_VI4HLfz1qv9IApwWfDA"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://reto-354a6-default-rtdb.firebaseio.com/"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int intValue;
float floatValue;

DHT dht(DHTPIN, DHTTYPE);
int luz = 15;
int valor = 0;  
int carrera = 18;

bool signupOK = false;
int count = 0;

void setup() 
{
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));
  pinMode(carrera, INPUT);

  dht.begin();
  setup_wifi();
}

void setup_wifi() {
  //WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  //* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}


void loop() 
{

////////////////////////////Sensor de iluminación/////////////////////
valor = analogRead(luz);

if (valor > 3800){
  const char* estado = "Oscuridad";
  Serial.println(estado);
  Serial.println(valor);
}
else if (valor <= 3800 && valor >= 1000){
  const char* estado = "Ambiente";
  Serial.println(estado);
  Serial.println(valor);
}
else if (valor < 1000){
  const char* estado = "Luz";
  Serial.println(estado);
  Serial.println(valor);
}

///////////////////////Sensor fin de carrera////////////////////////////////////////////
if (digitalRead(carrera)){
  const char* pres_lib = "Presionado";
  Serial.println("pres_lib");
}
else{
  const char* pres_lib = "Libre";
  Serial.println("pres_lib");
}

///////////////////////Sensor fin de temperatura y humedad////////////////////////////////////////////
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) 
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);

///////////////////////firebase////////////////////////////////////////////
   if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();

    // Write an FLOAT number on the database path test/float
    if (Firebase.RTDB.setFloat(&fbdo, "test/temperatura", t)){ ///TEMPERATURA
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    if (Firebase.RTDB.setFloat(&fbdo, "test/humedad", h)){ ///HUMEDAD
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }

    if (Firebase.RTDB.setFloat(&fbdo, "test/valor", valor)){ ///VALOR DE LA FOTO RESISTENCIA
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }

    //Write an STRING number on the database path test/string
    if (Firebase.RTDB.setString(&fbdo, "test/estado", estado)){ ///ESTADO DE LA FOTO RESISTENCIA
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }

    if (Firebase.RTDB.setString(&fbdo, "test/pres_lib", pres_lib)){ ///FIN DE CARRERA (PRESIONADO/LIBRE)
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
  }
}
