//AVANZAR PRUEBA
void avanzar (){
for(int i = 0; i < 8; i++){
        if(i % 2 == 0)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);         
}
}
