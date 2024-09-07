//aqui va el codigo de proccesing que crea el poster//

import processing.serial.*;

Serial myPort;
PImage halloweenImage;

void setup() {
  size(800, 600);
  halloweenImage = loadImage("halloween.png"); // Asegúrate de tener la imagen en la carpeta 'data'
  myPort = new Serial(this, "COM3", 9600); // Ajusta el puerto COM según tu configuración
}

void draw() {
  background(0);
  image(halloweenImage, 0, 0);
}

void keyPressed() {
  if (key == ' ') {
    myPort.write('1'); // Enviar un dato al Arduino cuando se presione la tecla espaciadora
  }
}
