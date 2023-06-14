# TC1004B_IoT_SituacionProblema

### Noreth Sofía Villalpando Saldaña A01368578
### Paulina Reyes Reyes A01747136

## Situación Problema.

Durante el reto de IoT, el objetivo principal consiste en utilizar un **ESP32** para conectar varios sensores y obtener cinco lecturas, las cuales serán registradas en una base de datos. Para lograr esto, se desarrollará el código necesario utilizando **Arduino IDE** y se establecerá la conexión con **Firebase** para almacenar los datos recopilados.

Además, se creará una aplicación utilizando **MIT App Inventor**, la cual permitirá visualizar la información almacenada en la base de datos de Firebase. Desde esta aplicación, también será posible ingresar dos datos, el usuario y un dígito, los cuales serán guardados en la misma base de datos.

En resumen, el proyecto implica la interconexión de sensores a través del ESP32, la recopilación de cinco lecturas y su posterior registro en una base de datos Firebase. Asimismo, se desarrollará una aplicación móvil con MIT App Inventor para visualizar los datos almacenados en la base de datos y permitir el ingreso de información adicional.

## Configuración de la base de datos Firebase

Se accede a la página *firebase.google.com* y se crea un usuario en la misma.

![Firebase_Inicio](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/7f9e4b44-ba14-4d1c-b166-433e0f171355)

Una vez creado un usuario, se accede a la consola. En esta consola apareceran los proyectos que se encuentran disponibles y la opción de crear uno nuevo. En este caso, el proyecto que se creo se encuentra bajo el nombre *reto*.

![Firebase_Proy](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/e07f816c-53b9-4f27-bb03-d0efca7b7e49)

Después de realizar esto, se obtiene la llave de acceso para el servicio de almacenamiento y comunicación. Estos datos son ingresados en las variables y constantes que se encontrará en el código de *ARDUINO IDE*.

![Firebase_SDK](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/995c9ca0-7e9b-4613-8b3d-464aa17a7d03)

A partir de esto, se configuran los clientes a los que se les consederá el acceso a la base de datos y como se identifican. Por lo que se debe de entrar a las opciones del sistema mediante la página de Autenticación de la base de datos.

![Firebase_Aut](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/0f62856c-ff4c-49aa-994a-2ff3dc1cf026)

Estos permisos hacen que cualquier cliente que cuente con las llaves de acceso pueda escribir y leer los datos que se encuentra, mientrasq que **Firebase** agrega una "marca de tiempo" a cada solicitud.

## Diagrama de conexión de componentes

Se realizará la conexión de varios componentes al ESP32 utilizando un protoboard. Los componentes que se utilizarán incluyen una fotoresistencia, un sensor de fin de carrera, un sensor de temperatura y humedad DHT11, así como el propio ESP32. Además, se emplearán algunas resistencias para completar los circuitos necesarios. El objetivo principal será establecer la interacción entre estos sensores y el ESP32 para adquirir y procesar datos de manera efectiva. A continuación, se proporcionará un diagrama para la conexión de estos componentes.

![DiagramaCon_ESP32](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/05924edc-b370-485c-9479-917b08150687)

## Configuración inicial del entorno de Arduino para utilizar el ESP32
Antes de comenzar a escribir el código de Arduino, es importante realizar algunas configuraciones en tu equipo para garantizar un óptimo funcionamiento. A continuación, se te mostrara paso a paso a través de estas configuraciones para que puedas seguir el proceso de manera sencilla.
### Placa ESP32: Configuración y Conexión

Ve al menú "Arduino" y selecciona "Preferencias". 

![Arduino_Pre](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/4d8bd017-0fba-40cf-a9a8-0a6b4c8acebb)

En la ventana de preferencias, verás un campo llamado "URLs adicionales de gestor de tarjetas". Asegúrate de que esté vacío o que no contenga ninguna URL incorrecta. Ahora, debes añadir la URL del gestor de tarjetas del ESP32. Para ello, copia y pega la siguiente URL en el campo de "URLs adicionales de gestor de tarjetas": https://dl.espressif.com/dl/package_esp32_index.json

![Arduino_Pre_URL](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/7c98a137-36e0-4b04-9106-5eb5cdbd1282)

A continuación, ve al menú "Herramientas" y selecciona "Placa" > "Gestor de tarjetas". 

![Arduino_Placa](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/8eada9a0-ccd5-4f0f-b5c5-13d5dff7ca2a)

Se abrirá el gestor de tarjetas. En el campo de búsqueda, escribe "esp32". Aparecerá la opción "esp32 by Espressif Systems". Haz clic en el botón "Instalar" para descargar e instalar el gestor de tarjetas del ESP32.

