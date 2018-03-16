# ZorkTerror

## 1. Objetivo del juego

El jugador se encuentra en una casa abandonada por la noche. Tiene que intentar escapar de la casa sin que se lo coma el Grue que acecha en la oscuridad. Para escapar de la casa necesita encontrar las 4 llaves que desbloquean la cerradura de la puerta de salida. Necesita tener las 4 llaves en su inventario y después desbloquear la puerta.

## 2. Comandas del jugador

* **mirar:**
El jugador observa la sala en la que se encuentra. Si no hay luz de linterna o lámpara, solo verá en la habitación principal, en el resto de habitaciones lo verá todo completamente oscuro.
La comanda describe la sala junto con todas sus salidas y objetos que se hallan allí.
Ejemplo comanda: **mirar**

* **ir:**
Esta es la comanda que tiene el jugador para desplazarse por el mundo. Puede ir en 6 direcciones diferentes: **norte**, **sur**, **oeste**, **este**, **arriba** y **abajo**.
Si el jugador no puede ir en una dirección donde no hay salida o donde la salida esté bloqueada o escondida.
Ejemplo comanda: **ir sur**

* **coger:**
Permite al jugador interaccionar con el mundo. Puede intentar coger todos los items que hay en las habitaciones aunque solo algunos los puede llevar encima. Si un ítem ya lo lleva encima o bien está en un contenedor cerrado o no directamente no está en la sala, entonces el jugador no cogerá el objeto.
Ejemplo comanda: **coger linterna**

* **tirar:**
El jugador puede tirar objetos al suelo de su inventario.
Ejemplo comanda: **tirar llave**
Los objetos que se tiran al suelo, siguen describiéndose si el jugador observa la sala aunque con una diferente descripción.

* **mover:**
Se pueden mover casi todos los ítems. Realmente esta acción simplemente desplaza ligeramente el objeto seleccionado. Su interés es que hay algunos items que esconden alguna cosa y al moverlos podemos averiguarlo.
Ejemplo comanda: **mover sofa**
* **abrir:**
En este juego podemos abrir dos tipos de cosas diferentes. Podemos abrir puertas, que son salidas de las habitaciones, y tambíen contenedores,
Ejemplo comanda puerta: **abrir puertasotano**
Ejemplo comanda contenedor: **abrir baul**

* **cerrar:**
Función contraria a la comanda abrir.
Ejemplo: **cerrar puertajuegos**
Ejemplo: **cerrar cajon**

* **desbloquear**
Esta comanda permite desbloquear, o bien puerta bloqueadas, o bien contenedores bloqueados.
Ejemplo comanda: **desbloquear puertasotano con llave**
Ejemplo comanda: **desbloquear cajafuerte 123**

* **leer**
Hay ítems en el mundo que se pueden leer, tal como:
biblia, libros, carta...
Ejemplo comanda: **leer nota**

* **encender**
El jugador puede encender ítems como su linterna
(no funciona con la television de la sala de estar).
Ejemplo comanda: **encender lampara**
* **apagar**
Función contraria a encender.
Ejemplo comanda: **apagar linterna**

* **inventario**
El jugador puede ver todo lo que tiene en su inventario.
Ejemplo comanda: **inventario**

* **esconder**
El jugador se puede esconder en las habitaciones, aunque no todas disponen de escondite. Si está escondido el Grue no puede comérselo.
Ejemplo comanda: **esconder**

* **revelar**
Efecto contrario a esconder.
Ejemplo comanda: **revelar**

* **esperar**
Pasa un turno del jugador sin hacer nada.
Ejemplo comanda: **esperar**
* **exit**
Cierra el juego.
Ejemplo de comanda: **exit**

## 3. Sintaxis
La palabras que se escriben en consola deben ser **sin mayúsculas, acentos o ñ**, ya que sinó no detectará el nombre del elemento en cuestión. Si se añaden espacios en blanco al final de una comanda no funcionará.
Para las puertas se tiene que utilizar los siguientes nombres:
* puerta entre habitación principal y pasillo: **puertahabitacion**
* puerta entre pasillo y sala de juegos: **puertajuegos**
* puerta de salida de la casa: **puertasalida**
* puerta del sótano: **puertasotano** 

Para la caja fuerta que hay que escribir **cajafuerte**.
Para desbloquear la puerta de salida cuando se tienen todas las llaves se debe utilizar como comanda: **desbloquear puertasalida con llaves** ya que son múltiples llaves las que necesitamos, y solo desbloquear con una llave no haria efecto.

## 4. Mecánicas del juego
El juego va por turnos, cada vez que el usuario escribe algo en la consola y le da al **enter**, pasa un turno.
El jugador siempre se mueve primero, despues el Grue mira lo que hay en su sala y se mueve.
Es muy importante tener en cuenta si hay luz o no la sala en la que se está. Si el jugador enciende algún objeto luminoso, entonces iluminará la sala en la que está. Si el jugador se lleva el objeto con él, entonces se apagará la luz en la sala en la que estaba y se iluminará la nueva sala donde vaya.
**Mecánicas del Grue:**
* Si el **Grue** está en la misma sala que tu, y tienes alguna luz abierta, te comerá al instante y perderás la partida.
* En cambio si estás en una sala con la luz encendida, como los **Grue** odian la luz, no entrará en la sala. Es decir que el jugador puede entrar con luz en una sala donde está el **Grue** (entonces el jugador moriria) pero el **Grue** no puede entrar en una sala donde haya luz.
* Si el jugador y **Grue** están en una misma sala pero la luz está apagada entonces hay un **25%** de probabilidades de que te coma en ese turno.
* Si el jugador está escondido (no hay escondite en todas las salas) entonces el **Grue** aunque esté en la misma sala no lo verá.
* Cuando el **Grue** entra a la sala del jugador o sale de ella, este es avisado.
* El **Grue** se mueve aleatoriamente con una probabilidad de que se mueve en un turno de un **25%**.

