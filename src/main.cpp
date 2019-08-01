#include <M5Stack.h>
const unsigned int GREENTYPE = M5.Lcd.color565(7,235,235);
const unsigned int GREY = M5.Lcd.color565(153,153,153);
//******************************************************
int state=0;
int on=1,onc1=0, onc2=0,onc3=0,onc4=0;
int stateMenuL=0;
int stateMenuR=0;
int stateMenuCD=0;
int stateMenuTD=0;
int stateMenuPE=0;
int stateMenuSL=0;
//******************************************************
void text();
void menu();
void setCursorText(int x, int y);
void menuList();
void CountDown();
void Todo();
void Percentage();
void Sleep();
void imgClock();
void imgTodo();
void imgPer();
void imgSleep();
//******************************************************
void setup() {
  M5.begin();
}
//******************************************************
void loop(){
  menu();
 
}
//******************************************************
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
  //***********************************
    while(1){
        if(M5.BtnB.wasPressed()) {
          state++;
        }
        if (state==1){
          state=0;
          menuList();
        }
        else {
          state=0;
        }
      M5.update();  
    }

}
void imgClock(){
    M5.Lcd.fillCircle(40, 120, 35, GREY);//*
    M5.Lcd.fillCircle(40, 120, 25, WHITE);
    M5.Lcd.fillRect(25,124,15,3,GREY);
    M5.Lcd.fillRect(40,105,3,22,GREY);
    
}
void imgTodo(){
    M5.Lcd.fillCircle(120, 120, 35, GREY);//*
    M5.Lcd.fillRect(100,100,10,10,WHITE);
    M5.Lcd.fillRect(120,105,20,1,WHITE);
    M5.Lcd.fillRect(100,115,10,10,WHITE);
    M5.Lcd.fillRect(120,120,20,1,WHITE);
    M5.Lcd.fillRect(100,130,10,10,WHITE);
    M5.Lcd.fillRect(120,135,20,1,WHITE);
}
void imgPer(){
    M5.Lcd.fillCircle(200, 120, 35, GREY);//*
    M5.Lcd.fillCircle(200, 120, 25, WHITE);
    M5.Lcd.setTextColor(GREY);
    M5.Lcd.setTextSize(4.5);
    setCursorText(190,105);
    M5.Lcd.print("%");
}
void imgSleep(){
    M5.Lcd.fillCircle(280, 120, 35, GREY);//*
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(3);
    setCursorText(285,100);
    M5.Lcd.print("Z");
    M5.Lcd.setTextSize(2);
    setCursorText(270,115);
    M5.Lcd.print("Z");
    M5.Lcd.setTextSize(1);
    setCursorText(260,130);
    M5.Lcd.print("Z");
}
void menuList(){
  
  M5.Lcd.fillScreen(GREENTYPE);
  M5.Lcd.fillRect(0,0,900,50,GREY);
  text();
  setCursorText(135,20);
  M5.Lcd.print("MENU");
  
    imgClock();
    imgTodo();
    imgPer();
    imgSleep();
 
    text();
    setCursorText(50,200);
    M5.Lcd.printf("Home");
    setCursorText(150,200);
    M5.Lcd.printf("OK");
    setCursorText(250,200);
    M5.Lcd.printf(">");

    while(on)
  {
    //Button C 
      if(M5.BtnC.wasPressed()) {
      stateMenuL++;  
      }
      if(stateMenuL==5){
        stateMenuL=1;
      }

    switch (stateMenuL){
    case 1 :
       M5.Lcd.fillCircle(280, 165, 10,  GREENTYPE);
       M5.Lcd.fillCircle(40, 165, 10, WHITE);
       onc1=1;
       if(M5.BtnB.wasPressed()&&onc1==1){ 
          stateMenuCD++;
           
            if(stateMenuCD==1){
              on=0;
              onc1=0; 
              stateMenuCD=0;
              CountDown();
            } 
           else {stateMenuCD=0;}
          }
       break;
    case 2:
       M5.Lcd.fillCircle(40, 165, 10, GREENTYPE);
       M5.Lcd.fillCircle(120, 165, 10, WHITE);
       onc2=1;
       if(M5.BtnB.wasPressed()&&onc2==1){ 
          stateMenuTD++;
           
            if(stateMenuTD==1){
              on=0;
              onc2=0; 
              stateMenuCD=0;
              Todo();
            } 
           else {stateMenuTD=0;}
          } 
       
       break;
    case 3:
       M5.Lcd.fillCircle(120, 165, 10, GREENTYPE);
       M5.Lcd.fillCircle(200, 165, 10, WHITE);
       onc3=1;
       if(M5.BtnB.wasPressed()&&onc3==1){ 
          stateMenuPE++;
           
            if(stateMenuPE==1){
              on=0;
              onc3=0; 
              stateMenuPE=0;
              Percentage();
            } 
           else {stateMenuPE=0;}
          }
       break;
    case 4:
       M5.Lcd.fillCircle(200, 165, 10, GREENTYPE);
       M5.Lcd.fillCircle(280, 165, 10, WHITE);
       onc4=1;
         if(M5.BtnB.wasPressed()&&onc4==1){ 
          stateMenuSL++;
           
            if(stateMenuSL==1){
              on=0;
              onc4=0; 
              stateMenuSL=0;
              Sleep();
            } 
           else {stateMenuSL=0;}
          }
       break;
     }
  //Button A Home
      if(M5.BtnA.wasPressed()) {
      stateMenuR++;
      
      if(stateMenuR==1){
          stateMenuR=0;
          menu();
      }
      else {stateMenuR=0;}
     }  

     M5.update();
  }
}
void CountDown(){
  text();
  M5.Lcd.fillScreen(GREENTYPE);
  M5.Lcd.fillRect(0,0,900,50,GREY);
  setCursorText(100,20);
  M5.Lcd.print("Count-Down");
  setCursorText(250,200);
  M5.Lcd.printf(">");
    while(1){
        if(M5.BtnC.wasPressed()) {
          on=1;
          state++;
        }
        if (state==1){
          state=0;
          menuList();
        }
        else {
          state=0;
        }
      M5.update();  
    }
}
void Todo(){
  text();
  M5.Lcd.fillScreen(GREENTYPE);
  M5.Lcd.fillRect(0,0,900,50,GREY);
  setCursorText(100,20);
  M5.Lcd.print("Todo List");
  setCursorText(250,200);
  M5.Lcd.printf(">");
   while(1){
     
        if(M5.BtnC.wasPressed()) {
          state++;
          on=1;
        }
        if (state==1){
          state=0;
          menuList();
        }
        else {
          state=0;
        }
      M5.update();  
    }
}
void Percentage(){
  text();
  M5.Lcd.fillScreen(GREENTYPE);
  M5.Lcd.fillRect(0,0,900,50,GREY);
  setCursorText(100,20);
  M5.Lcd.print("Percentage");
  setCursorText(250,200);
  M5.Lcd.printf(">");
   while(1){
        if(M5.BtnC.wasPressed()) {
          on=1;
          state++;
        }
        if (state==1){
          state=0;
          menuList();
        }
        else {
          state=0;
        }
      M5.update();  
    }
}
void Sleep(){
  text();
  M5.Lcd.fillScreen(GREENTYPE);
  M5.Lcd.fillRect(70, 100, 50,10, GREY);
  M5.Lcd.fillRect(190, 100, 50,10, GREY);
  setCursorText(250,200);
  M5.Lcd.printf(">");
   while(1){
        if(M5.BtnC.wasPressed()) {
          on=1;
          state++;
        }
        if (state==1){
          state=0;
          menuList();
        }
        else {
          state=0;
        }
      M5.update();  
    }
}
