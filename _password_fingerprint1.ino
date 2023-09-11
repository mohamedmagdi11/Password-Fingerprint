#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);
#include <Keypad.h>
const byte row = 4;
const byte col = 4; 
char Keys[row][col] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[row] = {9,8,7,6};
byte colPins[col] = {5,4,3,2}; 
Keypad myKeypad = Keypad( makeKeymap(Keys), rowPins, colPins, row, col);

char pass[6] = {};
byte counter = 0;
#define id1 10
#define id2 11
#define id3 12
#define id4 13



void setup(){
  pinMode(id1,INPUT_PULLUP);
  pinMode(id2,INPUT_PULLUP);
  pinMode(id3,INPUT_PULLUP);
  pinMode(id4,INPUT_PULLUP);
  
  
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Password : ");


}
  
void loop(){
  char key = myKeypad.getKey();
  if(key)
  {
    if(counter <=5)
    {
    pass[counter] = key;
    lcd.setCursor(counter+10, 0);
    lcd.print("*");
    counter++;
    }
    else {counter = 0;}
    
  
    char enter = myKeypad.getKey();
    if(counter == 6)
    {
    while(!enter)
    enter = myKeypad.getKey();
    }
    if(pass[0] == '1' && pass[1] =='2' && pass[2] == '3' && pass[3] == '4' && pass[4] =='5' && pass[5] == '6'&& enter == 'D')
    {
      
    correct(); 
     
    }
    if(pass[0] != '1' && enter == 'D')
    {
    incorrect(); 
      
    }
   }
  if(!digitalRead(id1))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ID is : 1");
        delay(2000);
        lcd.clear();

    lcd.print("Password : ");
    
  }
 else if(!digitalRead(id2))
   {
    lcd.clear();
    lcd.setCursor(0, 0);
     lcd.print("ID is : 2");
        delay(2000);
       lcd.clear();

   lcd.print("Password : ");
   
  }
  
   
   
   
 else if(!digitalRead(id3))
   {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ID is : 3");
        delay(2000);
       lcd.clear();
   lcd.print("Password : ");
    
  }
  
   
   
 else if(!digitalRead(id4))
    {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ID is : 4");
        delay(2000);
       lcd.clear();

   lcd.print("Password : ");
    
  }
  }

void correct()
{    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Password : ");
    lcd.setCursor(0, 1);
    lcd.print("User authorized ");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Put your finger");
}
  

void incorrect()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Password : ");
    lcd.setCursor(0, 1);
    lcd.print("Incorrect ");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Put your finger");
}