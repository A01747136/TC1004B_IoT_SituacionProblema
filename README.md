# TC1004B_IoT_SituacionProblema

### Noreth Sofía Villalpando Saldaña A01368578
### Paulina Reyes Reyes A01747136

## Situación Problema.

Durante el reto de IoT, el objetivo principal consiste en utilizar un **ESP32** para conectar varios sensores y obtener cinco lecturas, las cuales serán registradas en una base de datos. Para lograr esto, se desarrollará el código necesario utilizando **Arduino IDE** y se establecerá la conexión con **Firebase** para almacenar los datos recopilados.

Además, se creará una aplicación utilizando **MIT App Inventor**, la cual permitirá visualizar la información almacenada en la base de datos de Firebase. Desde esta aplicación, también será posible ingresar dos datos, el usuario y un dígito, los cuales serán guardados en la misma base de datos.

En resumen, el proyecto implica la interconexión de sensores a través del ESP32, la recopilación de cinco lecturas y su posterior registro en una base de datos Firebase. Asimismo, se desarrollará una aplicación móvil con MIT App Inventor para visualizar los datos almacenados en la base de datos y permitir el ingreso de información adicional.

## DDiagrama de conexión de componentes

Se realizará la conexión de varios componentes al ESP32 utilizando un protoboard. Los componentes que se utilizarán incluyen una fotoresistencia, un sensor de fin de carrera, un sensor de temperatura y humedad DHT11, así como el propio ESP32. Además, se emplearán algunas resistencias para completar los circuitos necesarios. El objetivo principal será establecer la interacción entre estos sensores y el ESP32 para adquirir y procesar datos de manera efectiva. A continuación, se proporcionará un diagrama para la conexión de estos componentes.

![Imagen de WhatsApp 2023-06-13 a las 19 37 04](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/5a0dcd48-42b0-4252-8b94-b539e753cc71)

## Configuración inicial del entorno de Arduino para utilizar el ESP32
Antes de comenzar a escribir el código de Arduino, es importante realizar algunas configuraciones en tu equipo para garantizar un óptimo funcionamiento. A continuación, se te mostrara paso a paso a través de estas configuraciones para que puedas seguir el proceso de manera sencilla
### Placa esp32 configuración y conexión

Ve al menú "Arduino" y selecciona "Preferencias". 

![Captura de Pantalla 2023-06-13 a la(s) 8 42 12 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/5134b362-c3cb-45a5-a096-13ec31415d4f)

En la ventana de preferencias, verás un campo llamado "URLs adicionales de gestor de tarjetas". Asegúrate de que esté vacío o que no contenga ninguna URL incorrecta. Ahora, debes añadir la URL del gestor de tarjetas del ESP32. Para ello, copia y pega la siguiente URL en el campo de "URLs adicionales de gestor de tarjetas": https://dl.espressif.com/dl/package_esp32_index.json

![Captura de Pantalla 2023-06-13 a la(s) 8 55 32 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/4f898f5a-745c-42c6-942c-e8c45de5d163)

A continuación, ve al menú "Herramientas" y selecciona "Placa" > "Gestor de tarjetas". 

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/679d0142-721b-4258-8f9e-d3d5cf5eb370)

Se abrirá el gestor de tarjetas. En el campo de búsqueda, escribe "esp32". Aparecerá la opción "esp32 by Espressif Systems". Haz clic en el botón "Instalar" para descargar e instalar el gestor de tarjetas del ESP32.

![Captura de Pantalla 2023-06-13 a la(s) 8 28 57 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/3ef7707c-19e9-4250-9ded-f1b0ac7c5478)

Una vez instalado el gestor de tarjetas del ESP32, podrás seleccionar la placa ESP32 en el menú "Herramientas" > "Placa". Busca y selecciona la opción "DOIT ESP32 DEVKIT V1" de la lista de placas disponibles. Puede que tengas que desplazarte hacia abajo para encontrarla.

![Captura de Pantalla 2023-06-13 a la(s) 8 39 32 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/bce0506f-3b0f-4207-bf7d-7810c6ed2d1f)

Asegúrate de que también hayas seleccionado el puerto correcto en el submenú "Puerto" dentro del menú "Herramientas". Este puerto debe corresponder al puerto USB al que está conectada tu placa ESP32.

![Captura de Pantalla 2023-06-13 a la(s) 8 40 56 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/e723efd8-f7ff-4682-a155-02a7e2627070)

Ahora, ve al menú "Herramientas" nuevamente y busca la opción "Velocidad de subida" o "Upload Speed". Haz clic en ella para desplegar las opciones de velocidad de transferencia. Selecciona la velocidad de transferencia de 115200. Esta configuración asegurará una comunicación estable y confiable entre tu computadora y la placa ESP32 durante la carga del código.

![Captura de Pantalla 2023-06-13 a la(s) 8 41 34 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/a31f5dc8-7a77-4d71-8cde-41b297bb90fe)

