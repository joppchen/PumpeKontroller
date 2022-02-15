// DELPROSJEKTER
// 1) Ta inn signal fra 2 vannsensorer. Basert på logikk, send signal til 12V rele for å åpne strøm til pumpa. Basert på videre logikk, sett pumpesignal til LOW for å slå av pumpa.
// 2) Test påkrevd spenningsnivå for å trigge 12V rele
// 3) Test de litt tykke kablene (mett endene med loddetinn) som sensorer og sjekk at de åpner transistor nok til å sende signal til sensor-portene
// 4) Logg til nett: tidspunkt pumpen slo seg på, tidspunkt pumpen slo seg av. Bruk avstand mellom sensorer for å beregne volum. Se om det finnes volumstrømmålere som kan gi signal tilbake til Wemos.
// 5) Koble opp til web server på intranettet
// 6) Sett opp slik at man kan få tilgang til å lese pumpedata via internett


// PROSJEKT 1)
int noOfSensors = 2;
int noOfPumps = 1;

// Signals in
int sensor1 = D1;
int sensor2 = D2;
//int sensor3 = D5; // Oppfører seg på samme måte som D1
//int sensor4 = D6; // Oppfører seg på samme måte som D2

// FUTUREs
//int sensor5 = D3; // TODO: D3 oppfører seg rart. Hvordan få den til å oppføre seg på samme måte som D1?
//int sensor6 = D4; // TODO: D4 oppfører seg rart. Hvordan få den til å oppføre seg på samme måte som D2?
//int sensorAnalog = A0;;

// Signals out
int pump1 = D0; // Oppfører seg på samme måte som D7, jeg bruker hermed D0 til å styre pumpen
//int pumpLight = D7; // Pumpelyset er nå lagt i parallell med signalet til 12V-reléet
//int pump2 = D7; // Oppfører seg på samme måte som D1
//int pump3 = D8; // Oppfører seg på samme måte som D2

void setup() {

  // Definer input-pins
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  // Definer output-pins
  pinMode(pump1, OUTPUT);
  //pinMode(pumpLight, OUTPUT);
  
  
  // Turn on built-in LED when the controller has power
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); // built-in is inverse of the common cathode RGB LED, i.e. is it a anode LED?
}

void loop() {

  // Logikk  <- Mer robust logikk: hvis begge sensorene er på, slå på pumpen. Hvis begge sensorene slås av, slå av pumpen.
  if (digitalRead(sensor1) == HIGH && digitalRead(sensor2) == HIGH) {
      digitalWrite(pump1, HIGH);
      //digitalWrite(pumpLight, HIGH);
  }
  else if (digitalRead(sensor1) == LOW && digitalRead(sensor2) == LOW) {
    digitalWrite(pump1, LOW);
    //digitalWrite(pumpLight, LOW);
  }

  // Feil-sjekking
  // Hvis det er feil på nedre sensor: Hvor lenge pumpa går om gangen bør tidsbegrenses. Bruke stoppeklokke for måle hvor lang tid det tar å tømme brønnen, dette er ganske konstant, evt. mål volumstrømmen fra pumpa opp i en bøtte (f.eks. hvor lang tid tar det å pumpe 10 liter?). Aktiver warning (lys og melding) om at nedre sensor streiker)
  // Hvis det er feil på øvre sensor, ha en 3. back-up sensor sammen med øvre sensor. rett over som starter pumpa hvis sensoren aktiveres og pumpa ikke er i gang.
  // Hvis det er feil på pumpa, eller batteriet er tomt: Sensor 2 og 3 er aktivert en viss tidsvarighet. Hvis pumpa går, skal vannet synke under topp-sensorene ganske raskt - bruke stoppeklokke for å finne tida.

  // TODO:
  // Legg til kode for pumpe 2
  // Legg til kode for pumpe 3
  // Logikk: Opptil 4 veloppdragne sensorer (kan ha to til hvis jeg skjønner meg på D3 og D4), opptil 3 pumper
  // IDEAs:
    // Use mono jacks (signal connectors) for connecting sensors in a flexible way
    // Use barrel jacks (power connectors) for connecting pumps in a flexible way
    // Use e.g. slide switch to select between different modes, e.g. A: 1 pump, 2 sensors, B: 1 pump, 3 sensors, etc.
  
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
