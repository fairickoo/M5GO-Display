#include <M5Stack.h>
#include <list.h>
const unsigned int GREENTYPE = M5.Lcd.color565(7,235,235);
const unsigned int GREY = M5.Lcd.color565(153,153,153);
//******************************************************
int state=0;
int stateMenuL=0;
int stateMenuR=0;
int stateMenuTD=0;
int stateMenuSL=0;

//******************************************************
void text();
void menu();
void setCursorText(int x, int y);
void Todo();
void Sleep();

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
  M5.Lcd.printf("Todo");
  //***********************************
    while(1){
        if(M5.BtnB.wasPressed()) {
          state++;
        }
        if (state==1){
          state=0;
          Todo();
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
  M5.Lcd.printf("Sleep");
 
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);
   setCursorText(0,70);
        for(int x=0;x<5;x++)
        {
          for(int y=0;y<30;y++)
          { 
            M5.lcd.print(title[x][y]);
          }
           M5.lcd.println();
        }
 
   while(1){
     
        if(M5.BtnC.wasPressed()) {
          state++;
        }
        if (state==1){
          state=0;
          Sleep();
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
  setCursorText(45,200);
  M5.Lcd.printf("Home");
   while(1){
        if(M5.BtnA.wasPressed()) {
          state++;
        }
        if (state==1){
          state=0;
          menu();
        }
        else {
          state=0;
        }
      M5.update();  
    }
}
