# IGS - Indoor Growing Station

### Nomes:

-    Augusto Lopes
-    Henzo Alves
-    Marcelo Medeiros

## A - Descrição da ideia: Uma mini estufa.

#### 1 - Necessidade:

  Um espaço com condições climáticas controladas para que possa ser programado para se adaptar a todo tipo de cultivo.

#### 2 - Necessidade:

  Display para mostrar informações da web sem a necessidade de acessar uma página.

--------------------------------------------------------------------------------
## B)

#### 1 - Como é essa interface?

  Umidade do solo, luminosidade, Umidade e temperatura do ar.

#### 2 - O que é monitorado?

  Um servidor web conectado a um netbook hospeda uma página html onde as informações serão exibidas.

#### 3 - O que é alterado ou controlado?

  A ventilação da estufa que controla a umidade, a iluminação e temperatura interna do ar. A iluminação interna será implementada com uma lâmpada Fluorescente.

#### 4 - Quem são os concorrentes no mercado?

  A empresa que produziu o https://farmbot.io/ é um bom exemplo, embora o #### cda mesma seja o cultivo externo dependente das condições climáticas da região.

#### 5 - Qual o público alvo que vc quer atingir?

  Pessoas comuns que podem ter vontade de cultivar plantas em sua casa.

--------------------------------------------------------------------------------
## C) Desenvolvimento do projeto:

-	1 - Testar os sensores e sua comunicação com o arduino;

-  2 - Testar funcionamento do display e encontrar o meio mais adequado para
  comunicação com a WEB.

-  3 - Planejamento do circuito de monitoramento e aplicação do mesmo.

-  4 - Produção do circuito de monitoramento.
  -  4.1 - Controle da Webcam.
  -  4.2 - Comunicação com o netbook.

-  5 - Mandar informações para web.

-  6 - Design e construção da estufa.
  -  6.1 - Design estrutural da estufa.
  -  6.2 - Construção da estufa(Estrutural).
  -  6.3 - Design da placa de circuito de controle do sistema.
  -  6.4 - Construção da estufa(Instalação das lâmpadas e montagem geral).

-  9 - Display local pra captar e exibir informações da web.

-  10 - Teste final.

--------------------------------------------------------------------------------
## D) Estimativa do material a ser utilizado:

####  Controle :

-     Arduino nano.
-     Netbook.

####  Sensoreamento :

-     Sensor de umidade do solo.
-     Sensor de umidade do ar.
-     Sensor de temperatura do ar.
-     Sensor de luminosidade.
-     Web cam do netbook.

####  Atuação :

-     Relé 5V - 110V/220V.
-     Lâmpada fluorescente.
-     Transistor (?).
-     Cooler 12v.

####  Transmissão :

-     Netbook

####  Exibição :

-     Display 16/2 ou matriz de led.

####  Alimentação :

-     Fonte 12V.
-     Tomada 110V.

#### WEB:

- App responsivo para visualizar os dados dos sensores da estufa em tempo real e acesso a uma galeria com as fotos tiradas de forma periódica.

- Cada sensor vai ter uma tabela monstrando os dados das últimas análises feitas pelo sensor
- Também vamos usar um gráfico para representar de uma forma mais clara o progresso das análises feitas por cada sensor
- Para as fotos, vamos criar uma galeria separada para cada dia da estufa em funcionamento

- Basicamente, este não será um app para controle da estufa, e sim para monitoramento da mesma, já que irrigação e registro diário com as fotos serão 100% automatizados, além de outras funções também 100% automatizadas.

- Para desenvolver o app vamos usar Bootstrap para o design, AngularJS para a estrutura do frontend e MySQL para a estrutura e afins do backend.

--------------------------------------------------------------------------------

## E) Referências:

    https://www.youtube.com/watch?v=UjG2QGOC4aA
    https://www.youtube.com/watch?v=xpdpDo-gR3Q
    https://www.youtube.com/watch?v=9QZkCQSHnko
    https://www.youtube.com/watch?v=O_Q1WKCtWiA
