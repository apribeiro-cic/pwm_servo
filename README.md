# Atividade EmbarcaTech - Controle de Servomotor por PWM

## Visão Geral da Atividade
Esta atividade tem como objetivo desenvolver um sistema de controle de um **servomotor** utilizando o microcontrolador **RP2040 (Raspberry Pi Pico W)** em uma simulação no Wokwi, além de um experimento da placa **BitDogLab**. O sistema opera da seguinte forma:

1. **Inicialmente, a cada 5 segundos, o servo muda de posição**, seguindo a sequência:
   - **180 graus** (2400μs)
   - **90 graus** (1470μs)
   - **0 graus** (500μs)
2. **Após essas posições fixas, o servo movimenta-se suavemente** entre **0 e 180 graus**:
3. **A gestão do PWM é feita pelo módulo PWM do RP2040**, configurado para **50Hz (20ms de período)**.

## Requisitos de Software
Para compilar e executar o programa, serão necessários:
- **Pico SDK** instalado
- **Compilador ARM (arm-none-eabi-gcc)**
- **Ambiente de desenvolvimento** (Ex: VS Code)
- **Extensão do Wokwi**
- **Extensão do Raspberry Pi**

## Instruções de Compilação e Execução
1. **Clonar o projeto para sua máquina:**
   ```sh
   git clone https://github.com/apribeiro-cic/pwm_servo
   ```
   
2. **Importar o projeto pela extensão Raspberry Pi:**
   
   Esse passo pode não ser necessário, pois ao estar com a extensão instalada o VSCode cria a pasta `build` automaticamente ao ser executado. Porém, se esse não for o caso, será necessário importar o projeto pela extensão Raspberry Pi:

   - Clique na barra lateral em **Raspberry Pi Pico Project** e em **Import Project**.
   - Selecione o diretório e clique em **Import**.
  
3. **Compile o projeto e abra o arquivo `diagram.json`:**
   Compile o projeto e abra o arquivo `diagram.json` para que a simulação do projeto apareça (Extensão do Wokwi deve estar instalada).

4. **Inicie a simulação do projeto:**
   - No Wokwi, pressione o botão de **Run Simulation** para testar o comportamento do servomotor.

## Uso do Programa
1. **Ao iniciar o sistema, o servomotor será posicionado em 180 graus**.
2. **A cada 5 segundos, a posição do servo será alterada** para 90 graus e depois para 0 graus.
3. **Após esse ciclo, o servo se moverá suavemente entre 0 e 180 graus**, incrementando o pulso do PWM gradualmente.

## Considerações Finais
Este projeto demonstra o uso de **modulação por largura de pulso (PWM) no RP2040** para o controle preciso de um **servomotor**. A implementação foi testada na BitDogLab e simulada no Wokwi.

[Vídeo de demonstração do projeto.](https://youtu.be/Wio2ASbaWuw)
