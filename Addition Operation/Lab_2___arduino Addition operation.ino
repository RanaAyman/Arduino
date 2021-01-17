/*
  This program blinks pin 13 of the Arduino (the
  built-in LED)
*/
int number=0;
int sign=1;
void setup()
{
  Serial.begin(9600);
  delay(50);
}

int add(int n1,int n2){
  int result = n1+n2;
  return result;
}

void loop()
{
  Serial.println("\nEnter 1st Number :");

  int number1 = get_md_number();
  Serial.print("1st number = ");
  Serial.println(number1);
  
  Serial.println("\nEnter 2nd Number :");
  int number2 = get_md_number();
  Serial.print("2nd number = ");
  Serial.println(number2);
  
  int result = add(number1 , number2);
  //Serial.print("\nResult = ");
  Serial.print("\n");
  Serial.print(number1);
  Serial.print(" + ");
  Serial.print(number2);
  Serial.print(" = ");
  Serial.println(result);
}
  
int get_md_number(void){
 number =0;
 sign=1; 
 while(Serial.available()==0){ /*nn*/}
  while(Serial.available()){
    byte incoming =Serial.read();
    if(incoming >='0' && incoming <='9'){
      number=(number*10) + (incoming-'0');
      delay(5);
    }else if(incoming=='-'){
       sign=-1;
      delay(5);
    }else{
      Serial.println("\nInvalid Entry! Try Again.\n");
      loop();
    }
  }
  return number*sign;
}