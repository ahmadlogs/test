#include<EEPROM.h>
#include<SoftwareSerial.h>
//----------------------------------------------------
void gsmIncData();
void gsmIncData_print();
void Light_came__Sms();
void Light_came__Sms();
void Motor_on_success_sms();
void Motor_off_success_sms();
void Motor_off_failed_Sms();
void Sms_Service__On();
void Sms_service_off();
void Motor_On_Status_Sms();
void Motor_Off_Status_sms();
//----------------------------------------------------
SoftwareSerial sim800(3,4);
char C;
String Data;
String number;
int Sms_status;
//----------------------------------------------------




/*******************************************************************************************
 *gsmIncData FUNCTION 
*******************************************************************************************/
void gsmIncData(){
  delay(2000);
  while(sim800.available()){
    C=sim800.read();
    Serial.print(C);
  }
}     




/*******************************************************************************************
 *gsmIncData_print FUNCTION 
*******************************************************************************************/
void gsmIncData_print(){
  delay(2000);
  while(sim800.available()){
    C=sim800.read();
    Serial.print(C);
  }
}        




/*******************************************************************************************
 *ight_came__Sms FUNCTION 
*******************************************************************************************/       
void Light_came__Sms(){
  sim800.println("AT+CMGF=1");
  gsmIncData();
  
   sim800.println("Light came");
   gsmIncData();
   
   sim800.write(char(26));
   gsmIncData();
   
  Serial.println("message sent");
}




/*******************************************************************************************
 *Motor_on_success_sms FUNCTION 
*******************************************************************************************/  
void Motor_on_success_sms(){
  sim800.println("AT+CMGF=1");
  gsmIncData();
  
  sim800.println("AT+CMGS=\"+91"+number+"\"");
  gsmIncData();
  
  sim800.println("Motor ON failed");
  gsmIncData();
  
  sim800.write(char(26));
  gsmIncData();
  
  Serial.println("message sent");
}




/*******************************************************************************************
 *Motor_off_success_sms FUNCTION 
*******************************************************************************************/ 
void Motor_off_success_sms(){
  sim800.println("AT+CMGF=1");
  gsmIncData();
  
  sim800.println("AT+CMGS=\"+91"+number+"\"");
  gsmIncData();
  
  sim800.println("Motor OFF Success");
  gsmIncData();
  
  sim800.write(char(26));
  gsmIncData();
  
  Serial.println("message sent");
}




/*******************************************************************************************
 *Motor_on_failed_sms FUNCTION 
*******************************************************************************************/ 
void Motor_on_failed_sms(){
  sim800.println("AT+CMGF=1");
  gsmIncData();
  
  sim800.println("AT+CMGS=\"+91"+number+"\"");
  gsmIncData();
  
  sim800.println("Motor ON Failed");
  gsmIncData();
  
  sim800.write(char(26));
  gsmIncData();
}





/*******************************************************************************************
 *Motor_off_failed_Sms FUNCTION 
*******************************************************************************************/ 
void Motor_off_failed_Sms(){
  sim800.println("AT+CMGF=1");
  gsmIncData();
  
  sim800.println("AT+CMGS=\"+91"+number+"\"");
  gsmIncData();
  
  sim800.println("Motor OFF Failed");
  gsmIncData();
  
  sim800.write(char(26));
  gsmIncData();
}




/*******************************************************************************************
 *Sms_Service__On FUNCTION 
*******************************************************************************************/ 
void Sms_Service__On(){
  sim800.println("AT+CMGF=1");
  gsmIncData();
  
  sim800.println("AT+CMGS=\"+91"+number+"\"");
  gsmIncData();
  
  sim800.println("SMS Service start Successfully");
  gsmIncData();
  
  sim800.write(char(26));
  gsmIncData();
  Serial.println("message sent");
}




/*******************************************************************************************
 *Sms_service_off FUNCTION 
*******************************************************************************************/ 
void Sms_service_off(){
  sim800.println("AT+CMGF=1");
  gsmIncData();
  
  sim800.println("AT+CMGS=\"+91"+number+"\"");
  gsmIncData();
  
  sim800.println("SMS Service Stop Successfully");
  gsmIncData();
  
  sim800.write(char(26));
  gsmIncData();
  
  Serial.println("message sent");
}




/*******************************************************************************************
 *Motor_On_Status_Sms FUNCTION 
*******************************************************************************************/ 
void Motor_On_Status_Sms(){
  sim800.println("AT+CMGF=1");
  gsmIncData();
  
  sim800.println("AT+CMGS=\"+91"+number+"\"");
  gsmIncData();
  
  sim800.println("Motor is on");
  gsmIncData();
  
  sim800.write(char(26));
  gsmIncData();
  
  Serial.println("message sent");
       
}




