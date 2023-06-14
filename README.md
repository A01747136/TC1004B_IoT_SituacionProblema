# TC1004B_IoT_SituacionProblema

### Noreth Sofía Villalpando Saldaña A01368578
### Paulina Reyes Reyes A01747136

## Situación Problema.

Durante el reto de IoT, el objetivo principal consiste en utilizar un **ESP32** para conectar varios sensores y obtener cinco lecturas, las cuales serán registradas en una base de datos. Para lograr esto, se desarrollará el código necesario utilizando **Arduino IDE** y se establecerá la conexión con **Firebase** para almacenar los datos recopilados.

Además, se creará una aplicación utilizando **MIT App Inventor**, la cual permitirá visualizar la información almacenada en la base de datos de Firebase. Desde esta aplicación, también será posible ingresar dos datos, el usuario y un dígito, los cuales serán guardados en la misma base de datos.

En resumen, el proyecto implica la interconexión de sensores a través del ESP32, la recopilación de cinco lecturas y su posterior registro en una base de datos Firebase. Asimismo, se desarrollará una aplicación móvil con MIT App Inventor para visualizar los datos almacenados en la base de datos y permitir el ingreso de información adicional.

## Configuración de la base de datos Firebase

Se accede a la página *firebase.google.com* y se crea un usuario en la misma.

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/c1b71451-5bf4-4a10-84e6-5dae7b340e6b)

Una vez creado un usuario, se accede a la consola. En esta consola apareceran los proyectos que se encuentran disponibles y la opción de crear uno nuevo. En este caso, el proyecto que se creo se encuentra bajo el nombre *reto*.

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/61ff21c8-837d-41fd-a5b6-1cf69e40ff2b)

Después de realizar esto, se obtiene la llave de acceso para el servicio de almacenamiento y comunicación. Estos datos son ingresados en las variables y constantes que se encontrará en el código de *ARDUINO IDE*.

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/f3adf58d-b026-4f7a-a671-bd6fbe1734f5)

A partir de esto, se configuran los clientes a los que se les consederá el acceso a la base de datos y como se identifican. Por lo que se debe de entrar a las opciones del sistema mediante la página de Autenticación de la base de datos.

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/8441f308-9ded-43c0-ba9a-a47b079d63b6)

Estos permisos hacen que cualquier cliente que cuente con las llaves de acceso pueda escribir y leer los datos que se encuentra, mientrasq que **Firebase** agrega una "marca de tiempo" a cada solicitud.

## Diagrama de conexión de componentes

Se realizará la conexión de varios componentes al ESP32 utilizando un protoboard. Los componentes que se utilizarán incluyen una fotoresistencia, un sensor de fin de carrera, un sensor de temperatura y humedad DHT11, así como el propio ESP32. Además, se emplearán algunas resistencias para completar los circuitos necesarios. El objetivo principal será establecer la interacción entre estos sensores y el ESP32 para adquirir y procesar datos de manera efectiva. A continuación, se proporcionará un diagrama para la conexión de estos componentes.

![Imagen de WhatsApp 2023-06-13 a las 19 37 04](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/5a0dcd48-42b0-4252-8b94-b539e753cc71)

## Configuración inicial del entorno de Arduino para utilizar el ESP32
Antes de comenzar a escribir el código de Arduino, es importante realizar algunas configuraciones en tu equipo para garantizar un óptimo funcionamiento. A continuación, se te mostrara paso a paso a través de estas configuraciones para que puedas seguir el proceso de manera sencilla.
### Placa ESP32: Configuración y Conexión

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

### Función principal

![Captura de Pantalla 2023-06-14 a la(s) 8 05 55 a  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/af92e6e1-122a-40b8-98d7-6db3e4c1a107)

Se desarrolla la configuración inicial con la función *setup()*, en la cual se inicia la comunicación serial a una velocidad de 115200 baudios, además de imprimir un mensaje de prueba en la consola serial. Igualmente, se configura el pin del sensor de fin de carrera como entrada y se inicia el sensor DHT. Además, se llama a la función *setup_wifi()* para conectar el dispositivo a la red Wi-Fi y configurar **Firebase**.

