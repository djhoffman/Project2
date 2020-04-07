
//referenced: sensor example
//implemented: RGB instead

// inputs
int red = 12;
int green = 27;

// PWM (pulse width modulation)
const int freq = 5000;
int ledChannel = 0;
const int resolution = 8;

void setup(){
  // outputs
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  
  // LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);

  // attach the channel GPIO (general-purpose input/output)
  ledcAttachPin(red, ledChannel);

  // serial communication (bits per second)
  Serial.begin(9600);

}

void loop(){
  // analog pin A0
  int sensorValue = analogRead(A0);
  // print value
  Serial.println(sensorValue);

  // INPUT
  sensorValue = constrain(sensorValue, 200, 330);
  int brightness = map(sensorValue, 200, 330, 0 , 255);
  
  //OUTPUT
  ledcWrite(ledChannel, brightness);

  if(sensorValue < 300){
  // orange when sensor is high and green when low
  digitalWrite(green, HIGH);
  Serial.println("Someone is at the door.");
  }
}
