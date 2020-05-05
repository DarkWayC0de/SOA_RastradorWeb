# ${NOMBRE_PROYECTO}

${DESCRIPCION_PROYECTO}

## Cómo empezar

Para empezar:

 1. Acepta la [actividad en GitHub Classroom](${CLASSROOM_ID}).

    Obtendrás tu propia copia de este mismo repositorio para comenzar a trabajar. Por ejemplo, si la actividad se
    llama `soa-actividad01` y tu equipo es `grupo01`, tu nuevo repositorio se llamará
    `ull-esit-sistemas-operativos/soa-actividad01-grupo01`.

 1. [Clona](http://git.github.io/git-reference/#clone) el nuevo repositorio en tu ordenador. Esa será tu copia local del
 proyecto y el repositorio original `ull-esit-sistemas-operativos/soa-actividad01-grupo01` será `origin`.

 1. En tu copia local en tu ordenador no trabajes directamene en la rama `master`.
 Crea una rama con el prefijo `develop-` seguido por el nombre de tu cuenta en GitHub y haz todos los cambios sobre ella.
 Por ejemplo, si tu cuenta en GitHub es `alu0100123456`, crea la rama de la siguiente manera:

    ~~~~.sh
    $ git checkout -b develop-alu0100XXXXXX
    ~~~~

    Así cada miemmbro del equipo tendrá su propia rama de desarrollo.
    Por simplificar, en el resto del documento la llamaremos rama _develop_. 
    Como comentaremos después, la idea es pasar los cambios a _master_ solo cuando tengan algo definitivo.

 1. Añade el repositorio extra `git@github.com:ull-esit-sistemas-operativos/soa-actividad01.git` como `upstream`:

    ~~~~.sh
    $ git remote add upstream git@github.com:ull-esit-sistemas-operativos/soa-actividad01.git
    ~~~~

    Así se pueden obtener las últimas actualizaciones a la actividad ejecutando:

    ~~~~.sh
    $ git pull upstream master
    ~~~~

## Tareas

Trabaja en la rama  _develop_ de tu copia local siguiendo los pasos indicados a continuación:

 1. ...

 1. Modifica `README.md` usando [Markdown](https://guides.github.com/features/mastering-markdown/) para:
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