![Arduino_LibESP](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/e1f3596a-17f3-433d-b323-c788cd4b3c98)

Una vez instalado el gestor de tarjetas del ESP32, podrás seleccionar la placa ESP32 en el menú "Herramientas" > "Placa". Busca y selecciona la opción "DOIT ESP32 DEVKIT V1" de la lista de placas disponibles. Puede que tengas que desplazarte hacia abajo para encontrarla.

![Arduino_ESP](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/34ed2fbc-5f0f-465d-8777-0e1261dacbb7)

Asegúrate de que también hayas seleccionado el puerto correcto en el submenú "Puerto" dentro del menú "Herramientas". Este puerto debe corresponder al puerto USB al que está conectada tu placa ESP32.

![Arduino_Puerto](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/53a8c333-7b9e-4448-8e2a-d4e01a6ecd98)

Ahora, ve al menú "Herramientas" nuevamente y busca la opción "Velocidad de subida" o "Upload Speed". Haz clic en ella para desplegar las opciones de velocidad de transferencia. Selecciona la velocidad de transferencia de 115200. Esta configuración asegurará una comunicación estable y confiable entre tu computadora y la placa ESP32 durante la carga del código.

![Arduino_MonSer](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/d11d3c5d-ee00-4759-87af-53c7f03cfbdb)

Luego, ve al menú "Herramientas" y selecciona la opción "Monitor Serie" o "Serial Monitor". En la ventana del Monitor Serie, busca la velocidad de baudios (baud rate) y cámbiala a 115200. Esto garantizará que la comunicación entre la placa ESP32 y tu computadora a través del Monitor Serie se realice correctamente. 

![Arduino_Ba](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/c4c89c4b-643c-468c-9c65-8038a9f89248)

### Instalación de librerías

Ve al menú "Programa" y selecciona "Incluir biblioteca" > "Gestionar bibliotecas". En la ventana "Gestionar bibliotecas", verás un campo de búsqueda en la parte superior derecha. Escribe el nombre de la biblioteca que deseas instalar.

![Arduino_AdminLib](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/e27b707a-5ce8-469e-a234-c3a28f8fb744)

Para instalar la biblioteca EspMQTTClient, escribe "EspMQTTClient" en el campo de búsqueda. Verás la biblioteca EspMQTTClient en la lista de resultados. Haz clic en el botón "Instalar" para instalarla.

![Arduino_LibMQTT](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/77026f6b-a7a8-48be-80c9-a375ddb546fc)

Para instalar la biblioteca DHT Sensor Library, escribe "DHT Sensor" en el campo de búsqueda. Verás la biblioteca DHT Sensor Library en la lista de resultados. Haz clic en el botón "Instalar" para instalarla.

![Arduino_LibDHT](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/d2368ab9-79aa-4661-9f9d-2d4dc9ce2553)

Para instalar la biblioteca Firebase Arduino Client library for ESP8266, escribe "Firebase Arduino" en el campo de búsqueda. Verás la biblioteca Firebase Arduino en la lista de resultados. Haz clic en el botón "Instalar" para instalarla.

![Arduino_LibFB](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/bc95e619-1e0d-4e2f-8f25-631885d69c89)

Para instalar la biblioteca Firebase ESP32 Client, escribe "Firebase ESP32" en el campo de búsqueda. Verás la biblioteca Firebase ESP32 Client en la lista de resultados. Haz clic en el botón "Instalar" para instalarla.

![Arduino_LibESP](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/de121251-aa00-4910-8068-599db99be1f5)

## Configuración, lectura de sensores y envío de datos a la base de datos ARDUINO IDE

### Librerías
![ArdCod_Lib](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/ee4c12cc-58de-4136-b1eb-a7c7f90eb076)

Primero se integran las librerías que se van a utilizar: la librería DHT es para el sensor de temperatura y humedad DHT11, la librería Wifi es para establecer una conexión WiFi, PubSubClient es para el MQTT que es utilizado por **Firebase**, FirebaseESPClient es para poder interactuar con **Firebase** y TokenHelper es para los tokens de autenticación.

### Variables y constantes

![ArdCod_VarCons](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/eebe6278-b5db-4331-8c7e-b3066520b771)

Se definen ciertas constantes, una de ellas es para las credenciales de la red WiFi a la cual se debe de conectar el dispositivo (*SSID* y *Password*). Igualmente se introduce la clave de *API* para la base de datos **Firebase**, de la misma manera, se agrega la *URL* de la base de datos. Firebase *fbdo* funciona para interactuar con la base de datos, *auth* para la autenticación de usuario y *config* para la configuración de la conexión y autenticación de la base de datos.