Luego, ve al menú "Herramientas" y selecciona la opción "Monitor Serie" o "Serial Monitor". En la ventana del Monitor Serie, busca la velocidad de baudios (baud rate) y cámbiala a 115200. Esto garantizará que la comunicación entre la placa ESP32 y tu computadora a través del Monitor Serie se realice correctamente. 

![Captura de Pantalla 2023-06-13 a la(s) 8 43 46 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/88cda552-d766-40ce-ba0c-73e91ed4463d)



### Instalación de librerías

Ve al menú "Programa" y selecciona "Incluir biblioteca" > "Gestionar bibliotecas". En la ventana "Gestionar bibliotecas", verás un campo de búsqueda en la parte superior derecha. Escribe el nombre de la biblioteca que deseas instalar.

![Captura de Pantalla 2023-06-13 a la(s) 8 29 52 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/5a1f3e4b-288e-414e-b8de-0d1470dbf0d2)

Para instalar la biblioteca EspMQTTClient, escribe "EspMQTTClient" en el campo de búsqueda. Verás la biblioteca EspMQTTClient en la lista de resultados. Haz clic en el botón "Instalar" para instalarla.

![Captura de Pantalla 2023-06-13 a la(s) 8 31 04 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/3608c60b-cc2b-4e24-8c2c-20a3c834d534)

Para instalar la biblioteca DHT Sensor Library, escribe "DHT Sensor" en el campo de búsqueda. Verás la biblioteca DHT Sensor Library en la lista de resultados. Haz clic en el botón "Instalar" para instalarla.

![Captura de Pantalla 2023-06-13 a la(s) 8 31 45 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/88bf12e4-da06-4950-984f-d77feae29828)

Para instalar la biblioteca Firebase Arduino Client library for ESP8266, escribe "Firebase Arduino" en el campo de búsqueda. Verás la biblioteca Firebase Arduino en la lista de resultados. Haz clic en el botón "Instalar" para instalarla.

![Captura de Pantalla 2023-06-13 a la(s) 8 32 19 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/14d9c13f-6274-459b-8b00-386718aef49a)

Para instalar la biblioteca Firebase ESP32 Client, escribe "Firebase ESP32" en el campo de búsqueda. Verás la biblioteca Firebase ESP32 Client en la lista de resultados. Haz clic en el botón "Instalar" para instalarla.

![Captura de Pantalla 2023-06-13 a la(s) 8 33 04 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/755607fb-7e40-4494-827f-d7d30167503f)



## Configuración, lectura de sensores y envío de datos a la base de datos ARDUINO IDE

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

## Configuración de la base de datos Firebase


## Desarrollo de la aplicación móvil MIT AppInventor

En la plataforma MIT App Inventor, se utilizarán bloques de programación para desarrollar una aplicación móvil que permita visualizar los datos almacenados en Firebase y permita al usuario ingresar información. A continuación, se proporciona una explicación general de cómo se utilizarán los bloques en el entorno de App Inventor.

En la ventana de diseño (Designer), se arrastrarán y colocarán los elementos de la interfaz que se deseen, como etiquetas de texto, campos de texto, botones, etc. Estos componentes permitirán mostrar los datos y permitirán al usuario ingresar información.

![Imagen de WhatsApp 2023-06-13 a las 19 45 34](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/786abe38-5c6c-4ea5-994f-209ab58bcbfb)

Antes de comenzar a diseñar la interfaz de la aplicación, es necesario agregar los componentes relacionados con Firebase. En la ventana de diseño (Designer), se debe agregar el componente "FirebaseDB" desde la paleta de componentes, lo cual permitirá establecer la conexión con la base de datos Firebase.

![Captura de Pantalla 2023-06-13 a la(s) 9 36 15 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/1ffc3ee6-06dd-47d8-bb3a-30483bc0cfb2)

Es importante poner el API Key de tu base de datos en donde dice "FirebaseToken" y el URL en "FirebaseURL" para que se sincronice la app con tu base de datos.

![Captura de Pantalla 2023-06-13 a la(s) 9 42 57 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/8fd893dd-1faa-49bf-ab53-2791ed0506d2)

A continuación, se muestra la ventana de bloques, que representa la programación detrás de la aplicación que se creará. El primer conjunto de bloques se encarga de establecer la conexión con Firebase y mostrar en la pantalla del usuario las lecturas almacenadas en la base de datos. El segundo conjunto de bloques se activa al presionar el botón de enviar y se encarga de enviar los datos de usuario y dígito ingresados por el usuario a la base de datos. Además, al presionar el botón, se borran los campos de texto para una mejor experiencia de uso. 

![Imagen de WhatsApp 2023-06-13 a las 19 45 34](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/1a4f3f96-7b54-4702-ac6c-663d6052f6bf)



Es importante mencionar que al utilizar Firebase en MIT App Inventor, es recomendable que los nombres de las variables utilizadas en la aplicación se correspondan con los nombres de las colecciones y campos en la base de datos Firebase. Esto facilitará la sincronización y manipulación de los datos entre la aplicación y Firebase, asegurando una comunicación fluida y precisa entre ambos



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
