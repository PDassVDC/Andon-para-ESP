# Andon: Controle de Modos de Iluminação e Buzzer Sem Bloqueio (ESP8266/ESP32)

Este projeto implementa um sistema de controle de estados para fitas/módulos LED e acionamento de periféricos (como relés ou buzzers).

### 🚀 Funcionalidades Principais
* **Controle de Modos por Botão:** Alterna ciclicamente entre 6 estados visuais de iluminação (Desligado, Branco, Azul, Verde, Amarelo e Vermelho) através da biblioteca `EasyButton`.
* **Função "Chama Líder":** Acionamento especial ao pressionar e segurar o botão por 2 segundos, ativando uma saída temporizada (Buzzer/Relé) e forçando o estado visual para a cor vermelha.
* **LED de Status:** Indicador visual que pisca a cada 200ms em segundo plano para demonstrar que o processador está operando livre de travamentos.

### 🛠️ Tecnologias Utilizadas
* Linguagem C++ (Ambiente Arduino IDE)
* Biblioteca `EasyButton`
* Microcontroladores ESP8266 / ESP32
