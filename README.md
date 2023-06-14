# TC1004B_IoT_SituacionProblema

### Noreth Sofía Villalpando Saldaña A01368578
### Paulina Reyes Reyes A01747136

## Situación Problema.

A lo largo de cuatro semanas, para el reto de IoT se creó una base de datos en la página **Firebase**, la cual posteriormente se utilizaría para registrar ciertas lecturas. Estas cinco lecturas serán tomadas de tres sensores y una placa **ESP32**. Estos se utilizarán en conjunto con **Arduino IDE** y **AppInventor**. En **Arduino**, se realizará un código en el cual se logre la conexión entre la base de datos, la placa y los sensores. Mientras que **AppInventor** será utilizado para desarrollar una aplicación de teléfono móvil en la cual se observará la información de la base de datos **Firebase** y se permita subir dos datos al **Firebase** (usuario y dígito).

## Diagrama de Conexiones
![Imagen de WhatsApp 2023-06-13 a las 19 37 04](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/5a0dcd48-42b0-4252-8b94-b539e753cc71)

## Configuraciones en Arduino IDE
### Gestor de tarjetas
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/679d0142-721b-4258-8f9e-d3d5cf5eb370)

![Captura de Pantalla 2023-06-13 a la(s) 8 28 57 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/3ef7707c-19e9-4250-9ded-f1b0ac7c5478)

### Librerías
![Captura de Pantalla 2023-06-13 a la(s) 8 29 52 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/5a1f3e4b-288e-414e-b8de-0d1470dbf0d2)

![Captura de Pantalla 2023-06-13 a la(s) 8 31 04 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/3608c60b-cc2b-4e24-8c2c-20a3c834d534)

![Captura de Pantalla 2023-06-13 a la(s) 8 31 45 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/88bf12e4-da06-4950-984f-d77feae29828)

![Captura de Pantalla 2023-06-13 a la(s) 8 32 19 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/14d9c13f-6274-459b-8b00-386718aef49a)

![Captura de Pantalla 2023-06-13 a la(s) 8 33 04 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/755607fb-7e40-4494-827f-d7d30167503f)


## Código

### Librerías
![Imagen de WhatsApp 2023-06-13 a las 19 49 37](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/f547bb8c-1fbb-417e-86f8-c14e795be59e)

Primero se integran las librerías que se van a utilizar: la librería DHT es para el sensor de temperatura y humedad DHT11, la librería Wifi es para establecer una conexión WiFi, PubSubClient es para el MQTT que es utilizado por **Firebase**, FirebaseESPClient es para poder interactuar con **Firebase** y TokenHelper es para los tokens de autenticación.

### Variables y constantes

![Imagen de WhatsApp 2023-06-13 a las 19 54 02](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/47dfc4cc-0153-4f1e-aac3-8f6d3f5a6854)

Se definen ciertas constantes, una de ellas es para las credenciales de la red WiFi a la cual se debe de conectar el dispositivo (*SSID* y *Password*). Igualmente se introduce la clave de *API* para la base de datos **Firebase**, de la misma manera, se agrega la *URL* de la base de datos. Firebase *fbdo* funciona para interactuar con la base de datos, *auth* para la autenticación de usuario y *config* para la configuración de la conexión y autenticación de la base de datos.

La variable *sendDataPrevMillis* es utilizada para el control de tiempo del envío de datos a **Firebase** y las variables *intValue* y *floatValue* son utilizadas para el almacenamiento. Igualmente, se colocan las variables para *luz*, *valor* y *carrera* y el objeto *DHT*. La variable *signup* es para observar la conexión, si es verdadero (*true*) es exitosa la conexión, si es falso (*false*) se imprime un mensaje de error en la consola.

### Main function 
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/610ee85d-082a-4f6f-b532-14bd8034a418)


### Conexión Wi-Fi 
![Imagen de WhatsApp 2023-06-13 a las 19 59 50](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/c298076d-f921-4011-9c7d-d15c0b9ef5d8)

Aquí es donde se inicializa la comunicación serial y el sensor DHT. Llama a la función *setup_wifi* para conectar el dispositivo a la red WiFi y configurar **Firebase**. La función *setup_wifi* es la encargada de conectar el dispositivo a la red Wi-Fi que ha sido especializada y espera a que se establezca la conexión. Igualmente se configura la clave de *API* y la *URL* de la base de datos con el objeto config de **Firebase**. Se registran las credenciales proporcionadas por las variables *+SSID* y *Password*, y si el registro es exitoso, se establece la variable *signupOK* como verdadera (*true*), si el registro falla (*false*) se imprime un mensaje de error en la consola.

