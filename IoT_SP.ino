
#include "DHT.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>

#define DHTPIN 23    
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);
int luz = 32;
int valor = 0;
int carrera = 18;
bool signupOK = false;
int count = 0;


//firebase config
// SSID/Password combination
const char* ssid = "Pablito";
const char* password = "12345678";
#define API_KEY "AIzaSyDLyu1qVzjpg8E_VI4HLfz1qv9IApwWfDA" //firebase project API Key
#define DATABASE_URL "https://reto-354a6-default-rtdb.firebaseio.com/" // RTDB URLefine the RTDB URL */

//Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int intValue;
float floatValue;
void funcion_firebase(float tempValue, float humValue, float luzValue, String luzState, String switchState);

//////SETUP
void setup() 
{
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));
  pinMode(carrera, INPUT);
  dht.begin();
  setup_wifi();
}

////LOOP
void loop() {
  delay(2000);
  valor_luz();
  estado_luz();
  delay(2000);
  fin_de_carrera();

  float tempValue = temp_dht();
  float humValue = hum_dht();
  float luzValue = valor_luz();
  String luzState = estado_luz();
  String switchState = fin_de_carrera();

  funcion_firebase(tempValue, humValue, luzValue, luzState, switchState);
}


///FUNCION WIFI
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

//FUNCIONES SENSORES
//VALOR ILUMINCACION
 float valor_luz(){
  valor = analogRead(32);
  Serial.print("El valor de la lectura es ");
  Serial.println(valor);

  return valor;
  }
//ESTADO ILUMINCACION
String estado_luz() {
  String estado_l;
  valor = analogRead(luz);

  if (valor > 3800) {
    estado_l = "Oscuridad";
  } else if (valor <= 3800 && valor >= 1000) {
    estado_l = "Ambiente";
  } else if (valor < 1000) {
    estado_l = "Luz";
  }
    Serial.println("Estado: ");
    Serial.println(estado_l);
  return estado_l;
}
//FIN DE CARRERA
String fin_de_carrera() {
  String estado_c;

  if (digitalRead(carrera)) {
    Serial.println("Presionado");
    estado_c = "Presionado";
  } else {
    Serial.println("Libre");
    estado_c = "Libre";
  }

  return estado_c;
}
///TEMPERATURA
float temp_dht() {
  float t = dht.readTemperature();
  
  if (isnan(t)) {
    Serial.println(F("Failed to read temperature from DHT sensor!"));
    return 0.0; 
  }
  
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println();
  
  return t;
}
//HUMEDAD
float hum_dht() {
  float h = dht.readHumidity();
  
  if (isnan(h)) {
    Serial.println(F("Failed to read humidity from DHT sensor!"));
    return 0.0;
  }
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println();
    
  return h;
}
    
  ///FIREBASE
void funcion_firebase(float tempValue, float humValue, float luzValue, String luzState, String switchState){
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();

    if (Firebase.RTDB.setFloat(&fbdo, "test/temperatura", tempValue)){ ///TEMPERATURA
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println(
        
        
        "TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }

    if (Firebase.RTDB.setFloat(&fbdo, "test/humedad", humValue)){ ///HUMEDAD
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }

    if (Firebase.RTDB.setFloat(&fbdo, "test/valor", luzValue)){ ///VALOR DE LA FOTO RESISTENCIA
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    
      if (Firebase.RTDB.setString(&fbdo, "test/estado", luzState)){ ///ESTADO DE LA FOTO RESISTENCIA
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }

    if (Firebase.RTDB.setString(&fbdo, "test/pres_lib", switchState)){ ///FIN DE CARRERA (PRESIONADO/LIBRE)
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
