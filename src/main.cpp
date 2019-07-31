#include <M5Stack.h>
const unsigned int GREENTYPE = M5.Lcd.color565(7,235,235);
const unsigned int GREY = M5.Lcd.color565(153,153,153);
int state=0;
int stateMenuL=0;
int stateMenuR=0;
int stateMenuCD=0;
void text();
void menu();
void setCursorText(int x, int y);
void menuList();
void SetCountDown();
//***************************************************
void setup() {
  M5.begin();
}

void loop(){
  menu();
}

void text(){
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2.5);
}
void setCursorText(int x, int y){
   M5.Lcd.setCursor(x,y);
}
void menu(){

  M5.Lcd.fillScreen(GREENTYPE);
  M5.Lcd.fillCircle(100, 100, 20, GREY);
  M5.Lcd.fillCircle(200, 100, 20, GREY);
  M5.Lcd.fillCircle(112, 90, 10, WHITE);
  M5.Lcd.fillCircle(212, 90, 10, WHITE);
  text();
  setCursorText(130,200);
  M5.Lcd.printf("Manu");
  while(1){
    if(M5.BtnB.wasPressed()) {
      state++;
    }
    if (state==1)
    {
      state=0;
      menuList();
    }
    else if(state==2){
      state=0;
    }
  M5.update();  
}

}
void menuList(){
  text();
  //้header
  M5.Lcd.fillScreen(GREENTYPE);
  M5.Lcd.fillRect(0,0,900,50,GREY);
  setCursorText(135,20);
  M5.Lcd.print("MENU");
  //emoji
    M5.Lcd.fillCircle(40, 120, 35, GREY);
    M5.Lcd.fillCircle(120, 120, 35, GREY);
    M5.Lcd.fillCircle(200, 120, 35, GREY);
    M5.Lcd.fillCircle(280, 120, 35, GREY);
 // M5.Lcd.drawJpgFile(SD, "../src/I_clock.jpg");
    setCursorText(50,200);
    M5.Lcd.printf("Home");
    setCursorText(150,200);
    M5.Lcd.printf("OK");
    setCursorText(250,200);
    M5.Lcd.printf(">");
//Button
    while(1){
//ฺButton C
    if(M5.BtnC.wasPressed()) {
    stateMenuL++;
    if(stateMenuL==5){
      stateMenuL=1;
     }
    }
    switch (stateMenuL){
    case 1 :
       M5.Lcd.fillCircle(280, 120, 35, GREY);
       M5.Lcd.fillCircle(40, 120, 35, WHITE);
       break;
    case 2:
       M5.Lcd.fillCircle(40, 120, 35, GREY);
       M5.Lcd.fillCircle(120, 120, 35, WHITE);
       break;
    case 3:
       M5.Lcd.fillCircle(120, 120, 35, GREY);
       M5.Lcd.fillCircle(200, 120, 35, WHITE);
       break;
    case 4:
       M5.Lcd.fillCircle(200, 120, 35, GREY);
       M5.Lcd.fillCircle(280, 120, 35, WHITE);
       break;
     }
//Button A
      if(M5.BtnA.wasPressed()) {
      stateMenuR++;
        if(stateMenuR==1){
          stateMenuR=0;
          menu();
        }
      }
   
    
   
   
    



   M5.update();  
  }
}

void SetCountDown(){
  M5.Lcd.fillScreen(GREENTYPE);
  M5.Lcd.fillRect(0,0,900,50,GREY);
  setCursorText(50,20);
  M5.Lcd.print("Setting Count-Down");

}
