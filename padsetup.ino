#define SIZE 3
#include <Keypad.h>

int list [SIZE]= {};
int num;
int i = 0;
int password [3] = {1,2,3};

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}

  
void loop(){
    char key = keypad.getKey();// !Read the key
    num = key - 48; // converts ascii number to decimal
    list[i] = num; // inital i will be in beginning of the list 0th index 

    if (key == 'D'){ // reset condition
        i = 0;
        Serial.print("value of i in reset:");
        Serial.println(i);
        for(int x = 0; x < 3; x++){ // outputs each value inputed by keypad all contained in list
            list[x] = 0;
            
            }
        }

    //condtion for outputing keypad input
    else if (key != 'D' && key){

        i++; // loop variable for incrementing each index of list 
        Serial.print("Key Pressed : ");
        Serial.println(key);
        
        Serial.print("key value:");
        Serial.println(num);
        
        Serial.print("value of i:");
        Serial.println(i);

        if(i == SIZE){ // has loop variable reached max list size
        Serial.println("values in the list: ");
        for(int x = 0; x < SIZE; x++){ // outputs each value inputed by keypad all contained in list
            Serial.print(list[x]); // outputing on serial monitor in order

             
              if ( memcmp(list, password, sizeof(list)) == 0){// checks if each array index == key inputs
                Serial.println("Correct PASSWORD");


              }
            }
        }
  }
}