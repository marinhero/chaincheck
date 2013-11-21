Chaincheck
==========

Proyecto final de teoría de la computación.<br />
ITESM 2013.
Integrantes del equipo:<br />
Pedro Orellana Manzano<br />
Luis Eduardo Espinosa<br />
Andrea Aguiar Moreira<br />
Marin Alcaraz Cordova <br />

Información general
============================

<h3>Descripción</h3>
El programa construirá un objeto de tipo gramática con las reglas que se encuentran dentro del grammar.txt,<br />
posteriormente analizará las cadenas dentro de chains.txt y determinará si son aceptadas por la gramatica o no.

<h3>Requerimientos mínimos</h3>

<ul>
  <li>GCC 4.2.1</li>
  <li>Make</li>
</ul>

<h3>Instalación</h3>

<ul>
  <li>Clonar el repositorio a un directorio local:</li>
  <code>
    user@host> git clone https://github.com/marinhero/chaincheck.git
  </code>
  <br />
  <code>
    user@host> cd chaincheck
  </code>
  <br />
  <li> Compilar: </li>
  <code>
    user@host[chaincheck]> make <br />
    > Compiled <br />
  </code>
  <li>Ejecutar:</li>
  <code>
    user@host[chaincheck]> ./chain_check GRAMMAR_FILE CHAINS_FILE <br />
  </code>
  Una gramática de demostración está incluída en el repositorio
</ul>
