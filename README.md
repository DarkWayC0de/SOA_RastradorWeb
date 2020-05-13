# Rastreador web

A partir de las piezas que hemos desarrollado en el aula vamos a terminar de desarrollar el resto de componentes para crear un rastreador web basado en el modelo de actores. Todas las tareas aun no están disponibles. Las iremos añadiendo a este mismo documento según vayammos avanzado en clase.

## Cómo empezar

Para empezar:

 1. Acepta la [actividad en GitHub Classroom](https://classroom.github.com/g/fk-yGn4g).

    Obtendrás tu propia copia de este mismo repositorio para comenzar a trabajar. Por ejemplo, si la actividad se
    llama `soa-actividad01` y tu equipo es `grupo01`, tu nuevo repositorio se llamará
    `ull-esit-sistemas-operativos/soa-actividad01-grupo01`.

 1. [Clona](http://git.github.io/git-reference/#clone) el nuevo repositorio en tu ordenador. Esa será tu copia local del
 proyecto y el repositorio original `ull-esit-sistemas-operativos/soa-actividad01-grupo01` será `origin`.

 1. En tu copia local en tu ordenador no trabajes directamente en la rama `master`.
 Crea una rama con el prefijo `develop-` seguido por el nombre de tu cuenta en GitHub y haz todos los cambios sobre ella.
 Por ejemplo, si tu cuenta en GitHub es `alu0100123456`, crea la rama de la siguiente manera:

    ~~~~.sh
    $ git checkout -b develop-alu0100XXXXXX
    ~~~~

    Así cada miemmbro del equipo tendrá su propia rama de desarrollo.
    Por simplificar, en el resto del documento la llamaremos rama _develop_. 
    Como comentaremos después, la idea es pasar los cambios a _master_ solo cuando tengan algo definitivo.

 1. Añade el repositorio extra `git@github.com:ull-esit-sistemas-operativos/soa-rastreador-web.git` como `upstream`:

    ~~~~.sh
    $ git remote add upstream git@github.com:ull-esit-sistemas-operativos/soa-rastreador-web.git
    ~~~~

    Así se pueden obtener las últimas actualizaciones a la actividad ejecutando:

    ~~~~.sh
    $ git pull upstream master
    ~~~~

## Tareas

Trabaja en la rama  _develop_ de tu copia local siguiendo los pasos indicados a continuación.

### 1. Testing de libactors 

Cualquier buen desarrollo debe ir acompañado de tests. De hecho existen metodologías como TDD y BDD donde se escriben los test antes de comenzar a programar. Por esto te proponemos que escribas tests para al menos los siguientes casos de uso de la clase `Actor`.

* Que `sender()` devuelve `nullptr`cuando no se está atendiendo ningún mensaje.
* Que `sender()` tiene un puntero al remitente del mensaje cuando se está ejecutando el _slot_ que atiende al mensaje.
* Desde un _slot_ se puede usar `reply()` para responder al remitente del mensaje que se está atendiendo.
* Hay un _slot_ `Actor::unknownMessage(const QString& message)` al que llegan los mensajes desconocidos y funciona correctamente.
* El actor muere cuando lo solicita usando `Actor::kill()`.
* El actor padre es notificado con el mensaje `failed` cuando un hijo falla (por ejemplo, en un _slot_ se genera una excepción que no es manejada dentro del _slot_).

y opcionalmente para verificar los métodos `send()`, `spawn()` y `kill()` de la clase ActorManager.

Finalmente incluir la información de cobertura (_coverage_) de los tests en el archivo README.md.
Los detalles de cómo hacerlo usando GCOV están en el wiki del repositorio.

### 2. Rastreador web

El rastreador web usando el modelo de actores debe funcionar de la siguiente manera:

 1. Un actor "cliente" enviará un "crawlRequest(url, depth)" al actor CrawlServer, que se ejecuta de forma permanente.
 1. El CrawlServer creará y delegará la petición como "request(url, depth)" a un nuevo actor LinkChecker, a menos que una petición a la 
 misma URL ya se esté atendiendo.
 En ese caso el cliente será añadido a la lista de remitentes para la tarea en marcha y recibirá una respuesta una
 vez se complete la petición original.
 1. El actor LinkChecker será quién maneje la petición original y coordine el proceso de extracción las URL encontradas.
 1. LinkChecker hará el seguimiento de todas las URL rastreadas y delegará la descarga de URL instanciando actores HttpGetter
 y enviando el mensaje "request(url, depth)" a cada no.
 1. Cada actor HttpGetter recuperá el contenido de la página, extraerá las URL y manda mensajes "checkUrl(url, depth)" de
 vuelta al LinkChecker con cada una de las URL encontradas.
 Cada HttpGetter solo se preocupará de descargar y procesar la URL que le han pedido con "request(url, depth)" y no de cada URL que 
 encuentre.
 1. Una vez todos los enlaces de la URL han sido detectados, el HttpGetter enviará un mensaje de "done" y morirá.
 1. Cuando el LinkChecker reciba un mensaje de "done" comprobará si todos los HttpGetter han terminado y si es así, recuperá todos los
 enlaces encontrados y enviará un mensaje "result(url, links)" al CrawlServer y morirá.
 1. El LinkChecker evitará comprobar varias veces la misma URL, para no rastrear la web indefinidamente y limitaremos el rastreo al 
 dominio de la URL original.
 1. Cuando el CrawlServer reciva un mensaje con el resultado responderá a los clientes enviando "crawlResponse(url, links)".

### 99. Documentación

 Modifica `README.md` usando [Markdown](https://guides.github.com/features/mastering-markdown/) para:
 
  1. Explicar cómo compilar y probar el proyecto, incluyendo requisitos adicionales, si los hubiera.
  1. Comentar las características implementadas, opcionales y bugs conocidos.

No te olvides de hacer un _commit_ en _develop_ para preservar los cambios en README.md.

## Para entregar la actividad

Cuando hayas terminado y estés preparado para entregar la actividad o cuando quieras _feedback_ del profesor:

 1. [Sube](http://git.github.io/git-reference/#push) todos los cambios de tu rama  _develop_ al repositorio `origin` en GitHub.
 1. En la interfaz web de GitHub, crea un [pull request](https://help.github.com/articles/creating-a-pull-request) de
 tu rama _develop_ a `master` para notificar al profesor.

En el título del _pull request_ intenta usar [Feedback] o [Entrega] como prefijo para que podamos identificar rápidamente las consultas, cuando nos llegue la notificación al correo, y así responderlas lo antes posible.

Cuando todos los miembros del grupo hayan hecho sus _pull request_ de [Entrega] deberán ponerse de acuedo para revisar los cambios propuestos, discutir mejoras o alternativas y resolver los conflictos que surjan entre las propuestas.
Una vez estén de acuerdo en la resolución de estas cuestiones, deberán hacer el _merge_ de cada _pull request_ a `master`.

## Consideraciones adicionales sobre el desarrollo

 1. En lugar de tener una única rama _develop_ por miembro del equipo para todo el desarrollo, es mejor crear una rama local por cada tarea o característica y enviar para su revisión cada una según se van terminando. A esta práctica se la denomina [branching](https://docs.google.com/presentation/d/1EXEiEz1d__aHQvAYcPFOiwzlRMunIsDUlJ4tMMYaFig/edit?usp=sharing).

 1. Usa el sistema de [issues](https://guides.github.com/features/issues/) de GitHub para controlar las tareas pendientes
 y su estado.

    Si te decides a usar las _issues_ y a aplicar _branching_, es buena idea nombrar las ramas incluyendo primero el número asignado a la _issue_ correspondiente: `10-feature-x`

 3. [Escribe comentarios adecuados](https://docs.google.com/presentation/d/1EXEiEz1d__aHQvAYcPFOiwzlRMunIsDUlJ4tMMYaFig/edit#slide=id.g351ee290dd_2_105) para cada commit.
