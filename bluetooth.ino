#include "BluetoothSerial.h" 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

BluetoothSerial ESP_BT; //Object for Bluetooth

LiquidCrystal_I2C lcd(0x27, 20, 4);  

String message = "";
char incomingChar;

String inString = "";    // string to hold input


void setup() {

  // initialize LCD
  lcd.init();                 
  lcd.backlight();
  
  Serial.begin(115200); //Start Serial monitor in 9600
  ESP_BT.begin("ESP32"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

  lcd.setCursor(0,0);
  lcd.print("Bluetooth ESP32");
  lcd.setCursor(0,1);
  lcd.print("Ready to Pair");
  delay(2000);
  lcd.clear();

}

void loop() {

  servo();

  /*lcd.setCursor(0,0);
  lcd.print("Youtube : Tech Wan");
  lcd.setCursor(0,2);
  lcd.print("Char Receive :");
  
   if (ESP_BT.available()){
   
    delay(2);
    char incomingChar = ESP_BT.read();
    message += incomingChar;
    
    if (message.length() >0) {
      Serial.println(message);
      lcd.setCursor(14,2);
      lcd.print("  ");
      lcd.setCursor(15,2);
      lcd.print(message);
  
      message="";
    }
        
  }
 
 delay(20);
 */



 
}


void servo()
{
  // Read serial input:
  while (ESP_BT.available() > 0) {
    int inChar = ESP_BT.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }

         
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      Serial.print("Value:");
      Serial.println(inString.toInt());

      int value = inString.toInt();
      
                      if(value>=0 && value<=90){
                      Serial.println(value); 
                      
                      }
                     if(value>90 && value<=181){
                      Serial.println(value); 
                      
                      }
                
                    if(value>181 && value<=272){
                      Serial.println(value); 
                     
                      }
                
                    if(value>272 && value<=363){
                      Serial.println(value); 
                      
                      }

                      if(value>363 && value<=454){
                      Serial.println(value); 
                     
                      }
    
      inString = "";

  
      
      //Serial.print("String: ");
      //Serial.println(inString);
      // clear the string for new input:
     // 
    }
    
  }
}
