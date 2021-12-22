#include <Key.h>
#include <Keypad.h>
#define makeKeyMap(x) ((char*)x)

const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad keypad = Keypad(makeKeyMap(keys), rowPins, colPins, ROWS, COLS);
const String password = "A1112";
String userInput;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  userInput.reserve(40);
  pinMode(13, OUTPUT);
}

void loop() {
  char keyInput = keypad.getKey();

  if (keyInput) {
    Serial.println(keyInput);
    if(keyInput == '*'){
      userInput = "";
    }
    if (keyInput == '#'){
      if(password == userInput){
        Serial.println("you shall pass :)");
        userInput = "";
        digitalWrite(12 , HIGH);
        delay(6000);
        digitalWrite(12 , LOW);
      }
      else{
          Serial.println("you shall NOT pass!!");
          digitalWrite(13,HIGH);
          delay(6000);
          digitalWrite(13,LOW);
      }
    }
    else{
      userInput += keyInput;
     }
    }

}
