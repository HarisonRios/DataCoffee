// Definições dos pinos e variáveis
// Definições dos pinos e variáveis
const int PINO_SENSOR_TEMPERATURA = A0;
float temperaturaCelsius;

const int PINO_SENSOR_UMIDADE_SOLO = A1;

//Função de inicialização.
void setup() {
  Serial.begin(9600);
  pinMode(PINO_SENSOR_UMIDADE_SOLO, INPUT);
}
//Função principal de execução continua.
void loop() {
  //Lê os valores analógicos do sensor LM35 e converte-os para temperatura em °C.
  int valorLeitura = analogRead(PINO_SENSOR_TEMPERATURA);
  temperaturaCelsius = (valorLeitura * 5.0 / 1023.0) / 0.01;
  //Lê os valores analógicos do sensor de umidade do solo e converte-os para %.
  int leituraSensor = analogRead(PINO_SENSOR_UMIDADE_SOLO);

  float porcentagemUmidade = (leituraSensor / 1023.0) * 100;
  //Exibe os valores de temperatura ja convertidos para °C.

  Serial.print(temperaturaCelsius);
  Serial.print(";");
  
  //Exibe os valores de umidade ja convertidos para %.

  Serial.print(porcentagemUmidade);
  Serial.print(";");
  Serial.println(" ");
  
  //Tempo até a proxima leitura em ms(milisegundos).
  delay(5000);
}