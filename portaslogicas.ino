#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int a = 13;
int b = 12;
int s = 11;

int tamanho = 4;
int aArray[4];
int bArray[4];

int andArray[4];
int orArray[4];
int nAndArray[4];
int nOrArray[4];
int xOrArray[4];
int xNorArray[4];

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(s, OUTPUT);
  
  lcd.begin(16, 2);
}

/*FUNÇÃO PARA POPULAR O PRIMEIRO ARRAY*/
void popularArrayA() {
    for(int i = 0; i < tamanho; i++) {
        if (i < (tamanho/2)) {
            aArray[i] = 0;
        } else {
            aArray[i] = 1;
        }
    }
}

/*FUNÇÃO PARA POPULAR O SEGUNDO ARRAY*/
void popularArrayB() {
    int quantidade = 1;
    int contador = 0;

    for(int i = 0; i < tamanho; i++) {
        if(contador == quantidade) {
            bArray[i] = 1;
        } else if(contador > quantidade) {
            contador = 0;
            i--;
            continue;
        } else {
            bArray[i] = 0;
        }
        contador++;
    }
}


void andFunction() {
    for(int i = 0; i < tamanho; i++) {
        if(aArray[i] == 0 && bArray[i] == 0) {
            andArray[i] = 0;
        } else if(aArray[i] == 0 && bArray[i] == 1) {
            andArray[i] = 0;
        } else if(aArray[i] == 1 && bArray[i] == 0) {
            andArray[i] = 0;
        } else if(aArray[i] == 1 && bArray[i] == 1) {
            andArray[i] = 1;
        }
      	digitalWrite(a, aArray[i]);
      	digitalWrite(b, bArray[i]);
      	digitalWrite(s, andArray[i]);      
              
      	delay(2000);
    }
}

void orFunction() {
    for(int i = 0; i < tamanho; i++) {
        if(aArray[i] == 0 && bArray[i] == 0) {
            orArray[i] = 0;
        } else if(aArray[i] == 0 && bArray[i] == 1) {
            orArray[i] = 1;
        } else if(aArray[i] == 1 && bArray[i] == 0) {
            orArray[i] = 1;
        } else if(aArray[i] == 1 && bArray[i] == 1) {
            orArray[i] = 1;
        }
      	digitalWrite(a, aArray[i]);
      	digitalWrite(b, bArray[i]);
      	digitalWrite(s, orArray[i]);      
              
      	delay(2000);
    }
}

void nAndFunction() {
    for(int i = 0; i < tamanho; i++) {
        if(aArray[i] == 0 && bArray[i] == 0) {
            nAndArray[i] = 1;
        } else if(aArray[i] == 0 && bArray[i] == 1) {
            nAndArray[i] = 1;
        } else if(aArray[i] == 1 && bArray[i] == 0) {
            nAndArray[i] = 1;
        } else if(aArray[i] == 1 && bArray[i] == 1) {
            nAndArray[i] = 0;
        }
      	digitalWrite(a, aArray[i]);
      	digitalWrite(b, bArray[i]);
      	digitalWrite(s, nAndArray[i]);      
              
      	delay(2000);
    }
}

void nOrFunction() {
    for(int i = 0; i < tamanho; i++) {
        if(aArray[i] == 0 && bArray[i] == 0) {
            nOrArray[i] = 1;
        } else if(aArray[i] == 0 && bArray[i] == 1) {
            nOrArray[i] = 0;
        } else if(aArray[i] == 1 && bArray[i] == 0) {
            nOrArray[i] = 0;
        } else if(aArray[i] == 1 && bArray[i] == 1) {
            nOrArray[i] = 0;
        }
      	digitalWrite(a, aArray[i]);
      	digitalWrite(b, bArray[i]);
      	digitalWrite(s, nOrArray[i]);      
              
      	delay(2000);
    }
}

void xOrFunction(){
    for(int i = 0; i < tamanho; i++) {
    	 if(aArray[i] == 0 && bArray[i] == 0) {
            xOrArray[i] = 0;
        } else if(aArray[i] == 0 && bArray[i] == 1) {
            xOrArray[i] = 1;
        } else if(aArray[i] == 1 && bArray[i] == 0) {
            xOrArray[i] = 1;
        } else if(aArray[i] == 1 && bArray[i] == 1) {
            xOrArray[i] = 0;
        }
      	digitalWrite(a, aArray[i]);
      	digitalWrite(b, bArray[i]);
      	digitalWrite(s, xOrArray[i]);      
              
      	delay(2000);
    }
}

void xNorFunction(){
    for(int i = 0; i < tamanho; i++) {
    	 if(aArray[i] == 0 && bArray[i] == 0) {
            xNorArray[i] = 1;
        } else if(aArray[i] == 0 && bArray[i] == 1) {
            xNorArray[i] = 0;
        } else if(aArray[i] == 1 && bArray[i] == 0) {
            xNorArray[i] = 0;
        } else if(aArray[i] == 1 && bArray[i] == 1) {
            xNorArray[i] = 1;
        }
      	digitalWrite(a, aArray[i]);
      	digitalWrite(b, bArray[i]);
      	digitalWrite(s, xNorArray[i]);      
              
      	delay(2000);
    }
}

void loop() {
  popularArrayA();
  popularArrayB();
  
  lcd.clear();
  
  lcd.setCursor(1, 0);
  lcd.print("PORTAS LOGICAS");
  
  lcd.setCursor(6, 1);
  lcd.print("AND");
  andFunction();
  
  lcd.clear();
  
  lcd.setCursor(1, 0);
  lcd.print("PORTAS LOGICAS");
  
  lcd.setCursor(6, 1);
  lcd.print("OR");
  orFunction();
  
  lcd.clear();
  
  lcd.setCursor(1, 0);
  lcd.print("PORTAS LOGICAS");
  
  lcd.setCursor(6, 1);
  lcd.print("NAND");
  nAndFunction();
  
  lcd.clear();
  
  lcd.setCursor(1, 0);
  lcd.print("PORTAS LOGICAS");
  
  lcd.setCursor(6, 1);
  lcd.print("NOR");
  nOrFunction();
  
  lcd.clear();

  lcd.setCursor(1, 0);
  lcd.print("PORTAS LOGICAS");
  
  lcd.setCursor(6, 1);
  lcd.print("XOR");
  xOrFunction();
  
  lcd.clear();
  
  lcd.setCursor(1, 0);
  lcd.print("PORTAS LOGICAS");
  
  lcd.setCursor(6, 1);
  lcd.print("XNOR");
  xNorFunction();
  
  lcd.clear();

}


  