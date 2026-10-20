
/*Andon para ESP8266/32
 * Data: 01/09/2022
 * Desenvolvedores: Maicon Silva, Leonardo Oliveira Prado
 * Revisado: Leonardo Romão
 * Data: 20/10/2026
 */

#include <EasyButton.h>
#include "Arduino.h"
#include "led.h"


#define LED_STATUS 2 //Da placa ESP8266
#define pinoRelay 4 // D2
#define BT_MODO 5   // D1

uint8_t modo = 0;
uint8_t ultimo_modo = 10;

EasyButton button_modo(BT_MODO, 100, false, false);

unsigned long ultima_atualizacao_led = 0;
unsigned long tempo_acionou_buzzer = 0;
bool buzzer_ativo = false;


void onPressedModo()
{
  if (++modo > 4)
  {
    modo = 0;
  }
}

void chamaLider()
{
  modo = 5;
  onLedRed();
  
  digitalWrite(pinoRelay, HIGH); // Liga o buzzer/relé
  tempo_acionou_buzzer = millis(); // Guarda o milissegundo atual
  buzzer_ativo = true;           // Avisa o sistema que o buzzer está ligado
}


void setup()
{
  setupLed();
  pinMode(pinoRelay, OUTPUT);
  digitalWrite(pinoRelay, LOW);
  pinMode(LED_STATUS, OUTPUT);

  button_modo.begin();
  button_modo.onPressedFor(2000, chamaLider);
  button_modo.onPressed(onPressedModo);
}

void loop()
{

  button_modo.read(); 
  // MONITOR DO BUZZER (Substitui o delay de 400ms de forma inteligente)
  if (buzzer_ativo && (millis() - tempo_acionou_buzzer >= 400))
  {
    digitalWrite(pinoRelay, LOW); // Passou 400ms? Desliga!
    buzzer_ativo = false;         // Finaliza o monitoramento
  }

  if (ultimo_modo == modo)
  {
  }
  else
  {
    ultimo_modo = modo;
    switch (modo)
    {
      case 0: ledOff();       break;
      case 1: onLedWhite();   break;
      case 2: onLedBlue();    break;
      case 3: onLedGreen();   break;
      case 4: onLedYellon();  break; 
      case 5: onLedRed();     break;
    }
  }

  if (millis() - ultima_atualizacao_led > 200)
  {
    digitalWrite(LED_STATUS, !digitalRead(LED_STATUS));
    ultima_atualizacao_led = millis();
  }
}
