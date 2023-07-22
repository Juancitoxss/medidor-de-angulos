//Se definen los pines a usar.
#define POT A7
#define D2 3   // 1
#define D3 2   // 8
#define D4 12  // 0
#define boton 11 
const int segs[7] =
{
 10,  //A
  9,  //B
  8,  //C
  7,  //D
  6,  //E
  5,  //F
  4,  //G
};
const byte numbers[] =
{
  0b0111111, //0
  0b0000110, //1
  0b1011011, //2
  0b1001111, //3
  0b1100110, //4
  0b1101101, //5
  0b1111101, //6
  0b0000111, //7
  0b1111111, //8
  0b1101111, //9
};
void setup()
{
  Serial.begin(9600);
  pinMode(POT, INPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(boton, INPUT);
  for (int i = 4  ; i <= 10; i++)
  {
    pinMode(i, OUTPUT);
  }
}
void loop()
{
  int Val = analogRead(POT);
  int correccion=Val/3.6;
  MostrarNum(correccion);
  /* if(digitalRead(boton)==HIGH)
  {
     digitalWrite(D2,!digitalRead(D2));
     delay(250);
     digitalWrite(D3,!digitalRead(D3));
     delay(250);
     digitalWrite(D4,!digitalRead(D4));
     delay(250);
  } */
} 
void MostrarNum(int num)
{
  int digit2 = (num / 100) % 10;
  int digit3 = (num / 10) % 10;
  int digit4 = num % 10;
  Digito2(numbers[digit2]);
  delay(5);
  Digito3(numbers[digit3]);
  delay(5);
  Digito4(numbers[digit4]);
  delay(5);
}

void Digito2(byte n)
{
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  segmentos(n);
}

void Digito3(byte n)
{
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
  segmentos(n);
}

void Digito4(byte n)
{
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
  segmentos(n);
}

void segmentos(byte n)
{
  for (int i = 0; i < 7; i++)
  {
    int bit = bitRead(n, i);
    digitalWrite(segs[i], bit);
  }
}
