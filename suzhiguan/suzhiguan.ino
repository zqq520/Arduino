 #include <dht11.h>

dht11 mydht11;   
int dhtpin = A3;  
int buzzerPin = A4;
int ledPin = A5;
//--------!!!!!!!!!!!!接口不能占用IO口！！！！！！！！！！！！！
 //设置阴极接口
 int a = 2;
 \
 int b = 3;
 int c = 4;
 int d = 5;
 int e = 6;
 int f = 7;
 int g = 8;
 int p = 9;
 //设置阳极接口
 int d4 = 12;
 int d3 = 13;
 int d2 = 11;
 int d1 = 10;
 //设置变量
 long n = 1230;
 int x = 100;
 int del = 15;  //此处数值对时钟进行微调
float humidity;
float temperature;
int humidityset=30;
int temperatureset=35;
int num4;
int num3;
int num2;
int num1;
void setup(){
 Serial.begin(19200);
 pinMode(d1, OUTPUT);
 pinMode(d2, OUTPUT);
 pinMode(d3, OUTPUT);
 pinMode(d4, OUTPUT);
 pinMode(a, OUTPUT);
 pinMode(b, OUTPUT);
 pinMode(c, OUTPUT);
 pinMode(d, OUTPUT);
 pinMode(e, OUTPUT);
 pinMode(f, OUTPUT);
 pinMode(g, OUTPUT);
 pinMode(p, OUTPUT);
 pinMode(buzzerPin,OUTPUT);
 pinMode(ledPin,OUTPUT);//设置led引脚为输出引脚
}


void loop()
{
  Serial.println("请输入字符'H'或'T'分别修改湿度和温度阈值：");
   if(Serial.available()>0){
    Serial.print("输入字符：");
    char signal=Serial.read();
    Serial.println(signal);
    delay(5000);
    if(signal=='H'){//修改湿度阈值
      if(Serial.available()>0){       
        int i = Serial.parseInt();  
        Serial.print("修改湿度阈值：");
        Serial.println(i);
        humidityset=i;
      }
    }
    if(signal=='T'){//修改温度阈值
      if(Serial.available()>0){
        int i = Serial.parseInt();  
        Serial.print("修改温度阈值：");
        Serial.println(i);
        temperatureset=i;
      }
     }
  }
  mydht11.read(dhtpin);  // 读取 DHT11 传感器
  humidity=mydht11.humidity;
  temperature=mydht11.temperature;
  int show=humidity*100;
  dispose(show);
  clearLEDs();
  Serial.print("当前湿度：");
  Serial.println(humidity);
  for(int k=2000;k>0;k--){
  clearLEDs();
  pickDigit(1);
  pickNumber(num1);
  clearLEDs();
  pickDigit(2);
  dispDec(2);
  pickNumber(num2);
  clearLEDs();
  pickDigit(3);
  pickNumber(num3);
  clearLEDs();
  pickDigit(4);
  pickNumber(num4); 
  }     
  Serial.print("当前温度：");
  Serial.println(temperature);
  show=temperature*100;
  clearLEDs();
  dispose(show);
  for(int k=2000;k>0;k--){
  clearLEDs();
  pickDigit(1);
  pickNumber(num1);
  clearLEDs();
  pickDigit(2);
  dispDec(2);
  pickNumber(num2);
  clearLEDs();
  pickDigit(3);
  pickNumber(num3);
  clearLEDs();
  pickDigit(4);
  pickNumber(num4); 
  }      
  clearLEDs();
  if(temperature>temperatureset){
    digitalWrite(ledPin,HIGH);
  }else{
    digitalWrite(ledPin,LOW);
  }
  if(humidity>humidityset){
    tone();
  }
  delay(2000);
}

void pickDigit(int x)  //定义pickDigit(x),其作用是开启dx端口
{
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
  
  switch(x)
  {
  case 1:
    digitalWrite(d1, HIGH);
    break;
  case 2:
    digitalWrite(d2, HIGH);
    break;
  case 3:
    digitalWrite(d3, HIGH);
    break;
  default:
    digitalWrite(d4, HIGH);
    break;
  }
}

void pickNumber(int x)   //定义pickNumber(x),其作用是显示数字x
{
  switch(x)
  {
  default:
    zero();
    break;
  case 1:
    one();
    break;
  case 2:
    two();
    break;
  case 3:
    three();
    break;
  case 4:
    four();
    break;
  case 5:
    five();
    break;
  case 6:
    six();
    break;
  case 7:
    seven();
    break;
  case 8:
    eight();
    break;
  case 9:
    nine();
    break;
  }
}

void dispDec(int x)  //设定开启小数点
{
  digitalWrite(p, LOW);
}

void clearLEDs()  //清屏
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(p, HIGH);
}

void zero()  //定义数字0时阴极那些管脚开关
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void one()  //定义数字1时阴极那些管脚开关
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void two()  //定义数字2时阴极那些管脚开关
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void three()  //定义数字3时阴极那些管脚开关
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void four()  //定义数字4时阴极那些管脚开关
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void five()  //定义数字5时阴极那些管脚开关
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void six()  //定义数字6时阴极那些管脚开关
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void seven()  //定义数字7时阴极那些管脚开关
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void eight()  //定义数字8时阴极那些管脚开关
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void nine()  //定义数字9时阴极那些管脚开关
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void dispose(int show){
  num4=show%10;
  show=show/10;
  num3=show%10;
  show=show/10;
  num2=show%10;
  show=show/10;
  num1=show%10;
}
void tone(){
  for(int i=0;i<100;i++){
    digitalWrite(buzzerPin,HIGH);
    delay(10);
    digitalWrite(buzzerPin,LOW);
    delay(1);
    digitalWrite(buzzerPin,HIGH);
    delay(10);
    digitalWrite(buzzerPin,LOW);
    delay(3);
  }
}