Para el bucle principal *loop()*, se realiza una pausa de 2 segundos utilizando la función *delay()* para asegurar una lectura precisa de los sensores. Se llaman a las funciones para leer y obtener los valores del sensor de luz, el estado de la luz y el estado del sensor de fin de carrera, además de obtener los valores de temperatura y humedad del sensor DHT.
De igual manera, se llama a la función *funcion_firebase()* para enviar los datos a Firebase.

### Conexión Wi-Fi 
![Imagen de WhatsApp 2023-06-13 a las 19 59 50](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/c298076d-f921-4011-9c7d-d15c0b9ef5d8)

Aquí es donde se inicializa la comunicación serial y el sensor DHT. Llama a la función *setup_wifi* para conectar el dispositivo a la red WiFi y configurar **Firebase**. La función *setup_wifi* es la encargada de conectar el dispositivo a la red Wi-Fi que ha sido especializada y espera a que se establezca la conexión. Igualmente se configura la clave de *API* y la *URL* de la base de datos con el objeto config de **Firebase**. Se registran las credenciales proporcionadas por las variables *SSID* y *Password*, y si el registro es exitoso, se establece la variable *signupOK* como verdadera (*true*), si el registro falla (*false*) se imprime un mensaje de error en la consola.

### Foto resistencia
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/35675699-8644-415f-90d7-e767ecd34fdb)

### Fin de carrera
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/59eee143-2912-4894-9234-83995adab511)

### Sensor de temperatura y humedad DHT11
![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/dc7953f0-0baa-4538-8f54-6088efddb464)

Se determinan las funciones para obtener valores de los sensores. La función *valor_luz()* se utiliza para leer el valor analógico del sensor de luz utilizando la función *analogRead()* y lo devuelve. La función *estado_luz()* es utilizada para leer el valor del sensor de luz y con los parámetros establecidos determina el estado de iluminación (*oscuridad*, *ambiente* o *luz*) según el valor leído. Devuelve el estado como una cadena de texto. De una similar manera, la función *fin_de_carrera()* es la encargada de lee el estado del sensor de fin de carrera y devuelve *Presionado* si el sensor está presionado y la lectura es de 0, y si la lectura es de 1 significa que el botón está siendo presionado y devuelve *Libre*. 

Por último, las funciones para obtener los valores de temperatura y humedad del sensor DHT son *temp_dht()*, la cual lee la temperatura en grados Celsius del sensor DHT utilizando la función *readTemperature()* y la devuelve como un valor de tipo float. Igualmente, se utiliza *hum_dht()¨para leer la humedad del sensor DHT utilizando la función *readHumidity()* y la devuelve como un valor de tipo float. Para ambas funciones, si la lectura falla, se imprime un mensaje de error en la consola serial y se devuelve 0.0.

### Firebase

![Captura de Pantalla 2023-06-14 a la(s) 8 06 16 a  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/790e034e-9f2d-40b1-8453-6efd6853ac0d)
![Captura de Pantalla 2023-06-14 a la(s) 8 06 35 a  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/937488fb-ac07-4e46-b0de-6ddfc06120b7)

La función *funcion_firebase()* se utiliza para enviar los datos obtenidos a **Firebase**. En esta función se verifica si **Firebase** está listo, si el registro fue exitoso y si ha pasado suficiente tiempo desde el último envío de datos. Si se cumplen todas las condiciones, utiliza las funciones *setFloat()* y *setString()* de **Firebase** para enviar los valores de temperatura, humedad, valor de luz, estado de luz y estado del sensor de fin de carrera a las rutas correspondientes en la base de datos de **Firebase**. Básicamente lo que cambia para enviar cada dato, es dentro del if de esta forma: (Firebase.RTDB.set**Tipo de variable(String/Float)**(&fbdo, "**nodo dentro de la base de datos**/**subnodo dentro del nodo**", **variable a almacenar**)). Finalmente, imprime mensajes de éxito o error en la consola serial según el resultado de cada operación.

## Monitor serial y envió de datos

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/a23afbee-3e00-4789-825d-9d55d19e5e24)

En el monitor serial se muestran los datos obtenidos de los sensores, además de mostrar si la conexión Wi-Fi es exitosa. Igualmente, se muetsra si se subieron los datos a **Firebase** correctamente.

