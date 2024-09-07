//aqui va el codigo de proccesing que crea el poster//

import processing.serial.*;

Serial myPort;
PImage halloweenImage1;
PImage halloweenImage2;
boolean imageToShow = true;

void setup() {
  size(800, 600);
  
  // Cargar las imágenes
  halloweenImage1 = loadImage("halloween1.png"); // Imagen 1
  halloweenImage2 = loadImage("halloween2.png"); // Imagen 2
  
  // Configurar el puerto serie
  myPort = new Serial(this, "COM3", 9600); // Ajusta el puerto COM según tu configuración
}

void draw() {
  background(0);
  
  // Mostrar la imagen correspondiente
  if (imageToShow) {
    image(halloweenImage1, 0, 0);
  } else {
    image(halloweenImage2, 0, 0);
  }
}

void serialEvent(Serial myPort) {
  // Leer datos del puerto serie
  int inByte = myPort.read();
  
  // Cambiar la imagen según el comando recibido
  if (inByte == '1') {
    imageToShow = true;
  } else if (inByte == '2') {
    imageToShow = false;
  }
}
