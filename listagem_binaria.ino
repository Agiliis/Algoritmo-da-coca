// C++ code
//

void setup(){
  Serial.begin(9600);
}

String binNum = "";

void lista(int ldN, int index){
  for(int i = 0; i < 2; i++){
    if(index != ldN) lista(ldN, index+1);
    else{
      Serial.print(binNum + " ");
      binNum[index] = '1';
      Serial.print(binNum + " ");
      break;
    }
    
    binNum[index+1] = '0';
    binNum[index] = '1';
  }
}

void loop(){
  if(Serial.available()>0){
    int ledNum = Serial.read()-48, n = ledNum;
    
    while(n--) binNum += '0';
    
    lista(--ledNum,0);
    Serial.print("\n");
    
    binNum = "";
  }
}