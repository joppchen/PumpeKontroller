// DELPROSJEKTER
// 1) Ta inn signal fra 2 vannsensorer. Basert på logikk, send signal til 12V rele for å åpne strøm til pumpa. Basert på videre logikk, sett pumpesignal til LOW for å slå av pumpa.
// 2) Test påkrevd spenningsnivå for å trigge 12V rele
// 3) Test de litt tykke kablene (mett endene med loddetinn) som sensorer og sjekk at de åpner transistor nok til å sende signal til sensor-portene
// 4) Logg til nett: tidspunkt pumpen slo seg på, tidspunkt pumpen slo seg av. Bruk avstand mellom sensorer for å beregne volum. Se om det finnes volumstrømmålere som kan gi signal tilbake til Wemos.
// 5) Koble opp til web server på intranettet
// 6) Sett opp slik at man kan få tilgang til å lese pumpedata via internett


// PROSJEKT 1)

// Signals in
int lowerSensor = D1;
int upperSensor = D2;

// Signals out
int lowerLight = D5;
int upperLight = D6;
int pump = D7;

// Internals
bool pumpIsRunning = false;

void setup() {

  // Initialiser med sensorer av. Hvis de faktisk er neddykket i det Wemos resettes, vil dette oppdateres i første sykel i loopen
  pinMode(lowerSensor, INPUT);
  pinMode(upperSensor, INPUT);
//  digitalWrite(lowerLight, LOW);
  pinMode(lowerLight, OUTPUT);
  pinMode(upperLight, OUTPUT);
//  digitalWrite(upperLight, LOW);
  
  
  // set up built-in LED
//  pinMode(LED_BUILTIN, OUTPUT);
//  digitalWrite(LED_BUILTIN, HIGH); // built-in is inverse of the common cathode RGB LED, i.e. is it a anode LED?


}

void loop() {

  int lowerSensorValue = digitalRead(lowerSensor);
  digitalWrite(lowerLight, lowerSensorValue);
  
  int upperSensorValue = digitalRead(upperSensor);
  digitalWrite(upperLight, upperSensorValue);

  // Logikk
//  if (digitalRead(upperSensor) == HIGH) {
//    digitalWrite(LED_BUILTIN, HIGH);
//    digitalWrite(upperLight, HIGH);
//  }
//  else {
//    digitalWrite(LED_BUILTIN, LOW);
//    digitalWrite(upperLight, LOW);
//  }
  // Hvis pumpen ikke går og B aktiveres, start pumpen.
//    if (!pumpIsRunning and digitalRead(upperSensor) == HIGH) {
//      digitalWrite(pump, HIGH);
//      pumpIsRunning = true;
//    }

    // Hvis A svitsjes av, stopp pumpen.
//    if (pumpIsRunning and lowerSensorValue == HIGH) {
//      digitalWrite(pump, LOW);
//      pumpIsRunning = false;
//    }

  // Feil-sjekking
  // Hvis det er feil på nedre sensor: Hvor lenge pumpa går om gangen bør tidsbegrenses. Bruke stoppeklokke for måle hvor lang tid det tar å tømme brønnen, dette er ganske konstant. Aktiver warning (lys og melding) om at nedre sensor streiker)
  // Hvis det er feil på øvre sensor, ha en 3. back-up sensor sammen med øvre sensor. rett over som starter pumpa hvis sensoren aktiveres og pumpa ikke er i gang.
  // Hvis det er feil på pumpa, eller batteriet er tomt: Sensor 2 og 3 er aktivert en viss tidsvarighet. Hvis pumpa går, skal vannet synke under topp-sensorene ganske raskt - bruke stoppeklokke for å finne tida.
  
}

void blinkStartup(int source) {
  digitalWrite(source, HIGH);
  delay(500);
  digitalWrite(source, LOW);
}

void blinkWifiConnected(int source) {
  delay(1000);
  digitalWrite(source, HIGH);  // 'initial state'
  for (int i = 1; i <= 3; i++) {
    digitalWrite(source, LOW);
    delay(100);
    digitalWrite(source, HIGH);
    delay(100); 
  }
  digitalWrite(source, LOW);
}
