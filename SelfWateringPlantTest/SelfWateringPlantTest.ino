#define ANA A0
#define DIGI D0
#define WATERPUMP D6
#define LED D4 // Use built-in LED which connected to D4 pin or GPIO 2

double analogValue = 0.0;
int digitalValue = 0;
int waterpumpValue = 0;
double analogVolts = 0.0;
unsigned long timeHolder = 0;
int counter = 0;
int max_count = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(ANA, INPUT);
  pinMode(DIGI, INPUT);
  pinMode(WATERPUMP, OUTPUT);
  pinMode(LED, OUTPUT); 
  Serial.begin(115200);
  Serial.println("Test");
}

void loop() {
  analogValue = analogRead(ANA);
  digitalValue = digitalRead(DIGI);
  
  // Serial data
  Serial.print("Analog raw: ");
  Serial.println(analogValue);
  Serial.print("Digital raw: ");
  Serial.println(digitalValue);
  Serial.print("Waterpump raw: ");
  Serial.println(waterpumpValue);
  if(analogValue > 300)
  { 
    if(counter < max_count)
    {
      counter ++;
      Serial.println("Switching pump on");
      digitalWrite(WATERPUMP, true);
      digitalWrite(LED, LOW);   // Turn the LED on because the LED is active low
    }
    else
    {
      Serial.println("Pump overload, switching off");
      digitalWrite(LED, HIGH);  // Turn the LED off because the LED is active low
    }
  }
  else
  { 
    counter = 0;
    Serial.println("Switching pump off");
    digitalWrite(WATERPUMP, false);
    digitalWrite(LED, HIGH);  // Turn the LED off because the LED is active low
  }
  Serial.println(" ");
  delay(5000);
}
