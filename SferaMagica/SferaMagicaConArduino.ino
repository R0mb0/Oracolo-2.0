#define LedBlu 2 // LED collegato al pin digitale 2  
#define LedRosso 3 // LED collegato al pin digitale 3
#define LedGiallo 4 // LED collegato al pin digitale 4
#define LedVerde 5 // LED collegato al pin digitale 5
#define LedBianco 6  // LED collegato al pin digitale 6
#define Pulsante 7   // pin di input dove è collegato il pulsante (7)
#define LedRgbBlu 8    //LED collegato al pin digitale 8
#define LedRgbRosso 9     //LED collegato al pin digitale 9
int  val = 0;                 // si userà val per conservare lo stato del pin di input  
int sled = 0;
long Number;

void setup() {  

  
  pinMode(LedBlu, OUTPUT);
  pinMode(LedRosso, OUTPUT); 
  pinMode(LedGiallo, OUTPUT); 
  pinMode(LedVerde, OUTPUT); 
  pinMode(LedBianco, OUTPUT);
  pinMode(LedRgbBlu, OUTPUT); 
  pinMode(LedRgbRosso, OUTPUT);        
  pinMode(Pulsante, INPUT);   
  Serial.begin(115200);
  randomSeed(analogRead(A0)); //a seconda di quello che rileva l'antenna cambia la probabilità  
}  
  
void loop() {  
  val = digitalRead(Pulsante);  // legge il valore dell'input e lo conserva  
  
  // controlla che l'input sia HIGH (pulsante premuto)  
  if (val == HIGH) {
      digitalWrite(LedRgbBlu, LOW); // spegne il led spia
      sled=1;   // porta sled a 1
      digitalWrite(LedRgbRosso,HIGH);   
  }  
  else {  
    digitalWrite(LedRgbBlu, HIGH);   // accende il led spia  
  }
  if(sled==1){
    delay(1000);
    Number = random(1, 5);       // genera un numero pseudo casuale tra 1 e 5
    Serial.println(Number);
    digitalWrite(LedRgbRosso,LOW);  
    
    if (Number == 1) digitalWrite(LedBlu, HIGH);  // se randNumber è  1, LED blu ON altrimenti OFF
  else digitalWrite(LedBlu, LOW);

  if (Number == 2) digitalWrite(LedRosso, HIGH);
  else digitalWrite(LedRosso, LOW);

  if (Number == 3) digitalWrite(LedGiallo, HIGH);
  else digitalWrite(LedGiallo, LOW);

  if (Number == 4) digitalWrite(LedVerde, HIGH);
  else digitalWrite(LedVerde, LOW);

  if (Number == 5) digitalWrite(LedBianco, HIGH);
  else digitalWrite(LedBianco, LOW);
  
  delay(5000);
  sled=0;
  digitalWrite(LedBlu,LOW);
  digitalWrite(LedRosso,LOW);
  digitalWrite(LedGiallo,LOW);
  digitalWrite(LedVerde,LOW);
  digitalWrite(LedBianco,LOW);
  
    } 
     
 }
  
