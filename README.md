Monitoramento de Temperatura para Gestão Sustentável dos Oceanos


Descrição do Projeto

Este projeto foi desenvolvido para o Desafio de "Inovação Azul" 2024, que incentiva soluções inovadoras para a gestão sustentável dos oceanos. Nosso objetivo é monitorar a temperatura ambiente em áreas costeiras e marinhas, fornecendo alertas visuais e sonoros em caso de temperaturas críticas, que podem impactar a saúde dos oceanos e a subsistência das populações costeiras.

Componentes Utilizados

Arduino UNO
Sensor de Temperatura DHT22
Módulo RTC DS1307
Display LCD 16x2
LEDs (Vermelho, Amarelo, Verde)
Buzzer

Funcionalidades

Medição da temperatura ambiente em tempo real.
Exibição da hora e temperatura no display LCD.
Alertas visuais através de LEDs indicando diferentes estados de temperatura:
Verde: Temperatura normal (20°C a 30°C).
Amarelo: Temperatura baixa (<20°C).
Vermelho: Temperatura alta (>30°C).
Alarme sonoro em caso de temperaturas críticas (alta ou baixa).

Resultados Esperados

Monitoramento contínuo e confiável da temperatura em ambientes costeiros.
Alertas imediatos para prevenir danos a equipamentos e garantir a conservação do ambiente.
Melhoria na gestão sustentável dos oceanos, proporcionando segurança e informações úteis para populações costeiras e empresas marítimas.

Instruções de Uso

Montagem do Hardware:

Conecte o sensor DHT22 ao Arduino:
VCC ao 5V do Arduino.
GND ao GND do Arduino.
DATA ao pino digital 9 do Arduino.
Conecte o módulo RTC DS1307 ao Arduino:
VCC ao 5V do Arduino.
GND ao GND do Arduino.
SDA ao pino A4 do Arduino.
SCL ao pino A5 do Arduino.
Conecte o display LCD 16x2 ao Arduino:
RS ao pino digital 7 do Arduino.
E ao pino digital 6 do Arduino.
D4 ao pino digital 5 do Arduino.
D5 ao pino digital 4 do Arduino.
D6 ao pino digital 3 do Arduino.
D7 ao pino digital 2 do Arduino.
Conecte os LEDs e o buzzer ao Arduino:
LED Vermelho ao pino digital 13 do Arduino.
LED Amarelo ao pino digital 12 do Arduino.
LED Verde ao pino digital 11 do Arduino.
Buzzer ao pino digital 10 do Arduino.

Upload do Código:

Abra o Arduino IDE.
Copie o código fornecido e cole no editor de código do Arduino IDE.
Compile e faça o upload do código para o Arduino.

Operação:

Após o upload, o sistema irá iniciar e mostrar a tela de logo.
O display LCD exibirá a hora e a temperatura em tempo real.
LEDs e buzzer indicarão o estado da temperatura conforme descrito acima.

Requisitos e Dependências

Arduino IDE: Software para programação e upload de código no Arduino.
Bibliotecas Arduino Necessárias:
LiquidCrystal: #include <LiquidCrystal.h>
DHT: #include <dht.h>
RTClib: #include <RTClib.h>

Conclusão

Este projeto visa contribuir para a gestão sustentável dos oceanos, fornecendo uma solução prática e eficaz para o monitoramento de temperatura em ambientes costeiros. Esperamos que nossa abordagem ajude a prevenir danos ambientais e garantir a segurança das populações e empresas que dependem dos oceanos.
