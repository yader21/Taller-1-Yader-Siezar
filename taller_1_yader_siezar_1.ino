

// Leds rgb
int LEDG1 = 6;
int LEDB1 = 7;
int LEDR1 = 8;
int LEDB2 = 9;
int LEDR2 = 10;
// Led normal
int LED = 13;
// otros valores
int numero = 0;
int cont_temp= 0;
bool negativos = false;
// Botones
int Boton_1 = 5;
int Boton_2 = 4;
int Boton_3 = 3;
int Boton_4 = 2;


void setup(){
	pinMode(LEDG1,OUTPUT);
  	pinMode(LEDB1,OUTPUT);
  	pinMode(LEDR1,OUTPUT);
  	pinMode(LEDB2,OUTPUT);
  	pinMode(LEDR2,OUTPUT);
  	pinMode( LED ,OUTPUT);
  	pinMode(Boton_1,INPUT);
    pinMode(Boton_2,INPUT);
    pinMode(Boton_3,INPUT);
    pinMode(Boton_4,INPUT);

  	Serial.begin( 9600 );
}


void loop(){
  	if ( digitalRead ( Boton_1 ) == LOW ){
      	suma1();
      	delay(200);
  	}
  	if ( digitalRead ( Boton_2 ) == LOW ){
      	suma2();
      	delay(200);
  	}
  	if ( digitalRead ( Boton_3 ) == LOW ){
      	reiniciar();
      	delay(1000);
  	}
  	if ( digitalRead ( Boton_4 ) == LOW ){
      if(negativos==false){
      		negativos= true;
      }
      else{
        	negativos= false;
      }
      escribir_N();
    }
}


int suma1(){
  numero = numero + 1;
  escribir_N();
}


int suma2(){
  numero = numero + 2;
  escribir_N();
}


int reiniciar(){
  	numero = 0;
  	digitalWrite(6,LOW);
  	digitalWrite(7,LOW);
  	digitalWrite(8,LOW);
  	digitalWrite(9,LOW);
  	digitalWrite(10,LOW);
  	digitalWrite(13,LOW);  
}



int escribir_N()
{
  delay(250);
  cont_temp=numero;
  
  if (numero>15){
   	digitalWrite(13,HIGH);
    
  } else if(cont_temp>0) {
  	
      if (negativos==false){
        
    	for (int led=6; led<=10;led++){
      		digitalWrite(led,(cont_temp%2));
     		cont_temp/=2;
    	}
      } else {
        cont_temp= cont_temp-1;
        for (int led=6; led<=10;led++) {
          if((cont_temp%2)==1){
          	digitalWrite(led,0);                          
     		cont_temp/=2;
          } else {
            digitalWrite(led,1);                         
     		cont_temp/=2;
          	}
          if (numero>=9)
            digitalWrite(10,LOW);
      		
      	 }
      }
  }
}