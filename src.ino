const int echoPin = 9;
const int trigPin = 10;
const int greenLed = 11;
const int yellowLed = 12;
const int redLed = 13;

enum systemState {
  greenState,
  yellowState,
  redState,
};

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("System active");
}

systemState currentState = greenState;
unsigned long lastChangeTime = 0;
bool carAcknowledged = false;

void loop(){
  unsigned long currentTime = millis();
  
  long distance = readDistance();
  
  switch(currentState) {
    
    // Default state: Main road flows
    case (greenState):
    	updateLED(LOW, LOW, HIGH);
    	if(distance <= 100){
          if(!carAcknowledged){
          	Serial.println("Car detected");
            Serial.println(distance);
            carAcknowledged = true;
          };
          if(currentTime - lastChangeTime >= 4000){
            currentState = yellowState;
          	lastChangeTime = currentTime;
          	carAcknowledged = false;
          };
        }else{
          carAcknowledged = false;
        };
    	break;
    
    
    // Transition state: Prepares for passage on side road
    case (yellowState):
    	updateLED(LOW, HIGH, LOW);
        if(currentTime - lastChangeTime >= 2000){
          currentState = redState;
          lastChangeTime = currentTime;
        };
    	break;
    
    
    // Action state: Side road passes
    case (redState):
    	updateLED(HIGH, LOW, LOW);
        if(currentTime - lastChangeTime >= 4000){
          currentState = greenState;
          lastChangeTime = currentTime;
        };
    	break;
  }
}


//Measures the distance from object to the sensor
int readDistance() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return (pulseIn(echoPin, HIGH) * 0.034) / 2;
}

//Helper function to manage LED states
void updateLED(int red, int yellow, int green){
  digitalWrite(redLed, red);
  digitalWrite(yellowLed, yellow);
  digitalWrite(greenLed, green);
}