# TC1004B_IoT_SituacionProblema

### Noreth Sofía Villalpando Saldaña A01368578
### Paulina Reyes Reyes A01747136

## Situación Problema.

A lo largo de cuatro semanas, para el reto de IoT se creó una base de datos en la página **Firebase**, la cual posteriormente se utilizaría para registrar ciertas lecturas. Estas lecturas serán tomadas de cinco sensores y una placa **ESP32**. Estos se utilizarán en conjunto con **Arduino** y **AppInventor**. En **Arduino**, se realizará un código en el cual se logre la conexión entre la base de datos, la placa y los sensores. Mientras que **AppInventor** será utilizado para desarrollar una aplicación de teléfono móvil en la cual se observará la información de la base de datos **Firebase**.

## Código

### Librerías
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/19257a47-8d72-4462-b4ac-a432b88972a6)

Primero se integran las librerías que se van a utilizar: la librería DHT es para el sensor de temperatura y humedad DHT11, la librería Wifi es para establecer una conexión WiFi, PubSubClient es para el MQTT que es utilizado por **Firebase**, FirebaseESPClient es para poder interactuar con **Firebase** y TokenHelper es para los tokens de autenticación.

### Constantes???
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/e19696bf-b769-48c3-a80c-c78be6f1e76e)

Se definen ciertas constantes, una de ellas es para las credenciales de la red WiFi a la cual se debe de conectar el dispositivo (*SSID* y *Password*). Igualmente se introduce la clave de API para la base de datos **Firebase**, de la misma manera, se agrega la URL de la base de datos. ****Firebase** fbdo funciona para interactuar con la base de datos. auth para la autenticación de usuario y config para la configuración de la conexión y autenticación de la base de datos.

La variable *sendDataPrevMillis* es utilizada para el control de tiempo del envío de datos a **Firebase** y las variables *intValue* y *floatValue* son utilizadas para el almacenamiento. Igualmente, se colocan las variables para *luz*, *valor* y *carrera* y el objeto *DHT*. La variable *signup* es para observar la conexión, si es verdadero (*true*) es exitosa la conexión, si es falso (*false*) se imprime un mensaje de error en la consola.

### Conexión Wi-Fi y Firebase
*No se cual de las dos poner*

Imagen 1

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/2dea42f6-4782-478f-bcfe-5be2aacdc509)

Imagen 2

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/9337c7a8-21ba-42e3-b54e-b9854a09a21e)

Aquí es donde se inicializa la comunicación serial y el sensor DHT. Llama a la función *setup_wifi* para conectar el dispositivo a la red WiFi y configurar **Firebase**. La función *setup_wifi* es la encargada de conectar el dispositivo a la red Wi-Fi que ha sido especializada y espera a que se establezca la conexión. Igualmente se configura la clave de *API* y la *URL* de la base de datos con el objeto config de **Firebase**. Se registran las credenciales proporcionadas por las variables *+SSID* y *Password*, y si el registro es exitoso, se establece la variable *signupOK* como verdadera (*true*), si el registro falla (*false*) se imprime un mensaje de error en la consola.

### Sensores
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/5853b5a7-15ef-45b4-887f-321ec64899a9)

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/e8663ee5-7c45-4a7b-aff2-c37e04bd8eec)

En la función bucle *loop* es ejecutada continuamente hasta que se haya completado la configuración inicial. Aquí es donde se van a leer los valores y estados de los sensores que después serán enviados a la base de datos. En el sensor de iluminación, se lee el valor analógico del sensor de iluminación utilizando la función analogRead() y se almacena en la variable valor. Se comparan los valores leídos para determinar el estado de iluminación (oscuridad, ambiente o luz). Se imprime el estado de iluminación y el valor leído en la consola serial.En el sensor de fin de carrera, se lee el estado del sensor de fin de carrera utilizando la función digitalRead() y se almacena en la variable pres_lib. Se imprime el estado del sensor (presionado o libre) en la consola serial. Y por último, para el sensor de temperatura y humedad (DHT11), se realiza una pausa de 2 segundos antes de leer los valores del sensor DHT para una mejor lectura. Se utiliza la función readHumidity() para leer la humedad y la función readTemperature() para leer la temperatura. Y se verifica si la lectura de los valores es exitosa utilizando la función isnan(). Si la lectura falla, se muestra un mensaje de error en la consola serial. Si la lectura es exitosa, se imprimen los valores de humedad y temperatura en la consola serial.

### Firebase Pt. 2
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/61857a77-7aec-4c9d-9b79-065194d95380)

En esta parte es el envió de datos a **Firebase**, se verifica que está listo con Firebase.ready, y con signupOK se verifica que el registro haya sido exitoso y que haya pasado el tiempo suficiente desde el último envío de datos (15 segundos). Si se cumplen estos requerimientos, realizará el envió de los valores de temperatura, humedad, valor de la fotorresistencia y estado. En la consola serial se muestra si el envió de datos fue exitoso.


## AppInventor

Se realiza una aplicación móvil para mostrar los datos resevados en la base de datos **Firebase**. Esta aplicación tiene que contar con dos campos de texto (usuario y número), los cuales también son enviados a la base de datos.


## Diagrama de Conexiones