### Foto resistencia
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/35675699-8644-415f-90d7-e767ecd34fdb)

### Fin de carrera
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/59eee143-2912-4894-9234-83995adab511)

### Sensor de temepratura y humedad DHT11
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/dc7953f0-0baa-4538-8f54-6088efddb464)

### Firebase
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/236e6797-db22-412c-90f8-dd37438cfe1e)


## AppInventor
![Imagen de WhatsApp 2023-06-13 a las 19 45 34](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/1a4f3f96-7b54-4702-ac6c-663d6052f6bf)
![Imagen de WhatsApp 2023-06-13 a las 19 45 34](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/786abe38-5c6c-4ea5-994f-209ab58bcbfb)


![Imagen de WhatsApp 2023-06-06 a las 23 05 06](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/18310c10-1eb5-4bae-9976-35bd16fe7385)

*La ultima se peude cambiar para una mas reciente (ver los otros sensores)*

Se realiza una aplicación móvil para mostrar los datos resevados en la base de datos **Firebase**. Esta aplicación tiene que contar con dos campos de texto (*usuario* y *número*), los cuales también son enviados a la base de datos.


## extra

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/5853b5a7-15ef-45b4-887f-321ec64899a9)

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/e8663ee5-7c45-4a7b-aff2-c37e04bd8eec)

En la función bucle *loop* es ejecutada continuamente hasta que se haya completado la configuración inicial. Aquí es donde se van a leer los valores y estados de los sensores que después serán enviados a la base de datos. En el sensor de iluminación, se lee el valor analógico del sensor utilizando la función *analogRead()* y se almacena en la variable *valor*. Se comparan los valores leídos para determinar el estado de iluminación (*oscuridad*, *ambiente* o *luz*). Se imprime el estado de iluminación y el valor leído en la consola serial. En el sensor de fin de carrera, se lee el estado utilizando la función digitalRead() y se almacena en la variable *pres_lib*. Se imprime el estado del sensor (*presionado* o *libre*) en la consola serial. 

Y por último, para el sensor de temperatura y humedad (*DHT11*), se realiza una pausa de 2 segundos antes de leer los valores del sensor DHT para una mejor lectura. Se utiliza la función *readHumidity()* para leer la humedad y la función *readTemperature()* para leer la temperatura. Y se verifica si la lectura de los valores es exitosa utilizando la función *isnan()*. Si la lectura falla, se muestra un mensaje de error en la consola serial. Si la lectura es exitosa, se imprimen los valores de humedad y temperatura en la consola serial.

### Firebase
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/61857a77-7aec-4c9d-9b79-065194d95380)

En esta parte es el envió de datos a **Firebase**, se verifica que está listo con *Firebase.ready*, y con *signupOK* se verifica que el registro haya sido exitoso y que haya pasado el tiempo suficiente desde el último envío de datos (15 segundos). Si se cumplen estos requerimientos, realizará el envió de los valores de temperatura, humedad, valor de la fotorresistencia y estado. En la consola serial se muestra si el envió de datos fue exitoso.


## AppInventor
![Imagen de WhatsApp 2023-06-13 a las 19 45 34](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/1a4f3f96-7b54-4702-ac6c-663d6052f6bf)
![Imagen de WhatsApp 2023-06-13 a las 19 45 34](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/786abe38-5c6c-4ea5-994f-209ab58bcbfb)


![Imagen de WhatsApp 2023-06-06 a las 23 05 06](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/18310c10-1eb5-4bae-9976-35bd16fe7385)

*La ultima se peude cambiar para una mas reciente (ver los otros sensores)*

Se realiza una aplicación móvil para mostrar los datos resevados en la base de datos **Firebase**. Esta aplicación tiene que contar con dos campos de texto (*usuario* y *número*), los cuales también son enviados a la base de datos.


## Diagrama de Conexiones
![Imagen de WhatsApp 2023-06-13 a las 19 37 04](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/5a0dcd48-42b0-4252-8b94-b539e753cc71)
