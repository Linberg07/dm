#include<iostream>
#include<cmath>
#include<sstream>
using namespace std;
struct Polynom{   //структура содержащая данные многочлена
	int Pol[300];    //массив содержащий степени и коэффициенты этой степени
};
void StringToInt(int &nom,string &str){   
	int len=str.length();  
	int umn = pow(10,len)/10; 
	for(int j=0;j<len;j++){ 
			nom+=(int(str[j])-48)*umn;
			umn=umn/10;
		} 
}
void inputPolynom(Polynom &polynom){ //функция ввода многочлена
	string p;  //строка для записи многочлена
	cin>>p;
	for(int i=0;i<300;i++){
		polynom.Pol[i] = 0;
	}
	char st='^';    
    char perem = 'x';
    string zn_vr = "";  //строка для записи коэфициентов 
    string deg = "";  //строка для записи степеней
    bool otrz = false;
   	for(int i=0;i<p.length();i++){
    	if(p[i]=='-') {
    		otrz = true;
    		continue;
		}
		if(p[i]!=perem){
    		zn_vr=zn_vr+p[i]; //коэфициент до х пишется в zn_vr
		}
		
		else{
			i++; //пропускаем x
			if(p[i]==st) i++; //пропускаем знак ^
			while(p[i]!='+'&&p[i]!='-'){  //записываем степень в deg
				deg=deg+p[i];
				i++;
			}
			if(p[i]=='-') i--;
			if(deg=="") deg="1"; //если степень не изменилась значит она равна 1
			if(zn_vr=="") zn_vr="1";  //если коэфициента перед х нет значит он равен "
			
			int nom=0;  //степень в int 
			StringToInt(nom,deg);
			int zn = 0;
			StringToInt(zn,zn_vr);
			if(otrz){
				zn=zn*(-1);
			}
			polynom.Pol[nom] = zn;  //запись коэфициента и степени в массив
			otrz = false;
			zn_vr="";
			deg="";
		}
	}
			int zn;
			StringToInt(zn,zn_vr);
			if(otrz){
				zn=zn*(-1);
			}
			polynom.Pol[0] = zn; //запись последнего числа в массив

}
void ADD_PP_P(Polynom &polynom,Polynom&polynom2){
	cout<<"Введите 1 полином(Пр. 5x^2+x+1, макс.степень = 300)"<<endl;
	inputPolynom(polynom);
	cout<<"Введите 2 полином(Пр. 5x^2+x+1, макс.степень = 300)"<<endl;
	inputPolynom(polynom2);
	Polynom polynom3;
	for(int i=0;i<300;i++){      
		int nom = 0;   //переменная, в которую поместится значение многочлена в определенной степени
		int nom1 = 0;  //переменная, в которую поместится значение многочлена в определенной степени
		
		if(polynom.Pol[i]!=0){  //если значение многочлена в определенной степени не равно значению по умолчанию, помещаем ее в переменную
			nom = polynom.Pol[i];
		}
		if(polynom2.Pol[i]!=0){ //если значение многочлена в определенной степени не равно значению по умолчанию, помещаем ее в переменную
			nom1 = polynom2.Pol[i];  
		}
		int nom2 = nom+nom1; //третья переменная хранящая сумму первых двух значений
		
		polynom3.Pol[i] = nom2; //присваиваем результативному полиному значение суммы в данной степени
	}
	for(int i = 299;i>=0;i--){  //вывод 
		if(polynom3.Pol[i]!=0){
			
			if(polynom3.Pol[i]>0){
				if(polynom3.Pol[i]==1){
					cout<<"+x^"<<i;
				}else{
				
			cout<<"+"<<polynom3.Pol[i]<<"x^"<<i;}
		}else{
			cout<<polynom3.Pol[i]<<"x^"<<i;
		}
		}
	}
}
void SUB_PP_P(Polynom&polynom,Polynom&polynom2){
	cout<<"Введите 1 полином(Пр. 5x^2+x+1, макс.степень = 300)"<<endl;
	inputPolynom(polynom);
	cout<<"Введите 2 полином(Пр. 5x^2+x+1, макс.степень = 300)"<<endl;
	inputPolynom(polynom2);
	Polynom polynom3;
	for(int i=0;i<300;i++){
		int nom = 0; //переменная, в которую поместится значение многочлена в определенной степени
		int nom1 = 0; //переменная, в которую поместится значение многочлена в определенной степени
		
		if(polynom.Pol[i]!=0){  //если значение многочлена в определенной степени не равно значению по умолчанию, помещаем ее в переменную
			nom = polynom.Pol[i];
		}
		if(polynom2.Pol[i]!=0){  //если значение многочлена в определенной степени не равно значению по умолчанию, помещаем ее в переменную
			nom1 = polynom2.Pol[i];
		}
		nom1 = nom1*(-1); //так как нужна разность, просто умножим коэффициенты второго мн-на на -1 и также сложим дальше
		int nom2 = nom+nom1;  //третья переменная хранящая сумму первых двух значений
		
		polynom3.Pol[i] = nom2; //присваиваем результативному полиному значение суммы в данной степени
	}
	for(int i = 299;i>=0;i--){ //вывод
		if(polynom3.Pol[i]!=0){
			
			if(polynom3.Pol[i]>0){
				if(polynom3.Pol[i]==1){
					cout<<"+x^"<<i;
				}else{
				
			cout<<"+"<<polynom3.Pol[i]<<"x^"<<i;}
		}else{
			cout<<polynom3.Pol[i]<<"x^"<<i;
		}
		}
	}
}
int main(){
	setlocale(LC_ALL,"rus");
	Polynom polynom;
	Polynom polynom2;
	
	ADD_PP_P(polynom,polynom2);
	SUB_PP_P(polynom,polynom2);

	
}
