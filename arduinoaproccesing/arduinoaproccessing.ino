//aqui el codigo del aduino//
#include <Esplora.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Crea una instancia para la pantalla TFT incorporada
Adafruit_ILI9341 tft = Adafruit_ILI9341();

const int buttonPin = Esplora.BUTTON_SELECT; // Botón que se usará para activar la acción
bool buttonState = false; // Estado del botón

// Definir imágenes en formato BMP
#include "halloween1.h" // Archivo BMP para la primera imagen
#include "halloween2.h" // Archivo BMP para la segunda imagen

bool mostrarPrimeraImagen = true; // Flag para alternar entre imágenes

void setup() {
  tft.begin();
  mostrarImagenHalloween1(); // Muestra la primera imagen de Halloween al iniciar
}

void loop() {
  // Lee el estado del botón
  buttonState = Esplora.readButton(buttonPin);

  if (buttonState) {
    realizarAccion(); // Función para realizar la acción cuando se presione el botón
    delay(500); // Retardo para evitar lecturas múltiples
  }
}

void mostrarImagenHalloween1() {
  // Mostrar la primera imagen de Halloween
  tft.fillScreen(ILI9341_BLACK); // Limpia la pantalla con color negro
  // Cargar la imagen BMP en la pantalla
  tft.drawBitmap(0, 0, halloween1, 240, 320, ILI9341_WHITE); // Ajusta el tamaño según la imagen
}

void mostrarImagenHalloween2() {
  // Mostrar la segunda imagen de Halloween
  tft.fillScreen(ILI9341_BLACK); // Limpia la pantalla con color negro
  // Cargar la imagen BMP en la pantalla
  tft.drawBitmap(0, 0, halloween2, 240, 320, ILI9341_WHITE); // Ajusta el tamaño según la imagen
}

void realizarAccion() {
  // Alternar entre dos imágenes
  if (mostrarPrimeraImagen) {
    mostrarImagenHalloween2();
  } else {
    mostrarImagenHalloween1();
  }
  mostrarPrimeraImagen = !mostrarPrimeraImagen; // Cambiar el estado
}