Hay una trampilla en el juego que lleva al sótano. Cuidado, ya que esa trampilla es de una sola dirección y la salida del sótano al principio está bloqueada y el jugador se puede quedar atrapado allí.

## 5. Dificultades 
Ha habido varias dificultades en este juego:
* La primera ha sido el hecho del tiempo, ya que quise hacer un proyecto bastante ambicioso y con el tiempo disponible resultó difícil de implementar y testear todas las situaciones posibles, así que aún hay algunas inconsistencias en el juego
* Quise, al parsear, cambiar las palabras con tilde o ñ, pero no funcionaba el código y no tuve tiempo para mirarlo mas de cerca.
* Referente a los ítems, tuve algunas dudas y dificultades ya que en mi juego hay mucho ítems, algunos tenian unas propiedades en común y otros no. Así que me resultó un poco complicado ver cuál era la jerarquía adecuada, así que probablemente la estructura de los ítems, con más tiempo, necesitaria un refactor para optimizar y simplificar el código.

## 6. Spoilers (como pasarse el juego)
A continuación explicamos en detalle el contenido de cada habitación.
##### Habitationes:
Aquí daremos la lista de objetos que hay en cada habitación y su utilidad en el juego.
 **Habitación principal:**
 * **carta**: pequeña carta explicativa.
 * **baúl**: contenedor donde podemos meter objetos.
 * **cama**: decorativo.
 * **linterna**: podemos llevarla encima y nos ayuda a iluminar el camino.
 * **puertahabitacion**: puerta abierta al sur que da al pasillo.
 
**Pasillo:**
* **armario**: decorativo.
* **biblia**: libro que al cogerlo o moverlo, desplaza el armario de forma que se abre una entrada secreta al oeste hacia la biblioteca.
* **escaleras**: escaleras que bajan a la sala de estar.
* **puertajuegos**: puerta que lleva al este a la sala de juegos.

**Sala de juegos:**
* **cuadro**: Cuadro coleccionable que al mover o coger, revela unas escaleras que suben desván.
* **tablero**: tablero coleccionable decorativo.
* **billar**: decorativo.

**Biblioteca:**
* **lámpara**: objeto que da luz a la sala pero no se puede coger.
* **libros**: objeto que se puede leer, decorativo.
* **estanteria**: decorativo.
* **mesa**: decorativo.
* **llave**: llave para salir de la casa.
* **alfombra**: alfombra que al mover revela una trampilla cerrada que lleva al sótano pero la trampilla solo es de un sentido.

**Desván:**
* **cajafuerte**: caja bloqueada que contiene una llave de salida. El código para desbloquearla es 666. Los tres número están escritos en 3 habitaciones distintas. El jugador tiene que adivinar que esos tres números son la combinación.
* **muñeca**: decorativo.
* **ventanal**: decorativo.

**Sala de estar:**
* **sofá**: decorativo
* **televisión**: decorativo
* **mesita**: decorativo
* **revista**: se puede leer, informativa.
* **puertasalida**: puerta de salida de la casa, necesitas 4 llaves para desbloquearla.
* **puertasotano**: puerta del sótano, inicialmente está atascada, necesitas desbloquearla con el destornillador de la cocina.

**Cocina:**
* **nevera**: contenedor, hay un cadáver dentro.
* **mesa**: decorativo.
* **llave**: llave para salir de la casa.
* **nota**: se puede leer, indicativa.
* **cajón**: contenedor, contiene un destornillador.

**Sótano:**
* **Grue**: el monstruo está encerrado en el sótano.
* **llave**: llave para salir de la casa.
* **ventana**: decorativo.
* **rata**: decorativo coleccionable.

Lo ideal es liberar al **Grue** lo más tarde posible ya que nos complicará la vida.
Aquí dos ejemplos de dos partidas, una que acaba en derrota y otra en victória. Hay que tener en cuenta que podria fallar la de victoria a veces ya que el **Grue** tiene un componente importante aleatório.

**Ejemplo comandas derrota**:
coger linterna

coger carta

leer carta

encender linterna

ir sur

ir abajo

ir oeste

abrir cajon

coger destornillador

ir este

desbloquear puertasotano con destornillador

abrir puertasotano

ir abajo

**Ejemplo comandas victoria**:
coger linterna

coger carta

leer carta

abrir baul

poner carta en baul

encender linterna

ir sur

coger biblia

leer biblia

ir oeste

coger llave

ir este

ir este

coger tablero

mover cuadro

ir arriba

desbloquear cajafuerte 666

abrir cajafuerte

coger llave

ir abajo

ir oeste

ir abajo

ir oeste

coger llave

abrir cajon

coger destornillador

ir este

desbloquear puertasotano con destornillador

abrir puertasotano

apagar linterna

ir abajo

coger llave

ir arriba

desbloquear puertasalida con llaves

abrir puertasalida

ir este

## 7. Autor
**Albert Val Vila** 
Estudiante de 4rto año del grado en Ingeniería Informática en la UPC, especialidad Ingeniería del Software.
## 8. Github
[Enlace al repositorio ](https://github.com/AlbertVVila/ZorkTerror/tree/master/ZorkTerror)
