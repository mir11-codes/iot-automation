int fertilizerpin=7;
int waterpin = 6;
float soilraw=0.0;
float soilmoist=0.0;
int senpin= A0;
int average;
int val;
int  readval=0;
int serialA=0;
void setup (){
  Serial.begin(9600);
  pinMode(senpin,INPUT);
  pinMode(fertilizerpin,1);
  pinMode(waterpin,1);
    pinMode(13,OUTPUT);
}

void loop(){
      
       if (Serial.available() > 2) {
  serialA = Serial.parseInt();
 
  }   

    if (serialA== 4){
    
    
   
    digitalWrite(fertilizerpin,1);
    
  
    }
     if (serialA== 8){
    
   
    
     digitalWrite(fertilizerpin,0);
  
    }
     if (serialA== 7){
       
       digitalWrite(waterpin,0);
   
  
    }
     if (serialA== 9){
   
     digitalWrite (waterpin,1);
  
  
    }
   
   soilraw = analogRead(senpin);
  soilmoist=map(soilraw,1024,0,0,100);
    for (int i=0; i < 160; i++) {
 average = average +soilmoist;
 }
 val = average/160;
 average=0;
 
Serial.println(val);

delay(1200);
if (val<40){
  digitalWrite(waterpin,HIGH);
}if (val>60){
  digitalWrite(waterpin,LOW);
}

}