/*******************************************************************************************
 *Motor_Off_Status_sms FUNCTION 
*******************************************************************************************/ 
void Motor_Off_Status_sms(){
  sim800.println("AT+CMGF=1");
  gsmIncData();
  
  sim800.println("AT+CMGS=\"+91"+number+"\"");
  gsmIncData();
  
  sim800.println("Motor is off");
  gsmIncData();
  
  sim800.write(char(26));
  gsmIncData();
  
  Serial.println("message sent");
}



/*******************************************************************************************
 *SETUP FUNCTION 
*******************************************************************************************/
void setup() {
  //----------------------------------------------------
  Serial.begin(9600);
  sim800.begin(9600);
  delay(1000);
  //----------------------------------------------------
  pinMode(2,INPUT_PULLUP);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  Serial.println("Start Program");
  Serial.println("Wait for Network");
  delay(15000);
  //----------------------------------------------------
  gsmIncData();
  sim800.println("AT");
  gsmIncData_print();
    sim800.println("AT+CSQ");
  gsmIncData_print();
    sim800.println("AT+CBAND=ALL_BAND");
  gsmIncData();
    sim800.println("AT+CLIP=1");
  gsmIncData();
    sim800.println("AT+CPBF=\"Vinod\"");
  //----------------------------------------------------

  //***************************************************************************
  delay(2000);
  Data=="";
  Data=sim800.readString();
  int a2= Data.indexOf('+91');
  int b=a2+12;
  number= Data.substring(a2+2,b);
  Serial.println("Contact Number Saved in the sim with the name of Vinod1 is:");
  Serial.println(number);
  gsmIncData();
  Serial.println("Call Conected to Inform");
  sim800.println("ATD++91"+number+";");
  delay(15000);
  sim800.println("ATH");
  Serial.println("Outgoing Call Disconneted");
  gsmIncData();
  Sms_status = EEPROM.read(1);
  //------------------------------------------------------------------
  if(Sms_status==1){
    Serial.println("Sms Service is on");
    Serial.println("Light come sms is sending");//light_came_sms();
  }
  //------------------------------------------------------------------
  else{
    Serial.println("Sms Service is off");
  }
  //------------------------------------------------------------------
//***************************************************************************
}




/*******************************************************************************************
 *LOOP FUNCTION 
*******************************************************************************************/
void loop(){
  //MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
  while(sim800.available()){
    delay(20);
    Data=="";
    Data=sim800.readString();
    //serial.println(Data);
    //--------------------------------------------------------------
    int a=Data.indexOf("Vinod");
    int b=Data.indexOf("CLIP");
    int C=Data.indexOf("SMS ON");
    //--------------------------------------------------------------
    if(digitalRead(2)==HIGH){
      Serial.println("Motor is OFF");// Motor_off_status_sms();
    }
    //--------------------------------------------------------------
    else{
      Serial.println("Motor is ON");
      //Motor_on_status_sms();
    }
    //--------------------------------------------------------------
    if ((a!=-1)&&(C!=-1)){
      EEPROM.write(1,1);
      Serial.println("the message has been received to stop sms service");
      Sms_service_off();
    }
    //--------------------------------------------------------------
    if((a!=-1)&&(b!=-1)){
      //_________________________________________________
      if(digitalRead(2)==HIGH){
        digitalWrite(6,LOW);
        delay(1000);
        digitalWrite(6,HIGH);
        Serial.println("Motor ON");
        delay(2000);
        sim800.println("ATH");
        Serial.println("Incoming Call Disconnected");
        gsmIncData();
        //*******************************************
        if(Sms_status==1){
          Motor_on_success_sms();
        }
        //*******************************************
      }
      //_________________________________________________
    }
    //--------------------------------------------------------------
    else{
      Serial.println("the motor start failed");
      Motor_on_failed_sms();
    }
    //--------------------------------------------------------------
    digitalWrite(7,LOW);
    delay(1000);
    digitalWrite(7,HIGH);
    Serial.println("Motor OFF");
    delay(4000);
    sim800.println ("ATH");
    Serial.println("Incoming Call Disconnected");
    gsmIncData();
    //_________________________________________________
    if(Sms_status==1){
      if(digitalRead(2)==HIGH){
        Serial.println("The Motor Stop Successfully");
        Motor_off_failed_Sms();
      }   
    }
    //_________________________________________________
  }
  //MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
} 