## Desarrollo de la aplicación móvil MIT AppInventor

En la plataforma **MIT App Inventor**, se utilizarán bloques de programación para desarrollar una aplicación móvil que permita visualizar los datos almacenados en **Firebase** y permita al usuario ingresar información. Se mostrarán los datos resevados en la base de datos **Firebase** y la app va a contar con dos campos de texto (*usuario* y *número*), los cuales también son enviados a la base de datos. A continuación, se proporciona una explicación general de cómo se utilizarán los bloques en el entorno de App Inventor.

En la ventana de diseño (*Designer*), se arrastrarán y colocarán los elementos de la interfaz que se deseen, como etiquetas de texto, campos de texto, botones, etc. Estos componentes permitirán mostrar los datos y permitirán al usuario ingresar información.

![Imagen de WhatsApp 2023-06-13 a las 19 45 34](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/786abe38-5c6c-4ea5-994f-209ab58bcbfb)

Antes de comenzar a diseñar la interfaz de la aplicación, es necesario agregar los componentes relacionados con **Firebase**. En la ventana de diseño (*Designer*), se debe agregar el componente *FirebaseDB* desde la paleta de componentes, lo cual permitirá establecer la conexión con la base de datos **Firebase**.

![Captura de Pantalla 2023-06-13 a la(s) 9 36 15 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/1ffc3ee6-06dd-47d8-bb3a-30483bc0cfb2)

Es importante poner el API Key de tu base de datos en donde dice *FirebaseToken* y el URL en *FirebaseURL* para que se sincronice la app con tu base de datos.

![Captura de Pantalla 2023-06-13 a la(s) 9 42 57 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/8fd893dd-1faa-49bf-ab53-2791ed0506d2)

A continuación, se muestra la ventana de bloques, que representa la programación detrás de la aplicación que se creará. El primer conjunto de bloques se encarga de establecer la conexión con Firebase y mostrar en la pantalla del usuario las lecturas almacenadas en la base de datos. Es importante mencionar que al utilizar **Firebase** en **MIT App Inventor**, es recomendable que los nombres de las variables utilizadas en la aplicación se correspondan con los nombres de las colecciones y campos en la base de datos **Firebase**. Esto facilitará la sincronización y manipulación de los datos entre la aplicación y **Firebase**, asegurando una comunicación fluida y precisa entre ambos.

![Captura de Pantalla 2023-06-13 a la(s) 10 12 53 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/cbc20c74-b2fc-47e9-a537-4954cceac143)

El segundo conjunto de bloques se activa al presionar el botón de enviar y se encarga de enviar los datos de usuario y dígito ingresados por el usuario a la base de datos. Además, al presionar el botón, se borran los campos de texto para una mejor experiencia de uso. 

![Captura de Pantalla 2023-06-13 a la(s) 10 13 25 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/5cc31ed8-41f8-40b9-8ca8-72a6772edf22)

Para utilizar la aplicación desarrollada es necesario descargar la aplicación *MIT APP Inventor* en un dispositivo móvil Android. Una vez instalada, se debe acceder a la ventana de diseño (*Designer*) en *MIT AppInventor* desde tu ordenador y seleccionar la opción *"Connect"* seguida de *"AI Companion"*. Esto generará un código QR y un código alfanumérico que se deben ingresar en la aplicación móvil desde el dispositivo.

![Captura de Pantalla 2023-06-13 a la(s) 10 00 18 p  m](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/c7448c4e-fad2-4331-a421-5ec595e2bf73)

Una vez que el dispositivo móvil lee el código QR o el código alfanumérico, la aplicación comenzará a cargarse. Una vez que la carga se complete por completo, la pantalla de la aplicación diseñada en *MIT AppInventor* se mostrará en el dispositivo móvil.

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/135858550/f6ecd72c-3688-4536-9c56-b15d3da4d519)

## Resultados

![image](https://github.com/A01747136/TC1004B_IoT_SituacionProblema/assets/88682618/53da0784-d786-44e6-9864-5260c08deac8)

Los valores que se obtuvieron de **Arduino** y de **AppInventor** son mostrados en la base de datos **Firebase**. Estos valores van cambiando conforme vayan siendo obtenidos.
