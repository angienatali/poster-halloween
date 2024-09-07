//aqui el codigo del aduino//
#include <Esplora.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

const int buttonPin = Esplora.BUTTON_SELECT; // Botón que se usará para activar la acción
bool buttonState = false; // Estado del botón

bool mostrarPrimeraImagen = true; // Flag para alternar entre imágenes

void setup() {
  Serial.begin(9600); // Iniciar comunicación serial
}

void loop() {
  // Lee el estado del botón
  buttonState = Esplora.readButton(buttonPin);

  if (buttonState) {
    realizarAccion(); // Función para realizar la acción cuando se presione el botón
    delay(500); // Retardo para evitar lecturas múltiples
  }
}

void realizarAccion() {
  if (mostrarPrimeraImagen) {
    Serial.write('1'); // Enviar '1' para la primera imagen
  } else {
    Serial.write('2'); // Enviar '2' para la segunda imagen
  }
  mostrarPrimeraImagen = !mostrarPrimeraImagen; // Cambiar el estado
}
