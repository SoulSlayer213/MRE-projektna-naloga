#include <dht11.h>
#include <LiquidCrystal.h>
#define DHT11PIN 6

dht11 DHT11;
const  int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en,  d4, d5, d6, d7);
void  setup()
{
  Serial.begin(9600);Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  lcd.begin(16, 2);

 
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);
  
  lcd.setCursor( 0 , 0 ); 
  lcd.print("Temp: " ); 
  lcd.print(( float ) DHT11.temperature , 2 ); 
  lcd.print( "C" );
  
  lcd.setCursor( 0 , 1 ); 
  lcd.print( "Hum: " ); 
  lcd.print( ( float )DHT11.humidity , 2 ); 
  lcd.print( " %" );
  
  delay ( 2000 ) ; 

}