La variable *sendDataPrevMillis* es utilizada para el control de tiempo del envío de datos a **Firebase** y las variables *intValue* y *floatValue* son utilizadas para el almacenamiento. Igualmente, se colocan las variables para *luz*, *valor* y *carrera* y el objeto *DHT*. La variable *signup* es para observar la conexión, si es verdadero (*true*) es exitosa la conexión, si es falso (*false*) se imprime un mensaje de error en la consola.

### Función principal
![ArdCod_MainFun](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/00550fae-66e3-43b2-87c1-fb70a888ad63)

Se desarrolla la configuración inicial con la función *setup()*, en la cual se inicia la comunicación serial a una velocidad de 115200 baudios, además de imprimir un mensaje de prueba en la consola serial. Igualmente, se configura el pin del sensor de fin de carrera como entrada y se inicia el sensor DHT. Además, se llama a la función *setup_wifi()* para conectar el dispositivo a la red Wi-Fi y configurar **Firebase**.

Para el bucle principal *loop()*, se realiza una pausa de 2 segundos utilizando la función *delay()* para asegurar una lectura precisa de los sensores. Se llaman a las funciones para leer y obtener los valores del sensor de luz, el estado de la luz y el estado del sensor de fin de carrera, además de obtener los valores de temperatura y humedad del sensor DHT.
De igual manera, se llama a la función *funcion_firebase()* para enviar los datos a Firebase.

### Conexión Wi-Fi 
![ArdCod_WiFi](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/789f2e81-7760-4e90-8cab-27f4e59006af)

Aquí es donde se inicializa la comunicación serial y el sensor DHT. Llama a la función *setup_wifi* para conectar el dispositivo a la red WiFi y configurar **Firebase**. La función *setup_wifi* es la encargada de conectar el dispositivo a la red Wi-Fi que ha sido especializada y espera a que se establezca la conexión. Igualmente se configura la clave de *API* y la *URL* de la base de datos con el objeto config de **Firebase**. Se registran las credenciales proporcionadas por las variables *SSID* y *Password*, y si el registro es exitoso, se establece la variable *signupOK* como verdadera (*true*), si el registro falla (*false*) se imprime un mensaje de error en la consola.

### Foto resistencia
![ArdCod_FotoR](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/127f4e82-6fec-4f4d-9ce8-dab4d65d6681)

### Fin de carrera
![ArdCod_FinCar](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/7265ea69-751c-4f20-a9b7-99a0846373a7)

### Sensor de temperatura y humedad DHT11
![ArdCod_TemHum](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/23286bae-ee54-4e87-b56b-aa179bf165e3)

Se determinan las funciones para obtener valores de los sensores. La función *valor_luz()* se utiliza para leer el valor analógico del sensor de luz utilizando la función *analogRead()* y lo devuelve. La función *estado_luz()* es utilizada para leer el valor del sensor de luz y con los parámetros establecidos determina el estado de iluminación (*oscuridad*, *ambiente* o *luz*) según el valor leído. Devuelve el estado como una cadena de texto. De una similar manera, la función *fin_de_carrera()* es la encargada de lee el estado del sensor de fin de carrera y devuelve *Presionado* si el sensor está presionado y la lectura es de 0, y si la lectura es de 1 significa que el botón está siendo presionado y devuelve *Libre*. 

Por último, las funciones para obtener los valores de temperatura y humedad del sensor DHT son *temp_dht()*, la cual lee la temperatura en grados Celsius del sensor DHT utilizando la función *readTemperature()* y la devuelve como un valor de tipo float. Igualmente, se utiliza *hum_dht()¨para leer la humedad del sensor DHT utilizando la función *readHumidity()* y la devuelve como un valor de tipo float. Para ambas funciones, si la lectura falla, se imprime un mensaje de error en la consola serial y se devuelve 0.0.

### Firebase

![ArdCod_Firebase](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/5472b564-ebb3-44d2-bdfa-89c11b6a8486)
![ArdCod_Firebase2](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/2fc50512-4cc6-479d-8cc9-5242a094a593)

La función *funcion_firebase()* se utiliza para enviar los datos obtenidos a **Firebase**. En esta función se verifica si **Firebase** está listo, si el registro fue exitoso y si ha pasado suficiente tiempo desde el último envío de datos. Si se cumplen todas las condiciones, utiliza las funciones *setFloat()* y *setString()* de **Firebase** para enviar los valores de temperatura, humedad, valor de luz, estado de luz y estado del sensor de fin de carrera a las rutas correspondientes en la base de datos de **Firebase**. Básicamente lo que cambia para enviar cada dato, es dentro del if de esta forma: (Firebase.RTDB.set**Tipo de variable(String/Float)**(&fbdo, "**nodo dentro de la base de datos**/**subnodo dentro del nodo**", **variable a almacenar**)). Finalmente, imprime mensajes de éxito o error en la consola serial según el resultado de cada operación.

