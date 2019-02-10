int variableLinea=500;
//variable para cuando calibremos 

//ULTRASONICOS
int ultraT[4]={23,24,27,52};
int ultraE[4]={22,26,25,53};

int mc=0; 
//DERECHA A IZQUIERDA
int mH[8][3]={{HIGH,LOW,HIGH},{HIGH,HIGH,LOW},{HIGH,HIGH,HIGH},{LOW,LOW,LOW},{HIGH,LOW,LOW},{LOW,HIGH,HIGH},{LOW,HIGH,LOW},{LOW,LOW,HIGH}};
//ARRIBA A ABAJO, LA ULTIMA SIMPLEMENTE REPETÍ LA QUE ESTABA MÁS ALEJADA
int mV[8][3]={{HIGH,HIGH,LOW},{HIGH,HIGH,HIGH},{LOW,LOW,LOW},{HIGH,LOW,LOW},{LOW,HIGH,HIGH},{LOW,HIGH,LOW},{LOW,LOW,HIGH},{HIGH,LOW,LOW}};

//FOTORRESISTENCIAS MULTIPLEXOR
int mhDig[3]= {35,33,31}; 
int mvDig[3]= {32,34,36};
int mhAna=0;
int mvAna=2;
//MOTORES
int motores[8] = {9, 10, 12, 13, 18, 17, 19, 3}; //Puente H1: +,-,+,-,Puente H2: +,-,+,- 
int pmw[4] = {8, 11, 5, 6};
//DRIBBLER
int dribbler[2]={16,30}; //+,-
int dribblerPmw =4;
void setup() {
  Serial.begin(9600);

  //ULTRASONICOS
  
for(int i=0;i<4;i++)
{
  pinMode(ultraT[i],OUTPUT);
  pinMode(ultraE[i],INPUT);
}
//Digitales de multiplexor como salidas
for (int i=0;i<3;i++){
  pinMode(mhDig[i], OUTPUT);
}
for (int i=0;i<3;i++){
  pinMode(mvDig[i], OUTPUT);
}

//Declarar los pines de los motores como salidas
  for(int i = 0; i < 8; i++){
    pinMode(motores[i], OUTPUT);
  }
  
//Declarar los PMW como salidas
  for(int i = 0; i < 4; i++){
    pinMode(pmw[i], OUTPUT);
  }
  
//KICKER
  pinMode(7, OUTPUT);
  
//Potencia de Motores (Analogos varian de 0-255)
  analogWrite(pmw[0], 200); 
  analogWrite(pmw[1], 200);
  analogWrite(pmw[2], 200);
  analogWrite(pmw[3], 200);
}

void loop(){

changeAnalog();

if (readM1()<400)
{
  Serial.print(mc);
    Serial.print(":");
      Serial.println(readM1());
}
 }
 
