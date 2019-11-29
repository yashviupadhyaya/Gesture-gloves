const int FLEX_PIN_1 = A0;
const int FLEX_PIN_2 = A1;
const int FLEX_PIN_3 = A2;// Pin connected to voltage divider output
const int ledPin =  LED_BUILTIN;// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg


void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN_1, INPUT);
  pinMode(FLEX_PIN_2, INPUT);
  pinMode(FLEX_PIN_3, INPUT);
    // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}
float calculate(int FLEX_PIN){
  int flexADC = analogRead(FLEX_PIN);
  float flexV = flexADC * VCC / 1023.0;
  float flexR = R _DIV * (VCC / flexV - 1.0);
  //Serial.println("Resistance: " + String(flexR) + " ohms");

  float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  return angle;
}
void loop() 
{
  float angle1=calculate(A0);
  float angle2=calculate(A1);
  float angle3=calculate(A2);
//  Serial.println(angle1);
//  Serial.println(angle2);
//  Serial.println(angle3);
  if(angle1>0 && angle2>0 && angle3>0){
    {
      Serial.println("Water");
    }
  }
  else if(angle1>60 && angle2<60 && angle3<60){
    {
      Serial.println("Food");        
    }
  }
  else if(angle1<60 && angle2>60 && angle3<60){
   {
      Serial.println("Help");        
    }
  }
  else if(angle1<60 && angle2<60 && angle3>60){
   {
      Serial.println("Washroom");        
    }
  }
  else if(angle1>60 && angle2>60 && angle3<60){
    {
      Serial.println("Go out");        
    }
  }
  else if(angle1<60 && angle2>60 && angle3>60){
    {
      Serial.println("Call");        
    }
  }
  else if(angle1>60 && angle2<60 && angle3>60){
    {
      Serial.println("Thank  You!");        
    }
  }
  
 //Serial.println("Bend: " + String(angle) + " degrees");
  
  delay(1000);
}