## Monitor serial y envió de datos

![MonitorSerial_Sens](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/9d5f8a04-c43f-4d8b-b6b7-37d45bdc1ddf)

En el monitor serial se muestran los datos obtenidos de los sensores, además de mostrar si la conexión Wi-Fi es exitosa. Igualmente, se muetsra si se subieron los datos a **Firebase** correctamente.

## Desarrollo de la aplicación móvil MIT AppInventor

En la plataforma **MIT App Inventor**, se utilizarán bloques de programación para desarrollar una aplicación móvil que permita visualizar los datos almacenados en **Firebase** y permita al usuario ingresar información. Se mostrarán los datos resevados en la base de datos **Firebase** y la app va a contar con dos campos de texto (*usuario* y *número*), los cuales también son enviados a la base de datos. A continuación, se proporciona una explicación general de cómo se utilizarán los bloques en el entorno de App Inventor.

En la ventana de diseño (*Designer*), se arrastrarán y colocarán los elementos de la interfaz que se deseen, como etiquetas de texto, campos de texto, botones, etc. Estos componentes permitirán mostrar los datos y permitirán al usuario ingresar información.

![AppInv_Int](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/a3b069f1-35c1-4a4d-aa08-04411e3b2ed4)

Antes de comenzar a diseñar la interfaz de la aplicación, es necesario agregar los componentes relacionados con **Firebase**. En la ventana de diseño (*Designer*), se debe agregar el componente *FirebaseDB* desde la paleta de componentes, lo cual permitirá establecer la conexión con la base de datos **Firebase**.

![AppInv_FirebaseDB](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/957ef368-b1c4-4c51-9c59-6a83e31fcf6d)

Es importante poner el API Key de tu base de datos en donde dice *FirebaseToken* y el URL en *FirebaseURL* para que se sincronice la app con tu base de datos.

![AppInv_Prop](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/40981367-70cb-443e-ad2e-5b6494a917b5)

A continuación, se muestra la ventana de bloques, que representa la programación detrás de la aplicación que se creará. El primer conjunto de bloques se encarga de establecer la conexión con Firebase y mostrar en la pantalla del usuario las lecturas almacenadas en la base de datos. Es importante mencionar que al utilizar **Firebase** en **MIT App Inventor**, es recomendable que los nombres de las variables utilizadas en la aplicación se correspondan con los nombres de las colecciones y campos en la base de datos **Firebase**. Esto facilitará la sincronización y manipulación de los datos entre la aplicación y **Firebase**, asegurando una comunicación fluida y precisa entre ambos.

![AppInv_Blo1](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/a88358ed-ed9a-4adf-95f4-c07ef7a83055)

El segundo conjunto de bloques se activa al presionar el botón de enviar y se encarga de enviar los datos de usuario y dígito ingresados por el usuario a la base de datos. Además, al presionar el botón, se borran los campos de texto para una mejor experiencia de uso. 

![AppInv_Blo2](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/d8df2766-86ff-4e60-800d-ef9f8f3daaf1)

Para utilizar la aplicación desarrollada es necesario descargar la aplicación *MIT APP Inventor* en un dispositivo móvil Android. Una vez instalada, se debe acceder a la ventana de diseño (*Designer*) en *MIT AppInventor* desde tu ordenador y seleccionar la opción *"Connect"* seguida de *"AI Companion"*. Esto generará un código QR y un código alfanumérico que se deben ingresar en la aplicación móvil desde el dispositivo.

![AppInv_QR](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/f90a5997-a8f2-4215-b900-96ac61c5a6bc)

Una vez que el dispositivo móvil lee el código QR o el código alfanumérico, la aplicación comenzará a cargarse. Una vez que la carga se complete por completo, la pantalla de la aplicación diseñada en *MIT AppInventor* se mostrará en el dispositivo móvil.

![AppInv_SS](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/4e8da29d-128b-4a1d-999e-2fe0174bff3e)

## Resultados
![Firebase_Res](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/cde8b5b7-278c-4646-8593-b45d414a3fc4)

Los valores que se obtuvieron de **Arduino** y de **AppInventor** son mostrados en la base de datos **Firebase**. Estos valores van cambiando conforme vayan siendo obtenidos.
